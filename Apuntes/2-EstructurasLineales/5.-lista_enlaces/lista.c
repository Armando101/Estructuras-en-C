#include "lista.h"

#include <stdio.h>
#include <stdlib.h>

// Definir la estructura del tipo de dato
typedef struct nodo {
    TipoDato dato;
    struct nodo * siguiente;
    struct nodo * anterior;
} Nodo;

struct lista {
    int tamanio;
    int num_elementos;
    Nodo * primero;
    Nodo * ultimo;
};

// Funciones de creación y destrucción de la lista
Lista * Lista_Nueva(int tamanio)
{
    if (tamanio < 1) {
        tamanio = -1; // -1 Simboliza que no hay límites
    }

    Lista * nueva_lista = RESERVAR(1, Lista);
    if (nueva_lista == NULL) {
        return NULL;
    }

    *nueva_lista = (Lista) { .tamanio = tamanio };
    return nueva_lista;
}

#undef  Lista_Liberar
void    Lista_Liberar(Lista ** lista)
{
    while (!Lista_Vacia(*lista)) {
        TipoDato sacado;
        Lista_EliminarPosF(*lista, &sacado);
    }
    free(*lista);
}

static Nodo * encontrarEnesimoNodo(Nodo * nodo, int n)
{
    for (int i = 0; i < n; ++i) {
        nodo = nodo->siguiente;
    }
    return nodo;
}

// Modificación de los datos de la lista
bool Lista_InsertarPosI(Lista * lista, TipoDato dato)
{
    if (Lista_Llena(lista)) {
        return false;
    }

    Nodo * nuevo_nodo = RESERVAR(1, Nodo);
    if (nuevo_nodo == NULL) {
        return false;
    }
    *nuevo_nodo = (Nodo) { .dato = dato, .siguiente = lista->primero };
    if (Lista_Vacia(lista))
        lista->ultimo = nuevo_nodo;
    else
        lista->primero->anterior = nuevo_nodo;
    lista->primero = nuevo_nodo;
    lista->num_elementos++;
    return true;
}

bool Lista_InsertarPosF(Lista * lista, TipoDato dato)
{
    if (Lista_Llena(lista)) {
        return false;
    }

    Nodo * nuevo_nodo = RESERVAR(1, Nodo);
    if (nuevo_nodo == NULL) {
        return false;
    }
    *nuevo_nodo = (Nodo) { .dato = dato, .anterior = lista->ultimo };
    if (Lista_Vacia(lista))
        lista->primero = nuevo_nodo;
    else
        lista->ultimo->siguiente = nuevo_nodo;

    lista->ultimo = nuevo_nodo;
    lista->num_elementos++;
    return true;
}
bool Lista_InsertarPosN(Lista * lista, TipoDato dato, int pos_n)
{
    if (pos_n == 0) {
        return Lista_InsertarPosI(lista, dato);
    } else if (pos_n == lista->num_elementos) {
        return Lista_InsertarPosF(lista, dato);
    }

    if (Lista_Vacia(lista)) {
        return false;
    }
    if (pos_n < 1 || pos_n >= lista->num_elementos) {
        return false;
    }

    Nodo * aux = encontrarEnesimoNodo(lista->primero, pos_n - 1);
    Nodo * nuevo = RESERVAR(1, Nodo);
    *nuevo = (Nodo) { .dato = dato,
                      .anterior = aux, .siguiente = aux->siguiente };

    aux->siguiente = nuevo;
    if (nuevo->siguiente != NULL)
        nuevo->siguiente->anterior = nuevo;
    lista->num_elementos++;
    return true;
}

