/*
Quiros Vicencio Diego Demian
10/10/23(creado)
Actividad 10. FUNCIONES y METODOS DE ORDENACION Y BUSQUEDA
ESTRUCTURAS Y LIBRERIAS
*/ 


//Librerias utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "ddqvval.h"
#include "ddqvSort.h" 
#include "namesddqv.h"
//********************
#define REG_MAX 25
typedef struct _alum
{
    int status;
    int matricula;
    char apPat[30];
    char apMat[30];
    char nombre[30];
    int edad;
    int sexo;
}Talumn;

//Prototitpos
void menu (void);
int msge (void);

void fillAtmreg(Talumn vect_alum[],int indexNumber);
void fillRegManual(Talumn vect_alum[],int indexNumber);
void printRegs(Talumn vect_alumn[],int indexNumber);
void sortIds (Talumn vector[],int m);
int searchId (Talumn vector[],int m, int val);
//***************


int main ()
{
    srand(time(NULL));
    menu();
    return 0;
}

//num=min + rand() % (max - min + 1);



int msge (void)
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
    op=validInt(0,6,"","Rango Incorrecto");
    
    return op;
}

void menu (void)
{
    int op,num,id;
    Talumn _alum[500];
    int indexNumber = 0;
    do
    {

        system("CLS");

        op=msge();
        
        switch (op)
        {
        case 1:
            if(indexNumber+10 <= REG_MAX)
            {
                for (int i = 0; i < 10; i++)
                {
                    fillAtmreg(_alum,indexNumber);
                    indexNumber++; 
                }
            }   
            else
            {
                printf("Llegaria al Maximo de Alumnos, Podria registrar manualmente a %d alumnos mas",REG_MAX-indexNumber);
            }

            break;
        case 2:
           fillRegManual(_alum,indexNumber);
           indexNumber++;
            break;
        case 3:
           
            break;
        case 4:
            printf("Ingresa matricula a buscar: ");
            id=validInt(300000,399999,"","Numero invalido\n");
            num =  searchId(_alum,indexNumber,id);
            if (num != -1)
            {
                printRegs(_alum,1);
            }
            else
            {
                printf("Esa matricula no esta registrada\n");
            }
            
            break;
        case 5:
            sortIds(_alum,indexNumber);
            break;
        case 6:
            printRegs(_alum,indexNumber);
            break;
        default:
            break;
        }
        system("PAUSE");
    } while (op!=0);   
}



/*
    Funcion que llena 10 registros de forma automatica
    osea con valores aleatorios utilizando una lista de
    nombres y apellidos
*/
void fillAtmreg(Talumn vect_alum[],int indexNumber)
{
    //generar matricula y status
    vect_alum[indexNumber].status=1;
    vect_alum[indexNumber].matricula=300000 + rand() % (399999 - 300000 + 1);
    //Generar Nombre y apellidos
    genLastName(vect_alum[indexNumber].apPat);
    genLastName(vect_alum[indexNumber].apMat);
    genName(vect_alum[indexNumber].nombre);
    //Generar Otros datos
    vect_alum[indexNumber].edad= 17 +rand() % (40-17+1);
    vect_alum[indexNumber].sexo=sexDetect(vect_alum[indexNumber].nombre);
    indexNumber++;
}

void fillRegManual(Talumn vect_alum[],int indexNumber)
{
    char name[30];

    vect_alum[indexNumber].status=1;
    printf("Llenado Manual\n");
    printf("Ingresa Matricula: ");
    vect_alum[indexNumber].matricula=validInt(300000,399999,"","Rango Incorrecto\n");
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
    vect_alum[indexNumber].edad=validInt(17,99);
    printf("Ingresa sexo 1] Hombre 2] Mujer: ");
    vect_alum[indexNumber].sexo=validInt(1,2);
    indexNumber++;
}

void printRegs(Talumn vect_alumn[],int index)
{
    int i;
    char sexo[2][10]={"Hombre","Mujer"};
    char sexalumn[10];
    printf("Matricula         ApPat              ApMat           Nombre                 Edad      Sexo\n");

    for (i = 0; i < index; i++)
    {   
        if (vect_alumn[i].sexo == 1)
        {
            strcpy(sexalumn,sexo[0]);
        }
        else
        {
            strcpy(sexalumn,sexo[1]);

        }
    
        printf("%-6d          %-15s   %-15s  %-25s%2d        %-10s\n", vect_alumn[i].matricula, vect_alumn[i].apPat,vect_alumn[i].apMat,vect_alumn[i].nombre, vect_alumn[i].edad, sexalumn);
        /*
        printf("Status: %d\n",vect_alumn[i].status);
        printf("Matricula: %d\n",vect_alumn[i].matricula );
        printf("Apellido Paterno: %s\n",vect_alumn[i].apPat);
        printf("Apellido Materno: %s\n",vect_alumn[i].apMat);
        printf("Nombre(s): %s\n",vect_alumn[i].nombre);
        */
    }
}

void sortIds (Talumn vector[],int m)
{
    int i,j;
    int aux;

    for ( i = 0; i < m-1; i++)
    {
        for (j = i+1; j < m; j++)
        {
            if(vector[i].matricula>vector[j].matricula)
            {
                aux=vector[i].matricula;
                vector[i].matricula=vector[j].matricula;
                vector[j].matricula=aux;
            }
        }
    }
}

int searchId (Talumn vector[],int m, int val)
{
    int i;

    for (i = 0; i < m; i++)
    {
        if (vector[i].matricula==val)
        {
            return i;
        }
    }
    return -1;
}

