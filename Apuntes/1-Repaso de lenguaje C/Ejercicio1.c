#include <stdio.h>
// 1.- ¿Qué es un apuntador
// Un apuntador es un tipo de dato que contiene una dirección de memoria, la cual corresponderá a un dato o a una variable que contiene el dato.

// Tenemos dos operadores para el manejo de apuntadores
// El oprador dirección &: Regresa la dirección de una variable
// El operador de indirección *: Toma el contenido que hay en cierta dirección.

// Sintaxis:
// Tipo_dato * nombre del apuntador;
// Tipo_dato: Especifica el dipo de dato cuya dirección será guardada en nuestro apuntador (int, float, char, etc.)
// Ejemplos:
// int *ptr, entero.
// float *val


int main(int argc, char const *argv[]) {


	// Ejemplo 	

	int a;
	int *p;
	p=&a;

	// ¿Cuáles son correctas y porqué?
	scanf("%d", &a);
	scanf("%d", &p);
	scanf("%d", p);
	scanf("%d", a);
}