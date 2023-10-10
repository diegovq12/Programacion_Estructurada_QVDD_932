#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Funcion que tiene una lista de nombres y te da uno aleatorio
    puede regresar 1 o 2 nombres, pueden ser masculino o femenino
    todo aleatorio
*/
char genName ()
{
    srand(time(NULL));
    char maleName[30][25] = {"Alejandro","Juan"
    ,"Manuel","Jose","Luis","Carlos","Pedro",
    "Antonio","Javier","Miguel","David","Francisco",
    "Raúl","Daniel","Guillermo","Alberto","Mario","Eduardo"
    ,"Ángel","Sergio","Oscar","Rubén","Fernando","Jorge","Diego"};

    char femName[30][25] = {"María","Ana"
    ,"Laura","Isabel","Carmen","Rosa","Patricia",
    "Sara","Elena","Andrea","Marta","Sofía",
    "Beatriz","Natalia","Clara","Silvia","Lucía","Catalina"
    ,"Diana","Lorena","Vanessa","Alicia","Carolina","Jorge"};

    int OneOrTwo = rand()% 2 + 1;// 1 para un solo nombre 2 para dos
    int ForM = rand()% 2 + 1; // 1 para Masc 2 para Fem
    int namerand,namerand2;
    if (OneOrTwo == 1)
    {
        if (ForM == 1)
        {
            namerand==rand()% 25 ;
            return maleName[30][namerand];
        }
        else if (ForM == 2)
        {
            namerand==rand()% 25;
            return femName[30][namerand];
        }  
    }
    else if(OneOrTwo == 2)
    {
        if (ForM == 1)
        {
            namerand==rand()% 25;
            namerand2==rand()% 25;
            return maleName[30][namerand] + printf(" ") + maleName[30][namerand2];
        }
        else if (ForM == 2)
        {
            namerand==rand()% 25;
            namerand2==rand()% 25;
            return femName[30][namerand] + printf(" ") + femName[30][namerand2];
        }  
    }
}
//*****************************************************************

//Funcion que tiene una lista de apellidos y te da uno aleatorio
char genLastName ()
{
    srand(time(NULL));
    char lastName[30][25] = {"Gonzalez","Rodriguez"
    ,"Lopez","Perez","Martinez","Garcia","Sanchez",
    "Romero","Fernandez","Torres","Ruiz","Diaz",
    "Jimenez","Vargas","Castro","Morales","Rivera","Ortega"
    ,"Parra","Yepiz","Aguilar","Navarro","Ramirez","Vicencio","Llamas"};

    int namerand = rand()% 25 ;;

    return lastName[30][namerand];

}