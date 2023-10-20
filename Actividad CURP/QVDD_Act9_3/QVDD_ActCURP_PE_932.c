#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "ddqvval.h" //propia

#define TRUE 1
#define FALSE 0

int main(void);
void menu(void);
void getFullName (char name[], char lnPat[], char lnMat[]);
int showStates (void);

int main()
{
    menu();
    return 0;
}

int msge(void)
{
    int op;
    printf("\n GENERADOR DE CURP\n");
    printf("1.- GENERAR CURP\n");
    printf("0. Salir\n");
    printf("Ingresa Opcion\n");
    op = validInt(0, 1, "Opcion Invalida");

    return op;
}

void menu(void)
{
    char name[50], lnPat[50], lnMat[50],state[5];
    int op,stateop;
    do
    {

        system("CLS");

        op = msge();

        switch (op)
        {
        case 1:
            getFullName(name, lnPat, lnMat);

            stateop = showStates();
            getState(state,stateop);

            break;
        case 0:
            printf("Fin del programa\n");
            break;
        default:
            break;
        }
        system("PAUSE");
    } while (op != 0);
}

void getFullName (char name[], char lnPat[], char lnMat[])
{
    int correct;
    printf("Ingresa Nombre(s): ");
    fflush(stdin);
    gets(name);
    do
    {   
        correct = validString(name);
        if (correct == FALSE)
        {
            printf("Error - Reingresa correctamente los datos\n");
            printf("Ingresa Nombre(s): ");
            fflush(stdin);
            gets(name);
        }
    } while (correct == FALSE);
    capitalizeWords(name);

    printf("Ingresa Primer Apellido: ");
    fflush(stdin);
    gets(lnPat);
    do
    {   
        correct = validString(lnPat);
        if (correct == FALSE)
        {
            printf("Error - Reingresa correctamente los datos\n");
            printf("Ingresa Primer Apellido: ");
            fflush(stdin);
            gets(lnPat);
        }
    } while (correct == FALSE);
    capitalizeWords(lnPat);

    printf("Ingresa Segundo Apellido: ");
    fflush(stdin);
    gets(lnMat);
    do
    {   
        correct = validString(lnMat);
        if (correct == FALSE)
        {
            printf("Error - Reingresa correctamente los datos\n");
            printf("Ingresa Segundo Apellido: ");
            fflush(stdin);
            gets(lnMat);
        }
    } while (correct == FALSE);
    capitalizeWords(lnMat);    
}

int showStates (void)
{
    printf("Seleccione la entidad de nacimiento:\n");
    printf("1) Aguascalientes \n");
    printf("2) Baja California\n");
    printf("3) Baja California Sur \n");
    printf("4) Campeche \n");
    printf("5) Chiapas \n");
    printf("6) Chihuahua \n");
    printf("7) Coahuila \n");
    printf("8) Colima \n");
    printf("9) Ciudad de Mexico / CDMX \n");
    printf("10) Durango\n");
    printf("11) Estado de Mexico\n");
    printf("12) Guanajuato\n");
    printf("13) Guerrero\n");
    printf("14) Hidalgo\n");
    printf("15) Jalisco\n");
    printf("16) Michoacan\n");
    printf("17) Morelos\n");
    printf("18) Nayarit\n");
    printf("19) Nuevo Leon\n");
    printf("20) Oaxaca\n");
    printf("21) Puebla\n");
    printf("22) Queretaro\n");
    printf("23) Quintana Roo\n");
    printf("24) San Luis Potosi\n");
    printf("25) Sinaloa\n");
    printf("26) Sonora\n");
    printf("27) Tabasco\n");
    printf("28) Tamaulipas\n");
    printf("29) Tlaxcala\n");
    printf("30) Veracruz\n");
    printf("31) Yucatan\n");
    printf("32) Zacatecas\n");
    printf("33) Extranjero\n");
    int op = validInt(1,33,"Opcion Fuera de rango");
    return op;
}

