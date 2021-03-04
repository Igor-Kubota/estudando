#include <stdio.h>
#include <stdlib.h>



void MoveDisco(int de, int para){

printf(" %i -> %i\n", de, para);

}


// SOMENTE complete essa função
void MoveTorre(int altura, int de, int para, int aux){

    if (altura > 0){
        MoveTorre(altura - 1, de, aux, para);
        MoveDisco(de, para);
        MoveTorre(altura - 1, aux, para, de);
    }
}


int main(){

    int n;
    printf("Digite o numero de discos: ");
    scanf("%i", &n);
    MoveTorre(n, 1, 3, 2);
    return 0;

}

