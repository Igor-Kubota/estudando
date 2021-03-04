// RA: 19.02466-5 IGOR EIKI FERREIRA KUBOTA
// RA: 19.01145-8 RAFAEL RIBEIRO TOYAMA
// RA: 19.01907-6 BRUNO TADASHI OKUMA NAKAO

#include <stdio.h>
#include <stdlib.h>
#define NP 3
#define NA 4

void DigitarConsumo(int cCond[NP][NA]);
void ConsumoDosPredios(int cCond[NP][NA], int cPredio[NP]);
int ConsumoTotal(int cPredio[NP]);
void pcConsMorador(int cCond[NP][NA],int cTotal, float pcMorador[NP][NA]);
void ExibirResumo(int cPredio[NP], int cTotal);
void ExibirPorApartamento(float pcMorador[NP][NA], int cTotal);
// atenção com os tipos de dados dos parâmetros

// programa principal

int main()
{

    int cCond[NP][NA], cPredio[NP], cTotal;
    float pcMorador[NP][NA];

    DigitarConsumo(cCond);
    ConsumoDosPredios(cCond, cPredio);
    cTotal = ConsumoTotal(cPredio);
    pcConsMorador(cCond, cTotal, pcMorador);
    ExibirResumo(cPredio, cTotal);
    ExibirPorApartamento(pcMorador, cTotal);
    return 0;

}

// escreva as sub-rotinas aqui
void DigitarConsumo(int cCond[NP][NA])
{
    printf("Digite o consumo do apartamento 1 do predio A: ");
    scanf("%i", & cCond[0][0]);
    printf("Digite o consumo do apartamento 2 do predio A: ");
    scanf("%i", & cCond[0][1]);
    printf("Digite o consumo do apartamento 3 do predio A: ");
    scanf("%i", & cCond[0][2]);
    printf("Digite o consumo do apartamento 4 do predio A: ");
    scanf("%i", & cCond[0][3]);
    printf("Digite o consumo do apartamento 1 do predio B: ");
    scanf("%i", & cCond[1][0]);
    printf("Digite o consumo do apartamento 2 do predio B: ");
    scanf("%i", & cCond[1][1]);
    printf("Digite o consumo do apartamento 3 do predio B: ");
    scanf("%i", & cCond[1][2]);
    printf("Digite o consumo do apartamento 4 do predio B: ");
    scanf("%i", & cCond[1][3]);
    printf("Digite o consumo do apartamento 1 do predio C: ");
    scanf("%i", & cCond[2][0]);
    printf("Digite o consumo do apartamento 2 do predio C: ");
    scanf("%i", & cCond[2][1]);
    printf("Digite o consumo do apartamento 3 do predio C: ");
    scanf("%i", & cCond[2][2]);
    printf("Digite o consumo do apartamento 4 do predio C: ");
    scanf("%i", & cCond[2][3]);
}
void ConsumoDosPredios(int cCond[NP][NA], int cPredio[NP])
{
    int i, j, k;
    for (i = 0; i<NP; i++)
    {
        k = 0;
        for (j = 0; j < NA; j++)
        {
            k = k + cCond[i][j];
        }
        cPredio[i] = k;
    }
}
int ConsumoTotal(int cPredio[NP])
{
    int cTotal;
    cTotal = cPredio[0] + cPredio[1] + cPredio[2];
    return cTotal;
}
void pcConsMorador(int cCond[NP][NA],int cTotal, float pcMorador[NP][NA])
{
    int i, j;
    int a = '%';
    float p,q;
    for (i = 0; i<NP; i++)
    {
        for (j = 0; j < NA; j++)
        {
            p = cCond[i][j];
            q = cTotal;
            pcMorador[i][j] = (p * 100) / q ;
        }
    }
}
void ExibirResumo(int cPredio[NP], int cTotal)
{
    printf("Predio A: %i kWh \n", cPredio[0]);
    printf("Predio B: %i kWh \n", cPredio[1]);
    printf("Predio C: %i kWh \n \n", cPredio[2]);
    printf("Consumo Total: %i kWh \n \n", cTotal);
}

