#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int validInt(int ri, int rf, char msgecheck[30], char msgeWrong[30])
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
            printf(" %s\n",msgeWrong);
        }
    } while (num<ri || num>rf);
    printf("%s\n",msgecheck);
    return num;
}
