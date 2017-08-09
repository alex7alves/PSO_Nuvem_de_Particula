
/*
********************
    Algoritmo de nuvem de particulas
    para duas variáveis
    Autor : Alex Alves

********************
*/


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;


int Minimo (int Tamanho,float m[][7]){
    int pos=0;
    float minimo;
    // Pegando a setima coluna e inserindo em um vetor
    float temp [Tamanho];
    for (int i = 0; i< Tamanho;i++){
        for (int j = 0; j<7;j++){
            if( j==6) {
                temp[i] = m[i][j];
            }
        }
    }
    minimo= temp[0];
    for (int i = 0; i< Tamanho;i++){
         if(minimo > temp[i]) {
            minimo = temp[i];
            pos = i;
         }
    }
    return pos;
}


int main()
{
int duracao = 50; // iterações maxima
float w = 0.7; // ponderação da inercia
float c= 1.2; // parametro cognitivo
srand(time(NULL));

int Tamanho_populacao = 30,gbest;
//Criando a população
float Nuvem_particula[Tamanho_populacao][7];
float x,y,saidafuncao,r1,r2;
/* Posição atual de x e y =
    Nuvem_particula[i][0] e Nuvem_particula[i][1]
    melhor Posição  de x e y =
    Nuvem_particula[i][2] e Nuvem_particula[i][3]
    Velocidade  de x e y =
    Nuvem_particula[i][4] e Nuvem_particula[i][5]
    f(p) = Nuvem_particula[i][6]
*/

//Iniciando a população
for (int i = 0; i< Tamanho_populacao;i++){
    for (int j = 0; j< 7;j++){
        Nuvem_particula[i][j] = i;
    }
}
for (int i = 0; i< Tamanho_populacao;i++){
    Nuvem_particula[i][6] = 1000 ;     // valor inicial  maximo para função objetivo
    Nuvem_particula[i][4] = 0  ;       // Velocidade inicial para x
    Nuvem_particula[i][5] = 0;        //  Velocidade inicial para y
}

for (int iter = 0; iter<duracao; iter++ )
{

    for (int i = 0;i<Tamanho_populacao;i++){
        // Atualizando as posições
        Nuvem_particula[i][0] = Nuvem_particula[i][0] + Nuvem_particula[i][4] ;
        Nuvem_particula[i][1] = Nuvem_particula[i][1] + Nuvem_particula[i][5];
        x = Nuvem_particula[i][0];
        y = Nuvem_particula[i][1];

        // Fazendo restrições para as posições
        if ( Nuvem_particula[i][0] < -500) {
             Nuvem_particula[i][0] =-500;
        }
        if (Nuvem_particula[i][1] < -500) {
            Nuvem_particula[i][1] = -500;
        }
         if ( Nuvem_particula[i][0] > 500) {
             Nuvem_particula[i][0] =500;
        }
        if (Nuvem_particula[i][1] > 500) {
            Nuvem_particula[i][1] = 500;
        }
        // fazendo restrições para as velocidades
        if ( Nuvem_particula[i][4] > 30) {
             Nuvem_particula[i][4] =30;
        }
        if (Nuvem_particula[i][5] > 30) {
            Nuvem_particula[i][5] = 30;
        }
         if ( Nuvem_particula[i][4] < -30) {
             Nuvem_particula[i][4] =-30;
        }
        if (Nuvem_particula[i][5] < -30) {
            Nuvem_particula[i][5] = -30;
        }

        saidafuncao = (x*x)+(y*y) +(((3*x)+ (4*y) -26)*((3*x)+ (4*y) -26));
        if (saidafuncao < Nuvem_particula[i][6]) {  // f(x)<(fp)
            Nuvem_particula[i][2] = Nuvem_particula[i][0] ;  // px  =xi
            Nuvem_particula[i][3] = Nuvem_particula[i][1] ;  // py =yi
            Nuvem_particula[i][6] = saidafuncao  ;     //Atualizando a função objetivo para a particula
        }
        gbest = Minimo(Tamanho_populacao,Nuvem_particula); // Posição da melhor particula - gbest
    }
 //  Atualizando as velocidades
    for (int i = 0; i<Tamanho_populacao;i++){
        r1= rand()%1000;
        r1 = r1/1000;
        r2= rand()%1000;
        r2 = r2/1000;
        Nuvem_particula[i][4] =(w*Nuvem_particula[i][4]) +(c*r1)*(Nuvem_particula[i][2] - Nuvem_particula[i][0]) + (c*r2)*(Nuvem_particula[gbest][2] - Nuvem_particula[i][0])  ;
        Nuvem_particula[i][5] = (w*Nuvem_particula[i][5]) + (c*r1)*(Nuvem_particula[i][3] - Nuvem_particula[i][1]) + (c*r2)*(Nuvem_particula[gbest][3] - Nuvem_particula[i][1]) ;

 }

}

    for (int i = 0; i< Tamanho_populacao;i++){
        cout << Nuvem_particula[i][0]<<"  " << Nuvem_particula[i][1] << endl;
    }
/*for (int i = 0; i< 30;i++){
    for (int j = 0; j< 7;j++){
      cout << Nuvem_particula[i][j]<< " ";
    }
    cout << endl;
}*/
    return 0;
}

