// 19.00828-7 Raphael Marchetti Calciolari
// 19.01518-6 GUILHERME TORRES DE SOUZA
// 19.02466-5 IGOR EIKI FERREIRA KUBOTA


#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"

int main()
{

    BomDia();

    printf("\n\nN_CAIXAS: %i\n\n", N_CAIXAS);

    TFila Fila[N_CAIXAS]; // Filas de cada caixa
    int frenteDeCaixa[N_CAIXAS]; // Clientes na frente dos caixas

    for (int i = 0; i < N_CAIXAS; i++ )
    {
        CriarFila(&Fila[i]);
        frenteDeCaixa[i] = 0;
    }




    for (int hora = 8; hora < 23; hora ++)
    {
        for (int minuto = 0; minuto <= 59; minuto ++)
        {

            AtualizarClientes(hora, minuto);


            while (ClientesSemFila() > 0)
            {


                int filascheias = 0;

                for (int i = 0; i<N_CAIXAS; i++) // verifica se todas as filas estao cheias
                {

                    if (FilaCheia(Fila[i]) == 1)
                        filascheias++;


                }


                if ( !(filascheias == N_CAIXAS) ) // só adiciona o cliente se houver pelo menos 1 fila nao cheia
                {


                    Dados cliente;

                    cliente.valor = (float) ProximoCliente(); // recebe os itens do cliente

                    //-------------------------------------------- Identifica a fila com menos gente
                    int filaMenor = 0;
                    int contador = 0;
                    while (contador <= N_CAIXAS){

                        if (QuantidadeNaFila(Fila[contador]) < QuantidadeNaFila(Fila[filaMenor])){
                            filaMenor = contador;
                        }
                        contador ++;

                    }
                    //--------------------------------------------

                    if ((QuantidadeNaFila(Fila[filaMenor]) < 10) &&(filaMenor < N_CAIXAS)){
                        InserirNaFila(&Fila[filaMenor], cliente); // adiciona o cliente na fila com menos gente
                    }
                }
                else
                    break;

            }

            for (int i = 0; i<N_CAIXAS; i++ ) // para cada caixa
            {




                if (frenteDeCaixa[i] <= 0) // verifica se tem alguem sendo atendido p chamar prox cliente
                {

                    if (FilaVazia(Fila[i]) == 0) //verifica se alguem precisa passar na fila
                    {
                        Dados clienteatendido; // cliente

                        RetirarDaFila(&Fila[i], &clienteatendido); // atende o cliente e pega o seus produtos

                        frenteDeCaixa[i] = (int) clienteatendido.valor; // atualiza quem vai ser atendido

                    }


                }

                else //atende a pessoa que ja estava na frente
                {
                    frenteDeCaixa[i] -= 8;
                    if(frenteDeCaixa[i] < 0)
                        frenteDeCaixa[i] = 0;
                }



            }

            ExibirFilas(hora, minuto, Fila, frenteDeCaixa);


        }

    }

    printf("\n\nDia finalizado!\n\n");

    return 0;
}
