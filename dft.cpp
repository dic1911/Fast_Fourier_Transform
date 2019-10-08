#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std ;
vector<float> inputdata ;
const int LENGTH = 751104 ;

int main(){
    fstream file;
    file.open("music.txt") ;
    float temp ;
    for(int i=0;i<LENGTH;i++){
        file >> temp ;
        inputdata.push_back(temp) ;
    }
    file.close() ;
	cout << inputdata.size() << endl ;
    float pi=3.1416, u, v ;
	double a;
	for(int i=0;i<LENGTH;i++){
        u=0; v=0 ;
        for(int j=0;j<LENGTH;j++){
            u=u+inputdata[j]*cos(2*pi*i*j/LENGTH) ;
            v=v+inputdata[j]*sin(2*pi*i*j/LENGTH) ;
        }
        printf("X(%d)=%f-%fj\n",i,u,v) ;
	}
	return 0 ;
}
