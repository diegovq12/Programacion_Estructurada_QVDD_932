#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "namesddqv.h"
#include "ddqvval.h"

/*
Quiros Vicencio Diego Demian
28/10/23(creado) - 01/11/23 (modificado)
ACTIVIDAD 11
FUNCIONES y METODOS DE ORDENACION Y BUSQUEDA
ESTRUCTURAS Y LIBRERIAS
*/

#define FALSE 0
#define TRUE 1

#define MAX_REG 2000
#define AGG_REG 100

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
    char curp[19];
} Testudiante;

// prototipos
void menu(void);
int msges(void);

void llenarRegistroManual(Testudiante vectorAlumno[], int indice);
int msgesAgregar(void);
int searchLinearId(Testudiante vector[], int m, int val);
int binarySearchId(Testudiante vect[], int val, int start, int end);
int validarDia(int anio, int mes);
int generarDiaAleatorio(int anio, int mes);
int genEdo(void);
void imprimirRegistros(Testudiante vector[], int indice);
void imprimirRegistroIndividual(Testudiante vector[], int indice);
void llenarRegistroATM(Testudiante vector[], int indice);
void ordenarMatriculas(Testudiante vector[], int m);
void escrbirArchivo(char *nombreArchivo, Testudiante vector[], int indice);
void quikSort(Testudiante lista[], int indice);
void qs(Testudiante lista[], int limiteIzquierdo, int limiteDerecho);

// FUNCIONES PARA CURP
void curp(Testudiante vector[], char curp[], int indice);
char letraNombre(char nombre[]);
int validarNombres(char nombre[]);
void separarNombres(char nombre[], char primerNombre[], char otrosNombres[]);
int validarPreposiciones(char nombre[]);
char consonanteApellido(char apellido[]);
char primeraVocal(char nombre[]);
void obtenerCodigoEdo(char codigo[], int estado);
char buscarSegundaConsonante(char cad[]);
char consonanteNombres(char nombre[]);
void obtenerHomonimia(int anio, char homonimia[]);
char buscarPrimeraConsonante(char cadena[]);
char vocalApellido(char apellido[]);
void validarPalabrasAltisonantes(char curp[]);
void validarCaracteresEspeciales(char cadena[]);

//*************

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

int msges(void)
{
    int op;
    printf("R E G I S T R O S U A B C\n");
    printf("1.- AGREGAR\n");
    printf("2.- ELIMINAR REGISTRO\n");
    printf("3.- BUSCAR\n");
    printf("4.- ORDENAR\n");
    printf("5.- IMPRIMIR\n");
    printf("6.- ARCHIVO TEXTO\n");
    printf("0. Salir\n");
    op = validInt(0, 6, "INGRESA FUNCION A UTILIZAR: ", "OPCION INVALIDA");

    return op;
}

