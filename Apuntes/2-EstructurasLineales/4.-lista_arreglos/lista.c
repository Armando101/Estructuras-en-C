#include "lista.h"

#include <stdio.h>
#include <stdlib.h>

// Definir la estructura del tipo de dato
struct lista {
    int tamanio;
    int num_elementos;
    TipoDato * contenido;
};

// Funciones de creación y destrucción de la lista
Lista * Lista_Nueva(int tamanio)
{
    if (tamanio < 1) {
        tamanio = 16;
    }

    Lista * nueva_lista = RESERVAR(1, Lista);
    if (nueva_lista == NULL) {
        return NULL;
    }

    *nueva_lista = (Lista) { .tamanio = tamanio,
                             .contenido = RESERVAR(tamanio, TipoDato) };
    if (nueva_lista->contenido == NULL) {
        free(nueva_lista);
        return NULL;
    }
    return nueva_lista;
}

#undef  Lista_Liberar
void    Lista_Liberar(Lista ** lista)
{
    free((*lista)->contenido);
    free(*lista);
}

// Modificación de los datos de la lista
static bool agrandarSiLlena(Lista * lista)
{
    if (Lista_Llena(lista)) {
        lista->num_elementos <<= 1;
        TipoDato * nv_espacio =
            REDIM(lista->contenido, lista->num_elementos, TipoDato);
        if (nv_espacio == NULL) {
            lista->num_elementos >>= 1;
            return EXIT_FAILURE;
        }
        lista->contenido = nv_espacio;
    }
    return EXIT_SUCCESS;
}

bool Lista_InsertarPosI(Lista * lista, TipoDato dato)
{
    if (agrandarSiLlena(lista) == EXIT_FAILURE) {
        return false;
    }
    for (int i = lista->num_elementos - 1; i >= 0; --i) {
        lista->contenido[i + 1] = lista->contenido[i];
    }
    lista->contenido[0] = dato;
    lista->num_elementos++;
    return true;
}
bool Lista_InsertarPosF(Lista * lista, TipoDato dato)
{
    if (agrandarSiLlena(lista) == EXIT_FAILURE) {
        return false;
    }
    lista->contenido[lista->num_elementos] = dato;
    lista->num_elementos++;
    return true;
}
bool Lista_InsertarPosN(Lista * lista, TipoDato dato, int pos_n)
{
    if (agrandarSiLlena(lista) == EXIT_FAILURE) {
        return false;
    }
    if (pos_n < 0 || pos_n > lista->num_elementos) {
        return false;
    }

    for (int i = lista->num_elementos - 1; i >= pos_n; --i) {
        lista->contenido[i + 1] = lista->contenido[i];
    }
    lista->contenido[pos_n] = dato;
    lista->num_elementos++;
    return true;
}

bool Lista_EliminarPosI(Lista * lista, TipoDato * dato)
{
    if (Lista_Vacia(lista)) { return false; }
    *dato = lista->contenido[0];
    for (int i = 0; i < lista->num_elementos; ++i) {
        lista->contenido[i] = lista->contenido[i + 1];
    }
    lista->num_elementos--;
    return true;
}
bool Lista_EliminarPosF(Lista * lista, TipoDato * dato)
{
    if (Lista_Vacia(lista)) { return false; }
    *dato = lista->contenido[lista->num_elementos - 1];
    lista->num_elementos--;
    return true;
}
bool Lista_EliminarPosN(Lista * lista, TipoDato * dato, int pos_n)
{
    if (Lista_Vacia(lista)) { return false; }
    if (pos_n < 0 || pos_n >= lista->num_elementos) {
        fprintf(stderr, "Error, indice de pila inválido: %d\n", pos_n);
        exit(EXIT_FAILURE);
    }
    *dato = lista->contenido[pos_n];
    for (int i = pos_n; i < lista->num_elementos; ++i) {
        lista->contenido[i] = lista->contenido[i + 1];
    }
    lista->num_elementos--;
    return true;
}

static int compararInv(const TipoDato * a, const TipoDato * b)
        { return -compararDato(a, b); }

void Lista_Ordenar(Lista * lista, enum orden orden)
{
    qsort(lista->contenido, lista->num_elementos, sizeof(TipoDato),
        (void *)(orden == ORD_INVERSO ? compararInv : compararDato));
}

int Lista_Buscar(const Lista * lista, TipoDato buscado)
{
    for (int i = 0; i < lista->num_elementos; ++i) {
        if (compararDato(&lista->contenido[i], &buscado) == 0)
            return i;
    }
    return -1;
}

// Revisar el estado de la lista sin modificarlos
TipoDato Lista_ChecarPosI(const Lista * lista)
{
    if (Lista_Vacia(lista)) {
        fputs("Error, no hay elementos en la pila", stderr);
        exit(EXIT_FAILURE);
    }
    return lista->contenido[0];
}
TipoDato Lista_ChecarPosF(const Lista * lista)
{
    if (Lista_Vacia(lista)) {
        fputs("Error, no hay elementos en la pila", stderr);
        exit(EXIT_FAILURE);
    }
    return lista->contenido[lista->num_elementos - 1];
}
TipoDato Lista_ChecarPosN(const Lista * lista, int posicionDesdeInicio)
{
    if (posicionDesdeInicio < 0 || posicionDesdeInicio >= lista->num_elementos) {
        fprintf(stderr, "Error, indice de pila inválido: %d\n",
                posicionDesdeInicio);
        exit(EXIT_FAILURE);
    }
    return lista->contenido[posicionDesdeInicio];
}

bool Lista_Vacia(const Lista * lista)
        { return lista->num_elementos == 0; }
bool Lista_Llena(const Lista * lista)
        { return lista->num_elementos == lista->tamanio; }
int  Lista_NumeroElementos(const Lista * lista)
        { return lista->num_elementos; }

// Funciones para recorrer e imprimir
void Lista_Imprimir(const Lista * lista, enum orden orden)
{
    printf("[_");
    (orden ? Lista_RecorrerInv : Lista_Recorrer)(lista, imprimirDato);
    puts("]");
}
#ifdef true    // Con true se usan las funciones iterativas para recorrer
               // la lista. Con false se usan las funciones recursivas
void Lista_Recorrer(const Lista * lista, FunDato operacion)
{
    for (int i = 0; i < lista->num_elementos; ++i) {
        operacion(&lista->contenido[i]);
    }
}
void Lista_RecorrerInv(const Lista * lista, FunDato operacion)
{
    int n = lista->num_elementos;
    for (int i = 0; i < n; ++i) {
        operacion(&lista->contenido[n - 1 - i]);
    }
}
#else
static void aux_recorrer(TipoDato * actual, int faltantes, FunDato operacion,
                      enum orden orden)
{
    if (actual != NULL) {
        if (orden == ORD_NORMAL) {
            operacion(actual);
            aux_recorrer(actual + 1, faltantes - 1, operacion);
        } else {
            aux_recorrer(actual + 1, faltantes - 1, operacion);
            operacion(actual);
        }
    }
}
void Lista_Recorrer(const Lista * lista, void (*operacion)(TipoDato * dt))
{
    aux_recorrer(lista->contenido, lista->tamanio, operacion, ORD_NORMAL);
}

void Lista_RecorrerInv(const Lista * lista, FunDato operacion)
{
    aux_recorrer(lista->contenido, lista->tamanio, operacion, ORD_INVERSO);
}
#endif
