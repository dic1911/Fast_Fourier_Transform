ALMOST_NO_PIANO = 17000 ;


%change this value to filter some portion of the signal
gap = ALMOST_NO_PIANO ;
%改變調性(無則設0)
del = 0 ;
%放大訊號(聲音會變大)
amp = 2 ;

[y,fs]=audioread('D:\inputaudio.wav');
%sound(y, fs)
N = length(y) 
time=(1:1:N)/fs;  % 時間軸的向量
plot(time,y) ;

%fourier transfer
Y = fft(y) ;
subplot(2,2,1) ;
plot(real(Y))  % 畫出頻域

%改變調性
%Z = Y(1+del:N-del) * amp ;

%把某個頻段濾掉
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