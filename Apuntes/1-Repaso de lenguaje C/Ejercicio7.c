#include <stdio.h>

int main(int argc, char const *argv[]) {
	// Estructuras de datos

typedef struct {
	int info;
	int sig;
}TElemento;

TElemento a[2];
TElemento *p;

p=a;
(*p).info = 100;
// *p.info = 10;	// Esta línea marca un error ya que el operador . Tiene mayor prioridad que el operador *
// (*p+1).info; 		// Al igual que la línea anterior, ésta también es inválida

(*(p+1)).info=10;

printf("%d\n", (*p).info);
printf("%d\n", (*(p+1)).info);
printf("%d\n", p[1].info);
printf("%d\n", a[1].info);


// p-> info = 10 // Toma la direccion almacenada en p, ve a esa direccion y en su campo info guarda un 10
// p[2].info=10 == (*(p+2)).info=10 == (p+2)->info=10

// Paso de parametros por referencia con estructuras

void leerElemento(TElemento *dos) {
	dos[0].info=25;
}
void imprime(TElemento *dos) {
	printf("%d\n", (*dos).info);
}

TElemento uno;
uno.info=80;
leerElemento(&uno);
imprime(&uno);

	return 0;
}