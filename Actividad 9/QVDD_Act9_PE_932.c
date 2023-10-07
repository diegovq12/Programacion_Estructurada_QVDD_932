//Librerias utilizadas
#include <stdio.h>
#include <stdlib.h>
//********************

//Prototipos de Funciones
int msge(void);
void menu(void);



//************************


int main()
{

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
    scanf("%d",&op);
    
    return op;
}

void menu (void)
{
    int op;
    do
    {
    
        int vector1[10],vector2[10],vector3[20];
        int matriz[4][4];
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
            
            break;
        default:
            break;
        }
        system("PAUSE");
    } while (op!=0);   
}