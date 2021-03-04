/*
// Igor Eiki Ferreira Kubota 19.02466-5
// Murilo Amorim Rahal 19.01157-0
// Guilherme Cury Galli 19.00374-9
// Guilherme Patti Borges 19.01279-9

#include <stdio.h>
#include <stdlib.h>
#include "pokemon.h"


void Atacar(Pokemon *p1, Pokemon *p2);
int Batalha(Pokemon *p1, Pokemon *p2);
void ExibirTimes(Pokemon *p1, Pokemon *p2);



int main(){
    int i;
    int j;

    Pokemon p1[6], p2[6];
    GerarTimes(p1, p2);
    ExibirTimes(p1, p2);
    Batalha(p1,p2);

    return 0;
}


void Atacar(Pokemon *p1, Pokemon *p2){

    int dano1;
    int dano2;
    dano1 = (*p1).AT - (*p2).DF;

    if ((*p1).AT > (*p2).DF)
    {
        (*p2).HP = (*p2).HP - dano1;
    }
    else
    {
        (*p2).HP = (*p2).HP - 1;
    }

    if((*p2).HP<0)
        (*p2).HP = 0;


    if((*p1).HP < 0)
        (*p1).HP = 0;

    printf("p2 = %i\n",(*p2).HP);
    dano2 = (*p2).AT - (*p1).DF;

    if ((*p2).AT > (*p1).DF)
    {
        (*p1).HP = (*p1).HP - dano2;
    }

    else
    {
        (*p1).HP = (*p1).HP - 1;
    }


    if((*p2).HP<0)
        (*p2).HP = 0;

    if((*p1).HP < 0)
        (*p1).HP = 0;

    printf("p1 = %i\n",(*p1).HP);

}

int Batalha(Pokemon *p1, Pokemon *p2){

    int a;
    while((((*p1).HP)>0) && (((*p2).HP)>0))
    {
        if(((*p1).SP) > ((*p2).SP))
        {
            Atacar((p1),(p2));
        }

        else
        {
            Atacar((p2),(p1));
        }
    }
    if ((*p1).HP == 0)
    {
        a = 2;
        printf("vencedor da batalha = %i",a);
        return 2;
    }

    else
    {
        a = 1;
        printf("vencedor da batalha = %i",a);
        return 1;
    }

}

void ExibirTimes(Pokemon p1[6], Pokemon p2[6]){
    int i;
    system("CLS");
    printf("\t\tJogador 1\n");
    printf("        Nome        \tHP\tAT\tDF\tSP\t\n");
    for(i=0; i<6; i++)
    {
        printf("%s\t%i\t%i\t%i\t%i\t\n", p1[i].Nome,p1[i].HP,p1[i].AT,p1[i].DF,p1[i].SP);
    }
    printf("\n\t\tJogador 2\n");


    printf("        Nome        \tHP\tAT\tDF\tSP\t\n");
    for(i=0; i<6; i++)
    {
        printf("%s\t%i\t%i\t%i\t%i\t\n", p2[i].Nome,p2[i].HP,p2[i].AT,p2[i].DF,p2[i].SP);
    }
}
*/


#include <stdio.h>
#include <stdlib.h>
#include "pokemon.h"

void Atacar(Pokemon *p1, Pokemon *p2);
int Batalha(Pokemon *p1, Pokemon *p2);
void ExibirTimes(Pokemon *p1, Pokemon *p2);

int main(){
    int vencedor, i = 0, j = 0;
    Pokemon p1[6], p2[6];
    GerarTimes(p1, p2);
    //ExibirTimes(p1, p2);
    while( (i<6) && (j<6) ){
        vencedor = Batalha(&p1[i],&p2[j]);
        if(vencedor == 1){
            j++;
        }
        else{
            i++;
        }
        ExibirTimes(p1, p2);
        system("PAUSE");
    }

    if(i==6){
        printf("\n\n Jogador 2 Vencedor \n\n");
    }
    else{
        printf("\n\n Jogador 1 Vencedor \n\n");
    }
    return 0;
}

void Atacar(Pokemon *p1, Pokemon *p2){
    int dano;
    dano = (*p1).AT - (*p2).DF;
    if( (*p2).DF < (*p1).AT ){
        (*p2).HP = (*p2).HP - dano;
    }
    else{
        (*p2).HP = (*p2).HP - 1;
    }
    if((*p2).HP < 0){
        (*p2).HP = 0;
    }
}

int Batalha(Pokemon *p1, Pokemon *p2){
    int atual;
    if( (*p1).SP > (*p2).SP ){
        atual = 1;
    }
    else{
        atual = 2;
    }

    while(((*p1).HP>0) && ((*p2).HP>0)){
        if( atual == 1 ){
            Atacar(p1,p2);
            atual = 2;
        }
        else{
            Atacar(p2,p1);
            atual = 1;
        }
    }
    if( (*p1).HP>0 ){
        return 1;
    }
    else{
        return 2;
    }
}

void ExibirTimes(Pokemon p1[6], Pokemon p2[6]){
    int i;
    system("CLS");
    printf("Jogador 1\n\n");
    printf("        Nome        \tHP\tAT\tDF\tSP\t\n");
    for(i=0;i<6;i++){
        printf("%s\t%i\t%i\t%i\t%i\t\n", p1[i].Nome,p1[i].HP,p1[i].AT,p1[i].DF,p1[i].SP);
    }

    printf("\nJogador 2\n\n");
    printf("        Nome        \tHP\tAT\tDF\tSP\t\n");
    for(i=0;i<6;i++){
        printf("%s\t%i\t%i\t%i\t%i\t\n", p2[i].Nome,p2[i].HP,p2[i].AT,p2[i].DF,p2[i].SP);
    }
}


