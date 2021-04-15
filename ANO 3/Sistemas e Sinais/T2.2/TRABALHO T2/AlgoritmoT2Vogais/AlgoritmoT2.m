%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% 0 - Boas práticas
%% 
%% Dicas para a segunda parte do trabalho T2
%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%% prepara o ambiente de trabalho

clear all;
clc;
close all;

%%% carrega pacotes específicos

pkg load io;
pkg load signal;
pkg load statistics;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% 1 - Trabalha com os dados - "banco de dados"
%% 
%% Leitura de um arquivo csv
%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%% carrega as vogais em uma variável tipo xlsx.

vogais_DBA = xlsread ("Aoutlier.xlsx");

vogais_DBE = xlsread ("EOutlier.xlsx");

vogais_DBI = xlsread ("IOutlier.xlsx");

vogais_DBO = xlsread ("OOutlier.xlsx");

vogais_DBU = xlsread ("UOutlier.xlsx");


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



%%%%%   Separa as Formantes f0,f1 e f2 Da Vogal A.

Af0 = vogais_DBA(:,1);
Af1 = vogais_DBA(:,2);
Af2 = vogais_DBA(:,3);


%%%%    Cria os Valores de Média e Desvio padrão dos valores
%%%%    Sem os Outliers da Vogal A.

media_Af0 = mean(Af0)
std_Af0 = std(Af0)

media_Af1 = mean(Af1)
std_Af1 = std(Af1)

media_Af2 = mean(Af2)
std_Af2 = std(Af2)

%%%%    Cria O Vetor de localização da Vogal A.

Af1d1 = media_Af1 + std_Af1;
Af2d2 = media_Af2 + std_Af2;

AfVetor = [Af1d1 , Af2d2]


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%   Separa as Formantes f0,f1 e f2 Da Vogal E.

Ef0 = vogais_DBE(:,1);
Ef1 = vogais_DBE(:,2);
Ef2 = vogais_DBE(:,3);


%%%%    Cria os Valores de Média e Desvio padrão dos valores
%%%%    Sem os Outliers da Vogal E.

media_Ef0 = mean(Ef0)
std_Ef0 = std(Ef0)

media_Ef1 = mean(Ef1)
std_Ef1 = std(Ef1)

media_Ef2 = mean(Ef2)
std_Ef2 = std(Ef2)


%%%%    Cria O Vetor de localização da Vogal E

Ef1d1 = media_Ef1 + std_Ef1;
Ef2d2 = media_Ef2 + std_Ef2;

EfVetor = [Ef1d1 , Ef2d2]


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%   Separa as Formantes f0,f1 e f2 Da Vogal I

If0 = vogais_DBI(:,1);
If1 = vogais_DBI(:,2);
If2 = vogais_DBI(:,3);


%%%%    Cria os Valores de Média e Desvio padrão dos valores
%%%%    Sem os Outliers da Vogal I.

media_If0 = mean(If0)
std_If0 = std(If0)

media_If1 = mean(If1)
std_If1 = std(If1)

media_If2 = mean(If2)
std_If2 = std(If2)


%%%%    Cria O Vetor de localização da Vogal I

If1d1 = media_If1 + std_If1;
If2d2 = media_If2 + std_If2;

IfVetor = [If1d1 , If2d2]


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%   Separa as Formantes f0,f1 e f2 Da Vogal O

Of0 = vogais_DBO(:,1);
Of1 = vogais_DBO(:,2);
Of2 = vogais_DBO(:,3);


%%%%    Cria os Valores de Média e Desvio padrão dos valores
%%%%    Sem os Outliers da Vogal O.

media_Of0 = mean(Of0)
std_Of0 = std(Of0)

media_Of1 = mean(Of1)
std_Of1 = std(Of1)

media_Of2 = mean(Of2)
std_Of2 = std(Of2)


%%%%    Cria O Vetor de localização da Vogal O

Of1d1 = media_Of1 + std_Of1;
Of2d2 = media_Of2 + std_Of2;

OfVetor = [Of1d1 , Of2d2]


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%   Separa as Formantes f0,f1 e f2 Da Vogal U

Uf0 = vogais_DBU(:,1);
Uf1 = vogais_DBU(:,2);
Uf2 = vogais_DBU(:,3);


%%%%    Cria os Valores de Média e Desvio padrão dos valores
%%%%    Sem os Outliers da Vogal U.

media_Uf0 = mean(Uf0)
std_Uf0 = std(Uf0)

media_Uf1 = mean(Uf1)
std_Uf1 = std(Uf1)

media_Uf2 = mean(Uf2)
std_Uf2 = std(Uf2)


%%%%    Cria O Vetor de localização da Vogal U

Uf1d1 = media_Uf1 + std_Uf1;
Uf2d2 = media_Uf2 + std_Uf2;

UfVetor = [Uf1d1 , Uf2d2]



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%  Pega os picos f1 e f2 informados pelo usuário.

xf1 = input("Digite o f1: ")
xf2 = input("Digite o f2: ")


%%%%  Forma o Vetor Localização da vogal informada pelo usuário.

Xvetor = [xf1 , xf2]


%%%%  Faz as distancias entre as Vogais(A,E,I,O,U) da Base 
%%%%  e a vogal informada pelo Usuário.

distXA = norm(AfVetor - Xvetor)
distXE = norm(EfVetor - Xvetor)
distXI = norm(IfVetor - Xvetor)
distXO = norm(OfVetor - Xvetor)
distXU = norm(UfVetor - Xvetor)


%%%%  Cria Um Vetor com as 5 distancias obtidas.

Distancias = [distXA, distXE, distXI, distXO, distXU]


%%%%  Acha o menor valor obtido de Distancia.

DefineVogal = min(Distancias)


%%%%  Informa ao usuario a Vogal obtida em relação à
%%%%  Base de Conhecimentos de Dados.


if (DefineVogal == distXA)
  printf("A Vogal é um A!\n")
  
elseif (DefineVogal == distXE)
  printf("A Vogal é um E!\n")

elseif (DefineVogal == distXI)
  printf("A Vogal é um I!\n")
  
elseif (DefineVogal == distXO)
  printf("A Vogal é um O!\n")

elseif (DefineVogal == distXU)
  printf("A Vogal é um U!\n")

endif

