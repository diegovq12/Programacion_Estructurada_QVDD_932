#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int validInt(int ri, int rf, char *msgeWrong)
{
    int num;
    char cadenaNum[50];

    do
    {
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
        else if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (((unsigned char)c >= 128 && (unsigned char)c <= 165) || ((unsigned char)c >= 192 && c <= 255))) && (unsigned char)c != '\0')
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
    char prevChar = ' '; // Inicializamos prevChar con un espacio para evitar espacio al principio

    for (int i = 0; string[i] != '\0'; i++) {
        unsigned char c = string[i];

        // Verifica si el carácter no es una letra o es un espacio
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f') && c != '\0') {
            return 0;
        }

        // Verifica si hay más de un espacio consecutivo
        if (c == ' ' && prevChar == ' ') {
            return 0;
        }

        prevChar = c;
    }

    // Verifica si la cadena comienza o termina con un espacio
    if (hasSpace || prevChar == ' ') {
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
        // Verifica si el carácter es una letra minúscula
        if ((*str >= 'a' && *str <= 'z') && capitalizeNext)
        {
            // Convierte la letra a mayúscula
            *str = *str - 'a' + 'A';
            capitalizeNext = 0; // Ya hemos capitalizado esta palabra
        }
        // Verifica si el carácter es un espacio en blanco
        else if (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r' || *str == '\v' || *str == '\f')
        {
            capitalizeNext = 1; // La próxima letra debe ser mayúscula
        }
        else
        {
            capitalizeNext = 0; // La próxima letra no debe ser mayúscula
        }
        str++; // Mueve el puntero al siguiente carácter
    }
}
