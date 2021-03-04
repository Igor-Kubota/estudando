#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//201, 205, 205, 205, 205, 205, 187
//186, 32, 176, 177, 178, 219, 186
//200, 205, 205, 205, 205, 205, 188
// ╔═════╗
// ║ ░▒▓█║
// ╚═════╝




// Cria a estrutura de dados "Ponto"
typedef struct{

    int L, C, cor;

} Ponto;



// Exibe a imagem

void Exibir(int M[80][80], int NC, int NL){

    int C, L;
    int cores[] = {32, 176, 177, 178, 219, 219};

    for (C = -1; C <= NC; C++)

        printf("%c", (C==-1)?201:(C==NC)?187:205);

    printf("\n");

    for (L = 0; L < NL; L++){

        for (C = -1; C <= NC; C++)

            printf("%c", (C==-1)?186:(C==NC)?186:cores[M[C][L]]);

        printf("\n");

    }

    for (C = -1; C <= NC; C++)

        printf("%c", (C==-1)?200:(C==NC)?188:205);

    printf("\n");

}

// separa as informações lidas em uma linha do arquivo
// em uma estrutura de dados com 3 campos utilizando o
// caractere ';' como separador
void SepararDados(char linha[], Ponto*px){

    int i, j, c;
    char temp[15];
    int valores[3];
    c = 0;
    for (i = 0; i< 3; i++){

        j = 0;
        while (linha[c] != ';' && c < strlen(linha)){

            temp[j] = linha[c];
            c++;
            j++;

        }
        c++; /* pular o separador */
        temp[j] = '\0';
        valores[i] = atoi(temp);

    }

// retorna, respectivamente, posição da coluna, a posição
// da linha e a cor uma estrutura passada por referência
    (*px).C = valores[0];
    (*px).L = valores[1];
    (*px).cor = valores[2];

}


int main()
{

    int n;

    char linha[15]; // uma linha do arquivo
    Ponto px; // um pixel
    int Matriz[80][80]; // a matriz que será preenchida
    int NC, NL; // número de coluna e de linhas da imagem

// manipulação básica do arquivo
    FILE *arq;
    arq = fopen("imagem.txt", "r"); // abre o arquivo para leitura
    if (arq == NULL){

        printf("Não consegui abrir o arquivo.");
        exit(EXIT_FAILURE);

    }

// CABEÇALHO DO ARQUIVO
    fgets(linha,15,arq); // faz a leitura do cabeçalho
    SepararDados(linha,&px); // separa as informações da linha em uma estrutura de dados
    NC = px.C;  // número total de colunas
    NL = px.L;  // número total de linhas

// PONTOS DO ARQUIVO
    while(!feof(arq)){ // verifica o arquivo até o final


        fgets(linha,15,arq); // faz a leitura de uma linha do arquivo
        SepararDados(linha,&px);
// separa as informações da linha em uma estrutura de dados


        Matriz[px.C][px.L] = px.cor/51; // armazena a cor (dividida por 51) no elemento da matriz, dado pela coluna e linha do ponto px lido

    }

    Exibir(Matriz, NC, NL);  // Exibe a Matriz, informando o número total de colunas e linhas, respectivamente

    fclose(arq);
    printf("Digite o numero de discos: ");
    scanf("%i", &n);


// fecha o arquivo
    return 0;

}
