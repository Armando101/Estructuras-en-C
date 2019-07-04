#include <stdio.h>

int main(int argc, char const *argv[]) {
	int a;
	int *p;
	p=&a;
	a=23;
	*p=26;	// Ve a la dirección de memoria que guarda p y ahí guarda un 26
	a=7;
	printf("%d\n", *p);	// ¿Qué imprime?
	printf("%p\n", p);	// Imprime la dirección de memoria de p
	
	return 0;
}