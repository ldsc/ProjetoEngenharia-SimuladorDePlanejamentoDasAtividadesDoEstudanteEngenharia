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




    // Atualiza a seção "Disciplinas em Andamento" mantendo dados existentes válidos
    arquivo.seek(0);
    QString conteudoOriginal = arquivo.readAll();
    arquivo.close();

    QStringList linhas = conteudoOriginal.split('\n');
    QStringList resultadoFinal;

    bool dentroDaSecao = false;
    QSet<QString> nomesEmCurso;
    for (const auto& d : disciplinasEmCurso)
        nomesEmCurso.insert(QString::fromStdString(d.nome).trimmed());

    QStringList novaSecao;
    for (int i = 0; i < linhas.size(); ++i) {
        QString linha = linhas[i].trimmed();

        if (linha == "Disciplinas em Andamento:") {
            dentroDaSecao = true;
            novaSecao << linha;
            continue;
        }

        if (!dentroDaSecao) {
            resultadoFinal << linhas[i];
            continue;
        }

        // Mantém comentários ou espaços dentro da seção
        if (linha.startsWith("#") || linha.isEmpty()) {
            novaSecao << linhas[i];
            continue;
        }

        QString nomeDisc = linha.section(';', 0, 0).trimmed();

        if (nomesEmCurso.contains(nomeDisc)) {
            // Mantém a linha completa com notas, faltas etc.
            novaSecao << linhas[i];
            nomesEmCurso.remove(nomeDisc);  // já está na seção
        }
    }

    // Adiciona as que faltaram
    for (const auto& nome : nomesEmCurso) {
        novaSecao << nome + " ; 0 ; InserirDiaDeAula,InserirHorariosDaAula ; Trabalhos: -(1) ; Provas: -(1)";
    }

    // Junta tudo novamente
    resultadoFinal << "" << "" << novaSecao;

    // Reescreve o arquivo
    QFile arquivoSaida(caminho);
    if (arquivoSaida.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&arquivoSaida);
        for (const auto& linha : resultadoFinal) {
            out << linha.trimmed() << "\n";
        }
        arquivoSaida.close();
    }



    // Atualiza diasHorarios das disciplinas em curso, lendo da seção "Disciplinas em Andamento"
    QFile arqReleitura(caminho);
    if (arqReleitura.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream inReleitura(&arqReleitura);
        bool lendoDisciplinasAndamento = false;

        while (!inReleitura.atEnd()) {
            QString linha = inReleitura.readLine().trimmed();

            if (linha == "Disciplinas em Andamento:") {
                lendoDisciplinasAndamento = true;
                continue;
            }

            if (lendoDisciplinasAndamento && !linha.isEmpty() && !linha.startsWith("#")) {
                QStringList partes = linha.split(";", Qt::SkipEmptyParts);
                if (partes.size() < 3) continue;

                QString nomeLinha = partes[0].trimmed();
                QString diasHorarios = partes[2].trimmed();

                for (auto& d : disciplinasEmCurso) {
                    QString nomeAluno = QString::fromStdString(d.nome).trimmed();
                    if (QString::compare(nomeAluno, nomeLinha, Qt::CaseInsensitive) == 0) {
                        d.diasHorarios = diasHorarios;
                        break;
                    }
                }
            }
        }

        arqReleitura.close();
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


int CAluno::calcularCHTotalCursada() const {
    std::vector<CDisciplinas> todas = getDisciplinasCurso();
    int total = 0;

    for (const auto& discAluno : disciplinasAprovadas) {
        QString nomeAluno = QString::fromStdString(discAluno.getNome()).trimmed();

        for (const auto& discCurso : todas) {
            QString nomeCurso = QString::fromStdString(discCurso.getNome()).trimmed();

            if (QString::compare(nomeAluno, nomeCurso, Qt::CaseInsensitive) == 0) {
                total += discCurso.getCH();
                break;
            }
        }
    }

    return total;


}
