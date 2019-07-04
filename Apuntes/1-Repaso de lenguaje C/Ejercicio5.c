#include <stdio.h>

int main(int argc, char const *argv[]) {
	int a, b, r;
	a=10;
	b=20;
	r=sumaRef(&a,&b);	// Se tiene que mandar una dirección
	printf("%d\n", r);
	
	//r=sumaRef5(&a,&b);
	sumaRef5(&a,&b, &r);
	printf("%d\n", r);
	printf("%d\n", a);	// El valor se ve afectado por el cambio en la función
	printf("%d\n", b);
	return 0;
}