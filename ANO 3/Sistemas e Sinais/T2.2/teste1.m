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

%%% carrega as vogais em uma variável tipo cell

vogais_DB = xlsread ("EVogal.xlsx");

%%% separa a coluna da classificação

f0 = vogais_DB(:,1);
f1 = vogais_DB(:,2);
f2 = vogais_DB(:,3);

categorias = [f0,f1,f2];

figure(1)
hist(f0,20);
ylabel("Hz")


figure(2)
hist(f1,20);
ylabel("Hz")


figure(3)
hist(f2,20);
ylabel("Hz")

media_f0 = mean(f0)
std_f0 = std(f0)

media_f1 = mean(f1)
std_f1 = std(f1)

media_f2 = mean(f2)
std_f2 = std(f2)

figure(4)
boxplot({f0,f1,f2});



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


