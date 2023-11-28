#include "ddqvalhd.h"
#include "namesddqv.h"
/*
Quiros Vicencio Diego Demian
11/23/23(creado) - 11/28/23 (modificado)
MENÚ
1.- AGREGAR
2.- ELIMINAR 
3.- BUSCAR 
4.- ORDENAR
5.- IMPRIMIR REGISTROS ARCHIVO ORIGINAL 
6.- IMPRIMIR REGISTROS ARCHIVO ORDENADO 
7.- GENERAR ARCHIVO TEXTO 
8.- EMPAQUETAR 
0.- SALIR
*/
#define MAX_REG 4200
#define ADD_REG 10
#define REGSBIN 3360
#define TRUE 1
#define FALSE 0

typedef int Tkey;
typedef struct _indice
{
    Tkey id;
    int consecutivo;
    char nombre[30];
    char apellidoP[50];
    char apellidoM[50];
    char sexo[15];
    char puesto[30];
    char estado[30];
    int edad;
    Tkey celular;
} Tindex;

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

int cargarBin(Templeado vect[], Tindex vectindex[], int i);

void llenarRegistroAuto(Templeado vector[], Tindex vectind[], int index);
void eliminarRegistro(Templeado vect[], Tindex vectInd[], int index, int ordenado);

int generarCelular(void);
void detectarSexo(Templeado vect);
void generarPuestoAleatorio(char code[]);
void generarEstadoAleatorio(char code[]);

int buscarId(Templeado vect[], int indice, int ordenado);
void bubbleSortIds(Templeado vector[], int m);
void quikSort(Templeado list[], int index);
void qs(Templeado lista[], int limiteIzquierdo, int limiteDerecho);
int binarySearchId(Templeado vect[], int val, int start, int end);
int binarySearchId2(Tindex vect[], int val, int start, int end);

int binarySearch2(Tindex vect[], int start, int end);
int searchLinearId(Templeado vector[], int m, int val);

void mostrar1Registro(Templeado vector[], int num);
void individualList(Templeado vect);
void imprimirRegistros(Templeado vect[], int index);
void imprimirRegVect_1(Tindex vect[], int posicion);
void imprimirRegVect(Tindex vect[], int posicion);
void imprimirIndicesOrdenados(Tindex vect[], int index);

void buscarRegistro(Templeado vect[], int index, int ordenado);
int encontrarValor(Templeado vect[], int n, int num);
int encontrarValorIndex(Tindex vect[], int n, int num);
void archivo(Templeado vect[], int n, char nombre[]);
void archivoOrdenado(Tindex vect[], int n, char nombre[]);
void empaquetar(Templeado vect[], int n);
//***************