void getState(char state[],int stateop)
{
    char temp[5];
    if (stateop == 1)
    {
        strcpy(state,"AS");
    }
    else
    {
        if (stateop == 2)
        {
            strcpy(state,"BC");
        }
        else
        {
            if (stateop == 3)
            {
                strcpy(state,"BS");
            }
            else
            {
                if (stateop == 4)
                {
                    strcpy(state,"CC");
                }
                else
                {
                    if (stateop == 5)
                    {
                        strcpy(state,"CS");
                    }
                    else
                    {
                        if (stateop == 6)
                        {
                            strcpy(state,"CH");
                        }
                        else
                        {
                            if (stateop == 7)
                            {
                                strcpy(state,"CL");
                            }
                            else
                            {
                                if (stateop == 8)
                                {
                                    strcpy(state,"CM");
                                }
                                else
                                {
                                    if (stateop == 9)
                                    {
                                        strcpy(state,"MC");
                                    }
                                    else
                                    {
                                        if (stateop ==10)
                                        {
                                            strcpy(state,"DG");
                                        }
                                        else
                                        {
                                            if (stateop == 11)
                                            {
                                                strcpy(state,"DF");
                                            }
                                            else
                                            {
                                                if (stateop == 12)
                                                {
                                                    strcpy(state,"GT");
                                                }
                                                else
                                                {
                                                    if (stateop == 13)
                                                    {
                                                        strcpy(state,"GR");
                                                    }
                                                    else
                                                    {
                                                        if (stateop == 14)
                                                        {
                                                            strcpy(state,"HG");
                                                        }
                                                        else
                                                        {   
                                                            if(stateop == 15)
                                                            {
                                                                strcpy(state,"JC");
                                                            }
                                                            else
                                                            {
                                                                if (stateop == 16)
                                                                {
                                                                    strcpy(state,"MN");
                                                                }
                                                                else
                                                                {
                                                                    if(stateop == 17)
                                                                    {
                                                                        strcpy(state,"MS");
                                                                    }
                                                                    else
                                                                    {
                                                                        if (stateop == 18)
                                                                        {
                                                                            strcpy(state,"NT");
                                                                        }
                                                                        else
                                                                        {
                                                                            if (stateop == 19)
                                                                            {
                                                                                strcpy(state,"NL");
                                                                            }
                                                                            else
                                                                            {
                                                                                if (stateop == 20)
                                                                                {
                                                                                    strcpy(state,"OC");
                                                                                }
                                                                                else
                                                                                {
                                                                                    if(stateop == 21)
                                                                                    {
                                                                                        strcpy(state,"PL");
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if (stateop == 22)
                                                                                        {
                                                                                            strcpy(state,"QT");
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                            if (stateop == 23)
                                                                                            {
                                                                                                strcpy(state,"QR");
                                                                                            }
                                                                                            else
                                                                                            {
                                                                                                if (stateop == 24)
                                                                                                {
                                                                                                    strcpy(state,"SP");
                                                                                                }
                                                                                                else
                                                                                                {
                                                                                                    if (stateop == 25)
                                                                                                    {
                                                                                                        strcpy(state,"SL");
                                                                                                    }
                                                                                                    else
                                                                                                    {   
                                                                                                        if(stateop == 26)
                                                                                                        {
                                                                                                            strcpy(state,"SR");
                                                                                                        } 
                                                                                                        else
                                                                                                        {
                                                                                                            if (stateop == 27)
                                                                                                            {
                                                                                                                strcpy(state,"TC");
                                                                                                            }
                                                                                                            else
                                                                                                            {
                                                                                                                if (stateop == 28)
                                                                                                                {
                                                                                                                    strcpy(state,"TS");
                                                                                                                }
                                                                                                                else
                                                                                                                {
                                                                                                                    if (stateop == 29)
                                                                                                                    {
                                                                                                                        strcpy(state,"TL");
                                                                                                                    }
                                                                                                                    else
                                                                                                                    {
                                                                                                                        if (stateop == 30)
                                                                                                                        {
                                                                                                                            strcpy(state,"VZ");
                                                                                                                        }
                                                                                                                        else
                                                                                                                        {
                                                                                                                            if (stateop == 31)
                                                                                                                            {
                                                                                                                                strcpy(state,"YN");
                                                                                                                            }
                                                                                                                            else
                                                                                                                            {
                                                                                                                                if (stateop == 32)
                                                                                                                                {
                                                                                                                                    strcpy(state,"ZS");
                                                                                                                                }
                                                                                                                                else
                                                                                                                                {
                                                                                                                                    if (stateop == 33)
                                                                                                                                    {
                                                                                                                                        strcpy(state,"NE");
                                                                                                                                    }  
                                                                                                                                }
                                                                                                                            }  
                                                                                                                        }
                                                                                                                    }                                                                                             
                                                                                                                } 
                                                                                                            }   
                                                                                                        }
                                                                                                    } 
                                                                                                }  
                                                                                            } 
                                                                                        } 
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        } 
                                                    }
                                                } 
                                            }
                                        }
                                    }      
                                }
                            }
                        }                        
                    }                    
                }                
            }       
        }
    }    
}