#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//PROTOTIPOS
int msges (void);
void menu (void);

void convertirMayusc (char *string);
void convertirMinusculas (char *string);
void convertirCapital (char *string);
void cantidadDeCaracteres (char *string);
void invertirPalabra (char *string);
void cadenaSinEspacios (char *string);
void cadenaAlfabetico (char *string);
void Cadenas (char *string);
void palindromoOno (char *string);
//*********



int main()
{
    menu();

    return 0;
}


int msges(void)
{
    int op;
    printf("\n \tM E N U\n");
    printf("1- Convertir a Mayusculas\n");
    printf("2- Convertir a Minusculas\n");
    printf("3- Convertir a Capital\n");
    printf("4- Cantidad de Caracteres\n");
    printf("5- Invertir Palabra\n");
    printf("6- Cadena sin Espacios\n");
    printf("7- Solo caracteres Alfabeticos\n");
    printf("8-Imprimir Diferentes Cadenas \n");
    printf("9- Palindromo O No?\n");
    printf("0- Salir\n");
    printf("Ingrese funcion a utilizar:\n");
    scanf("%d",&op);

    
    return op;
}

void menu (void)
{
    int op;
    char word[50];
    do
    {
        system("CLS");
        op=msges();

        if(op!=0)
        {    
            printf("Ingresa una palabra: \n");
            fflush(stdin);
            gets(word);
        }
        
        switch (op)
        {
        case 1:
            convertirMayusc(word);
            break;
        case 2:
            convertirMinusculas(word);
            break;
        case 3:
            convertirCapital(word);
            break;
        case 4:
            cantidadDeCaracteres(word);
            break;
        case 5:
            invertirPalabra(word);
            break;
        case 6:
            cadenaSinEspacios(word);
            break;
        case 7:
            cadenaAlfabetico(word);
            break;
        case 8:
            Cadenas(word);
            break;
        case 9:
            palindromoOno(word);
            break;

        case 0:
            printf("Gracias por usar!");
            break;
        default:
            break;
        }  

        system("PAUSE");
    } while (op!=0);
    
}
// Imprime la cadena en mayúscula.
// QVDD_Act7_parte2_01_932
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
//**************************************

// Imprime la cadena en Minusculas.
// QVDD_Act7_parte2_02_932
void convertirMinusculas(char *string)
{
    int i;
    for (i = 0; string[i] != '\0'; i++)
    {
        if (string[i] >='A')
        {
            if (string[i]<='Z')
            {
                string[i]=string[i]+32;
            }
        }
    }
    printf("\n%s\n",string);
}
//***************************************

// Imprimir la cadena en Capital.
// QVDD_Act7_parte2_03_932

void convertirCapital(char *string)
{
    if (string[0] >='a')
    {
        if (string[0]<='z')
        {
            string[0]=string[0]-32;
        }
    } 
    printf("\n %s \n",string);
}
//*************************************

// Imprime el numero de caracteres de la cadena.
// QVDD_Act7_parte2_04_932
void cantidadDeCaracteres(char *string)
{
    int size=0;

    while(string[size]!='\0')
    {
        size++;
    }
    printf("La cadena tiene %d caracteres\n",size);
}
//**************************************************
// Imprime la cadena en orden inverso.
// QVDD_Act7_parte2_05_932
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
}
//******************************************

// Imprime la cadena sin Espacios.
// QVDD_Act7_parte2_06_932
void cadenaSinEspacios(char *string)
{
    int i,j,size=0;
    while(string[size]!='\0')
    {
        size++;
    }

    for (i = 0,j = 0; i < size; i++)
    {
        if (string[i] != ' ')
        {
            string[j++]=string[i];
        }
    }
    string[j] = '\0';
    
    printf("%s\n",string);   
}
//***********************************

/* Imprime solamente caracteres alfabeticos
y verifica que no tenga Espacios al principio o al final*/
// QVDD_Act7_parte2_06_932
void cadenaAlfabetico (char *string)
{
    int i, j;
    char stringVerificado[30];

    // Programa
    for (i = 0, j = 0; string[i] != '\0'; i++)
    {
        // Verifica si es un caracter alfabetico o espacio
        if ((string[i] == ' ') || (string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z'))
        {
            // Verifica si no existe un doble espacio y que el primer y ultimo caracter no sean espacio.
            if (string[i] != ' ' || (i > 0 && string[i + 1] != '\0' && string[i - 1] != ' '))
            {
                stringVerificado[j] = string[i];
                printf("%c", stringVerificado[j]);
                j++;
            }
        }
    }
}
//********************************************************************************************************************

/*Imprime la cadena en MAYUSCULAS, minusculas
Capital,SinEspacios y Alreves*/
// QVDD_Act7_parte2_08_932
void Cadenas (char *string)
{
    char stringOrig[30];
    char Alreves[30];

    int i;
    for (i = 0; string[i] != '\0'; i++) {
        stringOrig[i] = string[i];
    }
    stringOrig[i] = '\0';
    
    for (i = 0; string[i] != '\0'; i++) {
        Alreves[i] = string[i];
    }
    Alreves[i] = '\0';
    
    printf("Palabra en Mayusculas: \n");
    convertirMayusc(string);
    printf("\n");
    printf("Palabra en Minusculas: \n");
    convertirMinusculas(string);
    printf("\n");
    printf("Palabra en Capital: \n");
    convertirCapital(string);
    printf("\n");
    printf("Palabra sin Espacios: \n");
    cadenaSinEspacios(stringOrig);
    printf("\n");
    printf("Palabra Invertida: \n");
    invertirPalabra(Alreves);
    printf("%s",Alreves);
    printf("\n");
}
//****************************************

/* Recibe una cadena y determina si es
Palindroma o no*/
// QVDD_Act7_parte2_09_932
void palindromoOno (char *string)
{
    char alreves[30];
    int i;
    for (i = 0; string[i] != '\0'; i++) {
        alreves[i] = string[i];
    }
    alreves[i] = '\0';

    int size=0;
    while (alreves[size] != '\0')
    {
        size++;
    }
    
    int aux;
    for (int i = 0,j=size-1; i<j; i++,j--)
    {
        aux=alreves[i];
        alreves[i]=alreves[j];
        alreves[j]=aux;
    }

    convertirMinusculas(string);
    convertirMinusculas(alreves);

    if (*alreves==*string)
    {
        printf("La palabra ingresada es un PALINDROMO\n");
    }
    else
    {
        if (*alreves!=*string)
        {
            printf("La palabra ingresada NO es un PALINDROMO\n");
        }
        
    }
}
//********************************************************************