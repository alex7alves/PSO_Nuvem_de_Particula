
/*
    Algoritmo de nuvem de particulas
    Autor : Alex Alves


    Posição atual de x e y =
    Nuvem_particula[i][0] e Nuvem_particula[i][1]
    melhor Posição  de x e y =
    Nuvem_particula[i][2] e Nuvem_particula[i][3]
    Velocidade  de x e y =
    Nuvem_particula[i][4] e Nuvem_particula[i][5]
    f(p) = Nuvem_particula[i][6]
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
int Minimo (int Tamanho,float m[][7]);

int main ()
{
    int duracao = 50; // iterações maxima
    float w = 0.7; // ponderação da inercia
    float c= 1.2; // parametro cognitivo
    srand(time(NULL));
    int Tamanho_populacao = 30,gbest;
    //Criando a população
    float Nuvem_particula[Tamanho_populacao][7];
    float x,y,saidafuncao,r1,r2;


    //Iniciando a população
    for (int i = 0; i< Tamanho_populacao;i++){
        for (int j = 0; j<7;j++){
            Nuvem_particula[i][j] = i+1;
        }
    }
    /*for (int i = 0; i< Tamanho_populacao;i++){
        for (int j = 0; j<7;j++){
            cout << Nuvem_particula[i][j]<< " ";
        }
        cout << endl;
    }*/
    gbest = Minimo(Tamanho_populacao,Nuvem_particula);

    return 0;
}

int Minimo (int Tamanho,float m[][7]){
    int pos=0;
    float minimo = m[0][6];

    for (int i = 0; i< Tamanho;i++){
       if(minimo > m[i][6]){
            minimo = m[i][6];
            pos =i;
       }
    }
   cout << minimo << "  " << pos;
    return pos;
}
