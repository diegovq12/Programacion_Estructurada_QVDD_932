/*
Quiros Vicencio Diego Demian
10/10/23(creado)
Actividad 10. FUNCIONES y METODOS DE ORDENACION Y BUSQUEDA
ESTRUCTURAS Y LIBRERIAS
*/

// Librerias utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "ddqvval.h" //propia
#include "namesddqv.h"//propia
//********************
#define REG_MAX 500
typedef struct _alum
{
    int status;
    int matricula;
    char apPat[35];
    char apMat[35];
    char nombre[50];
    int edad;
    int sexo;
} Talumn;

// Prototitpos
void menu(void);
int msge(void);

void fillAtmreg(Talumn vect_alum[], int indexNumber);
void fillRegManual(Talumn vect_alum[], int indexNumber);
void printRegs(Talumn vect_alumn[], int indexNumber);
void sortIds(Talumn vector[], int m);
int searchLinearId(Talumn vector[], int m, int val);
int binarySearchId(Talumn vect[], int val, int start, int end);
void printIndividualRegs(Talumn vect_alumn[], int index);
//***************

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

// num=min + rand() % (max - min + 1);

int msge(void)
{
    int op;
    printf("\n R E G I S T R O S U A B C\n");
    printf("1.- AGREGAR (AUTOM 10 REGISTROS)\n");
    printf("2.- AGREGAR MANUAL \n");
    printf("3.- ELIMINAR REGISTRO\n");
    printf("4.- BUSCAR\n");
    printf("5.- ORDENAR\n");
    printf("6.- IMPRIMIR\n");
    printf("0. Salir\n");
    printf("Ingresa funcion a utilizar:\n");
    op = validInt(0, 6, "Opcion Invalida");

    return op;
}

void menu(void)
{
    int op, num, id, sorted = 0;
    Talumn _alum[500];
    int indexNumber = 0;
    do
    {

        system("CLS");

        op = msge();

        switch (op)
        {
        case 1:
            if (indexNumber + 10 <= REG_MAX)
            {
                for (int i = 0; i < 10; i++)
                {
                    fillAtmreg(_alum, indexNumber);
                    indexNumber++;
                    sorted = 0;
                }
            }
            else
            {
                printf("Llegaria al Maximo de Alumnos, Podria registrar manualmente a %d alumnos mas\n", REG_MAX - indexNumber);
            }

            break;
        case 2:
            fillRegManual(_alum, indexNumber);
            indexNumber++;
            sorted = 0;
            break;
        case 3:
            printRegs(_alum, indexNumber);
            printf("Ingresa matricula a dar de baja: ");
            id = validInt(300000, 399999, "Matricula fuera de rango");
            num = searchLinearId(_alum, indexNumber, id);
            if (num != -1)
            {
                _alum[num].status = 0;
                printf("Alumno dado de baja.\n");
            }
            else
            {
                printf("Esa matricula no esta registrada\n");
            }
            break;
        case 4:

            printf("Ingresa matricula a buscar: ");
            id = validInt(300000, 399999, "Numero invalido\n");
            if (sorted == 0)
            {
                num = searchLinearId(_alum, indexNumber, id);
                if (num != -1)
                {
                    printIndividualRegs(_alum, num);
                }
                else
                {
                    printf("Esa matricula no esta registrada\n");
                }
            }
            else
            {
                num = binarySearchId(_alum, id, 0, indexNumber);
                if (num != -1)
                {
                    printIndividualRegs(_alum, num);
                }
                else
                {
                    printf("Esa matricula no esta registrada\n");
                }
            }

            break;
        case 5:
            if (sorted == 0)
            {
                sortIds(_alum, indexNumber);
                sorted = 1; // Bandera que indica si los registros estan ordenados o no
            }
            else
            {
                printf("Registros Actualmente ordenados\n");
            }
            break;
        case 6:
            printRegs(_alum, indexNumber);
            break;
        case 0:
            printf("Fin del programa\n");
            break;
        default:
            break;
        }
        system("PAUSE");
    } while (op != 0);
}

/*
    Funcion que llena 10 registros de forma automatica
    osea con valores aleatorios utilizando una lista de
    nombres y apellidos
*/
void fillAtmreg(Talumn vect_alum[], int indexNumber)
{
    int i, id;
    // generar matricula y status
    vect_alum[indexNumber].status = 1;

    do
    {
        id = 300000 + rand() % (399999 - 300000 + 1);
        i = searchLinearId(vect_alum, indexNumber, id);
    } while (i != -1);

    vect_alum[indexNumber].matricula = id;
    // Generar Nombre y apellidos
    genLastName(vect_alum[indexNumber].apPat);
    genLastName(vect_alum[indexNumber].apMat);
    genName(vect_alum[indexNumber].nombre);
    // Generar Otros datos
    vect_alum[indexNumber].edad = 17 + rand() % (40 - 17 + 1);
    vect_alum[indexNumber].sexo = sexDetect(vect_alum[indexNumber].nombre);
    indexNumber++;
}

