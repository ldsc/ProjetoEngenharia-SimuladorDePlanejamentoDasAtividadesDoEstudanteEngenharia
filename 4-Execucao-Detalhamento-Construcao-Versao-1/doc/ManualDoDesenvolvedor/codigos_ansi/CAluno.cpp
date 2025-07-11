#include "CAluno.h"
#include "CDisciplinas.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QRegularExpression>


bool CAluno::lerDoArquivo(const QString& caminho)  {
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




    arquivo.seek(0);
    QString conteudoOriginal = arquivo.readAll();
    arquivo.close();

    QStringList linhas = conteudoOriginal.split('\n');
    QStringList resultadoFinal;

    QSet<QString> nomesEmCurso;
    for (const auto& d : disciplinasEmCurso)
        nomesEmCurso.insert(QString::fromStdString(d.nome).trimmed());

    bool dentroDaSecao = false;
    int indiceInsercao = -1;

    for (int i = 0; i < linhas.size(); ++i) {
        QString linha = linhas[i].trimmed();

        if (linha == "Disciplinas em Andamento:") {
            dentroDaSecao = true;
            resultadoFinal << linhas[i];
            indiceInsercao = resultadoFinal.size();  // posi��o onde as novas ser�o inseridas
            continue;
        }

        if (!dentroDaSecao) {
            resultadoFinal << linhas[i];
        } else {
            if (linha.startsWith("#") || linha.isEmpty()) {
                resultadoFinal << linhas[i];
            } else {
                QString nomeDisc = linha.section(';', 0, 0).trimmed();
                if (nomesEmCurso.contains(nomeDisc)) {
                    resultadoFinal << linhas[i];
                    nomesEmCurso.remove(nomeDisc);
                }
            }
        }
    }

    // Inserir as disciplinas que faltam logo ap�s o cabe�alho
    QStringList novasDisciplinas;
    for (const auto& nome : nomesEmCurso) {
        novasDisciplinas << nome + " ; 0 ; InserirDiaDeAula,InserirHorariosDaAula ; Trabalhos: -(1) ; Provas: -(1)";
    }

    if (indiceInsercao != -1) {
        resultadoFinal.insert(indiceInsercao, novasDisciplinas.join("\n"));
    } else {
        // Se a se��o n�o existia, criar com cabe�alho completo
        resultadoFinal << "# Formato das disciplinas em andamento:";
        resultadoFinal << "# Nome da Disciplina ; Faltas ; Dias e Horarios ; Trabalhos: nota(peso),... ; Provas: nota(peso),...";
        resultadoFinal << "# EXEMPLO: Mecanica dos Fluidos ; 0 ; Segunda:8h-10h, Quarta:8h-10h ; Trabalhos: 75.0(1),-(3) ; Provas: -(1)";
        resultadoFinal << "Disciplinas em Andamento:";
        resultadoFinal << novasDisciplinas;
    }

    // Reescreve o arquivo
    QFile arquivoSaida(caminho);
    if (arquivoSaida.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&arquivoSaida);
        for (const auto& linha : resultadoFinal)
            out << linha.trimmed() << "\n";
        arquivoSaida.close();
    }




    // Atualiza diasHorarios das disciplinas em curso, lendo da se��o "Disciplinas em Andamento"
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


    // === Verifica e carrega atividades extras, se existirem ===
    bool encontrouCabecalhoExtras = false;
    bool lendoAtividadesExtras = false;
    atividadesExtras.clear();


    for (int i = 0; i < linhas.size(); ++i) {
        QString linha = linhas[i].trimmed();

        if (linha.startsWith("# Formato: Nome da Atividade")) {
            encontrouCabecalhoExtras = true;
            lendoAtividadesExtras = true;
            continue;
        }

        if (linha.startsWith("# Exemplo:")) {
            continue;
        }

        if (lendoAtividadesExtras) {
            if (!linha.startsWith("#") && !linha.isEmpty()) {
                atividadesExtras.push_back(linha);
            }
        }
    }


    QSet<QString> atividadesExistentes;
    for (const auto& a : atividadesExtras)
        atividadesExistentes.insert(a.trimmed());

    bool dentroSecaoExtras = false;
    int indiceInsercaoExtras = -1;

    for (int i = 0; i < resultadoFinal.size(); ++i) {
        QString linha = resultadoFinal[i].trimmed();

        if (linha.startsWith("# Formato: Nome da Atividade")) {
            dentroSecaoExtras = true;
            indiceInsercaoExtras = i + 2;  // Pula o exemplo
            continue;
        }

        if (dentroSecaoExtras) {
            if (!linha.startsWith("#") && !linha.isEmpty()) {
                QString atividade = linha.trimmed();
                atividadesExistentes.remove(atividade);  // J� est� l�, ent�o n�o precisa adicionar depois
            }
        }
    }

    // S� adiciona o que ainda n�o est� presente
    if (!atividadesExistentes.isEmpty()) {
        QStringList novasAtividades = atividadesExistentes.values();

        if (indiceInsercaoExtras != -1) {
            resultadoFinal.insert(indiceInsercaoExtras, novasAtividades.join("\n"));
        } else {
            // Se a se��o n�o existe ainda
            resultadoFinal << ""
                           << "# Formato: Nome da Atividade ; Dias e Hor�rios"
                           << "# Exemplo: Estudo Individual ; Ter�a:14h-16h, Quinta:14h-16h";
            resultadoFinal << novasAtividades;
        }
    }




    // Sempre reescreve o arquivo com todas as informa��es atualizadas
    QFile arquivoFinal(caminho);
    if (arquivoFinal.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream outFinal(&arquivoFinal);
        for (const auto& linha : resultadoFinal)
            outFinal << linha.trimmed() << "\n";
        arquivoFinal.close();
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
