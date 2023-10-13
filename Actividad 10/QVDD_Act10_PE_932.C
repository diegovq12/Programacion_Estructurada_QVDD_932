/*
Quiros Vicencio Diego Demian
10/10/23(creado)
Actividad 10. FUNCIONES y METODOS DE ORDENACION Y BUSQUEDA
ESTRUCTURAS Y LIBRERIAS
*/ 

//Librerias utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "ddqvval.h"
#include "ddqvSort.h"
#include "ddqvstructs10.h"
//********************

void menu (void);
int msge (void);


int main ()
{
    srand(time(NULL));
    menu();
    return 0;
}

//num=min + rand() % (max - min + 1);



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
     Talumn _alum[500];

    do
    {

        system("CLS");

        op=msge();
        
        switch (op)
        {
        case 1:
            fillAtmreg(_alum,indexNumber);
            break;
        case 2:
           fillRegManual(_alum,indexNumber);
            break;
        case 3:
           
            break;
        case 4:
           
            break;
        case 5:

            break;
        case 6:
            printRegs(_alum, indexNumber);
            break;
        default:
            break;
        }
        system("PAUSE");
    } while (op!=0);   
}