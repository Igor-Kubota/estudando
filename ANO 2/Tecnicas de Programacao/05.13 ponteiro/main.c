#include <stdio.h>
#include <stdlib.h>


int main(){

    int y;
    int *x;

    printf("Digite y: ");
    scanf("%i",&y);

    printf("Valor de y: %i\n",y);
    printf("Endereco de y: %p\n",&y);

    x = &y;

    printf("\nValor de x: %p\n",x);
    printf("Endereco de x: %p\n",&x);
    printf("Valor da variavel que x aponta: %i\n",*x);

    *x = 2;

    printf("\nValor de y: %i\n",y);
    printf("Endereco de y: %p\n",&y);

    printf("\nValor de x: %p\n",x);
    printf("Endereco de x: %p\n",&x);
    printf("Valor da variavel que x aponta: %i\n",*x);

    return 0;
}
/*
#include <stdio.h>
#include <stdlib.h>

void algo1(int *);
void algo2(int *);

int main(){

    int y;

    printf("Digite y: ");
    scanf("%i",&y);

    printf("Valor de y: %i\n",y);
    algo1(&y);
    printf("Valor de y: %i\n",y);

    return 0;
}

void algo1(int *a){
    *a = *a + 5;
    algo2(a);
}

void algo2(int *a){
    *a = *a *3;
    algo3(a);
}

void algo3(int *a){
    *a = *a *2;

}
*/
/*
int main(){

    int *Atual;
    int Vetor[7],i;

    Atual = Vetor;

    for(i = 0; i < 7; i++)
        *(Atual+i) = i;

    for(i = 0; i < 7; i++)
	printf("%i\n", Vetor[i]);



    return 0;
}*/



