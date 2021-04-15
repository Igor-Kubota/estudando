%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%    Igor Eiki Ferreira Kubota 
%%    RA: 19.02466-5

%%  0 -  Proposta de trabalho - parte 2
%%
%%  a. Cada aluno determina as frequ�ncias fo, f1 e f2 (3x) - cada vogal 9 valores - 45 valores. //
%%      Foi utilizado para preencher a Base de Conhecimentos.

%%  b. Base de conhecimento N�mero de alunos x 45.//
%%      Foi utilizada a vers�o disponivel no dia 13/04, sendo assim os dados
%%      posteriores a essa data n�o foram utilizados.

%%  c. Histrograma de cada vogal - m�dia e o desvio padr�o de cada frequ�ncia para cada vogal. //
%%      Cada Vogal possui o seu arquivo na pasta "AnaliseVogais", em que cada arquivo.m 
%%      plota os histogramas de f0,f1 e f2; um Boxplot das frequencias, e o scatter
%%      das frequencias com os parametros f1 e f2.


%%  d. Elimnar valores fora de contexto e verificar diferen�as da base//
%%      Os Outliers foram eliminados observando o Boxplot e o scatter,
%%      sendo assim removidas manualmente da Base de Dados atraves do Excel.

%%  e. Gravar cinco vogais que n�o ser�o usadas na base. Ser�o usadas somente para teste.//
%%      As vogais foram gravadas e analisadas para a obten��o de f0, f1 e f1.


%%        Vogal	f0	  f1	  f2

%%         A	  140	  650	  1040
%%
%%         E	  100	  550	  1810
%%
%%         I	  310	  2280  3020
%%
%%         O	  147	  535	  909
%%
%%         U  	119	  736	  2484

%%  f. 1 - acertou e 0 - errou --> a,e,i,o,u --> 0 1 1 1  //
%%      Apresentou Erro somente na Vogal A, em que obteve-se a vogal O,
%%      Devido � similidaridade dos dados no banco de dados.

%%  g. Qualidade do sistema de aprendizado para cada vogal
%%      Obteve-se em m�dia uma taxa de acerto de 80%, uma vez que somente
%%      encontrou-se erro em rela��o � Vogal A testada. Com um refinamento
%%      dos dados presentes na BD, talvez seja possivel melhorar o 
%%      resultado obtido.

%%
%%  Entrega 15/04 at� 23:59 - individual

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% 1 - Prepara��o do c�digo 
%% 
%% Boas pr�ticas: limpeza de vari�veis; vari�veis globais
%% Constantes; carregar bibliotecas;...
%%
%%% Limpeza

clc;          % limpa visual da tela de comandos
close all;    % limpa as figuras
clear all;    % limpa as vari�veis

pkg load io;
pkg load signal;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% 2 - Problema
%%
%% 
%% sinal g(k) - sinal amostrado

%%% sinal de refer�ncia - artificial
%%% com senoides
%%% sinal a ser trabalhado - gk

%%[gk,fs] = audioread('U3.wav');          % leitura de um sinal real - vogal /a/.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%  3 - Pr� - processamento do sinal
%% 
%%  Ambiente de c�lculo integral e simb�lico
%%  
%%  X[n] = 1/N somatoria_{k=0}^{N-1} g(k) exp(-j*n*k*2*pi/N)
%%
%%

N          = length(gk);               % n�mero de pontos de g(k)
Ts         = 1/fs;                     % Taxa de amostragem
Duracao    = N*Ts;                     % dura��o do sinal g(k)
ws         = 2*pi*fs;                  % frequencia angular
tempo      = linspace(0,Duracao,N);    % vetor tempo computacional 
fmax       = fs/2;                     % frequ�ncia m�xima
frequencia = linspace(-fmax,fmax,N);   % frequ�ncias de interesse                


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% 4 -  C�clculo de X(n)
%%  
%%  X[n] = 1/N somatoria_{k=0}^{N-1} g(k) exp(-j*n*k*2*pi/N)
%%
%%

%%% segunda estrutura: utilizando algebra linear

tic;                                % inicia um contator de tempo

Matriz_J      = (exp(-j*2*pi/N))*ones(N,N);   % cria a matriz de coeficientes

Matriz_nk     = [0:1:N-1]'*[0:1:N-1];         % matriz dos expoentes nk

WN            = Matriz_J.^Matriz_nk;          % matriz de Fourier - constante

Xn            = WN*gk;                       % S�rie discreeta de Fourier

toc;                                % determina o tempo decorrido

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%  6 -  Visualiza��o
%%
%%





figure(2)

%%% fftshift rotaciona o vetor 0 --> 2*pi ; -pi --> +pi

plot(frequencia,fftshift(log10(abs(Xn))),'k-','linewidth',2)     % configura plot(x,y, cor azul e linha cheia)
xlabel('Frequ�ncia em Hz')                      % tempo em segundos
ylabel('Amplitude')                             % amplitude em volts
title('Espectro de amplitude')                  % t�tulo
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
















