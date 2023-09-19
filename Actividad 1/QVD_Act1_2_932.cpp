#include <stdio.h>

//Diego Demian Quiros Vicencio
// 08/26/2023
//Ingresar un numero y determinar si es par o impar

int main(){

    int num;

    printf("Ingresa un numero: ");scanf("%d",&num);

    if (num%2==0)
    {
        printf("El numero %d es PAR", num);
    }
    else{
        printf("El numero %d es IMPAR", num);
    }
    
    return 0;
}