#include <cstdio>
#include <iostream>
#include <complex>
#include <iomanip>
using namespace std;

const double pi = 2.0 * acos(0);
const int N = 524288;
complex<double> x[N];

void easy_input(){
    /*for(int i=0;i<7;i++){
        x[i]=complex<double>(i+1,0.0);
        cout << x[i] << " ";
    }*/
    x[0]=complex<double>(0,0.0);
    x[1]=complex<double>(1.0,0.0);
    x[2]=complex<double>(0);
    x[3]=complex<double>(1,0.0);
    cout << endl;
}

void put_in(){
	FILE* file = fopen("music.txt","r") ;
	float temp;
	for(int i=0;i<N;i++){
		fscanf(file,"%f",&temp);
		x[i]=complex<double>(temp,0.0);
	}
	//for(int i=tN;i<N;i++) x[i]=complex<double>(0.0,0.0);
	//for(int i=0;i<tN;i++) cout << setprecision(2) << x[i] << endl;
	fclose(file) ;
	printf("File input Finished!\n") ;
}

void FFT()
{
    /* bit-reversal permutation */
    for (int i=1, j=0; i<N; ++i)
    {
        for (int k=N>>1; !((j^=k)&k); k>>=1) ;
//      for (int k=N>>1; k>(j^=k); k>>=1) ;
        if (i>j) swap(x[i], x[j]);
//      if (i<j) swap(x[i], x[j]);
    }

    /* dynamic programming */
    for (int k=2; k<=N; k<<=1)
    {
        double W = -2.0 * pi / k;
        complex<double> dsita(cos(W), sin(W));

        // 每k個做一次FFT
        for (int j=0; j<N; j+=k)
        {
            // 前k/2個與後k/2的三角函數值恰好對稱，
            // 因此兩兩對稱的一起做。
            complex<double> sita(1.0, 0.0);
            for (int i=j; i<j+k/2; i++)
            {
                complex<double> a = x[i];
                complex<double> b = x[i + k/2] * sita;
                x[i]       = a + b;
                x[i + k/2] = a - b;
                sita *= dsita;
            }
        }
    }
}

void IFFT()
{
    /* bit-reversal permutation */
    for (int i=1, j=0; i<N; ++i)
    {
        for (int k=N>>1; !((j^=k)&k); k>>=1) ;
//      for (int k=N>>1; k>(j^=k); k>>=1) ;
        if (i>j) swap(x[i], x[j]);
//      if (i<j) swap(x[i], x[j]);
    }

    /* dynamic programming */
    for (int k=2; k<=N; k<<=1)
    {
        double W = -2.0 * pi / k;
        complex<double> dsita(cos(W), sin(W));

        // 每k個做一次FFT
        for (int j=0; j<N; j+=k)
        {
            // 前k/2個與後k/2的三角函數值恰好對稱，
            // 因此兩兩對稱的一起做。
            complex<double> sita(1.0, 0.0);
            for (int i=j; i<j+k/2; i++)
            {
                complex<double> a = x[i];
                complex<double> b = x[i + k/2] * sita;
                x[i]       = a - b;
                x[i + k/2] = a + b;
                sita *= dsita;
            }
        }
    }
}

int main(){
    put_in();
    //easy_input();
    FFT();
    cout << "FFT done!\n";
    //IFFT();
    //cout << "IFFT done!\n";
    freopen("ffted.txt","w",stdout);
    /*for(int i=0;i<tN;i++)
        if(imag(x[i])>=0) cout << real(x[i]) << "+" << imag(x[i]) << "i" << "\n";
        else cout << real(x[i]) << imag(x[i]) << "i" << "\n";*/
    for(int i=0;i<N;i++)
        cout << x[i] << endl;
    return 0;
}
