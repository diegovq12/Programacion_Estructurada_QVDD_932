#include <stdio.h>

int validarNum() {
    char entrada[100];
    int numero = 0;
    int caracterEncontrado = 0;

    do {
        int i = 0;

        printf("Por favor, ingresa una cadena de caracteres con números: ");
        fgets(entrada, sizeof(entrada), stdin);

        // Restablecer el número a cero antes de cada intento
        numero = 0;
        caracterEncontrado = 0;

        // Verificar si la entrada contiene solo dígitos y, opcionalmente, un signo negativo al principio
        while (entrada[i] != '\0' && entrada[i] != '\n') {
            if (entrada[i] >= '0' && entrada[i] <= '9') {
                numero = numero * 10 + (entrada[i] - '0');
            } else {
                caracterEncontrado = 1;
                break;
            }
            i++;
        }

        if (caracterEncontrado) {
            printf("No se encontraron caracteres no numéricos en la entrada.\n");
        } else {
            printf("Número encontrado antes del carácter: %d\n", numero);
        }

    } while (caracterEncontrado);

    return numero;
}

