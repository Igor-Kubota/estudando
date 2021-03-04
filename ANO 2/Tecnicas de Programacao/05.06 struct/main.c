#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#include <string.h>

typedef struct{
    int quantidade;
    char titulo[MAX];
    char genero[MAX];

} livro;

void lerstring(char s[]){
    setbuf(stdin,0);
    fgets(s, MAX, stdin);
    if (s[strlen(s)-1]=='\n')
        s[strlen(s)-1] = '\0';
}

void Trocar(livro v[], int p){
    livro aux;
    aux = v[p];
    v[p] = v[p+1];
    v[p+1] = aux;

}

void Ordenar(livro v[], int n){
    int i, j;
    for(i=n-1;i>=1;i--)
        for(j=0;j<=i-1;j++)
            if(strcmpi(v[j].titulo,v[j+1].titulo) > 0)
                Trocar(v,j);

}




int main(){
    int i, n;
    livro livros[MAX];

    printf("digite o numero de livros a serem cadastrados: ");
    scanf("%i", &n);


    for(i=0; i<n; i++){
        printf("digite o titulo do livro[%i] ", i+1);
        lerstring(livros[i].titulo);
        printf("digite a quantidade[%i] ", i+1);
        scanf("%i",&livros[i].quantidade);
        printf("digite o genero do livro[%i] ", i+1);
        lerstring(livros[i].genero);
    }

    Ordenar(livros,n);

    printf("%15s %15s %15s \n","Titulo","Qntd","Genero");
    for(i=0; i<n; i++)
        printf("%15s %15i %15s \n",livros[i].titulo,livros[i].quantidade, livros[i].genero);


    return 0;
}
