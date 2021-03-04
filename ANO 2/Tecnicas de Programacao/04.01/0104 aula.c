#include <stdio.h>
#include <stdlib.h>
#define N 100

void LerMatriz(float [][N], char, int);
void MultiplicarMatriz(float [][N], float [][N], float [][N], int);
void ExibirMatriz(float [][N], char, int);

int main(){
    int n;
    float A[N][N], B[N][N], R[N][N];

    printf("Digite a ordem da matriz: ");
    scanf("%i", &n);

    LerMatriz(A,'A',n);
    LerMatriz(B,'B',n);
    MultiplicarMatriz(A,B,R,n);

    ExibirMatriz(A,'A',n);
    ExibirMatriz(B,'B',n);
    ExibirMatriz(R,'R',n);

    return 0;
}

void LerMatriz(float mat[][N], char nome, int n){
    int i,j;
    printf("\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("Digite o elemento %c[%i][%i]: ",nome,i,j);
            scanf("%f",&mat[i][j]);
        }
    }
}

void ExibirMatriz(float mat[][N], char nome, int n){
    int i,j;
    printf("\n");
    printf("Matriz %c: \n",nome);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%.2f ",mat[i][j]);
        }
        printf("\n");
    }
}

void MultiplicarMatriz(float A[][N], float B[][N], float R[][N], int n){
    int i,j,k;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){

            R[i][j] = 0;
            for(k=0;k<n;k++){
                R[i][j] += A[i][k] * B[k][j];
            }
        }
    }

}







