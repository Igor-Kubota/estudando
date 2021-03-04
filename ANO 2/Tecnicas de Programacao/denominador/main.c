#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#define ZERO 1E-6



void Exibir(int den) {

    printf("1/%i\n", den);

}



// SOMENTE complete essa função

void Fracoes(float f, int den) {

  if((fabs(f-(1.0/den))) < ZERO)
       return Exibir(den);

    if ((f-(1.0/den))>ZERO)
    {
       Exibir(den);
       return Fracoes((f-(1.0/den)), (den+1));
    }
    if ((f-(1.0/den))<ZERO)
      return Fracoes(f, (den + 1));










}



int main() {

    float f;

    int num, den;

    printf("Digite o numerador: ");

    scanf("%i", &num);

    printf("Digite o denominador: ");

    scanf("%i", &den);

    printf("\n%i\n", num/den); // exibe a parte inteira

    f = (float)(num)/(float)(den) - num/den; // obter a parte fracionária, ou seja, o valor de f será 0.xxxxx

    Fracoes(f, 2); // inicia a chamada recursiva a partir do valor 1/2

    return 0;

}
