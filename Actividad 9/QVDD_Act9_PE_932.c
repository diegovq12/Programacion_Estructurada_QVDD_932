/*
Quiros Vicencio Diego Demian
10/08/23(creado)
Actividad 9. FUNCIONES y METODOS DE ORDENACION Y BUSQUEDA.
programa en C que utilice librerias propias para realizar
distintas operaciones con matrices y vectores.
*/ 

//Librerias utilizadas
#include <stdio.h>
#include <stdlib.h>
#include "ddqv.h"
#include "ddqvval.h"
#include "ddqvSort.h"
//********************

//Prototipos de Funciones
int msge(void);
void menu(void);
//************************


int main()
{
    menu();
    
    return 0;
}


int msge (void)
{
    int op;
    printf("\n\t M E N U\n");
    printf("1.- LLENAR VECTOR\n");
    printf("2.- LLENAR MATRIZ \n");
    printf("3.- IMPRIMIR VECTOR\n");
    printf("4.- IMPRIMIR MATRIZ\n");
    printf("5.- ORDENAR VECTOR\n");
    printf("6.- BUSCAR VALOR EN VECTOR\n");
    printf("0. Salir\n");
    printf("Ingresa funcion a utilizar:\n");
    op=validInt(0,6);
    
    return op;
}

void menu (void)
{
    int op,op2;
    int num;
    int vector[100];
    int matrix[4][4];

    do
    {

        system("CLS");

        op=msge();
        
        switch (op)
        {
        case 1:
            fill_vectorRand(vector,15,100,200);
            break;
        case 2:
            fill_MatrizRand(matrix,4,4,1,16);
            break;
        case 3:
            printVector(vector,15,"Vector 1");
            break;
        case 4:
            printMatrix(4,4,matrix,"Matriz 1");
            break;
        case 5:
            bubbleSort(vector,15);
            break;
        case 6:
            do
            {
                printf("Que valor deseas buscar: ");
                num=validInt(0,1000);
                findVectorValue(vector,15,num);
                printf("Quisieras buscar otro valor?\n\t[ Yes[1]/No[2] ]");
                op2=validInt(1,2);
            } while (op2!=2);
            
            break;
        default:
            break;
        }
        system("PAUSE");
    } while (op!=0);   
}
