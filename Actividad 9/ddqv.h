#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void llena_vectorRandom (int vector[],int m,int ri,int rf)
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
    printf("\nEl Vector  ha sido llenado con valores del %d hasta %d\n",ri,rf);
}