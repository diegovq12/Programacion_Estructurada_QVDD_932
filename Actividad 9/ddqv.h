#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Funcion que llena un vector con valores aleatorios sin repetirse
//recibe como valor el vector,tamaño y los valores para obtener el
//rango de los valores
//QQVDD_Act9_PE_932
void fill_vectorRand (int *vector,int m,int ri,int rf)
{
    srand(time(NULL));
    int aux,num,i,j;
    for (i = 0; i < m; i++)
    {  
        aux=0;
        num=(rand()%(ri-rf))+ri;
        for (j = 0; j<m; j++)
        {
            if (num==vector[j])
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
            vector[i]=num;
        }
    }
    printf("\nVector has been filled with random values betwen %d & %d\n",ri,rf);
}

//Funcion que llena una matriz 4x4 con valores aleatorios sin repetirse
//recibe como valor la matriz,tamaño y los valores para obtener el
//rango de los valores
////QQVDD_Act9_PE_932
void fill_MatrizRand (int mat[4][4],int m, int n ,int ri,int rf)
{
    srand(time(NULL));
    int i,j,k,l,num;
    int aux;
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            do
            {
                aux=0;
                num=(rand()%(ri-rf))+ri;
                for(k=0 ; k<i ;k++)
                {
                    for (l = 0; l < n; l++)
                    {
                        if (mat[k][l] == num)
                        {
                            aux=1;
                        }   
                    }
                }                
            } while (aux==1);
            mat[i][j]=num;
        }
    } 
    printf("\nMatrix has been filled with random values betwen %d & %d\n",ri,rf);
}

//Funcion que Imprime un vector 
//recibe como valor el vector y tamaño
////QQVDD_Act9_PE_932
void printVector (int vect[], int m, char name[20])
{
    int i;
    printf("%s: \n",name);
    for ( i = 0; i < m; i++)
    {
        printf("%d -[%2d]\n",i,vect[i]);
    }  
}

//Funcion que Imprime una Matriz 
//recibe como valor la matriz y tamaño
////QQVDD_Act9_PE_932
void printMatrix (int m, int n, int mat[m][n],char name[20])
{
    int i,j;

    printf("%s:\n",name);

    for ( i = 0; i < m; i++)
    {
        printf("%d -",i);
       for (j = 0; j < n; j++)
       {    
            printf("[%2d]",mat[i][j]);
       }
       printf("\n");  
    }
}

//Funcion que busca un valor pedido por el usuario dentro
//de un vector
//solicita vector, tamaño y valor a buscar
////QQVDD_Act9_PE_932
void findVectorValue (int vector[], int m, int val)
{
    int i;
    int aux=0;

    for (i = 0; i < m; i++)
    {
        if (vector[i]==val)
        {
            printf("El Valor se encontro en el espacio %d\n",i);
            aux=1;
        }
    }
    if (aux==0)
    {
        printf("El valor %d no se ha encontrado en el vector\n",val);
    }
    
    
}