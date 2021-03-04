#include "grafo.h"
#include "fila.h"  /* Fila para busca em largura*/
#include <math.h>  /* para usar o INFINITY */


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


int GrauDeEntrada (Grafo g, int v)
{
    int i, s = 0;
    for (i=0; i < g.nVertices; i++)
        if (PesoDaAresta (g,i,v) != 0)
            s++;
    return s;
}


int GrauDeSaida (Grafo g, int v)
{
    int i, s = 0;
    for (i=0; i < g.nVertices; i++)
        if (PesoDaAresta (g, v, i) != 0)
            s++;
    return s;
}


int Vertedouro (Grafo g, int v)
{
    return GrauDeEntrada (g, v) == 0;
}


int Sorvedouro (Grafo g, int v)
{
    return GrauDeSaida (g, v) == 0;
}


int Adjacente (Grafo g, int de, int para)
{
    return g.Pesos[para][de] != 0;
}


void Warshall (Grafo g, int w[MAX_VERT][MAX_VERT])
{
    int i, j, k;

    for (i=0; i < g.nVertices; i++)
        for ( j=0; j < g.nVertices; j++)
            w[i][j] = PesoDaAresta (g, i, j) != 0;

    for (i=0; i < g.nVertices; i++)
        for (j=0; j < g.nVertices; j++)
            for (k=0; k < g.nVertices; k++)
                w[i][j] = w[i][j] || (w[i][k] && w[k][j]);
}


int Alcanca (Grafo g, int de, int para)
{
    int w [MAX_VERT][MAX_VERT];
    Warshall (g, w);
    return w[de][para] != 0;
}


float PesoDoPasseio (Grafo g, ListaDeVertices p)
{
    float s = 0;
    int i;
    for (i=0; i<p.nVertices-1; i++)
        if (Adjacente (g, p.vertices[i+1], p.vertices[i]))
            s += PesoDaAresta (g, p.vertices[i], p.vertices[i+1]);
        else
            return -1;
    return s;
}


// *******************************************
//                  Buscas
// *******************************************


void Pre_visita_DFS(Grafo g, int v, int destino, int *achei, ListaDeVertices *caminho)
{
    caminho->vertices[caminho->nVertices] = v;
    caminho->nVertices++;

    *achei = (v == destino);
}

void Pos_visita_DFS(Grafo g, int v, int destino, int nExplorados, ListaDeVertices *caminho)
{
    if ((nExplorados == 0) && v != destino)
        caminho->nVertices--;
}


void Explorar (Grafo g, int v, int destino, int *visitado, ListaDeVertices *caminho, int *achei)
{
    int u;
    int nExplorados = 0;
    visitado[v] = 1;

    Pre_visita_DFS(g, v, destino, achei, caminho);
    //Pre_visita_DFS(parâmetros) //opcional

    for (u=0; u<g.nVertices; u++)
        if (!visitado[u] && Adjacente(g,u,v) && !(*achei))
        {
            Explorar(g, u, destino, visitado, caminho, achei);
            nExplorados++;
        }

    Pos_visita_DFS(g, v, destino, nExplorados, caminho);
    //Pos_visita_DFS(parâmetros) // opcional
}


void DFS(Grafo g, int origem, int destino, ListaDeVertices *caminho)
{
    int v, achei;
    int visitado[g.nVertices];

    caminho->nVertices = 0;
    achei = 0; // se for procurar algo
    for (v=0; v<g.nVertices; v++)
        visitado[v] = 0;

    Explorar(g, origem, destino, visitado, caminho, &achei);

    /* se algum vertice ainda nao foi visitado */
    for (v=0; v<g.nVertices; v++)
        if (!visitado[v] && !achei)
            Explorar(g, v, destino, visitado, caminho, &achei);
}


void Pre_visita_BFD(/*Grafo g*/)
{
}


void Pos_visita_BFD(Grafo g, int v, ListaDeVertices *caminho)
{
    caminho->vertices[caminho->nVertices] = v;
    caminho->nVertices++;
}