bool Lista_EliminarPosI(Lista * lista, TipoDato * dato)
{
    if (Lista_Vacia(lista)) { return false; }
    Nodo * aux = lista->primero;
    *dato = aux->dato;
    lista->primero = aux->siguiente;
    free(aux);
    if (lista->num_elementos == 1) {
        lista->ultimo = NULL;
    } else {
        lista->primero->anterior = NULL;
    }
    lista->num_elementos--;
    return true;
}
bool Lista_EliminarPosF(Lista * lista, TipoDato * dato)
{
    if (Lista_Vacia(lista)) { return false; }
    Nodo * aux = lista->ultimo;
    *dato = aux->dato;
    lista->ultimo = aux->anterior;
    free(aux);
    if (lista->num_elementos == 1) {
        lista->primero = NULL;
    } else {
        lista->ultimo->siguiente = NULL;
    }
    lista->num_elementos--;
    return true;
}
bool Lista_EliminarPosN(Lista * lista, TipoDato * dato, int pos_n)
{
    if (Lista_Vacia(lista)) { return false; }
    if (pos_n < 0 || pos_n >= lista->num_elementos) {
        fprintf(stderr, "Error, indice de lista inválido: %d\n", pos_n);
        exit(EXIT_FAILURE);
    }
    if (pos_n == 0) {
        return Lista_EliminarPosI(lista, dato);
    } else if (pos_n == lista->num_elementos - 1) {
        return Lista_EliminarPosF(lista, dato);
    }
    Nodo * eliminar = encontrarEnesimoNodo(lista->primero, pos_n);

    *dato = eliminar->dato;
    Nodo * ant = eliminar->anterior;
    Nodo * sig = eliminar->siguiente;

    ant->siguiente = sig;
    sig->anterior = ant;

    free(eliminar);
    lista->num_elementos--;
    return true;
}

static void intercambiar(TipoDato * a, TipoDato * b) {
    TipoDato tmp = *a;
    *a = *b;
    *b = tmp;
}

void Lista_Ordenar(Lista * lista, enum orden orden)
{
    int n = lista->num_elementos;

    for (int i = 0; i < n; ++i) {
        Nodo * aux = lista->primero;
        for (int j = 0; j < n - i - 1; ++j) {
            int comparacion = compararDato(aux->dato, aux->siguiente->dato);
            if (orden == ORD_INVERSO) {
                comparacion *= -1;
            }
            if (comparacion > 0) {
                intercambiar(&aux->dato, &aux->siguiente->dato);
            }
            aux = aux->siguiente;
        }
    }
}

int Lista_Buscar(const Lista * lista, TipoDato buscado)
{
    Nodo * aux = lista->primero;
    for (int i = 0; i < lista->num_elementos; ++i) {
        if (compararDato(aux->dato, buscado) == 0) {
            return i;
        }
        aux = aux->siguiente;
    }
    return -1;
}

// Revisar el estado de la lista sin modificarlos
TipoDato Lista_ChecarPosI(const Lista * lista)
{
    if (Lista_Vacia(lista)) {
        fputs("Error, no hay elementos en la lista", stderr);
        exit(EXIT_FAILURE);
    }
    return lista->primero->dato;
}
TipoDato Lista_ChecarPosF(const Lista * lista)
{
    if (Lista_Vacia(lista)) {
        fputs("Error, no hay elementos en la lista", stderr);
        exit(EXIT_FAILURE);
    }
    return lista->ultimo->dato;
}
TipoDato Lista_ChecarPosN(const Lista * lista, int posicionDesdeInicio)
{
    if (posicionDesdeInicio < 0 || posicionDesdeInicio >= lista->num_elementos) {
        fprintf(stderr, "Error, indice de lista inválido: %d\n",
                posicionDesdeInicio);
        exit(EXIT_FAILURE);
    }
    return encontrarEnesimoNodo(lista->primero, posicionDesdeInicio)->dato;
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
    Nodo * aux = lista->primero;
    for (int i = 0; i < lista->num_elementos; ++i) {
        operacion(&aux->dato);
        aux = aux->siguiente;
    }
}
void Lista_RecorrerInv(const Lista * lista, FunDato operacion)
{
    Nodo * aux = lista->ultimo;
    for (int i = 0; i < lista->num_elementos; ++i) {
        operacion(&aux->dato);
        aux = aux->anterior;
    }
}
#else
static void auxRecorrer(TipoDato * actual, int faltantes, FunDato operacion,
                      enum orden orden)
{
    if (actual != NULL) {
        if (orden == ORD_NORMAL) {
            operacion(actual);
            auxRecorrer(actual + 1, faltantes - 1, operacion);
        } else {
            auxRecorrer(actual + 1, faltantes - 1, operacion);
            operacion(actual);
        }
    }
}
void Lista_Recorrer(const Lista * lista, void (*operacion)(TipoDato * dt))
{
    auxRecorrer(lista->contenido, lista->tamanio, operacion, ORD_NORMAL);
}

void Lista_RecorrerInv(const Lista * lista, FunDato operacion)
{
    auxRecorrer(lista->contenido, lista->tamanio, operacion, ORD_INVERSO);
}
#endif
