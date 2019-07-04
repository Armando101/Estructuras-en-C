#include "pila.h"

// Cabeceras y definiciones privadas
#include <stdio.h>
#include <stdlib.h>

// Definir la estructura del tipo de dato
struct pila {
    int tamanio;
    TipoDato * contenido;
    int tope;
};

// Funciones de creación y destrucción de la pila
Pila * Pila_Nueva(int tamanio)
{
    if (tamanio < 1) {
        tamanio = 16;
    }

    Pila * nueva_pila = RESERVAR(1, Pila);
    if (nueva_pila == NULL)
        return NULL;

    nueva_pila->tamanio=tamanio;
    nueva_pila->contenido = RESERVAR(tamanio, TipoDato);
    nueva_pila->tope=-1;

/*
    *nueva_pila = (Pila) { .tamanio = tamanio,
                           .contenido = RESERVAR(tamanio, TipoDato),
                           .tope = -1 };
*/
   
    if (nueva_pila->contenido == NULL) {
        free(nueva_pila);
        return NULL;
    }

    return nueva_pila;
}

//#undef Pila_Liberar
void  Pila_Liberar(Pila ** pila)
{
    free((*pila)->contenido);
    free(*pila);
    *pila = NULL;
}

// Funciones para insertar/eliminar
bool Pila_Insertar(Pila * pila, TipoDato dato)
{
    if (Pila_Llena(pila)) {
        pila->tamanio *= 2;
        TipoDato * nuevo_espacio = REDIM(pila->contenido, pila->tamanio, TipoDato);

        if (nuevo_espacio == NULL) {
            pila->tamanio /= 2;
            return false;
        }

        pila->contenido = nuevo_espacio;
    }

    pila->contenido[++pila->tope] = dato;
    return true;
}

bool Pila_Eliminar(Pila * pila, TipoDato * dato)
{
    if (Pila_Vacia(pila))
        return false;

    *dato = pila->contenido[pila->tope--];
    return true;
}

// Funciones para consultar datos sin modificarlos
TipoDato Pila_ChecarTope(const Pila * pila)
{
    if (Pila_Vacia(pila)) {
        fputs("Error, no hay elementos en la pila", stderr);
        exit(EXIT_FAILURE);
    }

    return pila->contenido[pila->tope];
}

TipoDato Pila_ChecarPosN(const Pila * pila, int posicionDesdeTope)
{
    if (posicionDesdeTope < 0 || posicionDesdeTope > pila->tope) {
        fprintf(stderr, "Error, indice de pila inválido: %d\n", posicionDesdeTope);
        exit(EXIT_FAILURE);
    }

    return pila->contenido[pila->tope - posicionDesdeTope];
}

bool Pila_Vacia(const Pila * pila)
{
    return pila->tope == -1;
}

bool Pila_Llena(const Pila * pila)
{
    return pila->tope == pila->tamanio - 1;
}

int  Pila_NumeroElementos(const Pila * pila)
{
    return pila->tope + 1;
}

// Funciones para recorrer e imprimir
void Pila_Imprimir(const Pila * pila, enum orden orden)
{
    printf("\n");
    if (orden == ORD_INVERSO)
        Pila_RecorrerInv(pila, imprimirDato);
    else
        Pila_Recorrer(pila, imprimirDato);
    // También se puede hacer lo siguiente
    // (orden == ORD_INVERSO ? Pila_RecorrerInv : Pila_Recorrer) (pila, imprimirDato);
}

//#if true  // Con true se usan las versiones iterativas de las funciones
          // de recorrido y con false se usan las versiones recursivas

// main
// Pila_Recorrer(p, multiplicar5);

void Pila_Recorrer(const Pila * pila, void (*operacion)(TipoDato * dt))
{
    for (int i = 0; i <= pila->tope; ++i) {
        operacion(&pila->contenido[i]);
    }
}

void Pila_RecorrerInv(const Pila * pila, void (*operacion)(TipoDato * dt))
{
    for (int i = pila->tope; i >= 0; --i) {
        operacion(&pila->contenido[i]);
    }
}


//#else
/*
static void auxRecorrer(TipoDato * actual, int faltantes,
                      void (*operacion)(TipoDato *dt))
{
    if (faltantes > 0) {
        operacion(actual);
        auxRecorrer(actual + 1, faltantes - 1, operacion);
    }
}
void Pila_Recorrer(const Pila * pila, void (*operacion)(TipoDato * dt))
{
    auxRecorrer(pila->contenido, Pila_NumeroElementos(pila), operacion);
}

static void auxRecorrerInv(TipoDato * actual, int faltantes,
                      void (*operacion)(TipoDato *dt))
{
    if (faltantes > 0) {
        auxRecorrerInv(actual + 1, faltantes - 1, operacion);
        operacion(actual);
    }
}
void Pila_RecorrerInv(const Pila * pila, void (*operacion)(TipoDato * dt))
{
    auxRecorrerInv(pila->contenido, Pila_NumeroElementos(pila), operacion);
}
#endif
*/