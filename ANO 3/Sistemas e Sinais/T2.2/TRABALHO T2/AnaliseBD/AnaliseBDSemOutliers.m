%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%    Igor Eiki Ferreira Kubota 
%%    RA: 19.02466-5

%% 0 - Boas pr�ticas
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

%%% carrega as vogais em uma variavel to tipo cell

%%% O Arquivo ja est� sem os Outliers ue foram retirados
%%% Manualmente pelo excel.

vogais_DB = csv2cell ("VogaisOutlierFinal2CSV.csv");

%%% separa a coluna da classifica��o

tipo_vogal = {vogais_DB{:,1}};

%%% verifica as categorias presentes

categorias = unique(tipo_vogal);

for k = 1:length(categorias)
  
  clear('aux_tipo');
  
%%% Localiza um tipo espec�fico de vogal

aux_tipo = strcmp(categorias(k),tipo_vogal);

%%% separa a frequ�ncia fundamental - fo

freq_fo = cell2mat({vogais_DB{aux_tipo,2}});

%%% separa a formante f1

freq_f1 = cell2mat({vogais_DB{aux_tipo,2}});

%%% separa a formante f2

freq_f2 = cell2mat({vogais_DB{aux_tipo,3}});

%%% Visualiza��o para a primeira categoria

figure(1)
scatter(freq_f1,freq_f2);
if k==1 hold; end
grid;
title('Formantes');
xlabel('Formante f1');
ylabel('Formante f2');

end


