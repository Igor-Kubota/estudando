#include <stdio.h>
#include <stdlib.h>
// 19.00331-5 Bruno Vilardi Bueno
// 19.01490-2 Conrado Pupo Azzalin
// 19.02466-5 Igor Eiki ferreira kubota

// RA Nome
// RA Nome
#include <math.h>
#include <string.h>

#define MAX 255
#define Ro 6372795.477598

// **************************************
//    Criar a estrutura de dados GPS
// **************************************
typedef struct{
    float lat;
    float lon;
    float alt;
    int temp;
} GPS;
// **************************************


// **************************************
//        Protótipos das funções
// **************************************
void LerLinha(char[], FILE*);
void Trocar(char[], char, char);
void SepararDados(char[], int, char, GPS*);
float CalcularDistancia(GPS, GPS);
float GrauRad(float);
// **************************************


int main(){
    // *******************************************
    //   declaração das variáveis
    FILE *arquivo_e, *arquivo_s;
    char linha[255], linha_pri[255], linha_resp[255];
    int i = 2;
    float dist, vel, dist_total;
    GPS gps_ant, gps_atu;
    // *******************************************
    //    abertura do arquivo de entrada

    arquivo_e = fopen("rio_do_ouro.csv", "r");

    // *******************************************
    //    abertura do arquivo de saida
    arquivo_s = fopen("resposta.csv", "w");

    // *******************************************
    //    Ler o cabeçalho do arquivo
    LerLinha(linha, arquivo_e);
    printf("%s\n", linha);
    sprintf(linha_resp, "%s,%s,%s,%s,%s,%s\n", "lat", "lon", "alt", "temp", "dist", "vel");
    fprintf(arquivo_s, linha_resp);

    // *******************************************
    //    Ler o primeiro dado do arquivo
    //    e armazenar como um "ponto anterior"
    LerLinha(linha_pri, arquivo_e);
    Trocar(linha_pri, ',', '.');
    SepararDados(linha_pri, 4,';', &gps_ant);
    printf("%s\n\n\n", linha_pri);
    // *******************************************
    //    Ler os demais dados do arquivo

    while (i<2040){
        //Ler uma linha e separar os dados do ponto

        LerLinha(linha, arquivo_e);
        Trocar(linha, ',', '.');
        SepararDados(linha, 4, ';', &gps_atu);
        // *******************************************
        //   Se o "tempo atual" for igual ao "tempo anterior"
        //   OU
        //   se todas as coordenadas do "ponto atual" forem
        //    iguais as do "ponto anterior"
        //   O PONTO DEVE SER IGNORADO
        // *****************************************************

        if (!( (gps_ant.temp == gps_atu.temp) || ( (gps_ant.lat==gps_atu.lat) && (gps_ant.lon==gps_atu.lon) ) )) {
            // **********************************************************************
            //  calcular a distância entre o "ponto atual" e o "ponto antrior" em m,
            //  calcular o somatório da distância total em m,
            //  calcular a velocidade instantânea em km/s
            //  exibir o que foi processado
            //  acrescantar ao novo arquivo as informações lidas e a velocidade
            // **********************************************************************
            dist = CalcularDistancia(gps_ant, gps_atu);
            dist_total = dist_total + dist;
            vel = 3.6 * dist/(gps_atu.temp - gps_ant.temp);
            printf("\ndistancia: %f \nvelocidade: %f\n", dist, vel);
            sprintf(linha_resp, "%f,%f,%f,%i,%f,%f\n", gps_atu.lat,gps_atu.lon,gps_atu.alt,gps_ant.temp,dist,vel);
            Trocar(linha_resp, ',', ';');
            Trocar(linha_resp, '.', ',');
            fprintf(arquivo_s, linha_resp);

            // *******************************************

        }  // fim do if
        // *******************************************



        // *******************************************
        //    Atualizar o "ponto anterior"
        // *******************************************

        gps_ant.alt = gps_atu.alt;
        gps_ant.lat = gps_atu.lat;
        gps_ant.lon = gps_atu.lon;
        gps_ant.temp = gps_atu.temp;




        // *******************************************
        i++;
    } // fim do while


    // *******************************************
    //    exibir o total percorrido
    // *******************************************

        printf("\n\ndistancia total: %fkm", dist_total);

    // *******************************************





    // *******************************************
    //    Fechar os arquivos
    fclose(arquivo_e);
    fclose(arquivo_s);
    // *******************************************


    // *******************************************

    return 0;
}


// **************************************
//       Ler uma linha do arquivo
// **************************************
void LerLinha(char linha[], FILE *arq)
{
    fgets(linha,MAX,arq);
    if (linha[strlen(linha)-1] == '\n')
        linha[strlen(linha)-1] = '\0';
}
// **************************************



// **************************************
//  Trocar o caractere antigo pelo novo
// **************************************
void Trocar(char linha[], char antigo, char novo)
{
    int i;
    for (i = 0; i < strlen(linha); i++)
        if (linha[i] == antigo)
            linha[i] = novo;
}
// **************************************



// ********************************************
//  Divide uma string pelo caractere separador
//  nos campos da estrutura de dados GPS
// ********************************************
void SepararDados(char linha[], int quantidade, char separador, GPS *valores){
    int i, j, c;
    char temp[80];
    char valorestxt[4][80];  /* GPS tem 4 campos*/
    c = 0;
    for (i = 0; i< quantidade; i++){
        j = 0;
        while (linha[c] != separador && c < strlen(linha))
        {
            temp[j] = linha[c];
            c++;
            j++;
        }
        c++; /* pular o separador */
        temp[j] = '\0';
        strcpy(valorestxt[i],temp);
    }

    // **************************************************
    //  faça conversão das 4 strings do vetor valorestxt
    //  para os 3 campos float e 1 int da estrutura GPS
    // **************************************************
    /*for (int k=0; k<quantidade; k++){
        printf("valor[%i]: %s\n", k, valorestxt[k]);
    }*/

    (*valores).lat = atof(valorestxt[0]);
    (*valores).lon = atof(valorestxt[1]);
    (*valores).alt = atof(valorestxt[2]);
    (*valores).temp = atoi(valorestxt[3]);


    // ****************************************************
}
// **************************************

float GrauRad( float ang){

    return ang * M_PI/180;
}



// *******************************************
//  Retorna a distância entre os pontos A e B
// *******************************************

float CalcularDistancia(GPS A, GPS B){
    float dh, dv;
    float Lata = GrauRad(A.lat);
    float Latb = GrauRad(B.lat);
    float Lona = GrauRad(A.lon);
    float Lonb = GrauRad(B.lon);
    float Alta = GrauRad(A.alt);
    float Altb = GrauRad(B.alt);


    dh = Ro * acos( sin(Lata)*sin(Latb) + cos(Lata)*cos(Latb)*cos(Lona - Lonb) );
    dv = Altb - Alta;

    return sqrt( pow(dh, 2) + pow(dv, 2) );



}
// **************************************
