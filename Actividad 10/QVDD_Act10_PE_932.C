/*
Quiros Vicencio Diego Demian
10/10/23(creado)
Actividad 9. FUNCIONES y METODOS DE ORDENACION Y BUSQUEDA
ESTRUCTURAS Y LIBRERIAS
*/ 

//Librerias utilizadas
#include <stdio.h>
#include <stdlib.h>
#include "ddqv.h"
#include "ddqvval.h"
#include "ddqvSort.h"
//********************





//num=(rand()%(ri-rf))+ri;



int msge (void)
{
    int op;
    printf("\n R E G I S T R O S U A B C\n");
    printf("1.- AGREGAR (AUTOM 10 REGISTROS)\n");
    printf("2.- AGREGAR MANUAL \n");
    printf("3.- ELIMINAR REGISTRO\n");
    printf("4.- BUSCAR\n");
    printf("5.- ORDENAR\n");
    printf("6.- IMPRIMIR\n");
    printf("0. Salir\n");
    printf("Ingresa funcion a utilizar:\n");
    op=validInt(0,6);
    
    return op;
}

void menu (void)
{
    int op;

    do
    {

        system("CLS");

        op=msge();
        
        switch (op)
        {
        case 1:
            
            break;
        case 2:
           
            break;
        case 3:
           
            break;
        case 4:
           
            break;
        case 5:

            break;
        case 6:
            do
            {
                
            } while (op2!=2);
            
            break;
        default:
            break;
        }
        system("PAUSE");
    } while (op!=0);   
}