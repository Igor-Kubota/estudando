%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%    Igor Eiki Ferreira Kubota 
%%    RA: 19.02466-5

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

vogais_DBO = xlsread ("OVogal.xlsx");

%%%%  Separa as formantes f0, f1 e f2 da Vogal

Of0 = vogais_DBO(:,1);
Of1 = vogais_DBO(:,2);
Of2 = vogais_DBO(:,3);

categorias = [Of0,Of1,Of2];


%%%%  Plota os Histogramas e o BoxPlot sem tratar a Base de Dados,
%%%%  Ou seja com os Outliers ainda presentes.

figure(1)
hist(Of0,20);
ylabel("Hz")

figure(2)
hist(Of1,20);
ylabel("Hz")

figure(3)
hist(Of2,20);
ylabel("Hz")


figure(4)
boxplot({Of0,Of1,Of2});


%%%%  Calcula os valores médios de cada formante,além do 
%%%%  Desvio Padrão, ainda com os Outliers.

media_Of0 = mean(Of0)
std_Of0 = std(Of0)

media_Of1 = mean(Of1)
std_Of1 = std(Of1)

media_Of2 = mean(Of2)
std_Of2 = std(Of2)


%%%%  Plota o Grafico de f1 por f2, para ter uma noção da distribuição
%%%%  das vogal.

for k = 1:length(categorias)
  clear('aux_tipo');

figure(5)
scatter(Of1,Of2);
if k==1 hold; end
grid;
title('Formantes');
xlabel('Formante f1');
ylabel('Formante f2');

end


