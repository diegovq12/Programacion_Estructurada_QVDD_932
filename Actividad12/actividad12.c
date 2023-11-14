#include "ddqvalhd.h"
#include "namesddqv.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX_REGS 1500
#define AGG_REG 10

typedef struct _fullName
{
    char fLastName[50];
    char mLastName[50];
    char name[50];
} Tfullname;

typedef struct _date
{
    int year;
    int month;
    int day;
} Tdate;

typedef struct _State
{
    char state[20];
    char stCode[3];
} Tstate;

typedef struct _student
{
    int status;
    int id;
    Tfullname fullName;
    Tdate born;
    int age;
    char sex[15];
    Tstate state;
} Tstudent;

//***************************
int msges(void);
void menu(void);
int loadFile(Tstudent vect[], int index, char name[]);
void printRegs(Tstudent vect[], int index);
void individualList(Tstudent vect);
void qs(Tstudent lista[], int limiteIzquierdo, int limiteDerecho);
void quikSort(Tstudent list[], int index);
void bubbleSortIds(Tstudent vector[], int m);
int searchLinearId(Tstudent vector[], int m, int val);
void getState(char code[], int stateCode);
int generarDiaAleatorio(int anio, int mes);
void fillAtmReg(Tstudent vect[], int index);
void print1Register(Tstudent vector[], int num);
//***************************

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

int msges(void)
{
    int op;
    printf("R E G I S T R O S U A B C\n");
    printf("1.- LOAD FILE\n");
    printf("2.- ADD REGISTER\n");
    printf("3.- DELETE\n");
    printf("4.- SEARCH\n");
    printf("5.- SORT\n");
    printf("6.- SHOW EVERYTHING\n");
    printf("7.- GENERATE FILE\n");
    printf("8.- AMMOUNT OF REGISTERS IN FILE\n");
    printf("9.- SHOW DELETED\n");
    printf("0. CLOSE\n");
    op = validInt(0, 6, "SELECT AN OPTION: ", "INVALID OPTION");
    return op;
}

void menu(void)
{
    Tstudent student[MAX_REGS];
    int op, op2, id, num;
    int loaded = FALSE;
    int index = 0;
    int sorted;
    char fileName[20];

    do
    {
        system("CLS");
        op = msges();

        switch (op)
        {
        case 1:
            // CARGAR ARCHIVO DE TEXTO
            if (loaded == TRUE)
            {
                printf("FILE LOADED PREVOUSLY\n");
            }
            else
            {
                if (index + 313 < MAX_REGS)
                {
                    getString(fileName, "FILE NAME: ");
                    index = loadFile(student, index, fileName);
                    loaded = TRUE;
                    sorted = FALSE;
                }
            }
            printf("\n%d\n", index);
            system("PAUSE");
            break;
        case 2:
            if (index + AGG_REG <= MAX_REGS)
            {
                for (int i = 0; i < AGG_REG; i++)
                {
                    fillAtmReg(student, index);
                    index++;
                }
                sorted = FALSE;
                printf("FILLED %d REGISTERS\n", AGG_REG);
            }
            system("PAUSE");
            break;
        case 3:

            id = validInt(300000, 399999, "ENTER ID: ", "ID OUT OF RANGE\n");
            num = searchLinearId(student, index, id);

            if (num != -1)
            {
                print1Register(student, num);
                op2 = validInt(1, 2, "CANCEL ID (1\\YES 2\\NO): ", "INVALID OPTION - OUT OF RANGE");
                if (op2 == 1)
                {
                    student[num].status = 0;
                    printf("STUDENT ID CANCELED.\n");
                }
            }
            else
            {
                printf("ID NO EXIST\n");
            }
            system("PAUSE");
            break;

        case 4:
            id = validInt(300000, 399999, "INGRESAR MATRICULA A BUSCAR: ", "MATRICULA FUERA DE RANGO\n");
            if (sorted == FALSE)
            {
                num = searchLinearId(student, index, id);
                if (num != -1)
                {
                    print1Register(student, num);
                }
                else
                {
                    printf("MATRICULA NO REGISTRADA\n");
                }
            }
            else
            {
                num = binarySearchId(student, id, 0, index);
                if (num != -1)
                {
                    print1Register(student, num);
                }
                else
                {
                    printf("ID INVALID\n");
                }
            }
            system("PAUSE");
            break;
        case 5:

            break;

        case 6:
            printRegs(student, index);
            system("PAUSE");
            break;
        default:
            break;
        }
    } while (op != 0);
}

