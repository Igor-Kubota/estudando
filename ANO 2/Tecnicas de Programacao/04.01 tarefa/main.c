#include <stdio.h>
#include <stdlib.h>
#define N 2



// protótipos

void MultiplicarMatriz(int[][N], int[][N], int[][N]);

void MultiplicarMatrizVetor(int[][N], int[], int[]);

void CopiarMatriz(int [][N], int [][N]);



// programa principal

int main()
{

    int i, n;

    // crie as matrizes M, Aux e R. Preencha os valores da matriz M

    int Aux[N][N];
    int R[N][N];
    int M[N][N];

    M[0][0] = 0;
    M[0][1] = 1;
    M[1][0] = 1;
    M[1][1] = 1;
    R[0][0] = 0;
    R[0][1] = 0;
    R[1][0] = 0;
    R[1][1] = 0;




    // crie os vetores v e r. Preencha os valores do vetor v

    int r[N], v[N];
    v[0] = 1;
    v[1] = 0;





    printf("Digite o numero de Fibonacci desejado: ");

    scanf("%i", &n);



    // calcular R = M^n
    CopiarMatriz(Aux,M);
    for(i=0; i<n; i++)
    {
        MultiplicarMatriz(M,Aux,R);
        CopiarMatriz(Aux,R);

    }





    // calcular r = R * v e exibir seu primeiro valor

    MultiplicarMatrizVetor(R,v,r);
    printf("F(%i) = %i \n",n,r[0]);







    return 0;

}



// as sub-rotinas

void MultiplicarMatriz(int A[][N], int B[][N], int Resp[][N])
{

    int i,j,k;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {

            Resp[i][j] = 0;
            for(k=0; k<N; k++)
            {
                Resp[i][j] += A[i][k] * B[k][j];
            }
        }
    }




}



void MultiplicarMatrizVetor(int M[][N], int v[], int resp[])
{
    int i, k ;
    for(i=0; i<N; i++)
    {
        resp[i] = 0;
        for(k=0; k<N; k++)
        {
            resp[i] += M[i][k] * v[k];

        }


    }


}









void CopiarMatriz(int recebe[][N], int envia[][N])
{
    int i;
    int j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            recebe[i][j] = envia[i][j];



        }
    }
}




