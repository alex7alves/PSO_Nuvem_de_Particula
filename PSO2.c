/*
    Algoritmo de nuvem de particulas
    Autor : Marcelo Avelino, Cássio Daniel e Alex Alves
    Descrição: Algoritmo de busca pelo valor mnínimo de uma nuvem de partículas utilizando vetorizaço.

    Posição atual de x e y =
    Nuvem_particula[i][0] e Nuvem_particula[i][1]
    melhor Posição  de x e y =
    Nuvem_particula[i][2] e Nuvem_particula[i][3]
    Velocidade  de x e y =
    Nuvem_particula[i][4] e Nuvem_particula[i][5]
    f(p) = Nuvem_particula[i][6]
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int Minimo (int Tamanho,float m[][7]);
float Randomico();

int main(){

    srand(time(NULL));
    int duracao = 100000; // iterações maxima
    float w = 0.5; // ponderação da inercia
    float c1 = 1.5, c2 = 1.5; // parametros cognitivos
    int Tamanho_populacao = 30, gbest;

    //Criando a população
    float Nuvem_particula[Tamanho_populacao][7];
    double x, y, saidafuncao, r1, r2;
    int i, j, iter;


    //Iniciando a população
    // Vetorizado
    for (i = 0; i < Tamanho_populacao; i++){
           for (j = 0; j <7 ;j++){
               Nuvem_particula[i][j] =i;
           }
    }
    #pragma vector always
    #pragma ivdep
    for (i = 0; i < Tamanho_populacao; i++){

        Nuvem_particula[i][4] = 0;   // Velocidade inicial para x
        Nuvem_particula[i][5] = 0;   //  Velocidade inicial para y
        Nuvem_particula[i][6] = 1000; // valor inicial  maximo para função objetivo

    }
    for (iter = 1; iter <= duracao; iter++){
         #pragma ivdep
        for(i = 0; i < Tamanho_populacao; i++){
            // Atualizando as posições das particulas
             Nuvem_particula[i][0] = Nuvem_particula[i][0] + Nuvem_particula[i][4];
             Nuvem_particula[i][1] = Nuvem_particula[i][1] + Nuvem_particula[i][5];

             // Fazendo restrições para as posições
             Nuvem_particula[i][0] = (Nuvem_particula[i][0] <  -500) ? -500 :Nuvem_particula[i][0];
             Nuvem_particula[i][1] =  (Nuvem_particula[i][1] < -500) ? -500 : Nuvem_particula[i][1];
             Nuvem_particula[i][0] =  (Nuvem_particula[i][0] > 500) ? 500 : Nuvem_particula[i][0];
             Nuvem_particula[i][1] = (Nuvem_particula[i][1] > 500) ? 500 : Nuvem_particula[i][1];

            // fazendo restrições para as velocidades
            Nuvem_particula[i][4]= (Nuvem_particula[i][4] > 30) ? 30 : Nuvem_particula[i][4];
            Nuvem_particula[i][5]= (Nuvem_particula[i][5] > 30) ? 30 : Nuvem_particula[i][5];
            Nuvem_particula[i][4]= (Nuvem_particula[i][4] < -30) ? -30 : Nuvem_particula[i][4];
            Nuvem_particula[i][5] =(Nuvem_particula[i][5] < -30) ? -30 : Nuvem_particula[i][5];


            x = Nuvem_particula[i][0];
            y = Nuvem_particula[i][1];
            saidafuncao = (x*x) + (y*y) + ( (3*x) + (4*y) - 26 ) * ( (3*x) + (4*y) - 26 );
        // Isso tem que vetorizar
            if(saidafuncao < Nuvem_particula[i][6]){  // f(x) <f(p)
                    // Atualizar as melhores posições das particulas
                    Nuvem_particula[i][2] = Nuvem_particula[i][0];  //Px = Xi
                    Nuvem_particula[i][3] = Nuvem_particula[i][1];  //Py = Yi
                    //Atualizar função objetivo da particula
                    Nuvem_particula[i][6] = saidafuncao;

                    // Pegar melhor posição do grupo
                    gbest = Minimo(Tamanho_populacao,Nuvem_particula);  // equivale a f(x) <f(g)
             }

       }
            for (j = 0; j < Tamanho_populacao; j++){
                 r1 = Randomico();
                 r2 = Randomico();
                 // Atualizando velocidades
                 Nuvem_particula[j][4] = (w*Nuvem_particula[j][4]) + (c1*r1*(Nuvem_particula[j][2] -Nuvem_particula[j][0])) + (c2*r2*(Nuvem_particula[gbest][2] -Nuvem_particula[j][0]));
                 r1 = Randomico();
                 r2 = Randomico();
                 Nuvem_particula[j][5] = (w*Nuvem_particula[j][5]) + (c1*r1*(Nuvem_particula[j][3] -Nuvem_particula[j][1])) + (c2*r2*(Nuvem_particula[gbest][3] -Nuvem_particula[j][1]));
            }
     }

     printf("----------------------------------\n");
     printf("Posicao x \t|\t Posicao y \n");
     printf("----------------------------------\n");
     for (i = 0; i < Tamanho_populacao; i++){
        printf(" %f \t|\t %f \n", Nuvem_particula[i][0], Nuvem_particula[i][1] );
     }
    return 0;
}

int Minimo (int Tamanho,float m[][7]){
    int i;
    int pos=0;
    float minimo = m[0][6];

    for (i = 0; i< Tamanho;i++){
        pos = (minimo >m[i][6]) ? i :pos;
        minimo = (minimo >m[i][6]) ? m[i][6] : minimo;
    }
    return pos;
}

float Randomico() {
   float  r= rand()%10000;
   r = r/10000;
   return r;
}

