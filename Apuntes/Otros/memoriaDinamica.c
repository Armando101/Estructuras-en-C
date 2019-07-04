#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	int n;
	float *v;
	printf("Número de alumnos\n");
	scanf("%d", &n);
	v=(float *)malloc(sizeof(float)*n);
	for (int i = 0; i < n; ++i) {
		printf("Promedio de alumno: %d\n", i+1);
		scanf("%f", &v[i]);
		//(v+i)
	}

	for (int i = 0; i < n; ++i) {
		printf("Promedio de alumno %d: %.2f\n", i+1, *(v+i));
	}

	return 0;
}