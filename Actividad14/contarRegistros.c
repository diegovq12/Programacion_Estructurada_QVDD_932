#include <stdio.h>
#include <stdlib.h>

// Definir Tkey según sea necesario
typedef int Tkey;

// Estructura que representa un registro
typedef struct _trabajador {
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

int contarRegistros(FILE *archivo) {
    int contador = 0;

    // Tamaño del registro, según la estructura proporcionada
    size_t tamanoRegistro = sizeof(Templeado);

    // Mover el cursor al final del archivo para determinar el tamaño total
    fseek(archivo, 0, SEEK_END);
    long tamanoTotal = ftell(archivo);

    // Calcular la cantidad de registros
    contador = tamanoTotal / tamanoRegistro;

    return contador;
}

int main() {
    // Nombre del archivo binario
    const char *nombreArchivo = "datos.dat";

    // Abrir el archivo en modo lectura binaria
    FILE *fa = fopen(nombreArchivo, "rb");

    if (fa == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Contar los registros
    int cantidadRegistros = contarRegistros(fa);

    // Mostrar el resultado
    printf("El archivo tiene %d registros.\n", cantidadRegistros);

    // Cerrar el archivo
    fclose(fa);

    return 0;
}