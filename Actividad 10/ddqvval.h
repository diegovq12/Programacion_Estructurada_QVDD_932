#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int validInt(int ri, int rf)
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
        }while(cadenaNum[0]==32 || cadenaNum[0]=='\0');    
        if (num<ri || num>rf)
        {
            printf("Out of range\n");
        }
    } while (num<ri || num>rf);
    return num;
}
