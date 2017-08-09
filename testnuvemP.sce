// Algoritmo de nuvem de particulas 
// Autor : Alex Alves

duracao = 50; // iterações maxima
w = 0.4; // ponderação da inercia
c= 1.5; // parametro cognitivo


Tamanho_populacao = 30;
//Criando a população
Nuvem_particula=zeros(Tamanho_populacao,7)

// Posição atual de x e y = 
//Nuvem_particula(i, 1) e Nuvem_particula(i, 2)  
//  melhor Posição  de x e y = 
//Nuvem_particula(i, 3) e Nuvem_particula(i, 4) 
// Velocidade  de x e y = 
//Nuvem_particula(i, 4) e Nuvem_particula(i, 6) 
// f(p) = Nuvem_particula(i, 7) 
//Iniciando a população 
for i = 1 : Tamanho_populacao
Nuvem_particula(i, 1:7) = i;
end

Nuvem_particula(:, 7) = 1000      // valor inicial  maximo para função objetivo
Nuvem_particula(:, 5) = 0         // Velocidade inicial para x
Nuvem_particula(:, 6) = 0         //  Velocidade inicial para y

for iter = 1 : duracao
    
    for i = 1 : Tamanho_populacao
        // Atualizando as posições 
        Nuvem_particula(i, 1) = Nuvem_particula(i, 1) + Nuvem_particula(i, 5) ;  
        Nuvem_particula(i, 2) = Nuvem_particula(i, 2) + Nuvem_particula(i, 6);   
        x = Nuvem_particula(i, 1);
        y = Nuvem_particula(i, 2);

      // z=-x.*sin(sqrt(abs(x)))-y.*sin(sqrt(abs(y)));
       //saidafuncao = ((x+y).*z).*((x-y).*z);

        saidafuncao = (x^2)+(y^2) +((3*x)+ (4*y) -26)^2;
        if saidafuncao < Nuvem_particula(i, 7)   // f(x)<(fp)
            Nuvem_particula(i, 3) = Nuvem_particula(i, 1)   // px  =xi
            Nuvem_particula(i, 4) = Nuvem_particula(i, 2)   // py =yi 
            Nuvem_particula(i, 7) = saidafuncao          //Atualizando a função objetivo para a particula
        end
        [temp, gbest] = min(Nuvem_particula(:, 7)) // Posição da melhor particula - gbest 
    
    end
 //  Atualizando as velocidades 
    for i = 1 : Tamanho_populacao
        Nuvem_particula(i, 5) =w*Nuvem_particula(i, 5) +( c*rand())*(Nuvem_particula(i, 3)...
            - Nuvem_particula(i, 1)) + (c*rand())*(Nuvem_particula(gbest, 3) - Nuvem_particula(i, 1))  ; 
        Nuvem_particula(i, 6) = w*Nuvem_particula(i, 6) + (c*rand())*(Nuvem_particula(i, 4)...
            - Nuvem_particula(i, 2)) + (c*rand())*(Nuvem_particula(gbest, 4) - Nuvem_particula(i, 2)) ;
    end 
    // Fazendo restrições para as posições e velocidades
    if  Nuvem_particula(i, 1) < -500 
        Nuvem_particula(i, 1) =-500;
    end
    if  Nuvem_particula(i, 2) < -500 
        Nuvem_particula(i, 2) = -500;
    end
     if  Nuvem_particula(i, 1) > 500
        Nuvem_particula(i, 1) =500;
    end
    if  Nuvem_particula(i, 2) > 500
        Nuvem_particula(i, 2) =500;
    end
    if  Nuvem_particula(i, 5) > 500
        Nuvem_particula(i, 5) =500;
    end
     if  Nuvem_particula(i, 6) > 500
        Nuvem_particula(i, 6) =500;
    end
    if   Nuvem_particula(i, 5)<0 |  Nuvem_particula(i, 6) <0
         Nuvem_particula(i, 5)=0;
         Nuvem_particula(i, 6)=0;
    end

 
   
  //  Ajustando os eixos automaticamente
    clf   
    // plotando  convergencia
    plot(Nuvem_particula(:, 1), Nuvem_particula(:, 2), 'x')  

end
// plotando  convergencia
//plot(Nuvem_particula(:, 1), Nuvem_particula(:, 2), 'x');
    disp(Nuvem_particula(:, 1),Nuvem_particula(:, 2));
