#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include <ctype.h>
#define MAX 20

void LerString(char[MAX]);
void exibirfila(TFila);


int main(){
    char op;
    TFila fila;
    Dados aux;
    CriarFila(&fila);
    int i=0;



    do{

    printf("(C)adastrar novo pedido\n");
    printf("(E)ntregar bebida\n");
    printf("(A)dministrativo\n");
    printf("(S)air do programa\n\n");
    printf("Digite o que deseja fazer: ");


    scanf("%c", &op);






    switch(toupper(op)){

    case 'C':
        i++;
        Dados b;

        b.valor = i;

        printf("Digite o Nome do Cliente: ");
        LerString(b.nome);
        printf("Digite o Pedido: ");
        LerString(b.pedido);

        if (InserirNaFila(&fila,b)==1){
            printf ("pedido inserido!\n");
        }
        else
            printf("Nao foi possivel adicionar");

        system("Pause;");
        fflush(stdin);


        break;

    case 'E':
                   if (QuantidadeNaFila(fila) > 0){

            printf("\nFinal: ");

            printf("%i\n\n", (fila.elemento[fila.frente]).valor) ;
            printf("%s", strupr((fila.elemento[fila.frente]).nome) );

            printf("!\n\n");

            printf("%s", (fila.elemento[fila.frente]).pedido );

            printf(" pronto!\n\n");

            RetirarDaFila( &fila, & (fila.elemento[fila.frente]) );

            system("pause");

            }

            else {

                printf("\nNao ha pedidos cadastrados.\n\n");
                system("pause");
            }

            break;


        break;

    case 'A':
        ExibirTabela(fila);
        system("pause");
        fflush(stdin);



        break;

    case 'S':
            printf("\nFechando\n");

            break;






        break;

    default :

        printf("Comando invalido\n");
        system("Pause;");
        break;



    }




    }
    while(toupper(op)!='S');

    return 0;
}



void LerString(char s[MAX]){

    setbuf(stdin, NULL);
    fgets(s, MAX, stdin);
    if(s[strlen(s)-1]=='\n')
        s[strlen(s)-1]='\0';
}


void ExibirTabela(TFila fila)
{
    int i;
    printf("Administrativo: \n");
    printf("+---+--------------------+--------------------+\n");
    printf("|ped|      cliente       |         item       |\n");
    printf("+---+--------------------+--------------------+\n");

    for (i = 0; i < fila.quantidade; i++)
    {
        printf("|%3i|%20s|%20s|\n", fila.elemento[i].valor, fila.elemento[i].nome, fila.elemento[i].pedido);
    }

    printf("+---+--------------------+--------------------+\n");


}
