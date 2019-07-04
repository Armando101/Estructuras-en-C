#ifndef DEFINICIONES_H
#define DEFINICIONES_H

// Nos permitirá recorrer nuestra pila en orden normal o inverso.
enum orden { ORD_NORMAL, ORD_INVERSO };

// Definimos algunas funciones con el fin de ahorrarnos código

// Reservar memoria dinámicamente
#define RESERVAR(cantidad, tipo) (tipo *)malloc(cantidad * sizeof(tipo))

// Redimensionar memoria dinámicamente
#define REDIM(anterior, cantidad, tipo) (tipo *)realloc(anterior, cantidad * sizeof(tipo))

#endif /* DEFINICIONES_H */
