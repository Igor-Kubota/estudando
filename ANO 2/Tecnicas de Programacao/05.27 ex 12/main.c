
#include <stdio.h>
#include <string.h>
#define MAX 255
#include <stdlib.h>

void LerLinha(char linha[], FILE *arq){
    fgets(linha, MAX, arq);
    if (linha[strlen(linha)-1] == '\n')
        linha[strlen(linha)-1] = '\0';
}

int main(){
    char linha[MAX];
    char *c;
    int total;

    FILE *arquivo;



    arquivo = fopen("teste1.txt","r");

    if (arquivo == NULL){
        printf("Não consegui abrir o arquivo.");
        exit(EXIT_FAILURE);
    }


    printf("digite o caracter a ser procurado: ");
    scanf("%c", &c);



    LerLinha(linha, arquivo);
    printf("%s\n", linha);

    while (c == strstr(linha ,c)!= NULL)
        total++;

        fclose(arquivo);
        total++;

    printf("foram digitado %i vezes.",total);

    return 0;
}

/*
#include <stdio.h>
#include <string.h>

int main()
 {
    char str[1001];
    char c;
    int i;
    int total;
    FILE *arq;

    arq = fopen("Teste1.txt","r");
   //printf("Escreva a frase: ");
    //fgets(str, sizeof(str), stdin);
     if (arq == NULL)  // Se houve erro na abertura
  {
     printf("Problemas na abertura do arquivo\n");

  }


    printf("digite o caracter a ser procurado: ");
    scanf("%c", &c);
    total = fscanf(arq, "%c", &c );

    //*for (i = 0; i < strlen(str) ; i++) {
    //    if (c == str[i])
    //        total++;
    //}

    //printf("o Caracter  '%c' aparece %i vezes ", c, total);
    //


    printf("foram digitado %i vezes.",total);
    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

/* Function declarations
int countOccurrences(FILE *fptr, const char *word);


int main()
{
    FILE *fptr;


    char word[50];

    int wCount;

    /* Input file path */


    /* Input word to search in file
    printf("Enter word to search in file: ");
    scanf("%s", word);

    /* Try to open file
    fptr = fopen("teste1.txt", "r");

    /* Exit if file not opened successfully
    if (fptr == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check you have read/write previleges.\n");

        exit(EXIT_FAILURE);
    }

    // Call function to count all occurrence of word
    wCount = countOccurrences(fptr, word);

    printf("'%s' is found %d times in file.", word, wCount);


    // Close file
    fclose(fptr);

    return 0;
}


/**
 * Returns total occurrences of a word in given file.

int countOccurrences(FILE *fptr, const char *word)
{
    char str[BUFFER_SIZE];
    char *pos;

    int index, count;

    count = 0;

    // Read line from file till end of file.
    while ((fgets(str, BUFFER_SIZE, fptr)) != NULL)
    {
        index = 0;

        // Find next occurrence of word in str
        while ((pos = strstr(str + index, word)) != NULL)
        {
            // Index of word in str is
            // Memory address of pos - memory
            // address of str.
            index = (pos - str) + 1;

            count++;
        }
    }

    return count;
}
*/
