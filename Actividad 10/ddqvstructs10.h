#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "namesddqv.h"

int indexNumber = 0;
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
void fillAtmreg(Talumn vect_alum[],int indexNumber)
{
    for (int i = 0; i < 10 ; i++)
    {
        vect_alum[indexNumber].status=1;
        vect_alum[indexNumber].matricula=300000 + rand() % (399999 - 300000 + 1);
        genLastName(vect_alum[indexNumber].apPat);
        genLastName(vect_alum[indexNumber].apMat);
        genName(vect_alum[indexNumber].nombre);
        vect_alum[indexNumber].edad= 17 +rand() % (40-17+1);
        vect_alum[indexNumber].sexo=sexDetect(vect_alum[indexNumber].nombre,vect_alum[indexNumber].sexo);
        indexNumber++;
    }
}

void fillRegManual(Talumn vect_alum[],int indexNumber)
{
    char name[30];
    int temp;   
    vect_alum[indexNumber].status=1;
    printf("Llenado Manual\n");
    printf("Ingresa Matricula: ");
    vect_alum[indexNumber].matricula=validInt(300000,399999);
    printf("Ingresa Apellido Paterno: ");
    fflush(stdin);
    gets(name);
    strcpy(vect_alum[indexNumber].apPat,name);
    printf("Ingresa Apellido Materno: ");
    fflush(stdin);
    gets(name);
    strcpy(vect_alum[indexNumber].apMat,name);
    printf("Ingresa Nombre: ");
    fflush(stdin);
    gets(name);
    strcpy(vect_alum[indexNumber].nombre,name);
    printf("Ingresa Edad: ");
    temp=validInt(17,99);
    printf("Ingresa sexo 1] Hombre 2] Mujer: ");
    temp=validInt(1,2);
    indexNumber++;
}

void printRegs(Talumn vect_alumn[],int indexNumber)
{
    printf("Status    Matricula         ApPat              ApMat             Nombre     Edad  Sexo\n");
    for (int i = 0; i < indexNumber + 1; i++)
    {   
        printf("%d          %-6d          %-15s   %-15s  %-15s%2d  %d\n",vect_alumn[i].status, vect_alumn[i].matricula, vect_alumn[i].apPat,vect_alumn[i].apMat,vect_alumn[i].nombre, vect_alumn[i].edad, vect_alumn[i].sexo);
        /*
        printf("Status: %d\n",vect_alumn[i].status);
        printf("Matricula: %d\n",vect_alumn[i].matricula );
        printf("Apellido Paterno: %s\n",vect_alumn[i].apPat);
        printf("Apellido Materno: %s\n",vect_alumn[i].apMat);
        printf("Nombre(s): %s\n",vect_alumn[i].nombre);
        */
    }
}