void menu(void)
{
    int num, matricula;
    int ordenado = 0;
    int indice = 0;
    Testudiante alumno[2005];
    int correcto;
    char nombreArchivo[30];
    int op, op2, maximo;

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
                system("CLS");
                op = msgesAgregar();
                system("CLS");

                switch (op)
                {
                case 1:
                    if (indice + 1 <= MAX_REG)
                    {
                        llenarRegistroManual(alumno, indice);
                        indice++;
                        ordenado = 0;
                    }
                    break;
                case 2:
                    if (indice + AGG_REG <= MAX_REG)
                    {
                        for (int i = 0; i < AGG_REG; i++)
                        {
                            llenarRegistroATM(alumno, indice);
                            indice++;
                        }
                        ordenado = 0;
                        printf("SE HAN LLENADO %d REGISTROS SATISFACTORIAMENTE\n", AGG_REG);
                    }
                    else
                    {
                        maximo = MAX_REG - indice;
                        printf("LLEGARIA AL MAXIMO DE ALUMNOS, PODRIA REGISTRAR A %d ALUMNOS MAS\n", MAX_REG - indice);
                        op2 = validInt(0, 1, "LLENAR REGISTROS AUTOMATICAMENTE (1\\SI 0\\REGRESAR): ", "VALOR INVALIDO - FUERA DE RANGO");
                        if (op2 == 1)
                        {
                            for (int i = 0; i <= MAX_REG - indice; i++)
                            {
                                llenarRegistroATM(alumno, indice);
                                indice++;
                            }
                            ordenado = 0;
                            printf("SE HAN LLENADO %d REGISTROS SATISFACTORIAMENTE\n", maximo);
                        }
                        else
                        {
                            // regresar
                        }
                    }
                    system("PAUSE");
                    break;

                default:
                    break;
                }
            } while (op != 3);
            break;
        case 2:

            matricula = validInt(300000, 399999, "INGRESAR MATRICULA A DAR DE BAJA: ", "MATRICULA FUERA DE RANGO\n");
            num = searchLinearId(alumno, indice, matricula);

            if (num != -1)
            {
                imprimirRegistroIndividual(alumno, num);
                op2 = validInt(1, 2, "DAR DE BAJA (1\\SI 2\\NO): ", "OPCION INVALIDA - FUERA DE RANGO");
                if (op2 == 1)
                {
                    alumno[num].status = 0;
                    printf("ALUMNO DADO DE BAJA.\n");
                }
            }
            else
            {
                printf("MATRICULA NO REGISTRADA\n");
            }
            system("PAUSE");
            break;
        case 3:
            matricula = validInt(300000, 399999, "INGRESAR MATRICULA A BUSCAR: ", "MATRICULA FUERA DE RANGO\n");
            if (ordenado == 0)
            {
                num = searchLinearId(alumno, indice, matricula);
                if (num != -1)
                {
                    imprimirRegistroIndividual(alumno, num);
                }
                else
                {
                    printf("MATRICULA NO REGISTRADA\n");
                }
            }
            else
            {
                num = binarySearchId(alumno, matricula, 0, indice);
                if (num != -1)
                {
                    imprimirRegistroIndividual(alumno, num);
                }
                else
                {
                    printf("MATRICULA NO REGISTRADA\n");
                }
            }
            system("PAUSE");
            break;
        case 4:
            if (indice > 100)
            {
                if (ordenado == 0)
                {
                    quikSort(alumno, indice);
                    ordenado = 1;
                }
                else
                {
                    printf("REGISTROS ACTUALMENTE ORDENADOS\n");
                }
            }
            else
            {
                if (ordenado == 0)
                {
                    ordenarMatriculas(alumno, indice);
                    ordenado = 1; // Bandera que indica si los registros estan ordenados o no
                }
                else
                {
                    printf("REGISTROS ACTUALMENTE ORDENADOS\n");
                }
            }
            system("PAUSE");
            break;
        case 5:
            imprimirRegistros(alumno, indice);
            break;
        case 6:

            printf("INGRESA NOMBRE DEL ARCHIVO: ");
            fflush(stdin);
            gets(nombreArchivo);
            do
            {
                correcto = validSingleString(nombreArchivo);
                if (correcto == 0)
                {
                    printf("ERROR - REINGRESA CORRECTAMENTE LOS DATOS.\n");
                    printf("INGRESA NOMBRE DEL ARCHIVO: ");
                    fflush(stdin);
                    gets(nombreArchivo);
                }
            } while (correcto == 0);

            escrbirArchivo(nombreArchivo, alumno, indice);
            printf("\n");
            system("PAUSE");
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
    printf("1.- AGREGAR MANUAL (1)\n");
    printf("2.- AGREGAR AUTOMATICO (%d)\n",AGG_REG);
    printf("3.- Regresar\n");
    op = validInt(1, 3, "Ingresa funcion a utilizar: ", "Opcion Invalida");
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
            printf("APELLIDO MATERNO: ");
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
    vectorAlumno[indice].nacimiento.anio = validInt(1900, 2007, "ANIO DE NACIMIENTO: ", "INVALIDO - REINGRESAR\n");

    vectorAlumno[indice].nacimiento.mes = validInt(1, 12, "MES DE NACIMIENTO: ", "INVALIDO - REINGRESAR");

    vectorAlumno[indice].nacimiento.dia = validarDia(vectorAlumno[indice].nacimiento.anio, vectorAlumno[indice].nacimiento.mes);

    vectorAlumno[indice].edad = 2023 - vectorAlumno[indice].nacimiento.anio;

    vectorAlumno[indice].sexo = validInt(1, 2, "SEXO 1) HOMBRE/ 2) MUJER: ", "INVALIDO - FUERA DE RANGO");
    vectorAlumno[indice].estado = genEdo();
    char curpalumno[19];
    curp(vectorAlumno, curpalumno, indice);
    strcpy(vectorAlumno[indice].curp, curpalumno);
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
        dia = validInt(1, 31, "DIA DE NACIMIENTO (1 - 31): ", "INVALIDO - FUERA DE RANGO");
    }

    if (mes == 2)
    {
        if ((anio % 4 == 0 && anio % 100 != 0) || anio == 2000 || anio == 1000)
        {
            bisiesto = TRUE;
        }
        if (bisiesto == TRUE)
        {
            printf("DIA DE NACIMIENTO (1 - 29): ");
            dia = validInt(1, 29, "DIA DE NACIMIENTO (1 - 31): ", "INVALIDO - FUERA DE RANGO");
        }
        else
        {
            printf("DIA DE NACIMIENTO (1 - 28): ");
            dia = validInt(1, 28, "DIA DE NACIMIENTO (1 - 31): ", "INVALIDO - FUERA DE RANGO");
        }
    }

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        printf("DIA DE NACIMIENTO (1 - 30): ");
        dia = validInt(1, 30, "DIA DE NACIMIENTO (1 - 31): ", "INVALIDO - FUERA DE RANGO");
    }

    return dia;
}

