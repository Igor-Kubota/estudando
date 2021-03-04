#include <stdio.h>
#include <stdlib.h>


int main(){
    float a;
    float b;

    printf("Digite o valor digital: ");
    scanf("%f",&a);

    if((a<0)||(a>1025))
        printf("error");
    else{
        printf("Digite o valor digital: ");
        scanf("%f",&a);

        b= a*5/1024;


        printf("o valor analogico eh %f", b);

    }

    return 0;
    }


