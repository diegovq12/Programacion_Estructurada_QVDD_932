#include <stdio.h>
#include <stdlib.h>

// Funcion que ordena un vector de mayor
// a menor mediante el metodo de la
// burbuja-Solicita el vector y su tamano
void bubbleSort(int vector[], int m)
{
    int i, j;
    int aux;

    for (i = 0; i < m - 1; i++)
    {
        for (j = i + 1; j < m; j++)
        {
            if (vector[i] > vector[j])
            {
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }
}