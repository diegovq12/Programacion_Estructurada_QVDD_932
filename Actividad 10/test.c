#include "namesddqv.h"
#include <stdio.h>

int main()
{
    srand(time(NULL));
    char apellidopat[30];
    char apellidomat[30];
    char nombre[30];

    genLastName(apellidopat);
    printf("Apellido Paterno: %s\n",apellidopat);
    genLastName(apellidomat);
    printf("Apellido Materno: %s\n",apellidomat);
    genName(nombre);
    printf("Nombre(s): %s\n",nombre);

}