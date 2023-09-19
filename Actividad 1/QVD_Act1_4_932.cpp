#include <stdio.h>

//Diego Demian Quiros Vicencio
// 08/26/2023
//Algoritmo que pide ingresar una opcion y determinar tu sexo

int main(){

    int sexo;

    printf("\tIngresa tu sexo:\n ");
    printf("1) Hombre\t2) Mujer");
    scanf("\n%d",&sexo);
    switch (sexo)
    {
    case 1:
        printf("Hola! Eres Hombre");
        break;
    case 2:
        printf("Hola! Eres Mujer");
        break;
    default:
        printf("HOMBRE O MUJER");
        break;
    }

    return 0;
}