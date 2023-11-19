
/*
Quiros Vicencio Diego Demian
11/08/23(creado) - 11/18/23 (modificado)
Actividad 13. Registros de empleados y archivos binarios
1.- Agregar : El programa deberá ser capaz de agregar 100 registros al vector de registros (Generar automáticamente los datos).
2.- Editar Registro : El programa deberá buscar una matrícula en el vector por medio del método de búsqueda más óptimo. Mostrar los datos en forma de registro Preguntar que campo quire Editar, actualiar los datos en el vector (solo a registros activos)
3.- Eliminar Registro : El programa deberá buscar una matrícula en el vector por medio del método de búsqueda más óptimo. Utilizar banderas para escoger el método más adecuado., imprimir el registro y preguntar si se quiere eliminar el registro.
4.- Buscar : El programa deberá buscar una matrícula en el vector por medio del método de búsqueda más óptimo. Utilizar banderas para escoger el método más adecuado. Mostrar los datos en forma de registro
5.- Ordenar : El programa deberá ordenar el vector por medio del método de ordenación más óptimo. Utilizar banderas para escoger el método más adecuado se ordenará por el campo llave (matrícula)
6.- Imprimir: El programa deberá mostrar todos los registros del vector y como están en ese momento ordenado o desordenado. (mostrar en forma de tabla )
7.- Generar Archivo Texto : El programa deberá preguntar al usuario el nombre del archivo,  solo nombre sin extensión, el programa generará un archivo con el nombre proporcionado por el usuario con extensión .txt los datos que pondrá en el archivo de texto serán idénticos a los contenidos en el Vector de registros. (ordenado o desordenado). El programa podrá generar múltiples archivos para comprobar las salidas.
8.- Mostrar Archivo Texto: El programa deberá preguntar al usuario el nombre del archivo,  solo nombre sin extensión, el programa generará un archivo con el nombre proporcionado por el usuario con extensión .txt mostrar el archivo de texto tal y como se encuantra.
9.- Crear archivo binario : El programa deberá crear un archivo binario con los datos del vector actualizados, sustituir el archivo base, realizar respaldo del archivo anterior y guardarlo con el mismo nombre pero extencion .tmp (validar msges si el archivo no se puede crear por falta de registros en el vector)
10 .- Cargar Archivo Binario : El programa deberá cargar al vector los registros del archivo binario (solo podrá cargarse una sola vez el archivo, el archivo binario se debara llamar datos.dll y si no existe debera indicar )
11.- Mostrar Borrados: El programa deberá mostrar del archivo binario solo los registros que se eliminaron (marcados con status 0) y que fueron marcados en su momento como registros eliminados.
*/

#include "ddqvalhd.h"
#include "namesddqv.h"

#define MAX_REG 5000
#define ADD_REG 100
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
    int celular;
} Templeado;

// PROTOTIPOS
int msges(void);
void menu();

void imprimirRegistros(Templeado vect[], int index);
void individualList(Templeado vect);
void llenarRegistroAuto(Templeado vect[], int index);
int generarCelular(void);
void detectarSexo(Templeado vect[], int index);
void generarPuestoAleatorio(char code[]);
void generarEstadoAleatorio(char code[]);
int searchLinearId(Templeado vector[], int m, int val);
int binarySearchId(Templeado vect[], int val, int start, int end);
void qs(Templeado lista[], int limiteIzquierdo, int limiteDerecho);
void quikSort(Templeado list[], int index);
void bubbleSortIds(Templeado vector[], int m);

int buscarId(Templeado vect[], int indice, int ordenado);
void editarRegistro(Templeado vect[], int i, int ordenado);
int msgeEditar(void);
int concatenarEnteros(int num1, int num2);
int genEdo(void);
void getState(char code[], int stateCode);
void eliminarRegistro(Templeado empleado[], int indice, int ordenado);
int genArch(Templeado vect[], int indice, char nombre[]);
int leerArchivo(char nombre[]);
int crearArchivoBinario(Templeado vect[], int indice, char nombre[]);
int leerArchivoBinario(Templeado vect[], int *indice, char nombre[]);
void mostrarEliminadosBin(Templeado vect[], int indice);
//***********************************************************************

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
    printf("2 .- EDITAR REGISTRO\n");
    printf("3 .- ELIMINAR REGISTRO\n");
    printf("4 .- BUSCAR REGISTRO\n");
    printf("5 .- ORDENAR REGISTROS\n");
    printf("6 .- IMPRIMIR REGISTROS\n");
    printf("7 .- GENERAR ARCHIVO TEXTO\n");
    printf("8 .- MOSTRAR ARCHIVO TEXTO\n");
    printf("9 .- CREAR ARCHIVO BINARIO\n");
    printf("10 .- CARGAR ARCHIVO BINARIO\n");
    printf("11 .- MOSTRAR BORRADOS\n");
    printf("0. SALIR\n");
    printf("========================================\n");
    op = validInt(0, 11, "INGRESA FUNCION A UTILIZAR: ", "OPCION INVALIDA");
    // printf("========================================");
    return op;
}