int loadFile(Tstudent vect[], int index, char name[])
{
    FILE *fa;
    Tstudent reg;
    int tempN = 0;

    char dir[] = "C:\\\\Users\\\\diego\\\\Documents\\\\diegouni\\\\Programacion_Estructurada_QVDD_932\\\\Actividad12\\\\";
    strcat(dir, name);
    strcat(dir, ".txt");
    fa = fopen(dir, "r");

    if (fa)
    {

        do
        {
            int result = fscanf(fa, "%d.- %d %s %s %s %d %s", &tempN, &reg.id, reg.fullName.name, reg.fullName.fLastName, reg.fullName.mLastName, &reg.age, reg.sex);
            if (result == 7)
            {
                reg.status = 1;
                vect[index++] = reg;
            }
        } while (!feof(fa));

        printf("\nFILE LOADED\n");
        fclose(fa);
    }
    else
    {
        printf("\nFILE UNAVAILABLE\n");
    }
    return index - 1;
}

void fillAtmReg(Tstudent vect[], int index)
{
    int i, id;

    vect[index].status = 1;
    do
    {
        id = 300000 + rand() % (399999 - 300000 + 1);
        i = searchLinearId(vect, index, id);
    } while (i != -1);

    vect[index].id = id;

    genLastName(vect[index].fullName.fLastName);
    genLastName(vect[index].fullName.mLastName);
    genNameV2(vect[index].fullName.name);

    convertMayus(vect[index].fullName.fLastName);
    convertMayus(vect[index].fullName.mLastName);
    vect[index].born.year = 1900 + rand() % (2007 - 1900 + 1);

    vect[index].born.month = 1 + rand() % (12 - 1 + 1);

    vect[index].born.day = generarDiaAleatorio(vect[index].born.year, vect[index].born.month);

    if (vect[index].born.month < 12)
    {
        vect[index].age = 2023 - vect[index].born.year;
    }
    else
    {
        vect[index].age = 2022 - vect[index].born.year;
    }

    int sexCode = sexDetectV2(vect[index].fullName.name);

    if (sexCode == 2)
    {
        strcpy(vect[index].sex, "FEMENINO");
    }
    else
    {
        strcpy(vect[index].sex, "MASCULINO");
    }

    int stateCode = 1 + rand() % (33 - 1 + 1);

    getState(vect[index].state.state, stateCode);
}

int generarDiaAleatorio(int anio, int mes)
{
    int dia;
    // determinar anio bisiesto
    int bisiesto = FALSE;

    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
    {
        dia = 1 + rand() % (31 - 1 + 1);
        ;
    }

    if (mes == 2)
    {
        if ((anio % 4 == 0 && anio % 100 != 0) || anio == 2000 || anio == 1000)
        {
            bisiesto = TRUE;
        }
        if (bisiesto == TRUE)
        {
            dia = 1 + rand() % (29 - 1 + 1);
        }
        else
        {
            dia = 1 + rand() % (28 - 1 + 1);
        }
    }

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        dia = 1 + rand() % (30 - 1 + 1);
    }

    return dia;
}

void getState(char code[], int stateCode)
{
    char stateCodeList[35][30] = {"AGUASCALIENTES", "BAJA CALIFORNIA", "BAJA CALIFORNIA SUR", "CAMPECHE", "CHIAPAS", "CHIHUAHUA", "COAHUILA", "COLIMA", "CDMX", "DURANGO",
                                  "DISTRITO FEDERAL", "GUANAJUATO", "GUERRERO", "HIDALGO", "JALISCO", "MICHOACAN", "MORELOS", "NAYARIT", "NUEVO LEON", "OAXACA",
                                  "PUEBLA", "QUERETARO", "QUINTANA ROO", "SAN LUIS POTOSI", "SINALOA", "SONORA", "TABASCO", "TAMAULIPAS", "TLAXCALA", "VERACRUZ",
                                  "YUCATAN", "ZACATECAS", "EXTRANJERO"};

    for (int i = 0; i < 33; i++)
    {
        if (stateCode == i + 1)
        {
            strcpy(code, stateCodeList[i]);
        }
    }
}

