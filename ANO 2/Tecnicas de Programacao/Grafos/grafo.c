// 19.00374-9 Guilherme Cury Galli
// 19.02466-5 Igor Eiki
// 19.01266-7 Gustavo Zamboni do Carmo

#include "grafo.h"

void CriarGrafo (Grafo *g, int n, int dig)
{
    int i, j;
    g->nVertices = n;
    g->digrafo = dig;
    for (i=0; i < g->nVertices; i++)
        for (j=0; j < g->nVertices; j++)
            g->Pesos[i][j] = 0;
}


void InserirAresta (Grafo *g, int de, int para, float peso)
{
    g->Pesos[de][para] = peso;
    if (!g->digrafo)
        g->Pesos[para][de] = peso;
}


void RemoverAresta (Grafo *g, int de, int para)
{
    g->Pesos[de][para] = 0;
    if (!g->digrafo)
        g->Pesos[para][de] = 0;
}


float PesoDaAresta (Grafo g, int de, int para)
{
    return g.Pesos[de][para];
}

int GrauDeEntrada (Grafo g, int v){
    int i;
    int GE = 0;
    for(i=0;i<g.nVertices;i++){
        if(g.Pesos[i][v]> 0)
            GE++;

    }
    return GE;



}
int GrauDeSaida (Grafo g, int v){
    int i;
    int GS = 0;
    for(i=0;i<g.nVertices;i++){
        if(g.Pesos[v][i]> 0)
            GS++;

    }
    return GS;


}
int Vertedouro (Grafo g, int v){
    int GE;
    GE = GrauDeEntrada(g,v);

    return GE==0;
}

int Sorvedouro (Grafo g, int v){
    int GS;
    GS = GrauDeSaida(g,v);

    return GS==0;
}
int Adjacente (Grafo g, int de, int para){
    if(g.digrafo==1)
        return PesoDaAresta(g,para,de)>0;
    else
        return ((PesoDaAresta(g,de,para)>0)&&(PesoDaAresta(g,para,de)>0));


}
void Warshall (Grafo g, int w[MAX_VERT][MAX_VERT]){

    int i,j,k;
    for(i=0;i<g.nVertices;i++){
        for(j=0;j<g.nVertices;j++){
            w[i][j]=PesoDaAresta(g,i,j) !=0;
        }
    }
    for(k=0;k<g.nVertices;k++){
       for(i=0;i<g.nVertices;i++){
        for(j=0;j<g.nVertices;j++){
                    w[i][j] = w[i][j] || (w[i][k] && w[k][j]);
            }
       }
    }

}




int Alcanca (Grafo g, int de, int para){
    int w[MAX_VERT][MAX_VERT];
    Warshall(g,w);


    return w[de][para]!= 0;



}

float PesoDoPasseio (Grafo g, ListaDeVertices p){
    float x=0;
    int i;
    for(i=0;i<(p.nVertices-1);i++)
        x+=g.Pesos[p.vertices[i]][p.vertices[i+1]];

    return x;

}


