/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 9

/*Escreva uma função que aceita como parâmetro um vetor de inteiros com N valores, e
determina o maior elemento do vetor e o número de vezes que esse elemento ocorreu no
vetor. Por exemplo, para um vetor com os seguintes elementos: 5, 2, 15, 3, 7, 15, 8, 6, 15,
a função deve retornar para o programa que a chamou o valor 15 e o número 3 (indicando
que o número 15 ocorreu 3 vezes). A função deve ser do tipo void.
*/


/*
void LerVetor(int[N]);
int Maximo(int[N]);

int main(){

    int i;
    int Max;
    int Vet[N];

    LerVetor(Vet);
    Max = Maximo(Vet);
    printf("Maior valor = %i",Max);

    return 0 ;
}


void LerVetor(int V[]){
    int i; //Variável local
    for(i=0; i<N; i++){
        printf("Valor[%i]: ",i);
        scanf("%i",&V[i]);
    }
}
int Maximo(int V[N]){
    int i;
    int maior=V[0]; // o primeiro
    for (i=1; i<N; i++)
    if (V[i] > maior)
        maior = V[i];
    return maior;


}
*/
#include <stdio.h>
#include <string.h>
#define N 10

int main(){
    int num[N];
    int maior;
    int i;
    int j;
    int total = 0;

    LerVetor(num);
    Maximo(num);

    for (j = 0; j < strlen(num) ; j++) {
        if (maior == num[j])
            total++;
            Maximo(num[N]);
    }

    printf("o numero  '%i' aparece %i vezes ", maior, total);
    return 0;
}
void LerVetor(int num[N]){
    int i;
    for(i=0; i<N; i++){
        printf("Escreva o numero [%i]: ",i);
        scanf("%i",&num[i]);
    }
}

int Maximo(int v[N]){
    int i;
    int maior = v[0];

    for (i=1; i<N; i++){
        if (v[i] > maior)
        maior = v[i];
    }
    return maior;
}




