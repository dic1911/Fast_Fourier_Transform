[y,fs]=audioread('D:\inputaudio.wav',[1,524288]);
fprintf('len = %d',length(y))
file=fopen('music.txt','w')
fprintf(file,'%f\n',y)
fclose(file)
