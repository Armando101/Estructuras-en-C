#ifndef LISTA_H
#define LISTA_H

// Cabeceras públicas
#include <stdbool.h>

// Definiciones
#include "tipo_entero.h"
#include "definiciones.h"
typedef struct lista Lista;

#define LISTA_EN_PRUEBAS true

// Prototipos de función
Lista * Lista_Nueva(int tamanio);
void    Lista_Liberar(Lista ** lista);
#define Lista_Liberar(l) Lista_Liberar(&l)

bool Lista_InsertarPosI(Lista * lista, TipoDato dato);
bool Lista_InsertarPosF(Lista * lista, TipoDato dato);
bool Lista_InsertarPosN(Lista * lista, TipoDato dato, int pos_n);
bool Lista_EliminarPosI(Lista * lista, TipoDato * dato);
bool Lista_EliminarPosF(Lista * lista, TipoDato * dato);
bool Lista_EliminarPosN(Lista * lista, TipoDato * dato, int pos_n);

TipoDato Lista_ChecarPosI(const Lista * lista);
TipoDato Lista_ChecarPosF(const Lista * lista);
TipoDato Lista_ChecarPosN(const Lista * lista, int posicionDesdeTope);

void Lista_Ordenar(Lista * lista, enum orden orden);
int Lista_Buscar(const Lista * lista, TipoDato buscado);

bool Lista_Vacia(const Lista * lista);
bool Lista_Llena(const Lista * lista);
int  Lista_NumeroElementos(const Lista * lista);

void Lista_Imprimir(const Lista * lista, enum orden orden);
void Lista_Recorrer(const Lista * lista, FunDato operacion);
void Lista_RecorrerInv(const Lista * lista, FunDato operacion);

#endif // LISTA_H
