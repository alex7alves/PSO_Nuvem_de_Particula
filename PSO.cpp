
/*
    Algoritmo de nuvem de particulas
    Autor : Alex Alves
*/
#include <iosream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
int Minimo (int Tamanho,float m[][7]);

int main ()
{


    return 0;
}

int Minimo (int Tamanho,float m[][7]){
    int pos=0;
    float minimo = m[0][6];

    for (int i = 0; i< Tamanho;i++){
       if(minimo > m[i][7]){
            minimo = m[i][7];
            pos =i;
       }
    }
   cout << minimo << "  " << pos;
    return pos;
}
