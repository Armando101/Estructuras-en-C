#include <stdio.h>

int main(int argc, char const *argv[]) {
	
	int *q;
	int p;
	q=&p;

	scanf("%d", &p);	// ¿Es correcta esta línea?
	printf("%d\n",p);

	scanf("%d", q);		// ¿Es correcta esta línea?
	printf("%d\n",p);	

	return 0;
}