int genEdo(void)
{
    printf("ESTADOS: \n");
    printf("1.  Aguascalientes\n");
    printf("2.  BAJA CALIFORNIA\n");
    printf("3.  BAJA CALIFORNIA SUR\n");
    printf("4.  CAMPECHE \n");
    printf("5.  CHIAPAS\n");
    printf("6.  CHIHUAHUA\n");
    printf("7.  COAHUILA\n");
    printf("8.  COLIMA\n");
    printf("9.  CDMX\n");
    printf("10. DURANGO\n");
    printf("11. DF\n");
    printf("12. GUANAJUATO\n");
    printf("13. GUERRERO\n");
    printf("14  HIDALGO\n");
    printf("15. JALISCO\n");
    printf("16. MICHOACAN\n");
    printf("17. MORELOS\n");
    printf("18. NAYARIT\n");
    printf("19. NUEVO LEON\n");
    printf("20. OAXACA\n");
    printf("21. PUEBLA\n");
    printf("22. QUERETARO\n");
    printf("23. QUINTANA ROO\n");
    printf("24. SAN LUIS POTOSI\n");
    printf("25. SINALOA\n");
    printf("26. SONORA\n");
    printf("27. TABASCO\n");
    printf("28. TAMAULIPAS\n");
    printf("29. TLAXCALA\n");
    printf("30. VERACRUZ\n");
    printf("31. YUCATAN\n");
    printf("32. ZACATECAS\n");
    printf("33. EXTRANJERO\n");

    int estado = validInt(1, 33, "INGRESA ESTADO DE NACIMIENTO: ", "OPCION FUERA DE RANGO");
    return estado;
}

void imprimirRegistros(Testudiante vector[], int indice)
{
    char sexo[2][10] = {"Hombre", "Mujer"};
    char sexalumn[10];
    char estado[30];
    char estados[35][35] = {"Aguascalientes", "Baja California", "Baja California Sur", "Campeche",
                            "Chiapas", "Chihuahua", "Coahuila", "Colima", "Ciudad de Mexico/CDMX", "Durango",
                            "Estado de Mexico", "Guanajuato", "Guerrero", "Hidalgo", "Jalisco", "Michoacan", "Morelos", "Nayarit",
                            "Nuevo Leon", "Oaxaca", "Puebla", "Queretaro", "Quintana Roo", "San Luis Potosi", "Sinaloa",
                            "Sonora", "Tabasco", "Tamaulipas", "Tlaxcala", "Veracruz", "Yucatan", "Zacatecas", "Extranjero"};
   
    int i = 0;
    while (i < indice)
    {
        system("CLS");
        printf("MATRICULA   APPAT                           APMAT                            NOMBRE                            FECHA NAC    EDAD   SEXO      LUGAR NAC              CURP\n\n");
        for (int j = i; j < i + 40 && j < indice; j++)
        {
            if (vector[j].status == 1)
            {
                if (vector[j].sexo == 1)
                {
                    strcpy(sexalumn, sexo[0]);
                }
                else
                {
                    strcpy(sexalumn, sexo[1]);
                }

                strcpy(estado, estados[vector[j].estado - 1]);

                printf("%-9d   %-30s   %-30s   %-30s   %02d-%02d-%4d   %-4d   %-7s   %-20s   %-18s\n", vector[j].matricula, vector[j].nombreCompleto.apellidoPat, vector[j].nombreCompleto.apellidoMat, vector[j].nombreCompleto.nombre, vector[j].nacimiento.dia, vector[j].nacimiento.mes, vector[j].nacimiento.anio, vector[j].edad, sexalumn, estado, vector[j].curp);
            }
        }

        i += 40;
        system("PAUSE");
    }
}

