#include "ddqvalhd.h"
#include "namesddqv.h"

#define MAX_REG 4200
#define ADD_REG 100
#define REGSBIN 3360
#define TRUE 1
#define FALSE 0

typedef int Tkey;

typedef struct _trabajador
{
    int status;
    Tkey id;
    char nombre[30];
    char apellidoP[50];
    char apellidoM[50];
    char sexo[15];
    char puesto[30];
    char estado[30];
    int edad;
    Tkey celular;

} Templeado;

// PROTOTIPOS
int msges(void);
void menu(void);

int cargarBin(Templeado vect[]);

void llenarRegistroAuto(Templeado vector[], int index);
int generarCelular(void);
void detectarSexo(Templeado vect);
void generarPuestoAleatorio(char code[]);
void generarEstadoAleatorio(char code[]);


int buscarId(Templeado vect[], int indice, int ordenado);
void bubbleSortIds(Templeado vector[], int m);
void quikSort(Templeado list[], int index);
void qs(Templeado lista[], int limiteIzquierdo, int limiteDerecho);
int binarySearchId(Templeado vect[], int val, int start, int end);
int searchLinearId(Templeado vector[], int m, int val);
void mostrar1Registro(Templeado vector[], int num);
void individualList(Templeado vect);
void imprimirRegistros(Templeado vect[], int index);
//***************

int main()
{
    srand(time(NULL));
    // system("./contarRegistros.exe");
    menu();
    return 0;
}

int msges(void)
{
    int op;
    printf("========================================");
    printf("\nR E G I S T R O S U A B C\n");
    printf("1 .- AGREGAR\n");
    printf("2 .- ELIMINAR REGISTRO\n");
    printf("3 .- BUSCAR REGISTRO\n");
    printf("4 .- ORDENAR REGISTROS\n");
    printf("5 .- IMPRIMIR REGISTROS ORIGINAL\n");
    printf("6 .- IMPRIMIR REGISTROS ORDENADO\n");
    printf("7 .- GENERAR ARCHIVO TEXTO\n");
    printf("8 .- EMPAQUETAR\n");
    printf("0. SALIR\n");
    printf("========================================\n");
    op = validInt(0, 8, "INGRESA FUNCION A UTILIZAR: ", "OPCION INVALIDA");
    // printf("========================================");
    return op;
}

void menu()
{
    int op;
    Tkey noEmpleados = 0;
    // int ordenado = 0;
    // char nombreArchivo[20];
    // int cargado = FALSE;
    Templeado empleados[MAX_REG];

    noEmpleados = cargarBin(empleados);
    system("PAUSE");
    do
    {
        system("CLS");
        op = msges();
        system("CLS");

        switch (op)
        {
        case 1:
            if (noEmpleados + ADD_REG <= MAX_REG)
            {
                for (int i = 0; i < ADD_REG; i++)
                {
                    llenarRegistroAuto(empleados, noEmpleados);
                    noEmpleados++;
                    // ordenado = FALSE;
                }
                printf("SE HAN LLENADO %d REGISTROS SATISFACTORIAMENTE\n", ADD_REG);
            }
            else
            {
                printf("SE EXCEDERIA EL LIMITE DE REGISTROS PERMITIDO\n");
            }
            system("PAUSE");
            break;

        case 2:

            break;

        case 6:
            imprimirRegistros(empleados, noEmpleados);
            system("PAUSE");
            break;

        default:
            printf("\nFINALIZANDO PROGRAMA...");
            break;
        }
    } while (op != 0);
}

// FUNCIONES PARA IMPRIMIR REGISTROS
void imprimirRegistros(Templeado vect[], int index)
{
    int i;
    printf("%-6s %-15s %-15s %-15s %-15s %-5s %-6s %-10s      %-9s   %s\n",
           "No.", "ID", "NOMBRE", "APELLIDO PAT", "APELLIDO MAT", "EDAD", "SEXO", "PUESTO", "CELULAR", "ESTADO");
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
            printf("%-6s %-15s %-15s %-15s %-15s %-5s %-6s %-10s      %-9s   %s\n",
                   "No.", "ID", "NOMBRE", "APELLIDO PAT", "APELLIDO MAT", "EDAD", "SEXO", "PUESTO", "CELULAR", "ESTADO");
        }
    }
    printf("=======================================================\n");
}

void individualList(Templeado vect)
{
    printf("%-5d        %-15s    %-15s %-15s %-4d %-6s %-10s      %-9d    %-19s\n",
           vect.id,
           vect.nombre,
           vect.apellidoP,
           vect.apellidoM,
           vect.edad,
           vect.sexo,
           vect.puesto,
           vect.celular,
           vect.estado);
}

void mostrar1Registro(Templeado vector[], int num)
{

    printf("\nID: %d\n", vector[num].id);
    printf("NOMBRE: %s\n", vector[num].nombre);
    printf("APELLIDO PAT: %s\n", vector[num].apellidoP);
    printf("APELLIDO MAT: %s\n", vector[num].apellidoM);
    printf("PUESTO: %s\n", vector[num].puesto);
    printf("EDAD: %d\n", vector[num].edad);
    printf("SEXO: %s\n", vector[num].sexo);
    printf("CELULAR: %d\n", vector[num].celular);
    printf("ESTADO: %s\n", vector[num].estado);
}
//****************************************************************************

