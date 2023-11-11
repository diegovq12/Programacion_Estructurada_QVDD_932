#include "ddqvalhd.h"

#define TRUE 1
#define FALSE 0

#define AGG_REG 100

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
    char sex[8];
    Tstate state;
} Tstudent;

//***************************
int msges(void);
void menu(void);
void loadFile(Tstudent vect[],int index, char name[]);

//***************************

int main()
{
    menu();
    return 0;
}

int msges(void)
{
    int op;
    printf("R E G I S T R O S U A B C\n");
    printf("1.- CARGAR ARCHIVO\n");
    printf("2.- ADD\n");
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
    Tstudent student[1501];
    int op;
    int loaded = 0, sorted = 0, index = 0;
    char fileName[20];
    do
    {
        system("CLS");
        op = msges();

        switch (op)
        {
        case 1:
            //CARGAR ARCHIVO DE TEXTO
            fflush(stdin);
            getString(fileName,"ENTER FILE NAME: ");
            loadFile(student,index,fileName);
            system("PAUSE");
            break;
        case 2:

            break;
        case 3:

            break;

        case 4:

            break;
        case 5:

            break;

        case 6:

            break;
        default:
            break;
        }
    } while (op != 0);
}

void loadFile(Tstudent vect[],int index, char name[])
{
    int i;
    int x;
    // Tstudent reg;
    FILE *fa;
    strcat(name,".txt");
    fa = fopen(name, "r");
    if (fa)
    {        
        fscanf(fa,"ID   F LAST NAME                           M LAST NAME                            NAME                               AGE   SEX      STATE\n\n", &x,x,x,x,x,x,x);

        do
        {
            fscanf(fa,"%-9d   %-30s   %-30s   %-30s   %-4d   %-7s  %-20s\n", vect[i].id, vect[i].fullName.fLastName, vect[i].fullName.mLastName, vect[i].fullName.name,vect[i].age, vect[i].sex, vect[i].state.state);
            index++;
        } while (!feof(fa));
        printf("FILE LOADED");
        fclose(fa);
    }
    else
    {
        printf("FILE UNAVAILABLE");
    }
}

/*void fillAtmReg (Tstudent vect[], int index)
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
    genName(vect[index].fullName.name);

    vect[index].born.year = 1900 + rand() % (2007 - 1900 + 1);

    vect[index].born.month = 1 + rand() % (12 - 1 + 1);

    vect[index].born.day = generarDiaAleatorio(vect[index].born.year, vect[index].born.month);

    if ( vect[index].born.month < 12)
    {
       vect[index].age = 2023 - vect[index].born.year; 
    }
    else
    {
        vect[index].age = 2022 - vect[index].born.year;
    }
    vect[index].sex = sexDetect(vect[index].fullName.name);

    int stateCode = 1 + rand() % (33 - 1 + 1);

    getState(vect[index].state.state,stateCode);

}
*/
/*void getState (char code[], int stateCode)
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
*/