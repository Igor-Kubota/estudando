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

vogais_DBI = xlsread ("IVogal.xlsx");

%%%%  Separa as formantes f0, f1 e f2 da Vogal

If0 = vogais_DBI(:,1);
If1 = vogais_DBI(:,2);
If2 = vogais_DBI(:,3);

categorias = [If0,If1,If2];


%%%%  Plota os Histogramas e o BoxPlot sem tratar a Base de Dados,
%%%%  Ou seja com os Outliers ainda presentes.

figure(1)
hist(If0,20);
ylabel("Hz")

figure(2)
hist(If1,20);
ylabel("Hz")

figure(3)
hist(If2,20);
ylabel("Hz")


figure(4)
boxplot({If0,If1,If2});


%%%%  Calcula os valores médios de cada formante,além do 
%%%%  Desvio Padrão, ainda com os Outliers.

media_If0 = mean(If0)
std_If0 = std(If0)

media_If1 = mean(If1)
std_If1 = std(If1)

media_If2 = mean(If2)
std_If2 = std(If2)


%%%%  Plota o Grafico de f1 por f2, para ter uma noção da distribuição
%%%%  das vogal.

for k = 1:length(categorias)
  clear('aux_tipo');

figure(5)
scatter(If1,If2);
if k==1 hold; end
grid;
title('Formantes');
xlabel('Formante f1');
ylabel('Formante f2');

end

