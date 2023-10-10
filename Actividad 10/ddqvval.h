#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int validInt(int ri, int rf)
{
    int num;
    char cadenaNum[50];

    do
    {
        fflush(stdin);
        gets(cadenaNum);
        num = atoi(cadenaNum);
        if (num<ri || num>rf)
        {
            printf("Out of range\n");
        }
    } while (num<ri || num>rf);
    return num;
}
