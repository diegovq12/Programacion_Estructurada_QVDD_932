/*Quiros Vicencio Diego Demian
09/26/23(creado) - 09/30/23(modificado)
Actividad 8. Arreglos en C  
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Prototipos
int msge(void);
void menu(void);

void llena_vectorManual (int vector1[10],int m,int ri,int rf);
void llena_vectorRandom (int vector2[10],int m,int ri,int rf);
void llena_vector3conV1yV2 (int vector3[20],int vector1[10],int vector2[10],int m);
void imprimir_vectores (int vect[],int m);
void llena_matriz4x4(int matriz[4][4],int vector3[],int m,int n);
void imprimir_matriz(int matriz[4][4],int m,int n);
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
            llena_vectorManual (vector1,10,30,70);
            break;
        case 2:
            llena_vectorRandom (vector2,10,1,20);
            break;
        case 3:
            llena_vector3conV1yV2(vector3,vector1,vector2,20);
            break;
        case 4:
            printf("Vector 1\n");
            imprimir_vectores(vector1,10);
            printf("\n");
            printf("Vector 2\n");
            imprimir_vectores(vector2,10);
            printf("\n");
            printf("Vector 3\n");
            imprimir_vectores(vector3,20);
            break;
        case 5:
            llena_matriz4x4(matriz,vector3,4,4);
            break;
        case 6:
            imprimir_matriz(matriz,4,4);
            break;
        default:
            break;
        }
        system("PAUSE");
    } while (op!=0);   
}


//Funcion Que llena un vector manualmente dentro de cierto rango de numeros
//QVDD_Act8_01_932.c
void llena_vectorManual (int vector1[10],int m,int ri,int rf)
{
    int num,aux;
    printf("Los datos del Vector deben estar entre los valores %d y %d\n",ri,rf);
    for (int i = 0; i < m; i++)
    {
        aux=0;
        scanf("%d",&num);
       if (num<ri || num>rf)
        {
            aux=1;
            
            do
            {
                printf("Valor fuera de limite\n");
                printf("El numero debe estar entre %d y %d\n",ri,rf);
                scanf("%d",&num);
                if (num>=ri && num<=rf)
                {
                    aux=0;
                }
                
            } while (aux==1);
        }
        vector1[i]=num;  
    }
}

//Funcion Que llena un vector aleatoriamente sin repetirse dentro de cierto rango de numeros
//QVDD_Act8_02_932.c
void llena_vectorRandom (int vector2[10],int m,int ri,int rf)
{
    srand(time(NULL));
    int aux,num,i,j;
    for (i = 0; i < m; i++)
    {  
        aux=0;
        num=(rand()%(ri-rf))+ri;
        for (j = 0; j<m; j++)
        {
            if (num==vector2[j])
            {
                aux=1;
            }
        }
        
        if (aux==1)
        {
            i--;
        }
        else
        {
            vector2[i]=num;
        }
    }
    printf("\nEl Vector 2 ha sido llenado con valores del %d hasta %d\n",ri,rf);
}

// FUNCION QUE LLENA VECTOR 3 CON DATOS DEL VECTOR1 Y VECTOR2.
//QVDD_Act8_03_932.c
void llena_vector3conV1yV2(int vector3[20],int vector1[10],int vector2[10],int m)
{
    int i,j;
    for (i = 0; i < m; i++)
    {
        vector3[i]=vector1[i];
    }
    j=0;
    for (i = 10; i < m; i++)
    {
        vector3[i]=vector2[j];
        j++;
    }
    printf("\nEl Vector ha sido llenado con los datos del Vector 1 y Vector 2");
}

// FUNCION QUE IMPRIME LOS DATOS DE LOS 3 VECTORES.
//QVDD_Act8_04_932.c
void imprimir_vectores(int vect[],int m)
{
    for (int i = 0; i < m; i++)
    {
        printf("%d - [%d]\n",i,vect[i]);
    }   
}

// FUNCION QUE LLENA UNA MATRIZ 4X4 CON LOS DATOS DE LOS
//VECTORES 1 Y 2.
//QVDD_Act8_05_932.c
void llena_matriz4x4(int matriz[4][4],int vector3[],int m,int n)
{
    int i,j;
    int aux=0;
    for (i = 0; i < m; i++)
    {
        for(j = 0; j<n ; j++)
        {
            matriz[i][j]=vector3[aux];
            aux++;
        }
    }   
    printf("Se ha llenado la matriz con los valores de los vectores anteriores\n");
}

// FUNCION QUE IMPRIME UNA MATRIZ 4X4
//QVDD_Act8_06_932.c
void imprimir_matriz(int matriz[4][4],int m,int n)
{
    int i,j;

    for (i = 0; i < m; i++)
    {
        for(j = 0; j<n ; j++)
        {
            printf("[%d]",matriz[i][j]);
        }
        printf("\n");
    }   
}
