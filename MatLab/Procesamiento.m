%GABRIEL AVILA 2016
%ESTE PROGRAMA TOMA UN SET DE DATOS ORGANIZADOS EN UN ARCHIVO CSV
%FILTRA DICHOS DATOS, GENERA UNAS MUESTRAS Y LES APLICA UNA VENTANA DE
%HAMMING
%POSTERIORMENTE SE HACE FFT Y SE CALCULA LA POTENCIA ESPECTRAL PARA LAS
%BANDAS DELTA, THETA, ALPHA, BETA Y GAMMA
%Lectura del archivo de datos
archivo = '../CodigoTG3/Lecturas/1027 - Gabriel/Lectura201601027_1806_Parpadeo.csv';
lectura = csvread(archivo);

%Calculo de número de líneas
fid = fopen(archivo,'r');
C = textscan(fid,'%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f',...
'Delimiter',',');
Nrows = numel(C{1});
%disp(Nrows);
fclose(fid);

Fs = 128;                               %Frecuencia de Muestreo 128 o 256
minTime = 0.5;                          %Tamaño en segundos de la muestra
minSize = Fs * minTime;              	%Equivalente a minTime segundos de muestreo
time = floor (Nrows / Fs);            	%Tiempo en segundo
samples = time / minTime;
%disp(time);
start = 1;
startFil = Nrows - time * Fs + 1;     	%Inicio para filtrado, de tal forma que el arreglo quede de Fs * samples
finish = Nrows;                         
tempName = '';

%Debug en caso de error
%dbstop if all error

%FILTRADO DE LOS DATOS
F1stop = 0.001;
F1pass = 0.2;
Astop = 65;
Apass = 0.5;

%FILTRO PASAALTO IIR: INFINITE IMPULSE RESPONSE
d1 = designfilt('highpassiir','StopbandFrequency',F1stop, ...
  'PassbandFrequency',F1pass,'StopbandAttenuation',Astop, ...
  'PassbandRipple',Apass,'SampleRate',Fs,'DesignMethod','butter');
%FILTRO PASAALTO FIR
%d1 = designfilt('highpassfir','StopbandFrequency',F1stop, ...
%   'PassbandFrequency',F1pass,'PassbandRipple',Apass, ...
%   'StopbandAttenuation',Astop,'DesignMethod','kaiserwin');

%FILTRO PASABAJO IIR
F2pass = 40;
F2stop = 63;
d2 = designfilt('lowpassiir', 'PassbandFrequency',F2pass, ...
  'StopbandFrequency',F2stop, 'StopbandAttenuation',Astop, ...
  'PassbandRipple',Apass,'SampleRate',Fs,'DesignMethod','butter');
%FILTRO PASABAJO FIR
%F2pass = .5;
%F2stop = .6;
%d2 = designfilt('lowpassfir','PassbandFrequency',F2pass, ...
%   'StopbandFrequency',F2stop,'PassbandRipple',Apass, ...
%   'StopbandAttenuation',Astop,'DesignMethod','kaiserwin');
 
fvtool(d1);
fvtool(d2);

rs=0;
for i = 2:15             %1:14 Señales en Total
    %Filtrado de los datos de entrada
    dato = lectura(:, i);
    datoPlot = dato(startFil:1:finish);
    
    %Se elimina la media, para evitar oscilaciones en el filtro.
    media = mean(dato);
    dato = dato - media;
    dato = dato(start:1:finish);

    %FiltFilt duplica los datos, para evitar oscilaciones al principio
    datoFil = filtfilt(d1, dato);
    datoFil = filtfilt(d2, datoFil);   
    datoFilPlot = datoFil(startFil:1:finish);
    
    %dataSize = size(minSize,1);
    rs = reshape(datoFilPlot,[],samples);
    
    %Impresion de datos
    %disp(rs(:,1));
    
    %figure;
    %subplot(2,1,1);
    %plot(datoPlot);
    %title('Datos originales');
    %subplot(2,1,2);
    %plot(datoFilPlot);
    j = i-1;
    
    switch j
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
    %title(tempName);
    
    %figure
    %title(+'Señales separadas');
    %for k = 1:samples
    %    subplot(samples,1,k);
    %    plot(rs(:,k));        
    %end
    
    fileName = strcat(tempName, '_file.txt');
    fid = fopen(fileName,'wt');
    for k = 1:samples        
        eje_norm=0:1:minSize-1;
        eje_norm=eje_norm*2*pi/(minSize-1);
        %Creación de una ventana de Hamming con tamaño = Fs * minTime
        window = hamming(minSize);
        windowed = rs(:,k) .* window;
        disp(windowed);
        %Transformada FFT
        fftTransform = fft(windowed);
        trans1 = fftTransform.*conj(fftTransform)/(minSize+1);
        trans1 = mag2db(trans1);
        %trans1 = 10*log10(abs(fftTransform));
        
        %IMPRESIÓN DEL ESPECTRO DE FRECUENCIA
        %if k == 1
        %figure
        %plot(trans1(1:Fs/4)); hold on
        %title( strcat('Espectro de frecuencia: ') );
        %title( strcat('Espectro de frecuencia: ', num2str(k)));
        %end
        
        powerSpectrum = trans1(1:1:minSize/2);
        
        psVector = reshape(powerSpectrum,[],16);   
        
        %Se guardan las potencias correspondientes a Delta, Theta y Alpha
        for l=1:3
        %disp( strcat('Señal: ', num2str(k)));
        %disp( strcat('PS1:',num2str(sum(psVector(:,1)))));
        fprintf(fid,num2str(sum(psVector(:,l))));
        fprintf(fid,',');
        end
        
        %Se suman las frecuencias en el rango 12-32Hz Beta
        suma=0;
        for l=4:8
        %disp( strcat('Señal: ', num2str(k)));
        %disp( strcat('PS1:',num2str(sum(psVector(:,1)))));
        suma= suma + sum(psVector(:,l));        
        end
        fprintf(fid,num2str(suma));
        fprintf(fid,',');
        
        %Se suman las frecuencias mayores a 32Hz Gamma
        suma=0;
        for l=9:16
        %disp( strcat('Señal: ', num2str(k)));
        %disp( strcat('PS1:',num2str(sum(psVector(:,1)))));
        suma= suma + sum(psVector(:,l));        
        end
        fprintf(fid,num2str(suma));        
        fprintf(fid,',');
        
        [sortedValues,sortIndex] = sort(rs(:,k),'descend');  %# Sort the values in descending order
        %disp(sortedValues);
        %disp('-----------------------');
        maxIndex = sortedValues(1);
        %disp(maxIndex);
        fprintf(fid,num2str(maxIndex));        
        fprintf(fid,'\n');

    end
    fclose(fid);

%figure;
%dato = lectura(:, 15);
%dato = dato(inicioFil:1:finalFil);
%plot(dato);
end 