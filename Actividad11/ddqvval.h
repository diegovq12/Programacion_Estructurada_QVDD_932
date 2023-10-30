#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int validInt(int ri, int rf,char* msge, char *msgeWrong)
{
    int num;
    char cadenaNum[50];

    do
    {
        printf("%s\n",msge);
        do
        {
            fflush(stdin);
            gets(cadenaNum);
            num = atoi(cadenaNum);
        } while (cadenaNum[0] == 32 || cadenaNum[0] == '\0');
        if (num < ri || num > rf)
        {
            printf(" %s\n", msgeWrong);
        }
    } while (num < ri || num > rf);
    return num;
}

int validSingleString(const char string[])
{
    if (string == NULL || string[0] == '\0')
    {
        return 0; // La cadena es nula o vacía
    }

    int hasSpace = 0;    // Variable para rastrear si hay un espacio
    char prevChar = ' '; // Inicializamos prevChar con un espacio para evitar espacio al principio

    for (int i = 0; string[i] != '\0'; i++)
    {
        unsigned char c = string[i];

        // Verifica si el carácter es un espacio
        if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f')
        {
            hasSpace = 1;

            // Verifica si hay dobles espacios
            if (prevChar == ' ')
            {
                return 0;
            }
        }
        // Verifica si el carácter no es una letra o es un espacio
        else if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (((unsigned char)c >= 128 && (unsigned char)c <= 165) || ((unsigned char)c >= 192 && (unsigned char) c <= 255))) && (unsigned char)c != '\0')
        {
            return 0;
        }
        prevChar = c;
    }

    // Verifica si la cadena comienza o termina con un espacio
    if (hasSpace || prevChar == ' ')
    {
        return 0;
    }
    return 1; // La cadena cumple con todas las condiciones
}

int validString(const char string[]) {
    if (string == NULL || string[0] == '\0') {
        return 0; // La cadena es nula o vacía
    }

    int hasSpace = 0;    // Variable para rastrear si hay un espacio
    int prevCharWasSpace = 1; // Inicializamos prevCharWasSpace en 1 para evitar espacio al principio

    for (int i = 0; string[i] != '\0'; i++) {
        unsigned char c = string[i];

        // Verifica si el carácter es una letra, un espacio o se encuentra en el rango del código ASCII [128, 165]
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f' || (c >= 128 && c <= 165)) {
            // El carácter es válido
        } else {
            return 0; // El carácter no es válido
        }

        // Verifica si hay más de un espacio consecutivo
        if (c == ' ' && prevCharWasSpace) {
            return 0;
        }

        // Actualiza hasSpace si se encuentra un espacio
        if (c == ' ') {
            hasSpace = 1;
        } else {
            hasSpace = 0;
        }

        prevCharWasSpace = (c == ' ');
    }

    // Verifica si la cadena comienza o termina con un espacio
    if (hasSpace || prevCharWasSpace) {
        return 0;
    }

    return 1; // La cadena cumple con todas las condiciones
}



void capitalizeWords(char *str)
{
    // Variable para rastrear si la próxima letra debe ser mayúscula
    int capitalizeNext = 1;

    while (*str)
    {
        if (capitalizeNext && (*str >= 'a' && *str <= 'z'))
        {
            *str = *str - 'a' + 'A';
            capitalizeNext = 0;
        }
        else if (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r' || *str == '\v' || *str == '\f')
        {
            capitalizeNext = 1;
        }
        else
        {
            capitalizeNext = 0;
        }
        str++;
    }
}


void convertMayus(char *string)
{
    int i;
    for (i = 0; string[i] != '\0'; i++)
    {
        if (string[i] >= 'a')
        {
            if (string[i] <= 'z')
            {
                string[i] = string[i] - 32;
            }
        }
    }
}

const char* validStringNull(const char string[]) {
    if (string == NULL || string[0] == '\0') {
        return NULL; // La cadena es nula o vacía, devuelve NULL
    }

    int hasSpace = 0;
    int prevCharWasSpace = 1;

    for (int i = 0; string[i] != '\0'; i++) {
        unsigned char c = string[i];

        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f' || (c >= 128 && c <= 165)) {
            // El carácter es válido
        } else {
            return NULL; // El carácter no es válido, devuelve NULL
        }

        if (c == ' ' && prevCharWasSpace) {
            return NULL;
        }

        if (c == ' ') {
            hasSpace = 1;
        } else {
            hasSpace = 0;
        }

        prevCharWasSpace = (c == ' ');
    }

    if (hasSpace || prevCharWasSpace) {
        return NULL;
    }

    return string; // La cadena cumple con todas las condiciones, devuelve la cadena original
}

int largoCadena (char cadena[])
{
    int largo=0;
    while (cadena[largo]!= '\0')
    {
        largo++;
    }
    return largo;
}