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

vogais_DBU = xlsread ("UVogal.xlsx");

%%%%  Separa as formantes f0, f1 e f2 da Vogal

Uf0 = vogais_DBU(:,1);
Uf1 = vogais_DBU(:,2);
Uf2 = vogais_DBU(:,3);

categorias = [Uf0,Uf1,Uf2];


%%%%  Plota os Histogramas e o BoxPlot sem tratar a Base de Dados,
%%%%  Ou seja com os Outliers ainda presentes.

figure(1)
hist(Uf0,20);
ylabel("Hz")

figure(2)
hist(Uf1,20);
ylabel("Hz")

figure(3)
hist(Uf2,20);
ylabel("Hz")


figure(4)
boxplot({Uf0,Uf1,Uf2});


%%%%  Calcula os valores médios de cada formante,além do 
%%%%  Desvio Padrão, ainda com os Outliers.

media_Uf0 = mean(Uf0)
std_Uf0 = std(Uf0)

media_Uf1 = mean(Uf1)
std_Uf1 = std(Uf1)

media_Uf2 = mean(Uf2)
std_Uf2 = std(Uf2)


%%%%  Plota o Grafico de f1 por f2, para ter uma noção da distribuição
%%%%  das vogal.

for k = 1:length(categorias)
  clear('aux_tipo');
  
figure(5)
scatter(Uf1,Uf2);
if k==1 hold; end
grid;
title('Formantes');
xlabel('Formante f1');
ylabel('Formante f2');

end