int main()
{
    srand(time(NULL));
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
    Templeado empleados[MAX_REG];
    Tindex vectind[MAX_REG];
    int ordenado = FALSE;
    char nombreArchivo[20];
    int op2;

    noEmpleados = cargarBin(empleados, vectind, noEmpleados);
    // imprimirRegVect(vectind,noEmpleados);

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
                    llenarRegistroAuto(empleados, vectind, noEmpleados);
                    noEmpleados++;
                    ordenado = FALSE;
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
            eliminarRegistro(empleados, vectind, noEmpleados, ordenado);
            system("PAUSE");
            break;
        case 3:
            buscarRegistro(empleados, noEmpleados, ordenado);
            system("PAUSE");
            break;
        case 4:
            if (ordenado == TRUE)
            {
                printf("LOS REGISTROS YA ESTAN ORDENADOS\n");
            }
            else
            {
                if (noEmpleados < 500)
                {
                    bubbleSortIds(empleados, noEmpleados);
                    ordenado = TRUE;
                    printf("SE HAN ORDENADO LOS REGISTROS");
                }
                else
                {
                    quikSort(empleados, noEmpleados);
                    ordenado = TRUE;
                    printf("SE HAN ORDENADO LOS REGISTROS");
                }
            }
            system("PAUSE");
            break;
        case 5:
            imprimirIndicesOrdenados(vectind, noEmpleados);
            system("PAUSE");
            break;
        case 6:
            system("CLS");
            imprimirRegistros(empleados, noEmpleados);
            system("PAUSE");
            break;

        case 7:
            getString(nombreArchivo, "INGRESE EL NOMBRE DE EL ARCHIVO A CREAR: ");
            strcat(nombreArchivo, ".txt");
            op2 = validInt(1, 2, "\nINGRESE TIPO DE ARCHIVO A CREAR (1/ORDENADO 2/NORMAL): ", "INVALIDO (1 - 2)");
            if (op2 == 1)
            {
                archivoOrdenado(vectind, noEmpleados, nombreArchivo);
            }
            else
            {
                archivo(empleados,noEmpleados,nombreArchivo);
            }

            break;
        case 8:
            empaquetar(empleados,noEmpleados);
            printf("ARCHIVOS EMPAQUETADOS EXITOSAMENTE!\n");
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
        if (vect[i].status == 1)
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
void llenarRegistroAuto(Templeado vector[], Tindex vectind[], int index)
{
    int i, id;

    vector[index].status = 1;
    do
    {
        id = randNum(300000, 399999);
        i = searchLinearId(vector, index, id);
    } while (i != -1);

    vector[index].id = id;
    vectind[index].consecutivo = index;

    genLastName(vector[index].apellidoP);
    genLastName(vector[index].apellidoM);
    genNameV2(vector[index].nombre);
    detectarSexo(vector[index]);
    generarPuestoAleatorio(vector[index].puesto);
    generarEstadoAleatorio(vector[index].estado);
    vector[index].edad = randNum(18, 60);
    vector[index].celular = generarCelular();
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
int binarySearchId2(Tindex vect[], int val, int start, int end)
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

int binarySearch2(Tindex vect[], int start, int end)
{
    int mid;

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (vect[mid].id != 0)
        {
            return mid;
        }
        else if (0 < vect[mid].id)
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

// OPERACIONES CON REGISTROS

void eliminarRegistro(Templeado vect[], Tindex vectInd[], int index, int ordenado)
{
    int encontrado, op;

    if (ordenado == TRUE)
    {
        int num;
        num = validInt(300000, 399999, "INGRESA MATRICULA A BUSCAR: ", "INVALIDO - FUERA DE RANGO (300000 - 399999)");
        encontrado = binarySearchId2(vectInd, num, 0, index - 1);

        if (encontrado != -1)
        {
            FILE *fa = fopen("datos.dat", "rb+");

            if (fa == NULL)
            {
                printf("ERROR AL ABRIR EL ARCHIVO\n");
            }

            if (fa)
            {
                if (fseek(fa, encontrado * sizeof(Templeado), SEEK_SET) == 0)
                {
                    mostrar1Registro(vect, encontrado);
                    op = validInt(1, 2, "INGRESA OPCION ELIMINAR (1\\SI 2/NO) : ", "OPCION INVALIDA");

                    if (op == 1)
                    {
                        fseek(fa, encontrado * sizeof(Templeado), SEEK_SET);
                        Templeado registro;
                        fread(&registro, sizeof(Templeado), 1, fa);
                        registro.status = 0;
                        fseek(fa, encontrado * sizeof(Templeado), SEEK_SET);
                        fwrite(&registro, sizeof(Templeado), 1, fa);
                        fclose(fa);
                        printf("DADO DE BAJA\n");
                    }
                }
                else
                {
                    printf("NO SE PUDO MOVER EL PUNTERO EN EL ARCHIVO\n");
                }
            }
        }
        else
        {
            printf("LA MATRICULA NO EXISTE\n");
        }
    }
    else
    {
        int num;
        num = validInt(300000, 399999, "INGRESA MATRICULA A BUSCAR: ", "INVALIDO - FUERA DE RANGO (300000 - 399999)");
        encontrado = encontrarValorIndex(vectInd, index, num);
        if (encontrado != -1)
        {
            FILE *fa = fopen("datos.dat", "rb+");
            if (fa == NULL)
            {
                printf("ERROR AL ABRIR EL ARCHIVO\n");
            }

            if (fa)
            {
                if (fseek(fa, encontrado * sizeof(Templeado), SEEK_SET) == 0)
                {
                    mostrar1Registro(vect, encontrado);

                    op = validInt(1, 2, "INGRESA OPCION ELIMINAR (1\\SI 2/NO) : ", "OPCION INVALIDA");

                    if (op == 1)
                    {
                        fseek(fa, encontrado * sizeof(Templeado), SEEK_SET);
                        Templeado registro;
                        fread(&registro, sizeof(Templeado), 1, fa);
                        registro.status = 0;
                        fseek(fa, encontrado * sizeof(Templeado), SEEK_SET);
                        fwrite(&registro, sizeof(Templeado), 1, fa);
                        fclose(fa);
                        printf("DADO DE BAJA\n");
                    }
                }
                else
                {
                    printf("ERROR AL MOVER EL PUNTERO DE ARCHIVO\n");
                }
            }
        }
        else
        {
            printf("LA MATRICULA NO EXISTE\n");
        }
    }
}

/******************************************************************/

int cargarBin(Templeado vect[], Tindex vectindex[], int i)
{
    FILE *fa;
    Templeado temp;
    fa = fopen("datos.dat", "rb");

    if (fa == NULL)
    {
        printf("ERROR AL LEER EL ARCHIVO\n");
        return -1;
    }

    while (fread(&temp, sizeof(Templeado), 1, fa))
    {
        vect[i] = temp;
        vectindex[i].consecutivo = i;
        vectindex[i].id = temp.id;
        i++;
    }
    printf("SE HAN CARGADO LOS REGISTROS DEL ARCHIVO BINARIO EXITOSAMENTE\n");
    fclose(fa);

    return i;
}

void imprimirRegVect_1(Tindex vect[], int posicion)
{
    int i;

    for (i = posicion; i < (posicion + 100); i++)
    {
        printf("%6d %10d\n", vect[i].consecutivo, vect[i].id);
    }
}

void imprimirRegVect(Tindex vect[], int posicion)
{
    int i;

    for (i = 0; i < posicion; i++)
    {
        printf("%6d %10d\n", vect[i].consecutivo, vect[i].id);
    }
}

int encontrarValor(Templeado vect[], int n, int num)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (vect[i].id == num)
        {
            return i;
        }
    }
    return -1;
}

int encontrarValorIndex(Tindex vect[], int n, int num)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (vect[i].id == num)
        {
            return i;
        }
    }
    return -1;
}

