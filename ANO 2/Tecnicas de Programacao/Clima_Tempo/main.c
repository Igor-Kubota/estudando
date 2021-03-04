//19.01518-6 GUILHERME TORRES DE SOUZA
//19.02466-5 IGOR EIKI FERRERIA KUBOTA
//19.01726-0 THIAGO AKIO KANADA TANAKA

#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
#define MAX 500

void ExibirTabela(sqlite3_stmt *stmt)
{
    int i;
    // exibe o cabeçalho
    for (i = 0; i < sqlite3_column_count(stmt); i++)
        printf("%s\t\t", sqlite3_column_name(stmt,i));
    printf("\n");

    // para cada linha da tabela
    while(sqlite3_step(stmt) != SQLITE_DONE)
    {
        // para cada coluna da linha
        for (i = 0; i < sqlite3_column_count(stmt); i++)
            if (sqlite3_column_type(stmt, i) == SQLITE_FLOAT)
                printf("%.2f\t", sqlite3_column_double(stmt,i)); // formata valores reais com 2 casas
            else
                printf("%s\t", sqlite3_column_text(stmt,i));
        printf("\n");
    }
    printf("\n");
}

void mostraMenu(){
    printf("Informe a Opcao desejada: \n\n");
    printf("1 - Consultar a precipitacao media no periodo\n");
    printf("2 - Consultar os dias com a temperatura maxima no periodo\n");
    printf("3 - Consultar os dias com a temperatura minima no periodo\n");
    printf("4 - Consultar a temperatura media no periodo\n");
    printf("0 - Sair do Sistema\n");

}

void formatarData(int dia, int mes, int ano, char *data)
{
    if (mes >= 10)
        sprintf(data,"%i-%i",ano,mes);
    else
        sprintf(data,"%i-0%i",ano,mes);
    if (dia >= 10)
        sprintf(data,"%s-%i",data,dia);
    else
        sprintf(data,"%s-0%i",data,dia);
}


int main()
{
    sqlite3 *db = NULL;
    sqlite3_stmt *stmt = NULL;
    char sql[MAX];
    int conexao;
    int dia, mes, ano, opcao;
    char dataIni[11], dataFim[11];

    //Abre a conexão com o banco
    conexao = sqlite3_open("Tempo.db", &db);
    if (conexao != SQLITE_OK)
    {
        printf("Erro ao conectar ao banco\n");
        exit(-1);
    }

    // laço principal
    do
    {
        // Faz a chamada do menu e a leitura da opção do usuário
        system("cls");
        mostraMenu();
        scanf("%i", &opcao);

        // se deseja fazer uma consulta
        if (opcao != 0)
        {
            // faz a leitura e formatação das datas inicial e final da consulta
            printf("Informe o dia de inicio: ");
            scanf("%i", &dia);
            printf("Informe o mes de inicio: ");
            scanf("%i", &mes);
            printf("Informe o ano de inicio: ");
            scanf("%i", &ano);

            formatarData(dia,mes,ano,&dataIni);

            printf("Informe o dia de fim: ");
            scanf("%i",&dia);
            printf("Informe o mes de fim: ");
            scanf("%i",&mes);
            printf("Informe o ano de fim: ");
            scanf("%i",&ano);

            formatarData(dia,mes,ano,&dataFim);


            // verifica a opção desejada
            switch(opcao)
            {
            case 1:
            {
                //Realiza consulta para determinar a precipitação média no período
                sprintf(sql,"SELECT AVG(precipitacao) FROM Medicoes WHERE data BETWEEN '%s' and '%s'",dataIni, dataFim);
                printf("\n%s\n\n", sql); // POPPA
                sqlite3_prepare(db, sql, -1, &stmt, NULL);
                ExibirTabela(stmt);
                break;
            } // fim do case 1

            case 2:
            {
                //Realiza a conculta para determinar a temperatura máxima no período
                sprintf(sql,"SELECT data, tmax FROM Medicoes WHERE tmax = (SELECT max(tmax) FROM Medicoes Where data BETWEEN '%s'AND '%s') AND data BETWEEN '%s' AND '%s'",dataIni,dataFim,dataIni,dataFim);
                printf("\n%s\n\n", sql); // POPPA
                sqlite3_prepare(db, sql, -1, &stmt, NULL);
                ExibirTabela(stmt);
                break;
            } // fim do case 2

            case 3:
            {
                //Realiza a consulta para determinar a temperatura mínima no período
                sprintf(sql,"SELECT data, tmin FROM Medicoes WHERE tmin = (SELECT min(tmin) FROM Medicoes Where data BETWEEN '%s'AND '%s') AND data BETWEEN '%s' AND '%s'",dataIni,dataFim,dataIni,dataFim);
                printf("\n%s\n\n", sql); // POPPA
                sqlite3_prepare(db, sql, -1, &stmt, NULL);
                ExibirTabela(stmt);
                break;
            } // fim do case 3
            case 4:
            {
                //Realiza consulta para determinar a temperatura média no período
                sprintf(sql,"SELECT data, AVG((tmax + tmin)/2) FROM Medicoes Where data BETWEEN '%s' AND '%s'",dataIni,dataFim);
                printf("\n%s\n\n", sql); // POPPA
                sqlite3_prepare(db, sql, -1, &stmt, NULL);
                ExibirTabela(stmt);
                break;
            } // fim do case 4
            } // fim do switch
            system("pause");
        }
    }
    while(opcao != 0);

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 0;


}