void imprimirRegistroIndividual(Testudiante vector[], int num)
{
    int i;
    char sexo[2][10] = {"HOMBRE", "MUJER"};
    char sexalumn[10];
    char estado[30];
    char estados[35][35] = {"Aguascalientes", "Baja California", "Baja California Sur", "Campeche",
                            "Chiapas", "Chihuahua", "Coahuila", "Colima", "Ciudad de Mexico/CDMX", "Durango",
                            "Estado de Mexico", "Guanajuato", "Guerrero", "Hidalgo", "Jalisco", "Michoacan", "Morelos", "Nayarit",
                            "Nuevo Leon", "Oaxaca", "Puebla", "Queretaro", "Quintana Roo", "San Luis Potosi", "Sinaloa",
                            "Sonora", "Tabasco", "Tamaulipas", "Tlaxcala", "Veracruz", "Yucatan", "Zacatecas", "Extranjero"};
    char nombre1[30];
    char nombre2[30];
    char nombre3[30];

    strcpy(nombre1, vector[num].nombreCompleto.nombre);

    char *temp = strtok(nombre1, " ");

    if (temp != NULL)
    {
        strcpy(nombre2, temp);
        temp = strtok(NULL, "");
        if (temp != NULL)
        {
            strcpy(nombre3, temp);
        }
    }
    for (i = 0; i < 1; i++)
    {

        if (vector[num].sexo == 1)
        {
            strcpy(sexalumn, sexo[0]);
        }
        else
        {
            strcpy(sexalumn, sexo[1]);
        }

        strcpy(estado, estados[vector[num].estado - 1]);

        printf("MATRICULA: %d\n", vector[num].matricula);
        printf("NOMBRE: %s\n", nombre1);

        if (nombre3 != NULL)
        {
            printf("NOMBRE 2: %s\n", nombre3);
        }
        else
        {
            printf("NOMBRE 2:\n");
        }

        printf("AP PATERNO: %s\n", vector[num].nombreCompleto.apellidoPat);
        printf("AP MATERNO: %s\n", vector[num].nombreCompleto.apellidoMat);
        printf("FECHA NAC: %02d-%02d-%4d\n", vector[num].nacimiento.dia, vector[num].nacimiento.mes, vector[num].nacimiento.anio);
        printf("EDAD: %d\n", vector[num].edad);
        printf("SEXO: %s\n", sexalumn);
        printf("LUGAR NACIMIENTO: %s\n", estado);
        printf("CURP: %s\n", vector[num].curp);
    }
}

void llenarRegistroATM(Testudiante vector[], int indice)
{
    int i, matricula;

    vector[indice].status = 1;
    do
    {
        matricula = 300000 + rand() % (399999 - 300000 + 1);
        i = searchLinearId(vector, indice, matricula);
    } while (i != -1);

    vector[indice].matricula = matricula;

    genLastName(vector[indice].nombreCompleto.apellidoPat);
    genLastName(vector[indice].nombreCompleto.apellidoMat);
    genName(vector[indice].nombreCompleto.nombre);

    vector[indice].nacimiento.anio = 1900 + rand() % (2007 - 1900 + 1);

    vector[indice].nacimiento.mes = 1 + rand() % (12 - 1 + 1);

    vector[indice].nacimiento.dia = generarDiaAleatorio(vector[indice].nacimiento.anio, vector[indice].nacimiento.mes);

    vector[indice].edad = 2023 - vector[indice].nacimiento.anio;

    vector[indice].sexo = sexDetect(vector[indice].nombreCompleto.nombre);

    vector[indice].estado = 1 + rand() % (33 - 1 + 1);

    char curpalumno[19];
    curp(vector, curpalumno, indice);
    strcpy(vector[indice].curp, curpalumno);
}

