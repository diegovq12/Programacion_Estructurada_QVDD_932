#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "ddqvval.h" //propia

#define TRUE 1
#define FALSE 0

int main(void);
void menu(void);
void getFullName(char name[], char lnPat[], char lnMat[], char initials[]);
void getState(char state[]);
int showMonth(void);
int borndate(char bornDate[]);
char firstVowel(char firstLn[]);
void getSex(char sex[]);
void detectConsonant(char name[], char ln[], char ln2[], char consonante[]);
void getHomonimia(int year, char homonimia[]);
void fixCurp(char curp[]);

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

int msge(void)
{
    int op;
    printf("GENERADOR DE CURP\n");
    printf("1.- GENERAR CURP\n");
    printf("0. Salir\n");
    printf("Ingresa Opcion\n");
    op = validInt(0, 1, "Opcion Invalida");

    return op;
}

void menu(void)
{
    char name[50], lnPat[50], lnMat[50], state[5], bornDate[10], initials1[10], consonants[10];
    char sex[2], homonimia[5];
    char curp[40];
    int op;
    int year;
    do
    {

        system("CLS");

        op = msge();

        switch (op)
        {
        case 1:
            system("CLS");
            getFullName(name, lnPat, lnMat, initials1);
            system("CLS");
            system("CLS");
            year = borndate(bornDate);
            getState(state);
            getSex(sex);
            detectConsonant(name, lnPat, lnMat, consonants);
            getHomonimia(year, homonimia);

            //printf("%s %s %s %s %s %s %s %s %s\n", name, lnPat, lnMat, initials1, bornDate, state, sex, consonants, homonimia);

            sprintf(curp, "%s%s%s%s%s%s", initials1, bornDate, sex, state, consonants, homonimia);
            fixCurp(curp);

            printf("\n%s\n", curp);
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

void getFullName(char name[], char lnPat[], char lnMat[], char initials[])
{
    int correct, found;
    char nameTemp[40];

    char nombresCortos[][7] = {"MARIA", "MAX", "MA", "MX",
                               "M", "JOSE", "JX", "J"};

    printf("Ingresa Nombre(s): ");
    fflush(stdin);
    gets(name); // Leer en copyName en lugar de name
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

    char *space = strchr(name, ' ');
    if (space != NULL)
    {
        *space = '\0';
        strcpy(nameTemp, space + 1);
    }

    int i;
    found = 0;
    for (i = 0; i < sizeof(nombresCortos) / sizeof(nombresCortos[0]) && found == 0; i++)
    {
        if (strcmp(name, nombresCortos[i]) == 0)
        {
            found = 1;
        }
    }
    // printf("found = %d\n", found);

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
        correct = validStringNull(lnMat);
        if (lnMat == NULL)
        {
            correct = TRUE;
        }

        if (correct == FALSE)
        {
            printf("Error - Reingresa correctamente los datos\n");
            printf("Ingresa Segundo Apellido: ");
            fflush(stdin);
            gets(lnMat);
        }
    } while (correct == FALSE);
    convertMayus(lnMat);

    initials[0] = lnPat[0];
    initials[1] = firstVowel(lnPat);

    if (lnMat != NULL)
    {
        initials[2] = lnMat[0];
    }
    else
    {
        initials[2] = 'X';
    }

    if (found == 1)
    {
        char reemplazo = nameTemp[0];
        initials[3] = reemplazo;
    }
    else
    {
        initials[3] = name[0];
    }

    initials[4] = '\0';

    strcat(name, " ");
    strcat(name, nameTemp);
}

void getState(char state[])
{
    char states[35][35] = {"Aguascalientes", "Baja California", "Baja California Sur", "Campeche",
                           "Chiapas", "Chihuahua", "Coahuila", "Colima", "Ciudad de Mexico/CDMX", "Durango",
                           "Estado de Mexico", "Guanajuato", "Guerrero", "Hidalgo", "Jalisco", "Michoacan", "Morelos", "Nayarit",
                           "Nuevo Leon", "Oaxaca", "Puebla", "Queretaro", "Quintana Roo", "San Luis Potosi", "Sinaloa",
                           "Sonora", "Tabasco", "Tamaulipas", "Tlaxcala", "Veracruz", "Yucatan", "Zacatecas", "Extranjero"};

    char stateCode[35][5] = {"AS", "BC", "BS", "CC", "CS", "CH", "CL", "CM", "MC", "DG", "DF", "GT", "GR", "HG", "JC", "MN", "MS",
                             "NT", "NL", "OC", "PL", "QT", "QR", "SP", "SL", "SR", "TC", "TS", "TL", "VZ", "YN", "ZS", "NE"};

    for (int i = 1; i <= 33; i++)
    {
        printf("%d) %s\n", i, states[i - 1]);
    }
    printf("Seleccione la entidad de nacimiento:\n");
    int op = validInt(1, 33, "Opcion Fuera de rango");
    for (int i = 0; i < 33; i++)
    {
        if (op == i + 1)
        {
            strcpy(state, stateCode[i]);
        }
    }
}

int showMonth()
{
    char month[30][12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre",
                          "Noviembre", "Diciembre"};
    for (int i = 1; (unsigned int)i <= (unsigned int)sizeof(month); i++)
    {
        printf("%d) %s\n", i, month[i - 1]);
    }
    printf("Ingresa tu mes de nacimiento: \n");
    int op = validInt(1, 12, "Opcion No valida");
    return op;
}

int borndate(char bornDate[])
{
    int year, month, day, bisiesto = FALSE;
    char dayC[5], monthC[5], yearC[5];
    system("CLS");
    printf("Ingresa el Annio de nacimiento: ");
    year = validInt(1950, 2023, "Invalido - Fuera de Rango");
    if (year == 2023)
    {
        printf("Ingresa el mes de nacimiento (1 - 12): ");
        month = validInt(1, 10, "Invalido - Fuera de Rango");
    }
    else
    {
        printf("Ingresa el mes de nacimiento (1 - 12): ");
        month = validInt(1, 12, "Invalido - Fuera de Rango");
    }

    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        printf("Ingresa el dia de nacimiento(1 - 31): ");
        day = validInt(1, 31, "Invalido - Fuera de Rango");
    }

    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        printf("Ingresa el dia de nacimiento (1 - 30): ");
        day = validInt(1, 30, "Invalido - Fuera de Rango");
    }

    if (month == 2)
    {
        if ((year % 4 == 0 && year % 100 != 0) || year == 2000 || year == 1000)
        {
            bisiesto = TRUE;
        }

        if (bisiesto == TRUE)
        {
            printf("Ingresa el dia de nacimiento (1 - 29): ");
            day = validInt(1, 29, "Invalido- Fuera de Rango");
        }
        else
        {
            printf("Ingresa el dia de nacimiento (1 - 28): ");
            day = validInt(1, 28, "Invalido- Fuera de Rango");
        }
    }

    if (day < 10)
    {
        sprintf(dayC, "0%d", day);
    }
    else
    {
        sprintf(dayC, "%d", day);
    }

    if (month < 10)
    {
        sprintf(monthC, "0%d", month);
    }
    else
    {
        sprintf(monthC, "%d", month);
    }

    int lastTwoDigits = year % 100;

    if (lastTwoDigits < 10)
    {
        sprintf(yearC, "0%d", lastTwoDigits);
    }
    else
    {
        sprintf(yearC, "%d", lastTwoDigits);
    }
    sprintf(bornDate, "%s%s%s", yearC, monthC, dayC);

    return year;
}

