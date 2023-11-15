#include "ddqvalhd.h"

int main()
{
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
    op = validInt(0, 11, "INGRESA FUNCION A UTILIZAR: ", "OPCION INVALIDA");
    printf("========================================");
}

void menu()
{
    int op;

    do
    {
        op = msges();
        system("CLS");

    }while (op != 0);
    
}