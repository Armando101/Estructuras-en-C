// Arreglo.h se incluye en el archivo de implementación del arreglo
// y también lo incluyen los programas que hagan uso del arreglo
#include "arreglo.h"

#include <stdio.h>
#include <stdlib.h>

// Definición "completa" del arreglo
struct arreglo {
    // Miembros del arreglo
    TipoDato * espacio;
    int tamanio;
};

// Funciones para crear y eliminar los arreglos
struct arreglo * crearArreglo(int tamanio) {
    struct arreglo * nuevo = malloc(sizeof(struct arreglo));
    nuevo->espacio = calloc(tamanio, sizeof(TipoDato));
    nuevo->tamanio = tamanio;

    return nuevo;
}

void liberarArreglo(struct arreglo * arr)
{
    // Se libera todo el espacio
    free(arr->espacio);
    // Se libera el arreglo
    free(arr);
}

void putArreglo(struct arreglo * arr, TipoDato dato, int pos) {
    if (pos < 0 || pos >= arr->tamanio) {
        fprintf(stderr, "Error. Indice incorrecto\n");
        return;
    }

    arr->espacio[pos] = dato;
}

TipoDato checarPosArreglo(struct arreglo * arr, int pos) {
    if (pos < 0 || pos >= arr->tamanio) {
        fprintf(stderr, "Error. Indice incorrecto\n");
        return (TipoDato) {0};
    }
    return arr->espacio[pos];
}

int tamArr(struct arreglo * arr) {
    return arr->tamanio;
}

void redimensionarArr(struct arreglo * arr,  int nuevo_tam)
{
    if (nuevo_tam < 0) {
        printf("Error. Tamaño negativo\n");
        return;
    }

    arr->tamanio = nuevo_tam;
    arr->espacio = realloc(arr->espacio, nuevo_tam * sizeof(TipoDato));
}