void printRegs(Tstudent vect[], int index)
{
    int i;
    printf("%-6s %-10s %-10s %-15s %-15s %-5s %s\n", "No.", "ID", "NAME", "F LAST NAME", "M LAST NAME", "AGE", "SEX");
    for (i = 0; i < index; i++)
    {
        if (vect[i].status)
        {
            printf("%-7d", i + 1);
            individualList(vect[i]);
        }

        if ((i + 1) % 40 == 0)
        {
            system("PAUSE");
            system("CLS");
            printf("%-6s %-10s %-10s %-15s %-15s %-5s %s\n", "No.", "ID", "NAME", "F LAST NAME", "M LAST NAME", "AGE", "SEX");
        }
    }
    printf("----------------------------------");
}

void individualList(Tstudent vect)
{
    printf("%-10d %-10s %-15s %-15s %-5d %s\n",
           vect.id,
           vect.fullName.name,
           vect.fullName.fLastName,
           vect.fullName.mLastName,
           vect.age,
           vect.sex);
}

void qs(Tstudent lista[], int limiteIzquierdo, int limiteDerecho)
{
    int izquierda, derecha, aux;
    Tstudent temp;
    izquierda = limiteIzquierdo;
    derecha = limiteDerecho;
    aux = lista[(izquierda + derecha) / 2].id;

    do
    {
        while (lista[izquierda].id < aux && izquierda < limiteDerecho)
        {
            izquierda++;
        }
        while (aux < lista[derecha].id && derecha > limiteIzquierdo)
        {
            derecha--;
        }
        if (izquierda <= derecha)
        {
            temp = lista[izquierda];
            lista[izquierda] = lista[derecha];
            lista[derecha] = temp;
            izquierda++;
            derecha--;
        }

    } while (izquierda <= derecha);
    if (limiteIzquierdo < derecha)
    {
        qs(lista, limiteIzquierdo, derecha);
    }
    if (limiteDerecho > izquierda)
    {
        qs(lista, izquierda, limiteDerecho);
    }
}

void quikSort(Tstudent list[], int index)
{
    qs(list, 0, index - 1);
}

void bubbleSortIds(Tstudent vector[], int m)
{
    int i, j;
    Tstudent aux;

    for (i = 0; i < m - 1; i++)
    {
        for (j = i + 1; j < m; j++)
        {
            if (vector[i].id > vector[j].id)
            {
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }
}

int searchLinearId(Tstudent vector[], int m, int val)
{
    int i;

    for (i = 0; i < m; i++)
    {
        if (vector[i].id == val)
        {
            return i;
        }
    }
    return -1;
}

void print1Register(Tstudent vector[], int num)
{
    // char sexo[2][10] = {"HOMBRE", "MUJER"};
    // char sexalumn[10];
    // char estado[30];
    /*char estados[35][35] = {"Aguascalientes", "Baja California", "Baja California Sur", "Campeche",
                            "Chiapas", "Chihuahua", "Coahuila", "Colima", "Ciudad de Mexico/CDMX", "Durango",
                            "Estado de Mexico", "Guanajuato", "Guerrero", "Hidalgo", "Jalisco", "Michoacan", "Morelos", "Nayarit",
                            "Nuevo Leon", "Oaxaca", "Puebla", "Queretaro", "Quintana Roo", "San Luis Potosi", "Sinaloa",
                            "Sonora", "Tabasco", "Tamaulipas", "Tlaxcala", "Veracruz", "Yucatan", "Zacatecas", "Extranjero"};
    */
    printf("ID: %d\n", vector[num].id);
    printf("NAME: %s\n", vector[num].fullName.name);
    printf("F. LAST NAME: %s\n", vector[num].fullName.fLastName);
    printf("M LAST NAME: %s\n", vector[num].fullName.mLastName);
    printf("AGE: %d\n", vector[num].age);
    printf("SEX: %s\n", vector[num].sex);
    printf("STATE: %s\n", vector[num].state.state);
}