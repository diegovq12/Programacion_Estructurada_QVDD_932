#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>

int randNum(int ri, int rf) {
    return ri + (rand() % (rf - ri + 1));
}

void getString (char string[], char msge[])
{
    printf("%s\n",msge);
    int i=0, key, space = 1;

    do
    {
        key = getch();
        key = toupper(key);

        if (isalpha(key))
        {
            printf("%c",key);
            string[i++]=key;
            space=0;
        }
        else
        {
            if (key == 32 && space == 0)
            {
                printf("%c",key);
                string[i++] = key;
                space = 1;
            }     
            else
            {
                if (key == 8 && i>0)
                {
                    printf("\b \b");
                    i--;
                    string[i]='\0';
                }
            }   
        }
        
    } while (key!=13);
    string[i] = '\0';
}