#include <stdio.h>
#include <stdlib.h>

int main()
{

    int mat[4][4];
    int i;
    int j;
    int Valor;
    int a;
    int b = 0;

//Monta a matriz
    for(i=0; i<4; i++){

        for(j=0; j<4; j++){

            printf("Valor[%i][%i]: ", i,j);
            scanf("%i",&mat[i][j]);
        }

    }
    printf("\n");
// exibe a matriz
    for (i = 0; i < 4; i++){

        for (j = 0; j < 4; j++){


            printf("%i\t", mat[i][j]);
        }

        printf("\n");
    }
    printf("\nValores maiores que 10 :\n");

//exibe os valores maiores que 10
    for (i = 0; i < 4; i++){

        for (j = 0; j < 4; j++){

            if (mat[i][j] > 10){
                a = mat[i][j];
                b = b + 1;
                printf("\n%i\t\n",a);


            }

        }


    }
// numero de valores maiores que 10

    printf("\nNumero de valores maiores que 10 : %i\n", b);

    return 0;
}
