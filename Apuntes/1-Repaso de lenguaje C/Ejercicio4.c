#include <stdio.h>

int main(int argc, char const *argv[]) {
	// Funciones
	
	// Clasificación
	// Funciones que entregan un valor: Se utilizan para asignaciones
	// x=sin(23);
	// x=valor();	x guarda lo que devuelve la función valor

	// Funciones que no entregan valores: Se identifican con void, no devuelven nada
	// printf("Hola\n");

	// Paso de parámetros
	// Paso por valor
	// El valor pasado a la función se puede modificar dentro de la función pero no se ve afectado el valor original, sólo se le pasa una copia a la función.
	
	int a, b, r;
	a=10;
	b=20;
	r=sumaVal(a,b);
	printf("%d\n", r);
	
	r=sumaVal5(a,b);
	printf("%d\n", r);
	printf("%d\n", a);	// El valor no se ve afectado por el cambio en la función
	printf("%d\n", b);

	return 0;
}