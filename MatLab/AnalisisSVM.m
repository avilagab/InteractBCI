%GABRIEL AVILA 2016

%Uniendo todos los electrodos en una sola matriz
NTotal = [];
ITotal = [];
for m=1:14
        switch m
        case 1, tempName = 'AF3';
        case 2, tempName = 'F7';
        case 3, tempName = 'F3';
        case 4, tempName = 'FC5';
        case 5, tempName = 'T7';
        case 6, tempName = 'P7';
        case 7, tempName = 'O1';
        case 8, tempName = 'O2';
        case 9, tempName = 'P8';
        case 10, tempName = 'T8';
        case 11, tempName = 'FC6';
        case 12, tempName = 'F4';
        case 13, tempName = 'F8';
        case 14, tempName = 'AF4';
        end
archivo = strcat('../CodigoTG3/Lecturas/1027 - Gabriel/DerechodB/', tempName, '_file.txt');
fid = fopen(archivo,'r');
N = textscan(fid,'%f %f %f %f %f %f',...
    'Delimiter',',');
NTotal = [NTotal N];
fclose(fid);

archivo = strcat('../CodigoTG3/Lecturas/1027 - Gabriel/IzquierdodB/', tempName, '_file.txt');
fid = fopen(archivo,'r');
I = textscan(fid,'%f %f %f %f %f %f',...
    'Delimiter',',');
ITotal = [ITotal I];
fclose(fid);
end

Class1 =  0 * ones(1, numel(NTotal{1}));
Class2 =  1 * ones(1, numel(ITotal{1}));

SVMTotal = [NTotal{:};ITotal{:}];
ClassTotal = [transpose(Class1);transpose(Class2)];

SVMModel = fitcsvm(SVMTotal, ClassTotal, 'KernelFunction', 'polynomial', 'KernelScale', 'auto', 'Standardize', true, 'ClassNames', [0, 1]);

%Uniendo todos los electrodos en una sola matriz
NTotal = [];
ITotal = [];
for m=1:14
        switch m
        case 1, tempName = 'AF3';
        case 2, tempName = 'F7';
        case 3, tempName = 'F3';
        case 4, tempName = 'FC5';
        case 5, tempName = 'T7';
        case 6, tempName = 'P7';
        case 7, tempName = 'O1';
        case 8, tempName = 'O2';
        case 9, tempName = 'P8';
        case 10, tempName = 'T8';
        case 11, tempName = 'FC6';
        case 12, tempName = 'F4';
        case 13, tempName = 'F8';
        case 14, tempName = 'AF4';
        end
archivo = strcat('../CodigoTG3/Lecturas/1027 - Gabriel/DerechodBTest/', tempName, '_file.txt');
fid = fopen(archivo,'r');
N = textscan(fid,'%f %f %f %f %f %f',...
    'Delimiter',',');
NTotal = [NTotal N];
fclose(fid);

archivo = strcat('../CodigoTG3/Lecturas/1027 - Gabriel/IzquierdodBTest/', tempName, '_file.txt');
fid = fopen(archivo,'r');
I = textscan(fid,'%f %f %f %f %f %f',...
    'Delimiter',',');
ITotal = [ITotal I];
fclose(fid);
end

nuevosDatos = [NTotal{:};ITotal{:}];

[label, score] = predict(SVMModel, nuevosDatos);
disp(strcat(num2str(label), ' : ', num2str(score)));

figure
plot(label(61:numel(label)));