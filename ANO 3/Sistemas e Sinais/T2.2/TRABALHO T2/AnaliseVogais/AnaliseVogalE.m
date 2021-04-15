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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%% carrega as vogais em uma variável tipo xlsx

vogais_DBE = xlsread ("EVogal.xlsx");

%%%%  Separa as formantes f0, f1 e f2 da Vogal

Ef0 = vogais_DBE(:,1);
Ef1 = vogais_DBE(:,2);
Ef2 = vogais_DBE(:,3);

categorias = [Ef0,Ef1,Ef2];


%%%%  Plota os Histogramas e o BoxPlot sem tratar a Base de Dados,
%%%%  Ou seja com os Outliers ainda presentes.

figure(1)
hist(Ef0,20);
ylabel("Hz")

figure(2)
hist(Ef1,20);
ylabel("Hz")

figure(3)
hist(Ef2,20);
ylabel("Hz")

figure(4)
boxplot({Ef0,Ef1,Ef2});


%%%%  Calcula os valores médios de cada formante,além do 
%%%%  Desvio Padrão, ainda com os Outliers.

media_Ef0 = mean(Ef0)
std_Ef0 = std(Ef0)

media_Ef1 = mean(Ef1)
std_Ef1 = std(Ef1)

media_Ef2 = mean(Ef2)
std_Ef2 = std(Ef2)


%%%%  Plota o Grafico de f1 por f2, para ter uma noção da distribuição
%%%%  das vogal.

for k = 1:length(categorias)
  clear('aux_tipo');

figure(5)
scatter(Ef1,Ef2);
if k==1 hold; end
grid;
title('Formantes');
xlabel('Formante f1');
ylabel('Formante f2');

end

