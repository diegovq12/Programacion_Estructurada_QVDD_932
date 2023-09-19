#include <stdio.h>

//Diego Demian Quiros Vicencio
// 08/26/2023
// Leer 3 calificaciones y desplegar la situacion del alumno
//Anidado por el falso

int main(){

    int calif1,calif2,calif3,calif4,prom;

    printf("Ingresa tus 3 calificaciones: ");scanf("%d %d %d",&calif1,&calif2,&calif3);

    prom= (calif1+calif2+calif3)/3;

    if (prom<100)
    {
        printf("Error en promedio");
    }
    else if (prom >=98 && prom <=100)
    {
        printf("Excelente!");
    }
    else if (prom>=90  && prom <98)
    {
        printf("Muy bien!");
    }
    else if (prom >=80 && prom <90)
    {
        printf("Bien");
    }
    else if (prom >=70 && prom <80)
    {
        printf("Regular");
    }
    else if ( prom >=60 && prom <70)
    {
        printf("Suficiente");
    }
    else if ( prom>=30 && prom <60 )
    {
        printf("Extraordinario");
    }
    else if(prom < 30 )
    {
        printf("Repetira");
    }
    
    return 0;
}