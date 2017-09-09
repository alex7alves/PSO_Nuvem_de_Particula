
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
#include <math.h>

using namespace std;
int Minimo (int Tamanho,float m[][7]);

int main ()
{
    srand(time(NULL));
    int duracao = 50; // iterações maxima
    float w = 0.7; // ponderação da inercia
    float c= 1.2; // parametro cognitivo
    int Tamanho_populacao = 30,gbest;
    //Criando a população
    float Nuvem_particula[Tamanho_populacao][7];
    double x,y,saidafuncao,r1,r2;


    //Iniciando a população
    for (int i = 0; i< Tamanho_populacao;i++){
        for (int j = 0; j<7;j++){
            Nuvem_particula[i][j] = i+1;
        }
    }
    for (int i =0 ;i <Tamanho_populacao;i++){
        Nuvem_particula[i][4] = 0;   // Velocidade inicial para x
        Nuvem_particula[i][5] = 0;   //  Velocidade inicial para y
        Nuvem_particula[i][6] = 1000; // valor inicial  maximo para função objetivo
    }

  /*  for (int i = 0; i< Tamanho_populacao;i++){
        for (int j = 0; j<7;j++){
            cout << Nuvem_particula[i][j]<< " ";
        }
        cout << endl;
    }*/

    for (int iter=1;iter<=duracao;iter++){

        for(int i =0;i<Tamanho_populacao;i++){
            x= Nuvem_particula[i][0];
            y= Nuvem_particula[i][1];
            saidafuncao =(x*x) + (y*y)+ ((3*x)+ (4*y)-26)*((3*x)+ (4*y)-26);
            if(saidafuncao <Nuvem_particula[i][6]){  // f(x) <f(p)
                // Atualizar as melhores posições das particulas
                Nuvem_particula[i][2] = Nuvem_particula[i][0];  //Px = Xi
                Nuvem_particula[i][3] = Nuvem_particula[i][1];  //Py = Yi
                //Atualizar função objetivo da particula
                Nuvem_particula[i][6] = saidafuncao;

                // Pegar melhor posição do grupo
                gbest = Minimo(Tamanho_populacao,Nuvem_particula);  // equivale a f(x) <f(g)
            }

        }

    }
    //gbest = Minimo(Tamanho_populacao,Nuvem_particula);

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
