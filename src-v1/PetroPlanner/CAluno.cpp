#include "CAluno.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QRegularExpression>

bool CAluno::lerDoArquivo(const QString& caminho) {
    QFile arquivo(caminho);
    if (!arquivo.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QTextStream in(&arquivo);
    std::vector<CDisciplinas> todasDisciplinas = getDisciplinasCurso();

    bool lendoTabela = false;
    while (!in.atEnd()) {
        QString linha = in.readLine().trimmed();

        if (linha.startsWith("Nome:"))
            nome = linha.section(":", 1).trimmed();
        else if (linha.startsWith("Matrícula:"))
            matricula = linha.section(":", 1).trimmed();
        else if (linha.startsWith("Curso:"))
            curso = linha.section(":", 1).trimmed();
        else if (linha.startsWith("Período:"))
            periodo = linha.section(":", 1).trimmed().toInt();
        else if (linha.startsWith("CRA:"))
            cra = linha.section(":", 1).trimmed().toFloat();
        else if (linha.startsWith("#") || linha.isEmpty())
            continue;
        else {
            lendoTabela = true;
        }

        if (lendoTabela && !linha.startsWith("#") && !linha.isEmpty()) {
            QTextStream stream(&linha);
            int periodoLinha;
            stream >> periodoLinha;

            QString palavra, nomeDisciplina;
            while (!stream.atEnd()) {
                stream >> palavra;
                if (palavra.contains(QRegularExpression("^\\d+(\\.\\d+)?$")) || palavra == "-")
                    break;
                nomeDisciplina += (nomeDisciplina.isEmpty() ? "" : " ") + palavra;
            }

            QString nomeTrim = nomeDisciplina.trimmed();
            auto it = std::find_if(todasDisciplinas.begin(), todasDisciplinas.end(), [&nomeTrim](const CDisciplinas& d) {
                return QString::fromStdString(d.nome).compare(nomeTrim, Qt::CaseInsensitive) == 0;
            });

            if (it == todasDisciplinas.end())
                continue;

            std::vector<QString> situacoes;
            while (!stream.atEnd()) {
                QString valor;
                stream >> valor;
                if (valor == "Aprovada" || valor == "Reprovada") {
                    situacoes.push_back(valor);
                } else if (valor == "Em") {
                    stream >> valor;
                    situacoes.push_back("Em Curso");
                } else if (valor == "Não") {
                    stream >> valor;
                    situacoes.push_back("Não Cursada");
                }
            }

            if (!situacoes.empty()) {
                QString ultimaSituacao = situacoes.back();

                if (ultimaSituacao == "Aprovada") {
                    disciplinasAprovadas.push_back(*it);
                } else if (ultimaSituacao == "Não Cursada") {
                    disciplinasNaoCursadas.push_back(*it);
                }
            }

        }
    }

    return true;
}
