#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "namesddqv.h"

typedef struct _alumm
{
    int status;
    int matricula;
    char apPat[30];
    char apMat[30];
    char nombre[30];
    int edad;
    int sexo;
}Talumn;


/*
    Funcion que llena 10 registros de forma automatica
    osea con valores aleatorios utilizando una lista de
    nombres y apellidos
*/
Talumn fillAtmreg(Talumn _alumm, Talumn vect_alum[])
{
    for (int i = 0; i < 10 ; i++)
    {
        vect_alum[i].status=1;
        vect_alum[i].matricula=3000 + rand() % (39999 - 3000 + 1);
        genLastName(vect_alum[i].apPat);
        genLastName(vect_alum[i].apMat);
        genLastName(vect_alum[i].nombre);
        vect_alum[i].edad= 17 +rand() % (40-17+1);
        vect_alum[i].sexo= rand() % 2 + 1;
    }
    
}

