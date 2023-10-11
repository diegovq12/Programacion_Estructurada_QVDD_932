#include <stdio.h>
#include <stdlib.h>

int validarNum() {
    char entrada[100];
    int numero;

    do {
        int i = 0;
        int esNumero = 1;

        printf("Por favor, ingresa un número entero: ");
        fgets(entrada, sizeof(entrada), stdin);

        // Verificar si la entrada contiene solo dígitos y, opcionalmente, un signo negativo al principio
        while (entrada[i] != '\0' && entrada[i] != '\n') {
            if (entrada[i] < '0' || entrada[i] > '9') {
                if (!(i == 0 && entrada[i] == '-' && entrada[i+1] >= '0' && entrada[i+1] <= '9')) {
                    esNumero = 0;
                    break;
                }
            }
            i++;
        }

        if (esNumero) {
            numero = atoi(entrada);
            return numero;
        } else {
            printf("Entrada no válida. Debe ser un número entero.\n");
        }
    } while (1);
}

int main() {
    int num;
    num = validarNum();
    printf("Número válido ingresado: %d\n", num);

    return 0;
}
