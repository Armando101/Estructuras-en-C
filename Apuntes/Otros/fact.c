#include <stdio.h>

double fac (int n) {
	if (n==1 || n==0)
		return 1;

	return n * fac(n-1);
}

int main(int argc, char const *argv[]) {
	
	int n;
	double fn;
	scanf("%d", &n);
	
	printf("\nEl factorial de %d es %.2f\n", n, fac(n));

	return 0;
}