// Funcion que permite al usuario ingresar los datos para llenar un registro
void fillRegManual(Talumn vect_alum[], int indexNumber)
{
    int correct = 0;
    vect_alum[indexNumber].status = 1;
    printf("Llenado Manual\n");
    int i;
    do
    {
        printf("Ingresa Matricula: ");

        vect_alum[indexNumber].matricula = validInt(300000, 399999, "Matricula Fuera de Rango\n");
        i = searchLinearId(vect_alum, indexNumber, vect_alum[indexNumber].matricula);
        if (i != -1)
        {
            printf("Matricula Ya Registrada\n");
        }

    } while (i != -1);

    printf("Ingresa Apellido Paterno: ");
    fflush(stdin);
    gets(vect_alum[indexNumber].apPat);
    do
    {
        correct = validSingleString(vect_alum[indexNumber].apPat);
        if (correct == 0)
        {
            printf("Error - Reingresa correctamente los datos\n");
            printf("Ingresa Apellido Paterno: ");
            fflush(stdin);
            gets(vect_alum[indexNumber].apPat);
        }
    } while (correct == 0);
    capitalizeWords(vect_alum[indexNumber].apPat);

    printf("Ingresa Apellido Materno: ");
    fflush(stdin);
    gets(vect_alum[indexNumber].apMat);
    do
    {
        correct = validSingleString(vect_alum[indexNumber].apMat);
        if (correct == 0)
        {
            printf("Error - Reingresa correctamente los datos\n");
            printf("Ingresa Apellido Materno: ");
            fflush(stdin);
            gets(vect_alum[indexNumber].apMat);
        }
    } while (correct == 0);
    capitalizeWords(vect_alum[indexNumber].apMat);

    printf("Ingresa Nombre: ");
    fflush(stdin);
    gets(vect_alum[indexNumber].nombre);
    do
    {
        correct = validString(vect_alum[indexNumber].nombre);
        if (correct == 0)
        {
            printf("Error - Reingresa correctamente los datos\n");
            printf("Ingresa Nombre: ");
            fflush(stdin);
            gets(vect_alum[indexNumber].nombre);
        }
    } while (correct == 0);
    capitalizeWords(vect_alum[indexNumber].nombre);

    printf("Ingresa Edad: ");
    vect_alum[indexNumber].edad = validInt(17, 99, "Edad invalida\n");
    printf("Ingresa sexo 1] Hombre 2] Mujer: ");
    vect_alum[indexNumber].sexo = validInt(1, 2, "Opcion invalida");
    indexNumber++;
}

/*
Funcion que imprimira todos los registros existentes
cuyo status sea igual a 1
*/
void printRegs(Talumn vect_alumn[], int index)
{
    int i;
    char sexo[2][10] = {"Hombre", "Mujer"};
    char sexalumn[10];
    printf("Matricula         ApPat              ApMat           Nombre                 Edad      Sexo\n");

    for (i = 0; i < index; i++)
    {
        if (vect_alumn[i].sexo == 1)
        {
            strcpy(sexalumn, sexo[0]);
        }
        else
        {
            strcpy(sexalumn, sexo[1]);
        }
        if (vect_alumn[i].status == 1)
        {
            printf("%-6d          %-15s   %-15s  %-25s%2d        %-10s\n", vect_alumn[i].matricula, vect_alumn[i].apPat, vect_alumn[i].apMat, vect_alumn[i].nombre, vect_alumn[i].edad, sexalumn);
        }
    }
}

/*
Funcion que sirve para ordenar la lista desordenada
mediante el metodo de la burbuja mejorada
*/
void sortIds(Talumn vector[], int m)
{
    int i, j;
    int aux;

    for (i = 0; i < m - 1; i++)
    {
        for (j = i + 1; j < m; j++)
        {
            if (vector[i].matricula > vector[j].matricula)
            {
                aux = vector[i].matricula;
                vector[i].matricula = vector[j].matricula;
                vector[j].matricula = aux;
            }
        }
    }
}

/*
Funcion que busca el indice de una matricula e
imprime todos los datos de esta
*/
int searchLinearId(Talumn vector[], int m, int val)
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

int binarySearchId(Talumn vect[], int val, int start, int end)
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

void printIndividualRegs(Talumn vect_alumn[], int index)
{
    int i;
    char sexo[2][10] = {"Hombre", "Mujer"};
    char sexalumn[10];
    printf("Matricula         ApPat              ApMat           Nombre                 Edad      Sexo\n");

    for (i = 0; i < 1; i++)
    {
        if (vect_alumn[index].sexo == 1)
        {
            strcpy(sexalumn, sexo[0]);
        }
        else
        {
            strcpy(sexalumn, sexo[1]);
        }
        if (vect_alumn[index].status == 1)
        {
            printf("%-6d          %-15s   %-15s  %-25s%2d        %-10s\n", vect_alumn[index].matricula, vect_alumn[index].apPat, vect_alumn[index].apMat, vect_alumn[index].nombre, vect_alumn[index].edad, sexalumn);
        }
    }
}