void buscarRegistro(Templeado vect[], int index, int ordenado)
{
    Tkey encontrado;
    int num;
    Templeado reg;
    FILE *fa;

    num = validInt(300000, 399999, "INGRESA MATRICULA A BUSCAR: ", "INVALIDO (300000 - 399999)");
    if (ordenado == TRUE)
    {
        encontrado = binarySearchId(vect, num, 0, index);
    }
    else
    {
        encontrado = encontrarValor(vect, index, num);
    }

    if (encontrado != -1)
    {
        fa = fopen("datos.dat", "rb+");
        fseek(fa, encontrado * sizeof(Templeado), SEEK_SET);
        fread(&reg, sizeof(Templeado), 1, fa);
        printf("\nID: %d\n", reg.id);
        printf("NOMBRE: %s\n", reg.nombre);
        printf("APELLIDO PAT: %s\n", reg.apellidoP);
        printf("APELLIDO MAT: %s\n", reg.apellidoM);
        printf("PUESTO: %s\n", reg.puesto);
        printf("EDAD: %d\n", reg.edad);
        printf("SEXO: %s\n", reg.sexo);
        printf("CELULAR: %d\n", reg.celular);
        printf("ESTADO: %s\n", reg.estado);
        fclose(fa);
    }
    else
    {
        printf("NO ENCONTRADO\n");
    }
}

void imprimirIndicesOrdenados(Tindex vect[], int index)
{
    int i;
    printf("INDICE  MATRICULA\n");
    for (i = 0; i < index; i++)
    {
        printf("%4d %6d\n", vect[i].consecutivo + 1, vect[i].id);

        if ((i + 1) % 40 == 0)
        {
            system("PAUSE");
            printf("%4d %6d\n", vect[i].consecutivo + 1, vect[i].id);
            system("CLS");
        }
    }
    printf("=======================================================\n");
}

void archivo(Templeado vect[], int n, char nombre[])
{
    int i;
    FILE *fa;
    fa = fopen(nombre, "w");
    fprintf(fa, "%-6s %-15s %-15s %-15s %-15s %-5s %-6s %-10s      %-9s   %s\n",
            "No.", "ID", "NOMBRE", "APELLIDO PAT", "APELLIDO MAT", "EDAD", "SEXO", "PUESTO", "CELULAR", "ESTADO");
    for (i = 0; i < n; i++)
    {
        fprintf(fa, "%-5d        %-15s    %-15s %-15s %-4d %-6s %-10s      %-9d    %-19s\n",
                vect[i].id,
                vect[i].nombre,
                vect[i].apellidoP,
                vect[i].apellidoM,
                vect[i].edad,
                vect[i].sexo,
                vect[i].puesto,
                vect[i].celular,
                vect[i].estado);
    }

    printf("ARCHIVO CREADO EXITOSAMENTE");
    fclose(fa);
}

void archivoOrdenado(Tindex vect[], int n, char nombre[])
{
    int i;
    FILE *fa;
    fa = fopen(nombre, "w");
    fprintf(fa,"INDICE  MATRICULA\n");

    for (i = 0; i < n; i++)
    {
        fprintf(fa,"%4d %6d\n", vect[i].consecutivo + 1, vect[i].id);

    }

    printf("ARCHIVO CREADO EXITOSAMENTE");
    fclose(fa);
}

void empaquetar(Templeado vect[], int n)
{
    FILE *fa;
    char nom[11] = "datos.dat";
    rename("datos.dat", "datos.bak");
    fa = fopen(nom, "wb");
    if (fa == NULL)
    {
        printf("NO SE ENCONTRO EL ARCHIVO\n");
        system("PAUSE");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (vect[i].status == 1)
            {
                fwrite(vect, sizeof(Templeado), 1, fa);
            }
        }

        fclose(fa);
    }
}