#include <stdio.h>
#include <stdlib.h>

typedef struct NODO{
	int info;
	struct NODO *sig;
}TNodo;

typedef struct {
	TNodo * h;
	TNodo *t;
}TCola;
	
void InsertarDato(TCola *, int dato);
void BuscarDato(TCola *, int dato);
TCola * NuevaCola();
void Imprime(TCola *);

TCola * NuevaCola() {
	TCola * cola;
	cola = (TCola*)malloc(sizeof(TCola));
	cola->h=cola->t=NULL;
}

TNodo * nuevoNodo(int dato) {
	TNodo *q;
	q=(TNodo*)malloc(sizeof(TNodo));
	q->info=dato;
	q->sig=NULL;
	return q;
}

void InsertarDato(TCola * cola, int dato) {
	TNodo * nuevo;
	nuevo = nuevoNodo(dato);
	if (cola -> h == NULL) {
		cola -> h = cola ->t = nuevo;
		return;
	}
	cola -> t ->sig = nuevo;
	cola -> t = nuevo;
}

void BuscarDato(TCola * cola, int dato) {
	if (cola->h==NULL) {
		printf("No ha ingresado datos\n");
		return;
	}


	if (cola->h->info == dato) {
		printf("Su numero fue encontrado en la primera posicion\n");
		return;
	}

	if (cola->t->info == dato) {
		printf("Su numero fue encontrado en la ultima posicion\n");
		return;
	}

	TNodo *p;
	p=cola->h->sig;
	int i = 1;
	while(p->sig!=NULL) {
		if (p->info == dato) {
			printf("Su numero fue encontrado en la posicion %d\n", i+1);
			return;
		}
		p=p->sig;
		i++;
	}
	printf("\nSu numero no se ha agregado a la lista\n");
}

void Imprime(TCola * cola) {
	if (cola->h==NULL) {
		printf("No ha ingresado datos\n");
		return;
	}
	TNodo *p;
	p=cola->h;
	printf("\n");
	while(p->sig!=NULL) {
		printf("%d\n", p->info);
		p=p->sig;
	}
	printf("%d\n\n", p->info);
}

void Clear() {
	#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}


int main(int argc, char const *argv[]) {
	int op, dato;
	TCola * cola;
	cola = NuevaCola();

	printf("\n\n\tBienvenido\n");
	while(1) {	
	printf("\nElija una opcion\n");
		printf("1: Insertar datos\n2: Realizar una busqueda\n3: Imprimir los datos\n4: Salir del programa\n");
		scanf("%d", &op);
		Clear();
		switch(op) {
			case 1:
				printf("Ingrese el dato que desea Insertar\n");
				scanf("%d", &dato);
				InsertarDato(cola, dato);
				break;
			case 2:
				printf("Ingrese el dato a buscar\n");
				scanf("%d", &dato);
				BuscarDato(cola, dato);
				break;
			case 3:
				Imprime(cola);
				break;
			case 4:
				printf("Vuelva pronto\n");
				return 0;
			default :
				printf("Ingrese una opcion valida\n");
				break;
		}
	}
	return 0;
}