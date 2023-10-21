#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "ddqvval.h" //propia

#define TRUE 1
#define FALSE 0

int main(void);
void menu(void);
void getFullName(char name[], char lnPat[], char lnMat[]);
void getState(char state[]);
int showMonth(void);
int ValBisiesto(int year);


int main()
{
    menu();
    return 0;
}

int msge(void)
{
    int op;
    printf("\n GENERADOR DE CURP\n");
    printf("1.- GENERAR CURP\n");
    printf("0. Salir\n");
    printf("Ingresa Opcion\n");
    op = validInt(0, 1, "Opcion Invalida");

    return op;
}

void menu(void)
{
    char name[50], lnPat[50], lnMat[50], state[5];
    int op;
    do
    {

        system("CLS");

        op = msge();

        switch (op)
        {
        case 1:
            system("CLS");
            getFullName(name, lnPat, lnMat);
            system("CLS");
            getState(state);
            system("CLS");

            printf("%s %s %s %s", name, lnPat, lnMat, state);

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

void getFullName(char name[], char lnPat[], char lnMat[])
{
    int correct;
    printf("Ingresa Nombre(s): ");
    fflush(stdin);
    gets(name);
    do
    {
        correct = validString(name);
        if (correct == FALSE)
        {
            printf("Error - Reingresa correctamente los datos\n");
            printf("Ingresa Nombre(s): ");
            fflush(stdin);
            gets(name);
        }
    } while (correct == FALSE);
    convertMayus(name);

    printf("Ingresa Primer Apellido: ");
    fflush(stdin);
    gets(lnPat);
    do
    {
        correct = validString(lnPat);
        if (correct == FALSE)
        {
            printf("Error - Reingresa correctamente los datos\n");
            printf("Ingresa Primer Apellido: ");
            fflush(stdin);
            gets(lnPat);
        }
    } while (correct == FALSE);
    convertMayus(lnPat);

    printf("Ingresa Segundo Apellido: ");
    fflush(stdin);
    gets(lnMat);
    do
    {
        correct = validString(lnMat);
        if (correct == FALSE)
        {
            printf("Error - Reingresa correctamente los datos\n");
            printf("Ingresa Segundo Apellido: ");
            fflush(stdin);
            gets(lnMat);
        }
    } while (correct == FALSE);
    convertMayus(lnMat);
}

void getState(char state[])
{
    char states[35][35]={"Aguascalientes","Baja California","Baja California Sur","Campeche",
    "Chiapas","Chihuahua","Coahuila","Colima","Ciudad de Mexico/CDMX","Durango",
    "Estado de Mexico","Guanajuato","Guerrero","Hidalgo","Jalisco","Michoacan","Morelos","Nayarit",
    "Nuevo Leon","Oaxaca","Puebla","Queretaro","Quintana Roo","San Luis Potosi","Sinaloa",
    "Sonora","Tabasco","Tamaulipas","Tlaxcala","Veracruz","Yucatan","Zacatecas","Extranjero"};

    char stateCode[35][5]={"AS","BC","BS","CC","CS","CH","CL","CM","MC","DG","DF","GT","GR","HG","JC"
    ,"MN","MS","NT","NL","OC","PL","QT","QR","SP","SL","SR","TC","TS","TL","VZ","YN","ZS","NE"};

    for (int i = 1; i <= 33; i++)
    {
        printf("%d) %s\n",i,states[i-1]);
    } 
    printf("Seleccione la entidad de nacimiento:\n");
    int op = validInt(1, 33, "Opcion Fuera de rango");
    for (int i = 0; i < 33; i++)
    {
        if (op == i+1)
        {
            strcpy(state, stateCode[i]);
        }  
    }
}


int ValBisiesto(int year)
{
    if (year %4 == 0 && year%100 != 0)
    {
        return TRUE;
    }
    return FALSE;
}

/*int getYear()
{

}*/

int showMonth()
{
    char month[30][12]={"Enero","Febrero","Marzo", "Abril"
    ,"Mayo","Junio","Julio","Agosto","Septiembre","Octubre",
    "Noviembre","Diciembre"};
    for (int i = 1; i <= sizeof(month); i++)
    {
        printf("%d) %s\n",i,month[i-1]);
    } 
    printf("Ingresa tu mes de nacimiento: \n");
    int op = validInt(1,12,"Opcion No valida");
   return op;
}

