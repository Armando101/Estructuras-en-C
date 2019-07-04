#ifndef DEFINICIONES_H
#define DEFINICIONES_H

enum orden { ORD_NORMAL, ORD_INVERSO };

#define RESERVAR(cantidad, tipo) (tipo *)malloc(cantidad * sizeof(tipo))
#define REDIM(anterior, cantidad, tipo) (tipo *)realloc(anterior, cantidad * sizeof(tipo))

#endif /* DEFINICIONES_H */
