#include "cola.h"

#include <stdio.h>
#include <stdlib.h>

// Definir la estructura del tipo de dato
struct cola {
    int tamanio;
    int num_elementos;

    TipoDato * contenido;

    int primero;
    int ultimo;
};

// Funciones de creación y destrucción de la pila
Cola * Cola_Nueva(int tamanio)
{
    if (tamanio < 1) {
        tamanio = 16;
    }

    Cola * nueva_cola = RESERVAR(1, Cola);
    if (nueva_cola == NULL) {
        return NULL;
    }

    *nueva_cola = (Cola) { .tamanio = tamanio,
                           .contenido = RESERVAR(tamanio, TipoDato) };
    if (nueva_cola->contenido == NULL) {
        free(nueva_cola);
        return NULL;
    }

    return nueva_cola;
}

#undef Cola_Liberar
void   Cola_Liberar(Cola ** cola)
{
    free((*cola)->contenido);
    free(*cola);
    cola = NULL;
}

// Funciones para insertar/eliminar
bool Cola_Insertar(Cola * cola, TipoDato dato)
{
    if (Cola_Llena(cola)) {
        return false;
    }

    cola->contenido[cola->ultimo] = dato;
    cola->ultimo = (cola->ultimo + 1) % cola->tamanio;
    cola->num_elementos++;
    return true;
}

bool Cola_Eliminar(Cola * cola, TipoDato * dato)
{
    if (Cola_Vacia(cola)) {
        return false;
    }

    *dato = cola->contenido[cola->primero];
    cola->primero = (cola->primero + 1) % cola->tamanio;
    cola->num_elementos--;
    return true;
}

// Funciones para consultar datos sin modificarlos
TipoDato Cola_ChecarPrimero(const Cola * cola)
{
    if (Cola_Vacia(cola)) {
        fputs("Error. La cola no tiene elementos para eliminar", stderr);
        exit(EXIT_FAILURE);
    }
    return cola->contenido[cola->primero];
}
TipoDato Cola_ChecarPosN(const Cola * cola, int posicionDesdeInicio)
{
    if (posicionDesdeInicio < 0 || posicionDesdeInicio >= cola->num_elementos) {
        printf("Error. Indice incorrecto: %d\n", posicionDesdeInicio);
        exit(EXIT_FAILURE);
    }

    int pos = (cola->primero + posicionDesdeInicio) % cola->tamanio;
    return cola->contenido[pos];
}

bool Cola_Vacia(const Cola * cola)
{
    return cola->num_elementos == 0;
}

bool Cola_Llena(const Cola * cola)
{
    return cola->num_elementos == cola->tamanio;
}

int Cola_NumeroElementos(const Cola * cola) {
    return cola->num_elementos;
}

// Función que usan recorridos
void Cola_Imprimir(const Cola * cola, enum orden orden)
{
    printf("[ ");
    if (orden == ORD_NORMAL) {
        printf("Inicio | ");
        Cola_Recorrer(cola, imprimirDato);
    } else {
        Cola_RecorrerInv(cola, imprimirDato);
        printf(" | Inicio");
    }

    printf(" ]\n");
}

#if true    // true hace que se usen los recorridos iterativos y
            // false hace que se usen los recorridos recursivos
void Cola_Recorrer(const Cola * cola, void (*operacion)(TipoDato * dt))
{
    for (int i = 0; i < cola->tamanio; ++i) {
        int indice = (cola->primero + i) % cola->tamanio;
        operacion(&cola->contenido[indice]);
    }
}

void Cola_RecorrerInv(const Cola * cola, void (*operacion)(TipoDato * dt))
{
    for (int i = 0; i < cola->tamanio; ++i) {
        int indice = (cola->ultimo + cola->tamanio - i - 1) % cola->tamanio;
        operacion(&cola->contenido[indice]);
    }
}
#else
static void auxRecorrer(TipoDato * actual, int faltantes,
                         void (*operacion)(TipoDato * dt ))
{
    if (faltantes > 0) {
        operacion(actual);
        auxRecorrer(actual + 1, faltantes - 1, operacion);
    }
}
void Cola_Recorrer(const Cola * cola, void (*operacion)(TipoDato * dt))
{
    auxRecorrer(cola->contenido, cola->tamanio, operacion);
}

static void auxRecorrerInv(TipoDato * actual, int faltantes,
                            void (*operacion)(TipoDato * dt))
{
    if (faltantes > 0) {
        auxRecorrerInv(actual + 1, faltantes - 1, operacion);
        operacion(actual);
    }
}
void Cola_RecorrerInv(const Cola * cola, void (*operacion)(TipoDato * dt))
{
    auxRecorrerInv(cola->contenido, cola->tamanio, operacion);
}
#endif
