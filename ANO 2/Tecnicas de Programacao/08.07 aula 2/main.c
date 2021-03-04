// Guilherme Samuel 19.00012-0
// Guilherme Cury Galli 19.00374-9
// Gustavo Consoleti Ramirez de Souza 19.00715-9
// Igor Eiki Ferreira Kubota 19.02466-5

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "pilha.h"
#define MAX 50

void Limpar()
{
    system("clear || cls");
}

void LerString(char s[MAX])
{
    setbuf(stdin, NULL);
    fgets(s, MAX, stdin);
    if(s[strlen(s)-1]=='\n')
        s[strlen(s)-1]='\0';
}

void ExibirPilha(TPilha pilha)
{
    int i;
    Limpar();

    for(i=0; i <= pilha.topo; i++)
        printf("%i:\t%8.3f\n", i, pilha.elemento[i].valor);
    printf("%i:\t    ", i);
}


int main()
{
    Limpar();

    char op[MAX];
    TPilha pilha;
    float x, y, z;

    CriarPilha(&pilha);
    Dados aux;
    ExibirPilha(pilha);

    LerString(op);

    while( strcmpi(op,"FIM") != 0 )
    {
        if (strcmpi(op, "+") == 0)
    {
        if (pilha.topo >= 1)
        {
            RetirarDaPilha(&pilha, &aux);
            x = aux.valor;
            RetirarDaPilha(&pilha, &aux);
            y = aux.valor;
            aux.valor = x + y;
            InserirNaPilha(&pilha, aux);
            ExibirPilha(pilha);
        }
        else
        {
            printf("Somente um valor na lista");
            system("pause");
            ExibirPilha(pilha);
        }
    }

    else if (strcmpi(op, "-") == 0)
    {
        if (pilha.topo >= 1)
        {
            RetirarDaPilha(&pilha, &aux);
            x = aux.valor;
            RetirarDaPilha(&pilha, &aux);
            y = aux.valor;
            aux.valor = x - y;
            InserirNaPilha(&pilha, aux);
            ExibirPilha(pilha);
        }
        else
        {
            printf("Somente um valor na lista");
            system("pause");
            ExibirPilha(pilha);
        }
    }

    else if (strcmpi(op, "*") == 0)
    {
        if (pilha.topo >= 1)
        {
            RetirarDaPilha(&pilha, &aux);
            x = aux.valor;
            RetirarDaPilha(&pilha, &aux);
            y = aux.valor;
            aux.valor = x * y;
            InserirNaPilha(&pilha, aux);
            ExibirPilha(pilha);
        }
        else
        {
            printf("Somente um valor na lista");
            system("pause");
            ExibirPilha(pilha);
        }
    }

    else if (strcmpi(op, "/") == 0)
    {
        if (pilha.topo >= 1)
        {
            RetirarDaPilha(&pilha, &aux);
            x = aux.valor;
            RetirarDaPilha(&pilha, &aux);
            y = aux.valor;

            if  (x != 0)
            {
                aux.valor = y / x;
                InserirNaPilha(&pilha, aux);
                ExibirPilha(pilha);
            }
            else
            {
                printf("Denominador igual a zero");
                system("pause");
                aux.valor = y;
                InserirNaPilha(&pilha, aux);
                aux.valor = x;
                InserirNaPilha(&pilha, aux);
                ExibirPilha(pilha);
            }
        }
        else
        {
            printf("Somente um valor na lista");
            system("pause");
            ExibirPilha(pilha);
        }
    }

    else if (strcmpi(op, "SIN") == 0)
    {
        if (pilha.topo >= 0)
        {
            RetirarDaPilha(&pilha, &aux);
            x = aux.valor/180*M_PI;
            aux.valor = sin(x);
            InserirNaPilha(&pilha, aux);
            ExibirPilha(pilha);
        }
        else
        {
            printf("Sem valor na lista");
            system("pause");
            ExibirPilha(pilha);
        }
    }

    else if (strcmpi(op, "COS") == 0)
    {
        if (pilha.topo >= 0)
        {
            RetirarDaPilha(&pilha, &aux);
            x = aux.valor/180*M_PI;
            aux.valor = cos(x);
            InserirNaPilha(&pilha, aux);
            ExibirPilha(pilha);
        }
        else
        {
            printf("Sem valor na lista");
            system("pause");
            ExibirPilha(pilha);
        }
    }

    else if (strcmpi(op, "RAIZ") == 0)
    {
        if (pilha.topo >= 0)
        {
            RetirarDaPilha(&pilha, &aux);
            x = aux.valor;

            if (x > 0)
            {
                aux.valor = sqrt(x);
                InserirNaPilha(&pilha, aux);
                ExibirPilha(pilha);
            }
            else
            {
                printf("Raiz de numero negativo, numero imaginario\n\n");
                system("pause");
                aux.valor = x;
                InserirNaPilha(&pilha, aux);
                ExibirPilha(pilha);
            }
        }
        else
        {
            printf("Sem valor na lista");
            system("pause");
            ExibirPilha(pilha);
        }
    }

    else if (strcmpi(op, "PI") == 0)
    {
        aux.valor = M_PI;
        InserirNaPilha(&pilha, aux);
        ExibirPilha(pilha);
    }


    else if (strcmpi(op, "FIM") != 0)
    {
        ExibirPilha(pilha);
        aux.valor = atof(op);
        InserirNaPilha(&pilha, aux);
        ExibirPilha(pilha);
    }

        LerString(op);

    }

    printf("\nNoix\n");

    return 0;
}
