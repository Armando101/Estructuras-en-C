#ifndef PILA_H
#define PILA_H

// Cabeceras p�blicas
#include <stdbool.h>

// Definiciones
#include "tipo_entero.h"
#include "definiciones.h"
typedef struct pila Pila;

//#define PILA_EN_PRUEBAS true


// Prototipos de funci�n
Pila * Pila_Nueva(int tamanio);
void  Pila_Liberar(Pila ** pila);
//#define Pila_Liberar(p) Pila_Liberar(&p)

bool Pila_Insertar(Pila * pila, TipoDato tipo);
bool Pila_Eliminar(Pila * pila, TipoDato * tipo);

TipoDato Pila_ChecarTope(const Pila * pila);
TipoDato Pila_ChecarPosN(const Pila * pila, int posicionDesdeTope);

bool Pila_Vacia(const Pila * pila);
bool Pila_Llena(const Pila * pila);
int  Pila_NumeroElementos(const Pila * pila);

void Pila_Imprimir(const Pila * pila, enum orden orden);
void Pila_Recorrer(const Pila * pila, void (*operacion)(TipoDato * dt));
void Pila_RecorrerInv(const Pila * pila, void (*operacion)(TipoDato * dt));

#endif // PILA_H
