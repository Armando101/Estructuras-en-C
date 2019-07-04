#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	char cadena[10] = "";

	for (int i = 1; i < 100; i++) {
		if (i%3==0)
			strcat(cadena, "Fizz");

		if (i%5==0)
			strcat(cadena, " Buzz");	

		if (i%3!=0 && i%5!=0)
			printf("%d", i);

		printf("%s\n", cadena);
		strcpy(cadena, "");
	}

	return 0;
}