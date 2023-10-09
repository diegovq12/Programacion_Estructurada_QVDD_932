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
    } while (num<ri || num>rf);
}
