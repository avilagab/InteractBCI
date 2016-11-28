%GABRIEL AVILA 2016
%PROGRAMA PARA HACER CLASIFICACIÓN ENTRE DOS CLASES

archivo = csvread('Gabriel_NI_20161127_2236.csv');
cantDatos = numel(archivo(:,1));
cantEnt = floor(cantDatos*.7);

Data = archivo(1:cantEnt,1:70);
Class =  archivo(1:cantEnt,71);

SVMModel = fitcsvm(Data, Class, 'KernelFunction', 'polynomial', 'KernelScale', 'auto', 'Standardize', true, 'ClassNames', [0, 1]);

nuevosDatos = archivo(cantEnt+1:cantDatos,1:70);

[label, score] = predict(SVMModel, nuevosDatos);
disp(strcat(num2str(label), ' : ', num2str(score)));

CP = classperf(archivo(cantEnt+1:cantDatos,71), label);
CM = confusionmat(archivo(cantEnt+1:cantDatos,71), label);
disp(CM);

figure
subplot(2,1,1);
plot(archivo(cantEnt+1:cantDatos,71));
subplot(2,1,2);
plot(label(1:numel(label)));