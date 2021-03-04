#include <stdio.h>
#include <stdlib.h>
#define MAX 255


void LerLinha(char linha[], FILE *arq){
    fgets(linha, MAX, arq);
    if (linha[strlen(linha)-1] == '\n')
        linha[strlen(linha)-1] = '\0';
}

int main(){
    FILE *arquivo;
    char linha[MAX];
    int i = 0;
    arquivo = fopen("teste2.csv", "w");

    /*Escrita direta no arquivo*/
    fprintf(arquivo,"%s;%s;%s;%s;%s\n", "x1", "x2", "x3", "x4", "x5");

    /*Escrita indireta no arquivo*/
    while(i < 100){
        sprintf(linha, "%i;%i;%i;%i;%i\n", i, i*2, i*3, i*4, i*5);
        fprintf(arquivo, "%s", linha);
        i++;
    }

    fclose(arquivo);

    /* ***************************  leitura ********************* */

    arquivo = fopen("teste2.csv", "r");

    if (arquivo == NULL){
        printf("Não consegui abrir o arquivo.");
        exit(EXIT_FAILURE);
    }

    /* Realiza a leitura do cabeçalho */
    LerLinha(linha, arquivo);
    printf("%s\n", linha);

    /*Continua a leitura dos dados até o fim*/
    while(!feof(arquivo)){
        LerLinha(linha, arquivo);
        printf("%s\n", linha);
    }

    fclose(arquivo);

    return 0;
}
