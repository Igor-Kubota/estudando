// Igor Eiki Ferreira Kubota
// RA: 19.02466-5

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int c[3] = {0,0,0};
    int atual[3];
    int sfinal[3];
    int origem, destino;

    printf("capacidade 0 : %i\t",c[0]);
    printf("capacidade 1 : %i\t",c[1]);
    printf("capacidade 2 : %i\t\n\n",c[2]);

    while((c[0]<=c[1]) || (c[1]<= c[2]))
    {

        printf("capacidade0: ");
        scanf("%i", &c[0]);
        printf("capacidade1: ");
        scanf("%i", &c[1]);
        printf("capacidade2: ");
        scanf("%i", &c[2]);
    }



    printf("\ngarrafa 0 : %i\t\t",c[0]);
    printf("garrafa 1 : %i\t\t",c[1]);
    printf("garrafa 2 : %i\n",c[2]);

    atual[0] = c[0];
    atual[1] = 0;
    atual[2] = 0;


    sfinal[0] = c[0]/2;
    sfinal[1] = c[0]/2;
    sfinal[2] = 0;

    do
    {
        system("CLS");
        printf("\nEstado atual 0 : %i\t\t",atual[0]);
        printf("Estado atual 1 : %i\t\t",atual[1]);
        printf("Estado atual 2 : %i\n\n",atual[2]);


        printf("digite a garrafa de origem: ");
        scanf("%i", &origem);

        printf("digite a garrafa de destino: ");
        scanf("%i", &destino);

        move(c,atual,origem,destino);
    }
    while((atual[0] != sfinal[0])||(atual[1] != sfinal[1])||(atual[2] != sfinal[2]));


    return 0;
}

void move(int c[],int atual[], int origem, int destino)
{
    if( (atual[origem]!= 0) && (atual[destino] < c[destino]) )
    {
        while((atual[origem]!= 0)&&(atual[destino] < c[destino]))
        {
            atual[origem] = atual[origem] - 1;
            atual[destino]= atual[destino] + 1;


        }


    }


}
