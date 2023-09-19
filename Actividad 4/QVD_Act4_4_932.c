#include <stdio.h>

//Diego Demian Quiros Vicencio
// 08/30/2023
/* Programa que sirva para calcular el salario semanal de un trabajador donde se obtiene
como dato de entrada las ​ horas semanales​ trabajadas, el ​ salario por hora​ */

int main(){

    int hrs;
    float salario,extra,extra2;
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\tPAGOS UABC\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Ingrese el salario por hora: ");scanf("%f",&salario); 
    printf("Ingrese las horas trabajadas: ");scanf("%d",&hrs); 

    if (hrs<=40)
    {
        salario=salario*hrs;
    }
    else if (hrs>40 && hrs<=49)
    {
        extra=salario*2;
        salario=salario*40;
        salario=salario+(extra*(hrs-40));
    }
    else if (hrs>=50)
    {
        extra=salario*2;
        extra2=salario*3;
        salario=salario*40;
        salario=salario+(extra*(hrs-40)+(extra2*(hrs-49)));
    }

    printf("El salario total es de: %.2f pesos\n",salario);
    printf("Horas trabajadas: %d horas",hrs);

    return 0;
}