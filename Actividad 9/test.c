#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int mat[4][4];
    int num, aux, i, j, k, l;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            aux = 0;
            do {
                num = (rand() % 16) + 1;
                // Comprobar si el numero ya existe en la matriz
                for (k = 0; k <= i; k++) {  // Cambio aquí: k <= i
                    for (l = 0; l <= j; l++) {  // Cambio aquí: l <= j
                        if (mat[k][l] == num) {
                            aux = 1;
                        }
                    }
                }
            } while (aux == 1);

            mat[i][j] = num;
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("[%2d]", mat[i][j]);  // Añadí un ancho de campo para imprimir números de dos dígitos
        }
        printf("\n");
    }

    return 0;
}

/*   
    for (i = 0; i < m; i++)
    {  
        aux=0;
        num=(rand()%(ri-rf))+ri;
        for (j = 0; j<m; j++)
        {
            if (num==vector[j])
            {
                aux=1;
            }
        }
        
        if (aux==1)
        {
            i--;
        }
        else
        {
            vector[i]=num;
        }
    }
*/
