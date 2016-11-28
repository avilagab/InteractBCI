%GABRIEL AVILA 2016
%PROGRAMA PARA HACER CLASIFICACIÓN MULTICLASE CON MATLAB

archivo = csvread('Gabriel_NM_20161127_2247.csv');
cantDatos = numel(archivo(:,1));
cantEnt = floor(cantDatos*.7);

%NTotal = [NTotal N];
%ITotal = [ITotal I];
Data = archivo(1:cantEnt,1:70);
Class =  archivo(1:cantEnt,71);

SVMModels = cell(3,1);
clases = unique(Class);

for j = 1:numel(clases);
    indx = eq(Class, clases(j)); % Create binary classes for each classifier
    SVMModels{j} = fitcsvm(Data,indx,'ClassNames',[false true],'KernelFunction', 'polynomial', 'KernelScale', 'auto', 'Standardize', true);
end

Scores = zeros(cantDatos-cantEnt,numel(clases));
nuevosDatos = archivo(cantEnt+1:cantDatos,1:70);

for j = 1:numel(clases);
    [~,score] = predict(SVMModels{j},nuevosDatos);
    Scores(:,j) = score(:,2); % Second column contains positive-class scores
end

[~,maxScore] = max(Scores,[],2);
Resultado = maxScore - 1;
disp(Resultado);

CP = confusionmat(archivo(cantEnt+1:cantDatos,71), Resultado);
disp(CP);
%figure;
%subplot(2,1,1);
%plot(archivo(cantEnt+1:cantDatos,71));
%subplot(2,1,2);
%plot(label(1:numel(label)));