#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#define MAX 20
#include <string.h>
// Guilherme Cury Galli 19.00374-9
// Igor Eiki Ferreira Kubota 19.02466-5

void LerString(char s[MAX]){
    int t;
    char c;

    setbuf(stdin, 0);
    fgets(s,MAX,stdin);
    t = strlen(s);
    if (s[t-1] == '\n')
        s[t-1] = '\0';
}

int main()
{
    char op;
    Dados dados;
    TLista *lista;
    lista = CriarLista();
    do{
        printf("valor: ");
        scanf("%f",&dados.valor);
        printf("texto: ");
        LerString(dados.texto);
        InserirEmOrdem(lista, dados);
        printf("Mais itens (S/N)? ");
        scanf("%c", &op);
    }

    while(toupper(op) != 'N');
        ExibirLista(lista);
        lista = DestruirLista(lista);
        return 0;
}
