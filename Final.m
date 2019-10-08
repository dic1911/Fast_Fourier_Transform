ALMOST_NO_PIANO = 17000 ;


%change this value to filter some portion of the signal
gap = ALMOST_NO_PIANO ;
%���ܽթ�(�L�h�]0)
del = 0 ;
%��j�T��(�n���|�ܤj)
amp = 2 ;

[y,fs]=audioread('D:\inputaudio.wav');
%sound(y, fs)
N = length(y) 
time=(1:1:N)/fs;  % �ɶ��b���V�q
plot(time,y) ;

%fourier transfer
Y = fft(y) ;
subplot(2,2,1) ;
plot(real(Y))  % �e�X�W��

%���ܽթ�
%Z = Y(1+del:N-del) * amp ;

%��Y���W�q�o��
Y(1:gap,:) = 0 ; 
Y(N-gap:N,:) = 0 ;
Z = Y * amp ;

subplot(2,2,2) ;
plot(real(Z))

%reverse fourier transform
rev = real(ifft(Z)) ;
sound(rev,fs)

subplot(2,2,3);
plot(y)
subplot(2,2,4);
plot(rev)

audiowrite('done.wav',rev,fs);