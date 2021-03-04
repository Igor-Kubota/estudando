//NOME: IGOR EIKI FERREIRA KUBOTA
//RA:   19.02466-5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 80
#define N 10

typedef struct{

    char nome[MAX];
    int idade;
} Pessoa;



void LerString(char []);
void preencherVetor(Pessoa*, int);
void exibirVetor(Pessoa*, int);
int BuscaBinariaRecursiva(Pessoa[], Pessoa*, int, int);
void quicksort(Pessoa*, int, int);



int main(){


    int n;
    Pessoa listaDePessoas[N], perdido;

    printf("Digite o numero de pessoas: ");
    scanf("%i", &n);
    preencherVetor(listaDePessoas, n);
    quicksort(listaDePessoas, 0, n-1);
    exibirVetor(listaDePessoas, n);

    printf("Digite o nome da pessoa que deseja procurar: ");
    LerString(perdido.nome);

    if (BuscaBinariaRecursiva(listaDePessoas, &perdido, 0, n-1) != -1 )
        printf("Idade: %i\n", perdido.idade);

    else
        printf("Pessoa nao cadastrada.\n");

    return 0;
}

int BuscaBinariaRecursiva(Pessoa v[], Pessoa *p, int L, int H){


    int pos = -1;
    int M;
    M =(L+H)/2;

    if (((strcmp((*p).nome,(v[M]).nome)) == 0 )){
            pos = M;
            *p = v[M];
        }
    else if(L<H)
        if((strcmp((*p).nome,(v[M]).nome))<0)
            pos=BuscaBinariaRecursiva(v,p,L,M-1);

        if((strcmp((*p).nome,(v[M]).nome))>0)
            pos=BuscaBinariaRecursiva(v,p,M+1,H);

    return pos;
}

void preencherVetor(Pessoa *v, int n){


    int i;
    for (i = 0; i < n; i++){

        printf("Digite o nome: ");
        LerString(v[i].nome);
        printf("Digite a idade: ");
        scanf("%i", &v[i].idade);
    }
}

void exibirVetor(Pessoa *v, int n){


    int i;
    printf("\n\nNome\tIdade\n");

    for (i = 0; i < n; i++)
        printf("%s\t%i\n", v[i].nome, v[i].idade);

    printf("\n");
}

void trocar(Pessoa *x, Pessoa *y){

    Pessoa aux=*x;
    *x=*y;
    *y=aux;

}

int particionar(Pessoa *v, int l, int r, int p){


    int i, j;
    Pessoa valor_pivo = v[p];
    trocar(&v[p], &v[r]);
    j = l;

    for (i = l; i <= r - 1; i++)
    {
        if (strcmp(v[i].nome,valor_pivo.nome)<0)
        {
            trocar(&v[i], &v[j]);
            j++;
        }
    }
    trocar(&v[j], &v[r]);
    return j;
}

void quicksort(Pessoa *v, int l, int r){


    int pivo, novoPivo;

    if (l < r){
        pivo = (l + r) / 2;
        novoPivo = particionar(v, l, r, pivo);
        quicksort(v, l, novoPivo - 1);
        quicksort(v, novoPivo + 1, r);
    }
}


void LerString(char s[MAX]){


    setbuf(stdin, 0);
    fgets(s, MAX, stdin);
    if (s[strlen(s)-1] == '\n')
        s[strlen(s)-1] = '\0';
}