void ExibirPorApartamento(float pcMorador[NP][NA], int cTotal)
{
    char a,b1,c1,d1,e1,b2,c2,d2,e2,b3,c3,d3,e3;
    int i;
    i = 0;
    a = '%';
    b1 = ' ';
    c1 = ' ';
    d1 = ' ';
    e1 = ' ';
    b2 = ' ';
    c2 = ' ';
    d2 = ' ';
    e2 = ' ';
    b3 = ' ';
    c3 = ' ';
    d3 = ' ';
    e3 = ' ';
    if (pcMorador[i][0]>=pcMorador[i][1]){
        if(pcMorador[i][0]>=pcMorador[i][2]){
            if(pcMorador[i][0]>=pcMorador[i][3]){
                    b1 = '!';
                    }
                }
            }
    if (pcMorador[i][1]>=pcMorador[i][0]){
        if(pcMorador[i][1]>=pcMorador[i][2]){
            if(pcMorador[i][1]>=pcMorador[i][3]){
                    c1 = '!';
                    }
                }
            }
    if (pcMorador[i][2]>=pcMorador[i][0]){
        if(pcMorador[i][2]>=pcMorador[i][1]){
            if(pcMorador[i][2]>=pcMorador[i][3]){
                    d1 = '!';
                    }
                }
            }
    if (pcMorador[i][3]>=pcMorador[i][0]){
        if(pcMorador[i][3]>=pcMorador[i][1]){
            if(pcMorador[i][3]>=pcMorador[i][2]){
                    e1 = '!';
                    }
                }
            }
    i = 1;
    if (pcMorador[i][0]>=pcMorador[i][1]){
        if(pcMorador[i][0]>=pcMorador[i][2]){
            if(pcMorador[i][0]>=pcMorador[i][3]){
                    b2 = '!';
                    }
                }
            }
    if (pcMorador[i][1]>=pcMorador[i][0]){
        if(pcMorador[i][1]>=pcMorador[i][2]){
            if(pcMorador[i][1]>=pcMorador[i][3]){
                    c2 = '!';
                    }
                }
            }
    if (pcMorador[i][2]>=pcMorador[i][0]){
        if(pcMorador[i][2]>=pcMorador[i][1]){
            if(pcMorador[i][2]>=pcMorador[i][3]){
                    d2 = '!';
                    }
                }
            }
    if (pcMorador[i][3]>=pcMorador[i][0]){
        if(pcMorador[i][3]>=pcMorador[i][1]){
            if(pcMorador[i][3]>=pcMorador[i][2]){
                    e2 = '!';
                    }
                }
            }
    i = 2;
    if (pcMorador[i][0]>=pcMorador[i][1]){
        if(pcMorador[i][0]>=pcMorador[i][2]){
            if(pcMorador[i][0]>=pcMorador[i][3]){
                    b3 = '!';
                    }
                }
            }
    if (pcMorador[i][1]>=pcMorador[i][0]){
        if(pcMorador[i][1]>=pcMorador[i][2]){
            if(pcMorador[i][1]>=pcMorador[i][3]){
                    c3 = '!';
                    }
                }
            }
    if (pcMorador[i][2]>=pcMorador[i][0]){
        if(pcMorador[i][2]>=pcMorador[i][1]){
            if(pcMorador[i][2]>=pcMorador[i][3]){
                    d3 = '!';
                    }
                }
            }
    if (pcMorador[i][3]>=pcMorador[i][0]){
        if(pcMorador[i][3]>=pcMorador[i][1]){
            if(pcMorador[i][3]>=pcMorador[i][2]){
                    e3 = '!';
                    }
                }}
    printf("%.2f%c%c\t%.2f%c%c\t%.2f%c%c\t%.2f%c%c\n", pcMorador[0][0], a,b1,pcMorador[0][1],a,c1,pcMorador[0][2],a,d1,pcMorador[0][3],a,e1);
    printf("%.2f%c%c\t%.2f%c%c\t%.2f%c%c\t%.2f%c%c\n", pcMorador[1][0], a,b2,pcMorador[1][1],a,c2,pcMorador[1][2],a,d2,pcMorador[1][3],a,e2);
    printf("%.2f%c%c\t%.2f%c%c\t%.2f%c%c\t%.2f%c%c\n", pcMorador[2][0], a,b3,pcMorador[2][1],a,c3,pcMorador[2][2],a,d3,pcMorador[2][3],a,e3);

}

Pressione Shift + Tab para acessar o histórico do bate-papo.
    }
    printf("%.2f%c%c\t%.2f%c%c\t%.2f%c%c\t%.2f%c%c\n", pcMorador[0][0], a,b1}}
    printf("%.2f%c%c\t%.2f%c%c\t%.2f%c%c\t%.2f%c%c\n", pcMorador[0][0], a,b1,pcMorador[0][1],a,c1,pcMorador[0][2],a,d1,pcMorador[0][3],a,e1);
    printf("%.2f%c%c\t%.2f%c%c\t%.2f%c%c\t%.2f%c%c\n", pcMorador[1][0], a,b2,pcMorador[1][1],a,c2,pcMorador[1][2],a,d2,pcMorador[1][3],a,e2);
    printf("%.2f%c%c\t%.2f%c%c\t%.2f%c%c\t%.2f%c%c\n", pcMorador[2][0], a,b3,pcMorador[2][1],a,c3,pcMorador[2][2],a,d3,pcMorador[2][3],a,e3);

}

Pressione Shift + Tab para acessar o histórico do bate-papo.
    printf("%.2f%c%c\t%.2f%c%c\t%.2f%c%c\t%.2f%c%c\n", pcMorador[0][0], a,b1,pcMorador[0][1],a,c1,pcMorador[0][2],a,d1,pcMorador[0][3],a,e1);
    printf("%.2f%c%c\t%.2f%c%c\t%.2f%c%c\t%.2f%c%c\n", pcMorador[1][0], a,b2,pcMorador[1][1],a,c2,pcMorador[1][2],a,d2,pcMorador[1][3],a,e2);
    printf("%.2f%c%c\t%.2f%c%c\t%.2f%c%c\t%.2f%c%c\n", pcMorador[2][0], a,b3,pcMorador[2][1],a,c3,pcMorador[2][2],a,d3,pcMorador[2][3],a,e3);

}

Pressione Shift + Tab para acessar o histórico do bate-papo.,pcMorador[0][1],a,c1,pcMorador[0][2],a,d1,pcMorador[0][3],a,e1);
    printf("%.2f%c%c\t%.2f%c%c\t%.2f%c%c\t%.2f%c%c\n", pcMorador[1][0], a,b2,pcMorador[1][1],a,c2,pcMorador[1][2],a,d2,pcMorador[1][3],a,e2);
    printf("%.2f%c%c\t%.2f%c%c\t%.2f%c%c\t%.2f%c%c\n", pcMorador[2][0], a,b3,pcMorador[2][1],a,c3,pcMorador[2][2],a,d3,pcMorador[2][3],a,e3);
}