void menu()
{
    int op, fa;
    int indice = 0, ordenado = 0;
    char nombreArchivo[20];
    int cargado = FALSE;
    Templeado empleados[MAX_REG];

    do
    {
        system("CLS");
        op = msges();
        system("CLS");

        switch (op)
        {
        case 1:
            if (indice + ADD_REG <= MAX_REG)
            {
                for (int i = 0; i < ADD_REG; i++)
                {
                    llenarRegistroAuto(empleados, indice);
                    indice++;
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
            editarRegistro(empleados, indice, ordenado);
            break;
        case 3:
            // ELIMINAR REGISTRO
            eliminarRegistro(empleados, indice, ordenado);
            break;
        case 4:
            buscarId(empleados, indice, ordenado);
            system("PAUSE");
            break;
        case 5:
            if (indice > 250)
            {
                if (ordenado == 0)
                {
                    quikSort(empleados, indice);
                    ordenado = TRUE;
                    printf("SE HAN ORDENADO LOS REGISTROS");
                }
                else
                {
                    printf("REGISTROS ACTUALMENTE ORDENADOS\n");
                }
            }
            else
            {
                if (ordenado == 0)
                {
                    bubbleSortIds(empleados, indice);
                    ordenado = TRUE;
                    printf("SE HAN ORDENADO LOS REGISTROS");
                }
                else
                {
                    printf("REGISTROS ACTUALMENTE ORDENADOS\n");
                }
            }
            system("PAUSE");
            break;
        case 6:
            imprimirRegistros(empleados, indice);
            system("PAUSE");
            break;
        case 7:
            getString(nombreArchivo, "INGRESA EL NOMBRE DEL ARCHIVO: ");
            strcat(nombreArchivo, ".txt");
            fa = genArch(empleados, indice, nombreArchivo);

            if (fa == 1)
            {
                printf("\nEL ARCHIVO SE HA ESCRITO CON EXITO\n");
            }
            else
            {
                printf("\nERROR AL ESCRIBIR EL ARCHIVO\n");
            }
            printf("\n");
            system("PAUSE");
            break;
        case 8:
            fflush(stdin);
            getString(nombreArchivo, "INGRESA EL NOMBRE DEL ARCHIVO: ");
            strcat(nombreArchivo, ".txt");
            printf("\n");
            fflush(stdin);

            fa = leerArchivo(nombreArchivo);

            if (fa == 1)
            {
                printf("\nEL ARCHIVO SE HA MOSTRADO CON EXITO\n");
            }
            else
            {
                printf("\nERROR AL MOSTRAR EL ARCHIVO\n");
            }
            printf("\n");
            system("PAUSE");
            break;
        case 9:
            fflush(stdin);
            getString(nombreArchivo, "INGRESA EL NOMBRE DEL ARCHIVO BINARIO: ");
            strcat(nombreArchivo, ".dll");

            fflush(stdin);

            fa = crearArchivoBinario(empleados, indice, nombreArchivo);

            if (fa == 1)
            {
                printf("\nEL ARCHIVO BINARIO SE HA CREADO CON EXITO\n");
            }
            else
            {
                printf("\nERROR AL CREAR EL ARCHIVO\n");
            }
            printf("\n");
            system("PAUSE");
            break;

        case 10:

            if (cargado == FALSE)
            {
                fflush(stdin);
                getString(nombreArchivo, "INGRESA EL NOMBRE DEL ARCHIVO BINARIO: ");
                strcat(nombreArchivo, ".dll");
                printf("\n");
                fflush(stdin);
                fa = leerArchivoBinario(empleados, &indice, nombreArchivo);

                if (fa == 1)
                {
                    printf("\nEL ARCHIVO SE HA CARGADO CON EXITO\n");
                    cargado = TRUE;
                }
                else
                {
                    printf("\nERROR AL CARGAR EL ARCHIVO\n");
                }
            }
            else
            {
                printf("YA HA SIDO CARGADO UN ARCHIVO");
            }
            printf("\n");
            system("PAUSE");
            break;

        case 11:
            mostrarEliminadosBin(empleados, indice);
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
void llenarRegistroAuto(Templeado vect[], int index)
{
    int i, id;

    vect[index].status = 1;
    do
    {
        id = randNum(300000, 399999);
        i = searchLinearId(vect, index, id);
    } while (i != -1);

    vect[index].id = id;

    genLastName(vect[index].apellidoP);
    genLastName(vect[index].apellidoM);
    genNameV2(vect[index].nombre);
    detectarSexo(vect, index);
    generarPuestoAleatorio(vect[index].puesto);
    generarEstadoAleatorio(vect[index].estado);
    vect[index].edad = randNum(18, 60);
    vect[index].celular = generarCelular();
}

int generarCelular(void)
{
    int lada = 646000000;
    int num = randNum(100000, 999999);

    return lada + num;
}

void detectarSexo(Templeado vect[], int index)
{
    int sexo = sexDetectV2(vect[index].nombre);
    if (sexo == 2)
    {
        strcpy(vect[index].sexo, "MUJER");
    }
    else
    {
        strcpy(vect[index].sexo, "HOMBRE");
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
    char stateCodeList[35][30] = {"AGUASCALIENTES", "BAJA CALIFORNIA", "BAJA CALIFORNIA SUR", "CAMPECHE", "CHIAPAS", "CHIHUAHUA", "COAHUILA", "COLIMA", "CDMX", "DURANGO",
                                  "DISTRITO FEDERAL", "GUANAJUATO", "GUERRERO", "HIDALGO", "JALISCO", "MICHOACAN", "MORELOS", "NAYARIT", "NUEVO LEON", "OAXACA",
                                  "PUEBLA", "QUERETARO", "QUINTANA ROO", "SAN LUIS POTOSI", "SINALOA", "SONORA", "TABASCO", "TAMAULIPAS", "TLAXCALA", "VERACRUZ",
                                  "YUCATAN", "ZACATECAS", "EXTRANJERO"};

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

void editarRegistro(Templeado vect[], int i, int ordenado)
{
    int registro, op, codeEdo;
    int sex, num, lada;
    registro = buscarId(vect, i, ordenado);

    mostrar1Registro(vect, registro);
    op = msgeEditar();

    switch (op)
    {
    case 1:
        getString(vect[registro].nombre, "INGRESA NOMBRE: \n");
        break;
    case 2:
        getString(vect[registro].apellidoP, "INGRESA APELLIDO PAT.: \n");
        break;
    case 3:
        getString(vect[registro].apellidoM, "INGRESA APELLIDO MAT.: \n");
        break;
    case 4:
        getString(vect[registro].puesto, "INGRESA PUESTO: \n");
        break;
    case 5:
        vect[registro].edad = validInt(20, 60, "INGRESA EDAD: ", "FUERA DE RANGO");
        break;
    case 6:
        sex = validInt(1, 2, "SELECCIONA SEXO: 1) HOMBRE 2) MUJER\n", "OPCION INVALIDA");
        if (sex != 1)
        {
            strcpy(vect[registro].sexo, "MUJER");
        }
        else
        {
            strcpy(vect[registro].sexo, "HOMBRE");
        }
        break;
    case 7:

        lada = validInt(100, 999, "INGRESA LADA: ", "FUERA DE RANGO");
        num = validInt(1000000, 9999999, "INGRESA NUMERO: ", "FUERA DE RANGO");
        vect[registro].celular = concatenarEnteros(lada, num);

        break;
    case 8:
        codeEdo = genEdo();
        getState(vect[registro].estado, codeEdo);
        break;
    default:
        break;
    }
}

int msgeEditar(void)
{
    int op;
    printf("\n1. NOMBRE\n");
    printf("2. APELLIDO P\n");
    printf("3. APELLIDO M\n");
    printf("4. PUESTO\n");
    printf("5. EDAD\n");
    printf("6. SEXO\n");
    printf("7. CELULAR\n");
    printf("8. ESTADO\n");
    op = validInt(1, 8, "INGRESA CAMPO A EDITAR: ", "FUERA DE RANGO");
    return op;
}

int concatenarEnteros(int num1, int num2)
{
    char strNum1[20];
    char strNum2[20];

    sprintf(strNum1, "%d", num1);
    sprintf(strNum2, "%d", num2);

    char concatenado[40];
    sprintf(concatenado, "%s%s", strNum1, strNum2);

    int resultado = atoi(concatenado);

    return resultado;
}

int genEdo(void)
{
    printf("ESTADOS: \n");
    printf("1.  Aguascalientes\t");
    printf("2.  BAJA CALIFORNIA\t");
    printf("3.  BAJA CALIFORNIA SUR\n");
    printf("4.  CAMPECHE \t");
    printf("5.  CHIAPAS\t");
    printf("6.  CHIHUAHUA\n");
    printf("7.  COAHUILA\t");
    printf("8.  COLIMA\t");
    printf("9.  CDMX\n");
    printf("10. DURANGO\t");
    printf("11. DF\t");
    printf("12. GUANAJUATO\n");
    printf("13. GUERRERO\t");
    printf("14  HIDALGO\t");
    printf("15. JALISCO\n");
    printf("16. MICHOACAN\t");
    printf("17. MORELOS\t");
    printf("18. NAYARIT\n");
    printf("19. NUEVO LEON\t");
    printf("20. OAXACA\t");
    printf("21. PUEBLA\n");
    printf("22. QUERETARO\t");
    printf("23. QUINTANA ROO\t");
    printf("24. SAN LUIS POTOSI\n");
    printf("25. SINALOA\t");
    printf("26. SONORA\t");
    printf("27. TABASCO\n");
    printf("28. TAMAULIPAS\t");
    printf("29. TLAXCALA\t");
    printf("30. VERACRUZ\n");
    printf("31. YUCATAN\t");
    printf("32. ZACATECAS\t");
    printf("33. EXTRANJERO");

    int estado = validInt(1, 33, "INGRESA ESTADO DE NACIMIENTO: ", "OPCION FUERA DE RANGO");
    return estado;
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

void eliminarRegistro(Templeado empleado[], int indice, int ordenado)
{

    int num = buscarId(empleado, indice, ordenado);
    if (num != -1)
    {
        int op = validInt(1, 2, "DAR DE BAJA (1\\SI 2\\NO): ", "OPCION INVALIDA - FUERA DE RANGO");
        if (op == 1)
        {
            empleado[num].status = 0;
            printf("EMPLEADO DADO DE BAJA.\n");
        }
    }
    else
    {
        printf("MATRICULA NO REGISTRADA\n");
    }
    system("PAUSE");
}

int genArch(Templeado vect[], int indice, char nombre[])
{
    FILE *fa;

    fa = fopen(nombre, "w");

    if (fa == NULL)
    {
        return -1;
    }

    if (fa)
    {
        fprintf(fa, "%-6s %-15s %-15s %-15s %-15s %-5s %-6s %-10s      %-9s   %s\n",
                "No.", "ID", "NOMBRE", "APELLIDO PAT", "APELLIDO MAT", "EDAD", "SEXO", "PUESTO", "CELULAR", "ESTADO");

        for (int i = 0; i < indice; i++)
        {
            if (vect[i].status == 1)
            {
                fprintf(fa, "%-4d  %-5d        %-15s    %-15s %-15s %-4d %-6s %-10s      %-9d    %-19s\n",
                        i + 1,
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
        }
        fclose(fa);
    }
    return 1;
}

int leerArchivo(char nombre[])
{
    FILE *fa;
    char caracter;

    fa = fopen(nombre, "r");

    if (fa == NULL)
    {
        return -1;
    }

    if (fa)
    {
        while ((caracter = fgetc(fa)) != EOF)
        {
            putchar(caracter);
        }

        fclose(fa);
    }

    return 1;
}

int crearArchivoBinario(Templeado vect[], int indice, char nombre[])
{
    FILE *fa;

    fa = fopen(nombre, "wb");

    if (fa == NULL)
    {
        printf("Error al abrir el archivo para escritura binaria.\n");
        return -1;
    }

    fprintf(fa, "%-6s %-15s %-15s %-15s %-15s %-5s %-6s %-10s      %-9s   %s\n",
            "No.", "ID", "NOMBRE", "APELLIDO PAT", "APELLIDO MAT", "EDAD", "SEXO", "PUESTO", "CELULAR", "ESTADO");

    fwrite(vect, sizeof(Templeado), indice, fa);

    fflush(fa);
    fclose(fa);

    return 1;
}

int leerArchivoBinario(Templeado vect[], int *indice, char nombre[])
{
    FILE *fa;

    fa = fopen(nombre, "rb");

    if (fa == NULL)
    {
        return -1;
    }

    char encabezado[256];
    fgets(encabezado, sizeof(encabezado), fa);

    *indice = fread(vect, sizeof(Templeado), MAX_REG, fa);

    fclose(fa);
    return 1;
}

void mostrarEliminadosBin(Templeado vect[], int indice)
{
    printf("\n\tREGISTROS ELIMINADOS:\n");
    printf("%-6s %-15s %-15s %-15s %-15s %-5s %-6s %-10s      %-9s   %s\n",
           "No.", "ID", "NOMBRE", "APELLIDO PAT", "APELLIDO MAT", "EDAD", "SEXO", "PUESTO", "CELULAR", "ESTADO");

    for (int i = 0; i < indice; i++)
    {
        if (vect[i].status == 0)
        {
            printf("%-4d  %-5d        %-15s    %-15s %-15s %-4d %-6s %-10s      %-9d    %-19s\n",
                   i + 1,
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
    }
    system("PAUSE");
}