int generarDiaAleatorio(int anio, int mes)
{
    int dia;
    // determinar anio bisiesto
    int bisiesto = FALSE;

    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
    {
        dia = 1 + rand() % (31 - 1 + 1);
        ;
    }

    if (mes == 2)
    {
        if ((anio % 4 == 0 && anio % 100 != 0) || anio == 2000 || anio == 1000)
        {
            bisiesto = TRUE;
        }
        if (bisiesto == TRUE)
        {
            dia = 1 + rand() % (29 - 1 + 1);
        }
        else
        {
            dia = 1 + rand() % (28 - 1 + 1);
        }
    }

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        dia = 1 + rand() % (30 - 1 + 1);
    }

    return dia;
}

void ordenarMatriculas(Testudiante vector[], int m)
{
    int i, j;
    Testudiante aux;

    for (i = 0; i < m - 1; i++)
    {
        for (j = i + 1; j < m; j++)
        {
            if (vector[i].matricula > vector[j].matricula)
            {
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }
}

void escrbirArchivo(char *nombreArchivo, Testudiante vector[], int indice)
{
    int i;
    char sexo[2][10] = {"Hombre", "Mujer"};
    char sexalumn[10];
    char estado[30];
    char estados[35][35] = {"Aguascalientes", "Baja California", "Baja California Sur", "Campeche",
                            "Chiapas", "Chihuahua", "Coahuila", "Colima", "Ciudad de Mexico/CDMX", "Durango",
                            "Estado de Mexico", "Guanajuato", "Guerrero", "Hidalgo", "Jalisco", "Michoacan", "Morelos", "Nayarit",
                            "Nuevo Leon", "Oaxaca", "Puebla", "Queretaro", "Quintana Roo", "San Luis Potosi", "Sinaloa",
                            "Sonora", "Tabasco", "Tamaulipas", "Tlaxcala", "Veracruz", "Yucatan", "Zacatecas", "Extranjero"};
    FILE *fa;
    fa = fopen(nombreArchivo, "w");
    fprintf(fa, "MATRICULA   NOMBRE                           APPAT                            APMAT                            FECHA NAC    EDAD   SEXO      LUGAR NAC              CURP\n");
    for (i = 0; i < indice; i++)
    {
        if (vector[i].status == 1)
        {
            if (vector[i].sexo == 1)
            {
                strcpy(sexalumn, sexo[0]);
            }
            else
            {
                strcpy(sexalumn, sexo[1]);
            }

            strcpy(estado, estados[vector[i].estado - 1]);

            fprintf(fa, "%-9d   %-30s   %-30s   %-30s   %02d-%02d-%4d   %-4d   %-7s   %-20s   %-18s\n", vector[i].matricula, vector[i].nombreCompleto.nombre, vector[i].nombreCompleto.apellidoPat, vector[i].nombreCompleto.apellidoMat, vector[i].nacimiento.dia, vector[i].nacimiento.mes, vector[i].nacimiento.anio, vector[i].edad, sexalumn, estado, vector[i].curp);
        }
    }

    printf("ARCHIVO ESCRITO CON EXITO.");
    fclose(fa);
}

void qs(Testudiante lista[], int limiteIzquierdo, int limiteDerecho)
{
    int izquierda, derecha, aux;
    Testudiante temp;
    izquierda = limiteIzquierdo;
    derecha = limiteDerecho;
    aux = lista[(izquierda + derecha) / 2].matricula;

    do
    {
        while (lista[izquierda].matricula < aux && izquierda < limiteDerecho)
        {
            izquierda++;
        }
        while (aux < lista[derecha].matricula && derecha > limiteIzquierdo)
        {
            derecha--;
        }
        if (izquierda <= derecha)
        {
            temp = lista[izquierda];
            lista[izquierda] = lista[derecha];
            lista[derecha] = temp;
            izquierda++;
            derecha--;
        }

    } while (izquierda <= derecha);
    if (limiteIzquierdo < derecha)
    {
        qs(lista, limiteIzquierdo, derecha);
    }
    if (limiteDerecho > izquierda)
    {
        qs(lista, izquierda, limiteDerecho);
    }
}

void quikSort(Testudiante lista[], int indice)
{
    qs(lista, 0, indice - 1);
}

// FUNCIONES PARA CURP
void curp(Testudiante vector[], char curp[], int indice)
{
    convertMayus(vector[indice].nombreCompleto.apellidoPat);
    convertMayus(vector[indice].nombreCompleto.apellidoMat);
    convertMayus(vector[indice].nombreCompleto.nombre);
    validarCaracteresEspeciales(vector[indice].nombreCompleto.apellidoPat);
    validarCaracteresEspeciales(vector[indice].nombreCompleto.apellidoMat);
    validarCaracteresEspeciales(vector[indice].nombreCompleto.nombre);

    char dia[3], mes[3], anio[3];
    sprintf(dia, "%02d", vector[indice].nacimiento.dia);
    sprintf(mes, "%02d", vector[indice].nacimiento.mes);
    sprintf(anio, "%02d", vector[indice].nacimiento.anio % 100);

    int sexo;
    sexo = sexDetect(vector[indice].nombreCompleto.nombre);
    char c;
    if (sexo != 1)
    {
        c = 'M';
    }
    else
    {
        c = 'H';
    }
    char curp0Resultado = letraNombre(vector[indice].nombreCompleto.apellidoPat);
    char curp1Resultado = vocalApellido(vector[indice].nombreCompleto.apellidoPat);
    char curp2Resultado = letraNombre(vector[indice].nombreCompleto.apellidoMat);
    char curp3Resultado = letraNombre(vector[indice].nombreCompleto.nombre);

    char codigoEdo[3];
    obtenerCodigoEdo(codigoEdo, vector[indice].estado);

    char auxCedo1 = codigoEdo[0];
    char auxCedo2 = codigoEdo[1];

    char homonimia[3];
    obtenerHomonimia(vector[indice].nacimiento.anio, homonimia);

    char aux13 = consonanteApellido(vector[indice].nombreCompleto.apellidoPat);
    char aux14 = consonanteApellido(vector[indice].nombreCompleto.apellidoMat);
    char aux15 = consonanteNombres(vector[indice].nombreCompleto.nombre);

    char aux16 = homonimia[0];

    curp[0] = curp0Resultado ? curp0Resultado : 'X';
    curp[1] = curp1Resultado ? curp1Resultado : 'X';
    curp[2] = curp2Resultado ? curp2Resultado : 'X';
    curp[3] = curp3Resultado ? curp3Resultado : 'X';
    curp[4] = anio[0];
    curp[5] = anio[1];
    curp[6] = mes[0];
    curp[7] = mes[1];
    curp[8] = dia[0];
    curp[9] = dia[1];
    curp[10] = c;
    curp[11] = auxCedo1;
    curp[12] = auxCedo2;
    curp[13] = aux13;
    curp[14] = aux14;
    curp[15] = aux15;
    curp[16] = aux16;
    curp[17] = (rand() % 10) + '0';
    curp[18] = '\0';

    convertMayus(curp);
    validarPalabrasAltisonantes(curp);
}

char letraNombre(char nombre[])
{
    int largo = largoCadena(nombre);
    char primerNombre[largo], segundoNombre[largo];
    separarNombres(nombre, primerNombre, segundoNombre);

    if ((validarNombres(primerNombre) || validarPreposiciones(primerNombre)) && segundoNombre[0] != '\0')
    {
        separarNombres(segundoNombre, primerNombre, segundoNombre);

        while (validarPreposiciones(primerNombre) && segundoNombre[0] != '\0')
        {
            separarNombres(segundoNombre, primerNombre, segundoNombre);
        }
    }

    if (primerNombre[0] == ',')
    {
        return 'X';
    }

    return primerNombre[0];
}

int validarNombres(char nombre[])
{
    int i;
    char lista[10][10] = {"MARIA", "MAX", "MA", "MX", "M", "JOSE", "JX", "J"};

    for (i = 0; i < 8; i++)
    {
        if (strcmp(nombre, lista[i]) == 0)
        {
            return TRUE;
        }
    }

    return FALSE;
}

void separarNombres(char nombre[], char primerNombre[], char otrosNombres[])
{
    int i = 0;
    while (nombre[i] != ' ' && nombre[i] != '\0')
    {
        primerNombre[i] = nombre[i];
        i++;
    }
    primerNombre[i] = '\0';

    if (nombre[i] != '\0')
    {
        i++;
        int j = 0;
        while (nombre[i] != '\0')
        {
            otrosNombres[j] = nombre[i];
            i++;
            j++;
        }
        otrosNombres[j] = '\0';
    }
    else
    {
        otrosNombres[0] = '\0';
    }
}

int validarPreposiciones(char nombre[])
{
    int i;
    char listaPreposiciones[19][4] = {"DA", "DAS", "DE", "DEL", "DER", "DI", "DIE", "DD", "Y", "EL", "LA", "LOS", "LAS", "LE", "LES", "MAC", "MC", "VAN", "VON"};

    for (i = 0; i < 19; i++)
    {
        if (strcmp(nombre, listaPreposiciones[i]) == 0)
        {
            return TRUE;
        }
    }

    return FALSE;
}

char consonanteApellido(char apellido[])
{
    int largo = largoCadena(apellido);
    char primerApellido[largo];
    char segundoApellido[largo];

    separarNombres(apellido, primerApellido, segundoApellido);

    if (validarPreposiciones(primerApellido))
    {
        separarNombres(segundoApellido, primerApellido, segundoApellido);

        while (validarPreposiciones(primerApellido) && segundoApellido[0] != '\0')
        {
            separarNombres(segundoApellido, primerApellido, segundoApellido);
        }
    }

    if (primerApellido[1] == ',')
    {
        return 'X';
    }

    return buscarSegundaConsonante(primerApellido);
}

char vocalApellido(char apellido[])
{
    int largo = largoCadena(apellido);
    char primerApellido[largo];
    char segundoApellido[largo];

    separarNombres(apellido, primerApellido, segundoApellido);

    if (validarPreposiciones(primerApellido))
    {
        separarNombres(segundoApellido, primerApellido, segundoApellido);

        while (validarPreposiciones(primerApellido) && segundoApellido[0] != '\0')
        {
            separarNombres(segundoApellido, primerApellido, segundoApellido);
        }
    }

    if (primerApellido[1] == ',')
    {
        return 'X';
    }

    return primeraVocal(primerApellido);
}

char primeraVocal(char nombre[])
{
    int i;
    int largo = largoCadena(nombre);
    i = 1;

    while (i < largo)
    {
        if (nombre[i] == 'A' || nombre[i] == 'E' || nombre[i] == 'I' || nombre[i] == 'O' || nombre[i] == 'U')
        {
            return nombre[i];
        }
        i++;
    }

    return 'X';
}

void obtenerCodigoEdo(char codigo[], int estado)
{
    char codigoEstados[35][5] = {"AS", "BC", "BS", "CC", "CS", "CH", "CL", "CM", "MC", "DG",
                                 "DF", "GT", "GR", "HG", "JC", "MN", "MS", "NT", "NL", "OC",
                                 "PL", "QT", "QR", "SP", "SL", "SR", "TC", "TS", "TL", "VZ",
                                 "YN", "ZS", "NE"};

    for (int i = 0; i < 33; i++)
    {
        if (estado == i + 1)
        {
            strcpy(codigo, codigoEstados[i]);
        }
    }
}

char buscarPrimeraConsonante(char cadena[])
{
    int i = 0;
    int largo = largoCadena(cadena) + 1;

    while (i < largo)
    {
        if (cadena[i] != 'A' && cadena[i] != 'E' && cadena[i] != 'I' && cadena[i] != 'O' && cadena[i] != 'U' && cadena[i] != ' ')
        {
            if (cadena[i] == ',')
            {
                return 'X';
            }

            return cadena[i];
        }
        i++;
    }

    return 'X';
}

char buscarSegundaConsonante(char cadena[])
{
    int i = 1;
    int largo = largoCadena(cadena) + 1;

    while (i < largo)
    {
        if (cadena[i] != 'A' && cadena[i] != 'E' && cadena[i] != 'I' && cadena[i] != 'O' && cadena[i] != 'U' && cadena[i] != ' ')
        {
            if (cadena[i] == ',')
            {
                return 'X';
            }

            return cadena[i];
        }
        i++;
    }

    return 'X';
}

char consonanteNombres(char nombre[])
{
    int largo = largoCadena(nombre);
    char primerNombre[largo], segundoNombre[largo];

    separarNombres(nombre, primerNombre, segundoNombre);

    if ((validarNombres(primerNombre) == TRUE) || ((validarPreposiciones(primerNombre) == TRUE) && segundoNombre[0] != '\0'))
    {
        separarNombres(segundoNombre, primerNombre, segundoNombre);

        if ((validarPreposiciones(primerNombre) == TRUE))
        {
            separarNombres(segundoNombre, primerNombre, segundoNombre);

            while (validarPreposiciones(primerNombre) && segundoNombre[0] != '\0')
            {
                separarNombres(segundoNombre, primerNombre, segundoNombre);
            }
        }
        return buscarSegundaConsonante(primerNombre);
    }

    if (validarPreposiciones(primerNombre))
    {
        separarNombres(segundoNombre, primerNombre, segundoNombre);

        while (validarPreposiciones(primerNombre) == TRUE && segundoNombre[0] != '\0')
        {
            separarNombres(segundoNombre, primerNombre, segundoNombre);
        }
    }
    return buscarSegundaConsonante(primerNombre);
}

void obtenerHomonimia(int anio, char homonimia[])
{
    char identificador[2], numero[2];
    int num;
    if (anio < 2000)
    {
        identificador[0] = '0';
    }
    else
    {
        if (anio >= 2000 && anio <= 2009)
        {
            identificador[0] = 'A';
        }
        else
        {
            if (anio >= 2010 && anio <= 2019)
            {
                identificador[0] = 'B';
            }
            else
            {
                identificador[0] = 'C';
            }
        }
    }
    num = rand() % 9 + 1;
    sprintf(numero, "%d", num);

    sprintf(homonimia, "%s%s", identificador, numero);
}

void validarCaracteresEspeciales(char cadena[])
{
    int i = 0;
    unsigned char caracter;

    while (cadena[i] != '\0')
    {
        caracter = (unsigned char)cadena[i];
        if (caracter >= 'a' && caracter <= 'z')
        {
            cadena[i] -= 32;
        }
        else
        {
            switch (caracter)
            {
            case 160: // á
            case 181: // Á
            case 132: // ä
            case 142: // Ä
                cadena[i] = 'A';
                break;

            case 130: // é
            case 144: // É
            case 137: // ë
            case 211: // Ë
                cadena[i] = 'E';
                break;

            case 161: // í
            case 214: // Í
            case 139: // ï
            case 216: // Ï
                cadena[i] = 'I';
                break;

            case 162: // ó
            case 224: // Ó
            case 148: // ö
            case 153: // Ö
                cadena[i] = 'O';
                break;

            case 163: // ú
            case 233: // Ú
            case 129: // ü
            case 154: // Ü
                cadena[i] = 'U';
                break;

            case 164: // ñ
            case 165: // Ñ
                cadena[i] = 'X';
                break;

            case 39:  // '
            case 44:  // ,
            case 45:  // -
            case 46:  // .
            case 47:  // /
            case 96:  // `
            case 239: // ´
            case 249: // ¨
                cadena[i] = ',';
                break;
            }
        }
        i++;
    }
}

void validarPalabrasAltisonantes(char curp[])
{
    char antisonantes[][5] = {"BACA", "BAKA", "BUEI", "BUEY", "CACA", "CACO", "CAGA", "CAGO", "CAKA", "CAKO", "COGE", "COGI", "COJA", "COJE",
                              "COJI", "COJO", "COLA", "CULO", "FALO", "FETO", "GETA", "GUEI", "GUEY", "JETA", "JOTO", "KACA", "KACO", "KAGA",
                              "KAGO", "KAKA", "KAKO", "KOGE", "KOGI", "KOJA", "KOJE", "KOJI", "KOJO", "KOLA", "KULO", "LILO", "LOCA", "LOCO",
                              "LOKA", "LOKO", "MAME", "MAMO", "MEAR", "MEAS", "MEON", "MIAR", "MION", "MOCO", "MOKO", "MULA", "MULO", "NACA",
                              "NACO", "PEDA", "PEDO", "PENE", "PIPI", "PITO", "POPO", "PUTA", "PUTO", "QULO", "RATA", "ROBA", "ROBE", "ROBO",
                              "RUIN", "SENO", "TETA", "VACA", "VAGA", "VAGO", "VAKA", "VUEI", "VUEY", "WUEI", "WUEY"};

    char cadenatemp[5];
    strncpy(cadenatemp, curp, 4);
    cadenatemp[4] = '\0';

    int i;
    int found = 0;
    for (i = 0; (unsigned int)i < (unsigned int)sizeof(antisonantes) / sizeof(antisonantes[0]) && found == 0; i++)
    {
        if (strcmp(cadenatemp, antisonantes[i]) == 0)
        {
            found = 1;
        }
    }

    if (found == 1)
    {
        curp[1] = 'X';
    }

    if (curp[14] == ' ' || curp[14] == '\0')
    {
        curp[14] = 'X';
    }

    if (curp[15] == ' ' || curp[15] == '\0')
    {
        curp[15] = 'X';
    }
}