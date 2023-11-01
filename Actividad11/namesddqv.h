#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
    Funcion que tiene una lista de nombres y te da uno aleatorio
    puede regresar 1 o 2 nombres, pueden ser masculino o femenino
    todo aleatorio
*/
void genName(char name[50])
{
    char maleName[25][50] = {
        "Alejandro", "Juan", "Manuel", "Jose", "Luis", "Carlos", "Pedro",
        "Antonio", "Javier", "Miguel", "David", "Francisco",
        "Raul", "Daniel", "Guillermo", "Alberto", "Mario", "Eduardo",
        "Angel", "Sergio", "Oscar", "Ruben", "Fernando", "Jorge", "Diego"};

    char femName[25][50] = {
        "Maria", "Ana", "Laura", "Isabel", "Carmen", "Rosa", "Patricia",
        "Sara", "Elena", "Andrea", "Marta", "Sofia",
        "Beatriz", "Natalia", "Clara", "Silvia", "Lucia", "Catalina",
        "Diana", "Lorena", "Vanessa", "Alicia", "Carolina", "Julieta"};
        
    int OneOrTwo = rand() % 2 + 1; // 1 para un solo nombre, 2 para dos
    int ForM = rand() % 2 + 1;     // 1 para masculino, 2 para femenino
    int namerand, namerand2;

    if (OneOrTwo == 1)
    {
        if (ForM == 1)
        {
            namerand = rand() % 25;
            strcpy(name, maleName[namerand]);
        }
        else if (ForM == 2)
        {
            namerand = rand() % 25;
            strcpy(name, femName[namerand]);
        }
    }
    else if (OneOrTwo == 2)
    {
        if (ForM == 1)
        {

            namerand = rand() % 25;
            // Comprobar que el segundo nombre no sea igual al primero
            do
            {
                namerand2 = rand() % 25;
            } while (namerand2 == namerand);

            sprintf(name, "%s %s", maleName[namerand], maleName[namerand2]);
        }
        else if (ForM == 2)
        {
            namerand = rand() % 25;
            // Comprobar que el segundo nombre no sea igual al primero
            do
            {
                namerand2 = rand() % 25;
            } while (namerand2 == namerand);

            sprintf(name, "%s %s", femName[namerand], femName[namerand2]);
        }
    }
}
//*****************************************************************

// Funcion que tiene una lista de apellidos y te da uno aleatorio
void genLastName(char lastname[30])
{
    char LastNamelist[30][25] = {"Gonzalez", "Rodriguez", "Lopez", "Perez", "Martinez", "Garcia", "Sanchez",
                                 "Romero", "Fernandez", "Torres", "Ruiz", "Diaz",
                                 "Jimenez", "Vargas", "Castro", "Morales", "Rivera", "Ortega", "Parra", "Yepiz", "Aguilar", "Navarro", "Ramirez", "Vicencio", "Llamas", "Diarte"};

    int namerand = rand() % 25;

    strcpy(lastname, LastNamelist[namerand]);
}

/*
    Funcion que detecta el sexo de el alumno mediante su nombre
    retorna 2 si es mujer y 1 si es hombre
*/
int sexDetect(char name[30])
{
    char femName[25][25] = {
        "Maria", "Ana", "Laura", "Isabel", "Carmen", "Rosa", "Patricia",
        "Sara", "Elena", "Andrea", "Marta", "Sofia",
        "Beatriz", "Natalia", "Clara", "Silvia", "Lucia", "Catalina",
        "Diana", "Lorena", "Vanessa", "Alicia", "Carolina", "Julieta"};

    char nametemp[30];      // Se genera una cadena temporal
    strcpy(nametemp, name); // se copia el nombre a comparar en el temporal

    // Se recorta la cadena hasta antes del primer espacio" ", en casod de que sean
    // dos nombres
    strtok(nametemp, " ");

    for (int i = 0; i < 25; i++)
    {
        if (strcmp(nametemp, femName[i]) == 0)
        {
            return 2;
        }
    }
    return 1;
}