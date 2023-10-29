#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct _nombreCompleto
{
    char apellidoPat[50];
    char apellidoMat[50];
    char nombre[50];
}TnombreCompleto;

typedef struct _fecha
{
    int anio;
    int mes;
    int dia;
}Tfecha;

typedef struct _estudiante
{
    int status;
    int matricula;
    TnombreCompleto nombreCompleto;
    Tfecha nacimiento;
    int edad;
    int sexo;
    int estado;
    char curp[9];
}Testudiante;


int main()
{

    return 0;
}