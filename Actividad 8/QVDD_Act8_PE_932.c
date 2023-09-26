#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Prototipos
int msge(void);
void menu(void);

void llena_vectorManual (int vector1[10],int m,int ri,int rf);
void llena_vectorRandom (void);
void llena_vector3conV1yV2 (void);
void imprimir_vectores (void);
void llena_matriz4x4(void);
void imprimir_matriz(void);
//*************

int main()
{
    menu();

    return 0;
}

int msge (void)
{
    int op;
    printf("\n\t M E N U\n");
    printf("1. Llenar Vector 1 (Manualtemnte)\n");
    printf("2. Llenar vector 2 Aleatoriamente\n");
    printf("3. Llenar vector 3 (Con Vector 1 y Vector 2)\n");
    printf("4. Imprimir Vectores\n");
    printf("5. Llena Matriz 4 x 4\n");
    printf("6. Imprimir Matriz\n");
    printf("0. Salir\n");
    printf("Ingresa funcion a utilizar:\n");
    scanf("%d",&op);
    
    return op;
}

void menu (void);
{
    int op;
    do
    {
        op=msge();
        system("CLS");
        switch (op)
        {
        case 1:
            llena_vectorManual (vector1[10],10,30,70);
            break;
        case 2:
            llena_vectorRandom (vector2[10],10,1,20);
            break;
        case 3:
            //llena_vector3conV1yV2();
            break;
        case 4:
            //imprimir_vectores();
            break;
        case 5:
            //llena_matriz4x4();
            break;
        case 6:
            //imprimir_matriz();
            break;
        default:
            break;
        }
    } while (op!=0);   
}

void llena_vectorManual (int vector1[],int m,int ri,int rf)
{
    int num;
    for (int = 0; i < m; i++)
    {
        vector1[i]=scanf("%d",&num);
    }
}

void llena_vectorRandom (int vector2[],int m,int ri,int rf)
{
    rand(time(NULL));
    int aux,num;
    for (int = 0; i < m; i++)
    {  
        for (int j = 0; j<m; j++)
        {
            num=(rand()%(ri-rf))+ri;
        }
        
        vector2[i]=num;
    }
}

void imprimir_vectores(int vect[],int m);