#include "CAluno.h"
#include "CDisciplinas.h"
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
        else if (linha.startsWith("Matricula:"))
            matricula = linha.section(":", 1).trimmed();
        else if (linha.startsWith("Curso:"))
            curso = linha.section(":", 1).trimmed();
        else if (linha.startsWith("Periodo:"))
            periodo = linha.section(":", 1).trimmed().toInt();
        else if (linha.startsWith("CRA:"))
            cra = linha.section(":", 1).trimmed().toFloat();
        else if (linha.startsWith("#") || linha.isEmpty())
            continue;
        else
            lendoTabela = true;

        if (lendoTabela && !linha.startsWith("#") && !linha.isEmpty()) {
            QStringList partes = linha.split(";", Qt::SkipEmptyParts);
            if (partes.size() < 4) continue;

            int periodoLinha = partes[0].trimmed().toInt();
            QString nomeDisciplina = partes[1].trimmed();

            auto it = std::find_if(todasDisciplinas.begin(), todasDisciplinas.end(),
                                   [&nomeDisciplina](const CDisciplinas& d) {
                                       return QString::fromStdString(d.nome).compare(nomeDisciplina, Qt::CaseInsensitive) == 0;
                                   });

            if (it == todasDisciplinas.end())
                continue;

            std::vector<QString> situacoes;
            for (int i = 2; i + 1 < partes.size(); i += 2) {
                QString nota = partes[i].trimmed();
                QString situacao = partes[i + 1].trimmed();

                if (!situacao.isEmpty()) {
                    situacoes.push_back(situacao);
                }
            }

            if (!situacoes.empty()) {
                QString ultimaSituacao = situacoes.back();

                if (ultimaSituacao == "Aprovada") {
                    disciplinasAprovadas.push_back(*it);
                } else if (ultimaSituacao == "Em Curso") {
                    disciplinasEmCurso.push_back(*it);
                } else if (ultimaSituacao == "Nao Cursada") {
                    disciplinasNaoCursadas.push_back(*it);
                }
            }


        }
    }




    // Verifica se a seção "Disciplinas em Andamento" já existe no arquivo
    arquivo.seek(0);
    QString conteudo = in.readAll();
    if (!conteudo.contains("Disciplinas em Andamento:")) {
        // Reabre para append e escreve a seção
        QFile arqAppend(caminho);
        if (arqAppend.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&arqAppend);
            out << "\n\n\n# Formato das disciplinas em andamento:\n";
            out << "# Nome da Disciplina ; Faltas ; Dias e Horarios ; Trabalhos: nota(peso),... ; Provas: nota(peso),...\n\n";
            out << "Disciplinas em Andamento:\n\n";
            for (const auto& disc : disciplinasEmCurso) {
                out << QString::fromStdString(disc.nome)
                << " ; 0 ; InserirDiaDeAula,InserirHorariosDaAula ; Trabalhos: -(1) ; Provas: -(1)\n";
            }
            out.flush();
            arqAppend.close();
        }
    }
}



int CAluno::calcularHorasEmCurso() const {
    std::vector<CDisciplinas> todas = getDisciplinasCurso();
    int total = 0;

    for (const auto& discAluno : disciplinasEmCurso) {
        for (const auto& discCurso : todas) {
            if (discAluno.getNome() == discCurso.getNome()) {
                total += discCurso.getHoras();
                break;
            }
        }
    }

    return total;
}
