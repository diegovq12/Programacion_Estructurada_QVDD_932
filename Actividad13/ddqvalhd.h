#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int randNum(int ri, int rf) {
    return ri + (rand() % (rf - ri + 1));
}

void getString(char string[], char msge[]) {
    printf("%s\n", msge);
    int i = 0, key, space = 1;

    do {
        key = getch();

        if (isalpha(key)) {
            printf("%c", key);
            string[i++] = key;
            space = 0;
        } else {
            if (key == 32 && space == 0) {
                printf("%c", key);
                string[i++] = key;
                space = 1;
            } else {
                if (key == 8 && i > 0) {
                    printf("\b \b");
                    i--;
                    string[i] = '\0';
                }
            }
        }

    } while (key != 13);
    //string[i] = '\0';
}


#include <stdio.h>
#include <stdlib.h>

int validInt(int ri, int rf, char* msge, char* msgeWrong) {
    int num;
    char input[50];

    do {
        printf("%s\n", msge);

        int i = 0, key, isValid = 1;

        do {
            key = getch();

            if (isdigit(key)) {
                printf("%c", key);
                input[i++] = key;
            } else {
                if (key == 8 && i > 0) {
                    printf("\b \b");
                    i--;
                } else {
                    isValid = 0;
                }
            }
        } while (key != 13 || !isValid);

        input[i] = '\0';
        num = atoi(input);

        if (num < ri || num > rf) {
            printf(" %s\n", msgeWrong);
        }
    } while (num < ri || num > rf);

    return num;
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

int sizeString (char cadena[])
{
    int largo=0;
    while (cadena[largo]!= '\0')
    {
        largo++;
    }
    return largo;
}