//Kaun Alexandre Puccio santos - 19.0224-7
//Mateus Silva Souza - 19.01309-4
//Vinicius Savrutsky Ivankovich - 19.01014-0



#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include <string.h>
void exibirfila(TFila);
void LerString(char[]);
int main()
{
    int i=0;


    TFila fila;
    Dados s;
    CriarFila(&fila);
    char opt;
    do
    {
        printf("\nDigite a funcionalidade: \n(C)adastrar novo pedido\n(E)ntregar bebida\n(A)dministrativo\n(S)air\n");
        scanf("%c", &opt);


        switch(opt)
        {


        case 'C':
            i++;
            Dados a;
            a.valor=i;
            printf("Digite o nome do cliente:");
            LerString(a.nome);
            printf("Digite o Pedido:");
            LerString(a.beb);
            if (InserirNaFila(&fila,a)==1);

            else
                printf("Nao foi possivel adicionar");

            system("Pause;");

            break;
        case 'E':
            if (RetirarDaFila(&fila,&s)==1)
            {
                RetirarDaFila(&fila,&s);
                printf("Final:%i\n",s.valor);
                printf("%s !\n",s.nome);
                printf("%s pronto!\n",s.beb);

            }
            else
            printf("Nao foi possivel entregar");

            system("Pause;");


            break;
        case 'A':
            exibirfila(fila);
            system("Pause;");




            break;
        case 'S':
            break;

        default :
            printf("Comando invalido\n");
            system("Pause;");
            break;






        }



    }
    while(opt!='S');

    return 0;
}




void exibirfila(TFila fila)
{
    int n;
    printf("Administrativo:\n");
    printf("+---+--------------------+--------------------+\n");
    printf("|ped|      cliente       |         item       |\n");
    printf("+---+--------------------+--------------------+\n");
    for(n=0; n<fila.quantidade; n++)
    {
        printf("|%3i|%20s|%20s|\n",fila.elemento[n].valor,fila.elemento[n].nome,fila.elemento[n].beb);



    }






}

void LerString(char s[MAX]){
setbuf(stdin, 0);
// ou fflush(stdin);
fgets(s, MAX, stdin);
if (s[strlen(s)-1] == '\n')
s[strlen(s)-1] = '\0';
}
