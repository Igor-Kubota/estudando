%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%  0 -  Proposta de trabalho - parte 2
%%
%%  a. Cada aluno determina as frequências fo, f1 e f2 (3x) - cada vogal 9 valores - 45 valores. //
%%  b. Base de conhecimento Número de alunos x 45.//
%%  c. Histrograma de cada vogal - média e o desvio padrão de cada frequência para cada vogal. //

%%  d. Elimnar valores fora de contexto e verificar diferenças da base//

%%  e. Gravar cinco vogais que não serão usadas na base. Serão usadas somente para teste.//

%%  Vogal	f0	  f1	  f2

%%     A	140	  650	  1040
%%
%%     E	100	  550	  1810
%%
%%     I	310	  2280  3020
%%
%%     O	147	  535	  909
%%
%%     U	119	  736	  2484

%%
%%  f. 1 - acertou e 0 - errou --> a,e,i,o,u --> 0 1 1 1  //

%%  Apresentou Erro somente na Vogal A, em que obteve-se O.

%%  g. Qualidade do sistema de aprendizado para cada vogal
%%
%%  Entrega 15/04 até 23:59 - individual

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% 1 - Preparação do código 
%% 
%% Boas práticas: limpeza de variáveis; variáveis globais
%% Constantes; carregar bibliotecas;...
%%
%%% Limpeza

clc;          % limpa visual da tela de comandos
close all;    % limpa as figuras
clear all;    % limpa as variáveis

pkg load io;
pkg load signal;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% 2 - Problema
%%
%% 
%% sinal g(k) - sinal amostrado

%%% sinal de referência - artificial
%%% com senoides
%%% sinal a ser trabalhado - gk

%%[gk,fs] = audioread('U3.wav');          % leitura de um sinal real - volga /a/.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%  3 - Pré - processamento do sinal
%% 
%%  Ambiente de cálculo integral e simbólico
%%  
%%  X[n] = 1/N somatoria_{k=0}^{N-1} g(k) exp(-j*n*k*2*pi/N)
%%
%%

N          = length(gk);               % número de pontos de g(k)
Ts         = 1/fs;                     % Taxa de amostragem
Duracao    = N*Ts;                     % duração do sinal g(k)
ws         = 2*pi*fs;                  % frequencia angular
tempo      = linspace(0,Duracao,N);    % vetor tempo computacional 
fmax       = fs/2;                     % frequência máxima
frequencia = linspace(-fmax,fmax,N);   % frequências de interesse                


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% 4 -  Cáclculo de X(n)
%%  
%%  X[n] = 1/N somatoria_{k=0}^{N-1} g(k) exp(-j*n*k*2*pi/N)
%%
%%

%%% segunda estrutura: utilizando algebra linear

tic;                                % inicia um contator de tempo

Matriz_J      = (exp(-j*2*pi/N))*ones(N,N);   % cria a matriz de coeficientes

Matriz_nk     = [0:1:N-1]'*[0:1:N-1];         % matriz dos expoentes nk

WN            = Matriz_J.^Matriz_nk;          % matriz de Fourier - constante

Xn            = WN*gk;                       % Série discreeta de Fourier

toc;                                % determina o tempo decorrido

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%  6 -  Visualização
%%
%%





figure(2)

%%% fftshift rotaciona o vetor 0 --> 2*pi ; -pi --> +pi

plot(frequencia,fftshift(log10(abs(Xn))),'k-','linewidth',2)     % configura plot(x,y, cor azul e linha cheia)
xlabel('Frequência em Hz')                      % tempo em segundos
ylabel('Amplitude')                             % amplitude em volts
title('Espectro de amplitude')                  % título
grid




%%    a1:	f0 = 108.6
%%  	    f1 = 660.8
%%  	    f2 = 1301.6


%%    a2:	f0 = 112.1
%%  	    f1 = 782.2
%%	      f2 = 1337.5


%%    a3:	f0 = 109.8
%%	      f1 = 540.2
%%	      f2 = 1329.9
















