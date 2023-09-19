#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Diego Demian Quiros Vicencio
// 08/30/2023
//Juego de chinchampu utilizando estructura de seleccion multiple

int main(){

    int j=1,m,puntajej,puntajem;

    printf("CHINCHAMPU\n");
    printf("1.Piedra\n");
    printf("2.Papel\n");  
    printf("3.Tijera\n");
    printf("Ingresa 0 para salir\n");
        
        
    while(j!=0)
    {        
        printf("\nEscoje tu opcion: ");scanf("%d",&j);

        srand(time(NULL));
        m=1+rand()%(3-1+1);

     
        if (j==1)
        {
            if (m==1)
            {
                printf("Empate!");
            }
            else
            {
                if (m==2)
                {
                    printf("Gana Papel-Maquina");
                    puntajem++;
                }
                else
                {
                    if (m==3)
                    {
                        printf("Gana Piedra- Jugador");
                        puntajej++;
                    }
                    
                }
            }
            
        }
        
        if (j==2)
        {
            if (m==2)
            {
                printf("Empate!");
            }
            else
            {
                if (m==1)
                {
                    printf("Gana Papel-Jugador");
                    puntajej++;
                }
                else
                {
                    if (m==3)
                    {
                        printf("Gana Tijera- Maquina");
                        puntajem++;
                    }
                }
            } 
        }
        if (j==3)
        {
            if (m==3)
            {
                printf("Empate!");
            }
            else
            {
                if (m==1)
                {
                    printf("Gana piedra-Maquina");
                    puntajem++;
                }
                else
                {
                    if (m==2)
                    {
                        printf("Gana Tijera- Jugador");
                        puntajej++;
                    }
                }
            } 
        }
        if (j>3)
        {
            printf("Selecciona una opcion valida\n");
        }
        
    }

    printf("\nPuntaje Jugador: %d puntos",puntajej);
    printf("\nPuntaje Maquina: %d puntos",puntajem);
    
    return 0;
}