#include <stdio.h>

//Diego Demian Quiros Vicencio
// 08/26/2023
// Algoritmo que lea 4 calificaciones e imprima si esta aprobado o reprobado


int main(){

    int calif1,calif2,calif3,calif4,promedio;

    printf("Ingresa tus 4 calificaciones: ");scanf("%d %d %d %d",&calif1,&calif2,&calif3,&calif4);

    promedio= (calif1+calif2+calif3+calif4)/4;


    if(promedio>=60){

        printf("El alumno Aprobo!");
    }
    else{

        printf("El alumno esta reprobado");
    }

    return 0; 
}