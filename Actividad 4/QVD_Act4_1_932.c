#include <stdio.h>

//Diego Demian Quiros Vicencio
// 08/29/2023
// Programa que use un menu para realizar una de las 4 operaciones basicas

void menu(){
    
    printf("~~~~~~~~~~~~~~~");    
    printf("\n\tCalculadora\n");
    printf("~~~~~~~~~~~~~~");
    printf("\n1. Suma");
    printf("\n2. Resta");
    printf("\n3. Multiplicacion");
    printf("\n4. Division");
    printf("\nIngrese la operacion a realizar: ");
}

int main(){
    int op,n1,n2,resultado;
    menu();
    scanf("%d",&op);

    printf("Ingresa 2 numeros: ");scanf("%d %d",&n1,&n2);

    if (op==1)
    {
        resultado=n1+n2;
        printf("Resultado= %d",resultado);
    }
    else
    {
        if (op==2)
        {
            resultado=n1-n2;
            printf("Resultado= %d",resultado);
        }
        else
        {
            if (op==3)
            {
                resultado=n1*n2;
                printf("Resultado= %d",resultado);    
            }
            else
            {
                if (op==4)
                {
                    if (n2!=0)
                    {
                        resultado=n1/n2;
                        printf("Resultado= %d",resultado);

                    }
                    else
                    {
                        printf("Error: Division entre 0");
                    }
                }
                
            }
        }   
    }
        


    return 0;
}