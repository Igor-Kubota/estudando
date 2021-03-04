#include <stdio.h>
#include <stdlib.h>

int main(){

    int v1;
    int v2;
    int aux;
    int a;
    int b;
    int c;
    printf("digite um numero de 3 digitos: ");
    scanf("%i", &v1);

    aux = v1;
    a = aux/100;
    b = aux/10%10;
    c = aux%10;



    printf("\nO numero digitado foi: %i\n", v1);

    printf("\nSua resposta eh %i%i%i\n",c,b,a);




return 0;




    }
