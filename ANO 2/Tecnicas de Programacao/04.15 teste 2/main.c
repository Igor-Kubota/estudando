#include <stdio.h>
#include <stdlib.h>


int main()
{

// soma de uma PA de 50 valores pares

    int s50;
    int a50;
    int a1;
    int r = 2;

    a1 = 2;

    a50  = a1 + r*(50-1);

    s50 = (50*(a1 + a50))/2;



    printf("a soma da PA: %i\n", s50);



    return 0;
}
