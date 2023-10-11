#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
    Funcion que tiene una lista de nombres y te da uno aleatorio
    puede regresar 1 o 2 nombres, pueden ser masculino o femenino
    todo aleatorio
*/
void genName(char name[50]) {

    char maleName[25][25] = {
        "Alejandro", "Juan", "Manuel", "Jose", "Luis", "Carlos", "Pedro",
        "Antonio", "Javier", "Miguel", "David", "Francisco",
        "Raul", "Daniel", "Guillermo", "Alberto", "Mario", "Eduardo",
        "Angel", "Sergio", "Oscar", "Ruben", "Fernando", "Jorge", "Diego"
    };

    char femName[25][25] = {
        "Maria", "Ana", "Laura", "Isabel", "Carmen", "Rosa", "Patricia",
        "Sara", "Elena", "Andrea", "Marta", "Sofia",
        "Beatriz", "Natalia", "Clara", "Silvia", "Lucia", "Catalina",
        "Diana", "Lorena", "Vanessa", "Alicia", "Carolina", "Julieta"
    };

    int OneOrTwo = rand() % 2 + 1;  // 1 para un solo nombre, 2 para dos
    int ForM = rand() % 2 + 1;     // 1 para masculino, 2 para femenino
    int namerand, namerand2;

    if (OneOrTwo == 1) {
        if (ForM == 1) {
            namerand = rand() % 25;
            strcpy(name, maleName[namerand]);
        } else if (ForM == 2) {
            namerand = rand() % 25;
            strcpy(name, femName[namerand]);
        }
    } else if (OneOrTwo == 2) {
        if (ForM == 1) {
            namerand = rand() % 25;
            namerand2 = rand() % 25;
            sprintf(name, "%s %s", maleName[namerand], maleName[namerand2]);
        } else if (ForM == 2) {
            namerand = rand() % 25;
            namerand2 = rand() % 25;
            sprintf(name, "%s %s", femName[namerand], femName[namerand2]);
        }
    }
}
//*****************************************************************

//Funcion que tiene una lista de apellidos y te da uno aleatorio
void genLastName (char lastname[30])
{
    char LastName[30][25] = {"Gonzalez","Rodriguez"
    ,"Lopez","Perez","Martinez","Garcia","Sanchez",
    "Romero","Fernandez","Torres","Ruiz","Diaz",
    "Jimenez","Vargas","Castro","Morales","Rivera","Ortega"
    ,"Parra","Yepiz","Aguilar","Navarro","Ramirez","Vicencio","Llamas"};

    int namerand = rand()% 25 ;

    strcpy(lastname,LastName[namerand]);
}