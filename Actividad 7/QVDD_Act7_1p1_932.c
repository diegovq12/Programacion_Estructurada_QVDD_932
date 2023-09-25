// Quiros Vicencio Diego Demian Matricula:372688
// 09/19/23 (creado) - 09/23/23 - 09/24/23 (modificado)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//PROTOTIPOS
int msges (void);
void menu (void);

void convertirMayusc (char *string);
void invertirPalabra (char *string);
void Salida3 (char *string);
void Salida4 (char *string);
void Salida5 (char *string);
void Salida6 (char *string);
void Salida7 (char *string);
void Salida8 (char *string);
void Salida9 (char *string);
void Salida10 (char *string);
//**********************************


//Main principal
int main()
{
    menu();

    return 0;
}
//*************

//Desarrollo de Funciones
/******************************************************/
int msges(void)
{
    int op;
    printf("\n \tM E N U\n");
    printf("1- Despegar Normal\n");
    printf("2- Invertida\n");
    printf("3- Vertical\n");
    printf("4- Vertical Invertida\n");
    printf("5- Eliminar de Derecha a Izquierda\n");
    printf("6- INVERTIDA Eliminar de Derecha a Izquierda\n");
    printf("7- Eliminar de Izquierda a Derecha\n");
    printf("8- INVERTIDA Eliminar de Izquierda a Derecha\n");
    printf("9- Despegar Consonantes\n");
    printf("10- Despegar Vocales\n");
    printf("0- Salir\n");
    printf("Ingrese funcion a utilizar:\n");
    scanf("%d",&op);

    
    return op;
}
/******************************************************/
void menu (void)
{
    int op;
    char word[20];
    do
    {
        op=msges();
        if(op!=0)
        {    
            printf("Ingresa una palabra: \n");
            fflush(stdin);
            gets(word);
            convertirMayusc(word);
        }
        
        switch (op)
        {
        case 1:
            convertirMayusc(word);
            break;
        case 2:
            invertirPalabra(word);
            break;
        case 3:
            Salida3(word);
            break;
        case 4:
            Salida4(word);
            break;
        case 5:
            Salida5(word);
            break;
        case 6:
            Salida6(word);
            break;
        case 7:
            Salida7(word);
            break;
        case 8:
            Salida8(word);
            break;
        case 9:
            Salida9(word);
            break;
        case 10:
            Salida10(word);
            break;
        case 0:
            printf("Gracias por usar!");
            break;
        default:
            break;
        }  
    } while (op!=0);
    
}


// Imprime la cadena en mayúscula.
// QVDD_Act7_parte1_01_932
void convertirMayusc(char *string)
{
    int i;
    for (i = 0; string[i] != '\0'; i++)
    {
        if (string[i] >='a')
        {
            if (string[i]<='z')
            {
                string[i]=string[i]-32;
            }
            
        }
    }
    printf("\n%s\n",string);
}
//***************************************
// Imprime la cadena en orden invertido
// QVDD_Act7_parte1_02_932
void invertirPalabra(char *string)
{
    int size=0;
    while (string[size] != '\0')
    {
        size++;
    }
    
    int aux;
    for (int i = 0,j=size-1; i<j; i++,j--)
    {
        aux=string[i];
        string[i]=string[j];
        string[j]=aux;
    }
    printf("\n%s\n",string);
}
//*****************************************

// Imprime la cadena en Vertical.
// QVDD_Act7_parte1_03_932
void Salida3 (char *string)
{
    for (int i = 0; string[i] != '\0' ; i++)
    {
        printf(" %c \n",string[i]);
    }
}
//*********************************************

// Imprime la cadena en Vertical e Invertida.
// QVDD_Act7_parte1_04_932
void Salida4 (char*string)
{
    invertirPalabra(string);
    Salida3 (string);
}
//***************************

// Imprime y va eliminando la cadena
// de derecha a izquierda
// QVDD_Act7_parte1_05_932
void Salida5 (char *string)
{
    int size=0;
    while (string[size] != '\0')
    {
        size++;
    }

    for (int i = 0, j=size; i <=size;i++)
    {

        string[j]='\0';
        j--;
        printf(" %s \n",string);
        
    }
}
//******************************************

// Invierte, imprime y va eliminando la cadena
// de derecha a izquierda
// QVDD_Act7_parte1_06_932
void Salida6 (char *string)
{
    invertirPalabra(string);
    Salida5(string);
}
//***************************

// Imprime y va eliminando la cadena
// de izquierda a derecha
// QVDD_Act7_parte1_07_932
void Salida7 (char *string)
{
    int size=0;
    while (string[size] != '\0')
    {
        size++;
    }
    printf("%s\n",string);
    while (size>1)
    {
        for (int i = 0; i < size-1; i++)
        {
            string[i]=string[i+1];
        }
        size--;
        string[size]='\0';
        printf("%s\n",string);
    }
}
//***************************************

// Invierte, imprime y va eliminando la cadena
// de izquierda a derecha
// QVDD_Act7_parte1_08_932
void Salida8 (char *string)
{
    int size=0;
    while (string[size] != '\0')
    {
        size++;
    }

    int aux;
    for (int i = 0,j=size-1; i<j; i++,j--)
    {
        aux=string[i];
        string[i]=string[j];
        string[j]=aux;
    }

    printf("%s\n",string);
    while (size>1)
    {
        for (int i = 0; i < size-1; i++)
        {
            string[i]=string[i+1];
        }
        size--;
        string[size]='\0';
        printf("%s\n",string);
    }
}
//******************************************

// Imprime solamente las  Consonantes
// QVDD_Act7_parte1_09_932
void Salida9 (char *string)
{
    for (int i = 0; i != '\n'; i++)
    {
        char caracter = string[i];
        if (caracter!= 'A' && caracter!= 'E' && caracter!= 'I' && caracter!= 'O' && caracter!= 'U' && caracter!= 'a' && caracter!= 'e' && caracter!= 'i' && caracter!= 'o' && caracter!= 'u')
        {
            printf("%c",caracter);
        }
    }
    
}
//*******************************************

// Imprime solamente las Vocales
// QVDD_Act7_parte1_10_932
void Salida10 (char *string)
{
    for (int i = 0; i != '\n'; i++)
    {
        char caracter = string[i];
        if (caracter == 'A' || caracter == 'E' || caracter == 'I' || caracter == 'O' || caracter == 'U' || caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u')
        {
            printf("%c",caracter);
        }
    }
}
//*******************************************