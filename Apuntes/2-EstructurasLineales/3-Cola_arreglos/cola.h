#ifndef COLA_H
#define COLA_H

// Cabeceras públicas
#include <stdbool.h>

// Definiciones
#include "tipo_entero.h"
#include "definiciones.h"
typedef struct cola Cola;

#define COLA_EN_PRUEBAS true

// Prototipos de función
Cola * Cola_Nueva(int tamanio);
void   Cola_Liberar(Cola ** cola);
#define Cola_Liberar(c) Cola_Liberar(&c)

bool Cola_Insertar(Cola * cola, TipoDato tipo);
bool Cola_Eliminar(Cola * cola, TipoDato * tipo);

TipoDato Cola_ChecarPrimero(const Cola * cola);
TipoDato Cola_ChecarPosN(const Cola * cola, int posicionDesdeInicio);

bool Cola_Vacia(const Cola * cola);
bool Cola_Llena(const Cola * cola);
int  Cola_NumeroElementos(const Cola * cola);

void Cola_Imprimir(const Cola * cola, enum orden orden);
void Cola_Recorrer(const Cola * cola, void (*operacion)(TipoDato * dt));
void Cola_RecorrerInv(const Cola * cola, void (*operacion)(TipoDato * dt));

#endif // COLA_H