// FUNCIONES PARA GENERAR EL REGISTRO
void llenarRegistroAuto(Templeado vector[], int index)
{
    
    FILE *fa;
    int i, id;
    Templeado vect;

    fa = fopen("datosmod.dat","ab");
    
    // if (fa == NULL)
    // {
    //     perror("ERROR AL AGREGAR REGISTRO");
    //     return -1;
    // }


    

    vect.status = 1;
    do
    {
        id = randNum(300000, 399999);
        i = searchLinearId(vector, index, id);
    } while (i != -1);

    vect.id = id;

    genLastName(vect.apellidoP);
    genLastName(vect.apellidoM);
    genNameV2(vect.nombre);
    detectarSexo(vect, index);
    generarPuestoAleatorio(vect.puesto);
    generarEstadoAleatorio(vect.estado);
    vect.edad = randNum(18, 60);
    vect.celular = generarCelular();

    fwrite(&vect,sizeof(Templeado),1,fa);
    fclose(fa);
    (index)++;
}

int generarCelular(void)
{
    int lada = 646000000;
    int num = randNum(100000, 999999);

    return lada + num;
}

void detectarSexo(Templeado vect)
{
    int sexo = sexDetectV2(vect.nombre);
    if (sexo == 2)
    {
        strcpy(vect.sexo, "MUJER");
    }
    else
    {
        strcpy(vect.sexo, "HOMBRE");
    }
}

void generarPuestoAleatorio(char code[])
{
    char listaTrabajos[35][30] = {"INTENDENTE", "MAESTRO", "COORDINADOR", "DIRECTOR",
                                  "SUBDIRECTOR", "SECRETARIO", "PSICOLOGO", "ASISTENTE",
                                  "ESPECIALISTA", "BIBLIOTECARIO", "BECARIO"};

    int num = randNum(0, 10);
    strcpy(code, listaTrabajos[num]);
}

void generarEstadoAleatorio(char code[])
{
    char stateCodeList[35][30] = {"AS", "BC", "BS", "CC", "CS", "CH", "CL", "CM", "MC", "DG", "DF", "GT", "GR", "HG", "JC", "MN", "MS",
                                  "NT", "NL", "OC", "PL", "QT", "QR", "SP", "SL", "SR", "TC", "TS", "TL", "VZ", "YN", "ZS", "NE"};

    int num = randNum(0, 32);
    strcpy(code, stateCodeList[num]);
}
//******************************************************************************************************

// METODOS DE ORDENACION Y BUSQUEDA
int searchLinearId(Templeado vector[], int m, int val)
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
int binarySearchId(Templeado vect[], int val, int start, int end)
{
    int mid;

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (vect[mid].id == val)
        {
            return mid;
        }
        else if (val < vect[mid].id)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return -1;
}
int buscarId(Templeado vect[], int indice, int ordenado)
{
    int num;
    int id = validInt(300000, 399999, "INGRESA ID: ", "FUERA DE RANGO\n");
    if (ordenado == FALSE)
    {
        num = searchLinearId(vect, indice, id);
        if (num != -1)
        {
            mostrar1Registro(vect, num);
        }
        else
        {
            printf("ID NO REGISTRADO\n");
        }
    }
    else
    {
        num = binarySearchId(vect, id, 0, indice);
        if (num != -1)
        {
            mostrar1Registro(vect, num);
        }
        else
        {
            printf("ID INVALIDO\n");
        }
    }
    return num;
}
void qs(Templeado lista[], int limiteIzquierdo, int limiteDerecho)
{
    int izquierda, derecha, aux;
    Templeado temp;
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

void quikSort(Templeado list[], int index)
{
    qs(list, 0, index - 1);
}

void bubbleSortIds(Templeado vector[], int m)
{
    int i, j;
    Templeado aux;

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
//*****************************************************************

//OPERACIONES CON REGISTROS
void eliminarRegistro(Templeado empleado[], int indice, int ordenado)
{

    Templeado worker;
    FILE *fa;
    Tkey i;

    int num = buscarId(empleado, indice, ordenado);
    if (num != -1)
    {
        int op = validInt(1, 2, "DAR DE BAJA (1\\SI 2\\NO): ", "OPCION INVALIDA - FUERA DE RANGO");

        if (op == 1)
        {
            empleado[num].status = 0;
            fseek(fa, empleado[i].id * sizeof(Templeado), SEEK_SET);
            fwrite(&worker, sizeof(Templeado), 1, fa);
            printf("EMPLEADO DADO DE BAJA.\n");
        }
    }
    else
    {
        printf("MATRICULA NO REGISTRADA\n");
    }
    system("PAUSE");
}
/******************************************************************/

int cargarBin(Templeado vect[])
{
    FILE *fa;
    int i;
    Templeado temp[REGSBIN];

    fa = fopen("datos.dat", "rb");

    if (fa == NULL)
    {
        printf("ERROR AL LEER EL ARCHIVO\n");
        return -1;
    }

    fread(temp, sizeof(Templeado), REGSBIN, fa);

    for (i = 0; i < REGSBIN; i++)
        vect[i] = temp[i];

    printf("SE HAN CARGADO LOS REGISTROS DEL ARCHIVO BINARIO EXITOSAMENTE\n");
    fclose(fa);

    return i;
}