#include <stdio.h>

//Diego Demian Quiros Vicencio
// 08/30/2023
//Programa que lea 6 números, desplegar el valor del número mayor.

int main(){

    int mayor,n1,n2,n3,n4,n5,n6;

    printf("Ingresa 6 numeros: ");
    scanf("%d %d %d %d %d %d",&n1,&n2,&n3,&n4,&n5,&n6);
    
    mayor=n1;

    if (n2>mayor)
    {
        mayor=n2;
    }

    if (n3>mayor)
    {
        mayor=n3;
    }
    if (n4>mayor)
    {
        mayor=n4;
    }
           
    if (n5>mayor)
    {
        mayor=n5;
    }
                
    if (n6>mayor)
    {
        mayor=n6;  
    }
                    
    
    printf("El numero mayor es= %d",mayor);

    return 0;
}