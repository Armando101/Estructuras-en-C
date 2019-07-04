#include <stdio.h>

int main(int argc, char const *argv[]) {
	typedef struct {
		char* nombre;
		int nl;
		float prom;
	}TAlumno;

TAlumno a, b;
a.nombre="Armando";
a.nl=34;
a.prom=8.5;

b=a;
b.nl=23;
b.nombre="Roberto";

printf("Nombre: %s NL: %d Promedio: %.2f\n", a.nombre ,a.nl, a.prom);
printf("Nombre: %s NL: %d Promedio: %.2f\n", b.nombre ,b.nl, b.prom);
// a y b son estructuras de datos almacenadas en distintas direcciones de memoria, cuando hago la asignacion a=b, lo que estpy haciendo es copiar la informacion que hay en b to a.

	return 0;
}