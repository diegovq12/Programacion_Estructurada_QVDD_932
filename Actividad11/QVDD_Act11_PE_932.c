#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "ddqvval.h"

#define FALSE 0
#define TRUE 1

#define MAX_REG 50
#define AGG_REG 10

typedef struct _nombreCompleto
{
    char apellidoPat[50];
    char apellidoMat[50];
    char nombre[50];
} TnombreCompleto;

typedef struct _fecha
{
    int anio;
    int mes;
    int dia;
} Tfecha;

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
} Testudiante;

// prototipos
void menu(void);
int msges(void);
//*************

int main()
{

    return 0;
}

int msges(void)
{
    int op;
    printf("\n R E G I S T R O S U A B C\n");
    printf("1.- AGREGAR\n");
    printf("2.- ELIMINAR REGISTRO\n");
    printf("3.- BUSCAR\n");
    printf("4.- ORDENAR\n");
    printf("5.- IMPRIMIR\n");
    printf("5.- ARCHIVO TEXTO");
    printf("0. Salir\n");
    op = validInt(0, 5, "Ingresa funcion a utilizar:\n", "Opcion Invalida");

    return op;
}

void menu(void)
{
    int num, ordenado = 0;
    int indice = 0;
    Testudiante alumno[2000];
    int op;

    do
    {
        system("CLS");
        op = msges();

        switch (op)
        {
        case 1:
            // MENU AGREGAR
            do
            {
                op = msgesAgregar();
                system("CLS");

                switch (op)
                {
                case 1:
                    // llenarRegistroManual(alumno, indice);
                    indice++;
                    ordenado = 0;
                    break;
                case 2:
                    if (indice + AGG_REG <= MAX_REG)
                    {
                        for (int i = 0; i < AGG_REG; i++)
                        {
                            // llenarRegistroAutomatico(alumno, indice);
                            indice++;
                            ordenado = 0;
                        }
                    }

                    break;

                default:
                    break;
                }
            } while (op != 3);

            break;
        case 2:
            // eliminarRegistros
            break;
        case 3:
            // buscarRegistros
            break;
        case 4:
            // ordenarRegistros
            break;
        case 5:
            // imprimirRegistros
            break;
        case 6:
            // archivoTextp
            break;
        default:
            break;
        }

    } while (op != 0);
}

int msgesAgregar(void)
{
    int op;
    printf("\nM E N U A G R E G A R\n");
    printf("1.- AGREGAR MANUAL\n");
    printf("2.- AGREGAR AUTOMATICO\n");
    printf("3.- Regresar\n");
    op = validInt(1, 3, "Ingresa funcion a utilizar:\n", "Opcion Invalida");
    return op;
}

void llenarRegistroManual(Testudiante vectorAlumno[], int indice)
{
    int correcto = 0;
    vectorAlumno[indice].status = 1;
    printf("LLENADO MANUAL\n");
    int i;

    do
    {
        vectorAlumno[indice].matricula = validInt(300000, 399999, "MATRICULA: ", "MATRICULA FUERA DE RANGO\n");
        i = searchLinearId(vectorAlumno, indice, vectorAlumno[indice].matricula);
        if (i != -1)
        {
            printf("MATRICULA YA REGISTRADA\n");
        }
    } while (i != -1);

    printf("APELLIDO PATERNO: ");
    fflush(stdin);
    gets(vectorAlumno[indice].nombreCompleto.apellidoPat);
    do
    {
        correcto = validString(vectorAlumno[indice].nombreCompleto.apellidoPat);
        if (correcto == 0)
        {
            printf("ERROR - REINGRESA CORRECTAMENTE LOS DATOS.\n");
            printf("APELLIDO PATERNO: ");
            fflush(stdin);
            gets(vectorAlumno[indice].nombreCompleto.apellidoPat);
        }
    } while (correcto == 0);
    capitalizeWords(vectorAlumno[indice].nombreCompleto.apellidoPat);

    printf("APELLIDO MATERNO: ");
    fflush(stdin);
    gets(vectorAlumno[indice].nombreCompleto.apellidoMat);
    do
    {
        correcto = validString(vectorAlumno[indice].nombreCompleto.apellidoMat);
        if (correcto == 0)
        {
            printf("ERROR - REINGRESA CORRECTAMENTE LOS DATOS.\n");
            printf("APELLIDO PATERNO: ");
            fflush(stdin);
            gets(vectorAlumno[indice].nombreCompleto.apellidoMat);
        }
    } while (correcto == 0);
    capitalizeWords(vectorAlumno[indice].nombreCompleto.apellidoMat);

    printf("NOMBRE: ");
    fflush(stdin);
    gets(vectorAlumno[indice].nombreCompleto.nombre);
    do
    {
        correcto = validString(vectorAlumno[indice].nombreCompleto.nombre);
        if (correcto == 0)
        {
            printf("ERROR - REINGRESA CORRECTAMENTE LOS DATOS.\n");
            printf("NOMBRE: ");
            fflush(stdin);
            gets(vectorAlumno[indice].nombreCompleto.nombre);
        }
    } while (correcto == 0);
    capitalizeWords(vectorAlumno[indice].nombreCompleto.nombre);
    // Minimo de edad para registrarse seran 16 anios por eso despues de 2007 no permitira registro
    vectorAlumno[indice].nacimiento.anio = validInt(1900, 2007, "ANIO DE NACIMIENTO: ", "INVALIDO - REINGRESAR");

    correcto = 0;
    do
    {
        vectorAlumno[indice].nacimiento.mes = validInt(1, 12, "ANIO DE NACIMIENTO: ", "INVALIDO - REINGRESAR");
    } while (correcto == 0);

    vectorAlumno[indice].edad = validInt(17, 99, "EDAD: ", "EDAD INVALIDA\n");
}

int searchLinearId(Testudiante vector[], int m, int val)
{
    int i;

    for (i = 0; i < m; i++)
    {
        if (vector[i].matricula == val)
        {
            return i;
        }
    }
    return -1;
}

int binarySearchId(Testudiante vect[], int val, int start, int end)
{
    int mid;

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (vect[mid].matricula == val)
        {
            return mid;
        }
        else if (val < vect[mid].matricula)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return -1;
}

int validarDia(int anio, int mes)
{
    int dia;
    // determinar anio bisiesto
    int bisiesto = FALSE;

    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
    {
        dia = validInt(1, 31,"DIA DE NACIMIENTO (1 - 31): ", "INVALIDO - FUERA DE RANGO");
    }

    if (mes == 2)
    {
        if ((anio % 4 == 0 && anio % 100 != 0) || anio == 2000 || anio == 1000)
        {
            bisiesto = TRUE;
        }
        if(bisiesto == TRUE)
        {
            printf("DIA DE NACIMIENTO (1 - 29): ");   
            dia = validInt(1, 29,"DIA DE NACIMIENTO (1 - 31): ", "INVALIDO - FUERA DE RANGO");        
        }
        else
        {
            printf("DIA DE NACIMIENTO (1 - 28): ");
            dia = validInt(1, 28,"DIA DE NACIMIENTO (1 - 31): ", "INVALIDO - FUERA DE RANGO");
        }
    }

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        printf("DIA DE NACIMIENTO (1 - 30): ");
        dia = validInt(1, 30,"DIA DE NACIMIENTO (1 - 31): ", "INVALIDO - FUERA DE RANGO");
    }
}