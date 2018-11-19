#include <stdio.h>
#include <string.h>

void recursivo(char*arreglo[],int limite_izq,int limite_der) {
    int izq,der;
    char * temporal;
    char * pivote;
    izq=limite_izq;
    der = limite_der;
    pivote = arreglo[(izq+der)/2];
    do {
        while(strcmp(arreglo[izq],pivote)<0 && izq<limite_der)
        	izq++;
        while(strcmp(pivote,arreglo[der])<0 && der > limite_izq)
        	der--;
        if(izq <=der) {
            temporal= arreglo[izq];
            arreglo[izq]=arreglo[der];
            arreglo[der]=temporal;
            izq++;
            der--;
        }
 
    } while(izq<=der);
    if(limite_izq<der)
    	recursivo(arreglo,limite_izq,der);

    if(limite_der>izq)
    	recursivo(arreglo,izq,limite_der);
}

void quicksort(char* arreglo[],int n) {
    recursivo(arreglo,0,n-1);
}

void Imprime(char * arreglo[], int size) {
	for (int i = 0; i < size; ++i)
		printf("%s\n",arreglo[i]);
	printf("\n");
}

int main(int argc, const char * argv[])	{
	char *arreglo[]={
		"Smoke on the water", "Wish you were here", "Don't let me now", "Amazing",
		"Stairway to heaven", "Sweet child o'mine", "Smells like teen spirit", "Losing my religion",
		"Paranoid", "Whole lotta love", "Another Brick in the wall", "November rain", 
		"Imagine", "Bohemian Rapsody", "The final countdown", "Wonderwall", 
		"Hey jude", "Walk this way", "Every breath you take", "Paint it black" 
		};
	int size = 20;
	char *inverso[size];
	
	printf("Arreglo Desordenado\n");
	printf("\n");
	Imprime(arreglo, size);
    printf("\n");
    
    quicksort(arreglo,size);

    printf("Arreglo ordenado alfabeticamente\n");
    printf("\n");
    Imprime(arreglo, size);
    printf("\n");


    printf("Arreglo ordenado de manera inversa\n");
    printf("\n");
    
    for (int i = 1; i <= size; i++) {
    	inverso[i-1]=arreglo[size-i];
    }

    Imprime(inverso,size);
    printf("\n");

    return 0;
}