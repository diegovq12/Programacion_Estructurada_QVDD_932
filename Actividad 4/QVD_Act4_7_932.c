#include <stdio.h>

// Diego Demian Quiros Vicencio
// 08/29/2023
// Promedio de examenes donde el de menor calificacion se elimina

int main(){

    float promedio;
    float calif1,calif2,calif3,calif4,calif5,menor;

    printf("Ingresar promedios de los examenes parciales: ");
    scanf("%f %f %f %f %f",&calif1,&calif2,&calif3,&calif4,&calif5);

    menor=calif5;
  
    if (calif4<menor)
    {
        menor=calif4;
    }
    if (calif3<menor)
    {
        menor=calif3;
    }
    if (calif2<menor)
    {
        menor=calif2;
    }
    if (calif1<menor)
    {
        menor=calif1;
    }
    
    promedio=(calif1+calif2+calif3+calif4+calif5-menor)/4;
    printf("Promedio= %.2f",promedio);

    return 0;
}