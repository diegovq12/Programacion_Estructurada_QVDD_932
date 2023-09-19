#include <stdio.h>

//Diego Demian Quiros Vicencio
// 08/26/2023
// Leer 4 calificaciones y desplegar la situacion del alumno
//Anidado por el verdadero

int main(){

    int calif1,calif2,calif3,calif4,promedio;

    printf("Ingresa tus 3 calificaciones: ");scanf("%d %d %d",&calif1,&calif2,&calif3);

    promedio= (calif1+calif2+calif3)/3;

    if (promedio<30)
    {
        printf("Repetira");
    }
    else if (promedio>=30 && promedio<60)
    {
        printf("Extraordinario");
    }
    else if (promedio>=60 && promedio<70)
    {
        printf("Suficiente");
    }
    else if (promedio>=70 && promedio<80)
    {
        printf("Regular");
    }
    else if (promedio>=80 && promedio<90)
    {
        printf("Bien!");
    }
    else if (promedio>=90 && promedio<98)
    {
        printf("Muy bien!");
    }
    else if (promedio>=98 && promedio<100)
    {
        printf("Excelente! Muy bien!");
    }
    else if(promedio<100)
    {
        printf("Error~");
    }
    
    return 0;
}