void getSex(char sex[])
{
    int sexo;
    printf("Ingresa tu sexo: ");
    printf("1) Hombre 2) Mujer\n");
    sexo = validInt(1, 2, "Valor Invalido, Reingresar");
    if (sexo == 1)
    {
        strcpy(sex, "H");
    }
    else
    {
        strcpy(sex, "M");
    }
}

char firstVowel(char firstLn[])
{
    char c = 'X';
    int flag = FALSE;
    for (int i = 0; firstLn[i] != '\0' && flag == FALSE; i++)
    {
        c = firstLn[i];
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            flag = TRUE;
        }
    }
    return c;
}

void detectConsonant(char name[], char ln[], char ln2[], char consonante[])
{
    char c = 'X';
    int flag = FALSE;
    char nameTemp[40];
    char nombresCortos[][7] = {"MARIA", "MAX", "MA", "MX",
                               "M", "JOSE", "JX", "J"};

    for (int i = 1; ln[i] != '\0' && flag == FALSE; i++)
    {
        c = ln[i];
        if (c >= 'A' && c <= 'Z' && c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U')
        {
            flag = TRUE;
        }
    }
    consonante[0] = c;

    flag = FALSE;

    for (int i = 1; ln2[i] != '\0' && flag == FALSE; i++)
    {
        c = ln2[i];
        if (c >= 'A' && c <= 'Z' && c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U')
        {
            flag = TRUE;
        }
    }
    consonante[1] = c;

    char *space = strchr(name, ' ');
    if (space != NULL)
    {
        *space = '\0';
        strcpy(nameTemp, space + 1);
    }

    int found = 0;
    for (int i = 1; (unsigned int)i < (unsigned int)sizeof(nombresCortos) / sizeof(nombresCortos[0]) && found == 0; i++)
    {
        if (strcmp(name, nombresCortos[i]) == 0)
        {
            found = 1;
        }
    }

    flag = FALSE;
    if (found != 1)
    {
        for (int i = 1; name[i] != '\0' && flag == FALSE; i++)
        {
            c = name[i];
            if (c >= 'A' && c <= 'Z' && c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U')
            {
                flag = TRUE;
            }
        }
    }
    else
    {
        if (found == 1)
        {
            for (int i = 1; nameTemp[i] != '\0' && flag == FALSE; i++)
            {
                c = nameTemp[i];
                if (c >= 'A' && c <= 'Z' && c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U')
                {
                    flag = TRUE;
                }
            }
        }
    }

    consonante[2] = c;

    consonante[3] = '\0';
}

void getHomonimia(int year, char homonimia[])
{
    char identifier[2], number[2];
    identifier[0] = 'X';
    int num;

    if (year < 2000)
    {
        identifier[0] = '0';
    }
    else
    {
        if (year >= 2000 && year <= 2009)
        {
            identifier[0] = 'A';
        }
        else
        {
            if (year >= 2010 && year <= 2019)
            {
                identifier[0] = 'B';
            }
            else
            {
                identifier[0] = 'C';
            }
        }
    }
    num = rand() % 9 + 1;
    sprintf(number, "%d", num);

    sprintf(homonimia, "%s%s", identifier, number);
}

void fixCurp(char curp[])
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
    for (i = 0; i < sizeof(antisonantes) / sizeof(antisonantes[0]) && found == 0; i++)
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
