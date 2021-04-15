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

vogais_DB = xlsread ("AVogal.xlsx");

%%%%  Separa as formantes f0, f1 e f2 da Vogal

f0 = vogais_DB(:,1);
f1 = vogais_DB(:,2);
f2 = vogais_DB(:,3);

categorias = [f0,f1,f2];


%%%%  Plota os Histogramas e o BoxPlot sem tratar a Base de Dados,
%%%%  Ou seja com os Outliers ainda presentes.


figure(1)
hist(f0,20);
ylabel("Hz")

figure(2)
hist(f1,20);
ylabel("Hz")

figure(3)
hist(f2,20);
ylabel("Hz")


figure(4)
[s,h] = boxplot({f0,f1,f2});


%%%%  Calcula os valores médios de cada formante,além do 
%%%%  Desvio Padrão, ainda com os Outliers.

media_f0 = mean(f0)
std_f0 = std(f0)

media_f1 = mean(f1)
std_f1 = std(f1)

media_f2 = mean(f2)
std_f2 = std(f2)


%%%%  Plota o Grafico de f1 por f2, para ter uma noção da distribuição
%%%%  das vogal.

for k = 1:length(categorias)
  clear('aux_tipo');

figure(5)
scatter(f1,f2);
if k==1 hold; end
grid;
title('Formantes');
xlabel('Formante f1');
ylabel('Formante f2');

end