void BFS(Grafo g, int origem, int destino, float *dist, ListaDeVertices *caminho)
{
    TFila fila;
    Dados dados;

    int u, v;
    int achei = 0;

    CriarFila(&fila);
    caminho->nVertices = 0;
    for (v=0; v<g.nVertices; v++)
        dist[v] = INFINITY;

    /* Pre_visita_BFD(parâmetros) //opcional */
    dist[origem] = 0;
    dados.valor = origem;
    InserirNaFila(&fila,dados);
    /* Pos_visita_BFD(parâmetros) //opcional */
    Pos_visita_BFD(g, origem, caminho);

    while (!FilaVazia(fila) && !achei)
    {
        /* Pre_visita_BFD(parâmetros) //opcional */
        RetirarDaFila(&fila, &dados);
        v = dados.valor;

        for (u=0; u<g.nVertices; u++)
            if (dist[u]==INFINITY && Adjacente(g, u, v) && !achei)
            {
                dados.valor = u;
                InserirNaFila(&fila, dados);
                /* Pos_visita_BFD(parâmetros) //opcional */
                Pos_visita_BFD(g, u, caminho);
                dist[u] = dist[v] + 1; // ou
                /* dist[u] = dist[v] + PesoDaAresta(g, v, u); */
            }
    }
}

// *******************************************
//               Caminho Mínimo
//            Árvore Geradora Mínima
// *******************************************


void Dijkstra(Grafo g, int origem, int destino, float *dist, int *ant, ListaDeVertices *caminho)
{
    int M[g.nVertices]; // Vertices marcados
    int i, v, aux;
    float novaDist, menor;

    /* Valores iniciais para o algoritmo */
    for (i=0; i<g.nVertices; i++)
    {
        /* Preencha o vetor dos vértices marcdos. Será que é "falso" ou "verdadeiro"? */
        M[i] = 0;
        /* Preencha o vetor das distâncias acumuladas. Use a infinidade positiva. */
        dist[i] = INFINITY;
        /* Preencha o vetor dos vértices antecessores. Use um vértice fictício, por exemplo -1. */
        ant[i] = -1;
    };

    v = origem;
    dist[v] = 0;
    while (v!=destino && v!=-1)
    {
        for (i=0; i<g.nVertices; i++)
            if (PesoDaAresta(g, v, i) != 0 && !M[i])
            {
                novaDist = dist[v] + PesoDaAresta(g, v, i);
                if (novaDist < dist[i])
                {
                    dist[i] = novaDist;
                    ant[i] = v;
                };
            };

        /* defina o vertice v como marcado */
        M[v] = 1;

        /* Procura do próximo vértice */
        menor = INFINITY;
        v = -1;
        for (i=0; i<g.nVertices; i++)
            if (!M[i] && dist[i] < menor)
            {
                menor = dist[i];
                v = i;
            };
    }; /* while */


    /* Preenche o caminho, do vértice final até o de origem */
    caminho->nVertices = 0;
    v = destino;
    while (v!=origem)
    {
        caminho->vertices[caminho->nVertices] = v;
        caminho->nVertices++;
        v = ant[v];
    };
    caminho->vertices[caminho->nVertices] = origem;
    caminho->nVertices++;

    // Inverte o caminho, retornando o passeio na ordem correta
    for (i=0; i<caminho->nVertices / 2; i++)
    {
        aux = caminho->vertices[i];
        caminho->vertices[i] = caminho->vertices[caminho->nVertices - 1 - i];
        caminho->vertices[caminho->nVertices - 1 - i] = aux;
    };
}


void Prim(Grafo g, int origem, int *ant, float *custo)
{
    float dist[g.nVertices];
    int M[g.nVertices]; // Vertices marcados
    int i, v, aux;
    float novaDist, menor;

    /* Valores iniciais para o algoritmo */
    for (i=0; i<g.nVertices; i++)
    {
        /* Preencha o vetor dos vértices marcdos. Será que é "falso" ou "verdadeiro"? */
        M[i] = 0;
        /* Preencha o vetor das distâncias acumuladas. Use a infinidade positiva. */
        dist[i] = INFINITY;
        /* Preencha o vetor dos vértices antecessores. Use um vértice fictício, por exemplo -1. */
        ant[i] = -1;
    };

    v = origem;
    dist[v] = 0;
    while (/*v!=destino &&*/ v!=-1)
    {
        for (i=0; i<g.nVertices; i++)
            if (PesoDaAresta(g, v, i) != 0 && !M[i])
            {
                novaDist = PesoDaAresta(g, v, i);
                if (novaDist < dist[i])
                {
                    dist[i] = novaDist;
                    ant[i] = v;
                };
            };

        /* defina o vertice v como marcado */
        M[v] = 1;

        /* Procura do próximo vértice */
        menor = INFINITY;
        v = -1;
        for (i=0; i<g.nVertices; i++)
            if (!M[i] && dist[i] < menor)
            {
                menor = dist[i];
                v = i;
            };
    }; /* while */

    /* calcula o custo total */
    *custo = 0;
    for (i=0; i<g.nVertices; i++)
        if (dist[i] != INFINITY)  // deseconsidera vértices desconexos
          *custo += dist[i];
}

