[y,fs]=audioread('D:\inputaudio.wav');
fprintf('%d',length(y))
file=fopen('music.txt','w')
fprintf(file,'%f\n',y)
fclose(file)
