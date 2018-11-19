#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Definición de las estructuras de datos*/

typedef struct NODO {	//Definimos una estructura de tipo nodo
	char * nom;			//Al trabajar con una lista doblemente ligada necesitamos
	struct NODO *sig;	//Un nodo que apunte al siguiente nodo
	struct NODO *ant;	//Y un nodo que apunte al nodo anterior
} TNodo;

typedef struct {		//Necesitamos una lista en la cual vamos a meter nuestros nodos
	TNodo *h;			//Necesitamos un apuntador que apunte a nuestro primer nodo
	TNodo *t;			//Y un apuntador que apunte al ultimo nodo
} TLista;

/*Definición de los prototipos de las funciones a implementar*/

TLista * nuevaLista();	//Crea una nueva lista
TNodo * nuevoNodo();	//Crea un nuevo nodo
void enqueue(TLista*, TNodo*);	//Funcion que agrega al final de una lista
TNodo * dequeue(TLista*);		//Funcion que elimia y devuelve el valor del inicio
TNodo * ExtraerNombre(TLista *, char *);	//Elimina y devuelve el nodo especificando el nombre
void Imprime(TLista*);
void InsertaNombres(TLista*, int);
void ExtraerNombres(TLista *, int);
void Clear();	//Limpia la pantalla
/*******************************Funcion Main******************************/

int main(int argc, char const *argv[]) {
int n = 4;		//Variando este numero es posible que el programa admita mas o menos nombres
TLista * Lista;	//Declaramos la lista con la que vamos a trabajar
Lista = nuevaLista();
int op;	
printf("\n\n\t\tBienvenido seleccione una  opcion del menu");
while(1) {
	printf("\n1:Insertar nombres");
	printf("\n2:Extraer un nombre");
	printf("\n3:Extraer dos nombre");
	printf("\n4:Extraer tres nombre");
	printf("\n5:Ver la lista");
	printf("\n6:Salir del programa\n");
	scanf("%d", &op);
	Clear();
	switch (op) {
		case 1:
			InsertaNombres(Lista, n);
			break;
		case 2:
			ExtraerNombres(Lista, 1);
			break;
		case 3:
			ExtraerNombres(Lista,2);
			break;
		case 4:
			ExtraerNombres(Lista, 3);
			break;
		case 5:
			Imprime(Lista);
			break;
		case 6:
			printf("Vuelva pronto\n");
			return 0;
		default :
			printf("Opcion no valida\n");
	}
}
return 0;
}

/*Implementación de las funciónes*/

TLista * nuevaLista() {		//Implementación de nuestra función para crear una nueva lista
	TLista * lista;
	lista=(TLista*)malloc(sizeof(TLista));
	lista -> h =NULL;
	lista -> t =NULL;
	return lista;
}

TNodo * nuevoNodo(char * nombre) {	//Implementación de nuestra función para crear un nuevo nodo
	TNodo *q;
	q=(TNodo*)malloc(sizeof(TNodo));
	q->nom=nombre;
	q->sig=NULL;
	q->ant=NULL;
	return q;
}

void enqueue(TLista * lista, TNodo * nodo) {	//Implementación de la función enqueue
	if (lista -> h == NULL) {
		lista -> h = lista ->t = nodo;
		return;
	}

	lista -> t ->sig = nodo;
	nodo -> ant = lista->t;
	lista -> t = nodo;
}

TNodo * dequeue(TLista * lista) {			//Implementación de la función dequeue		
	TNodo *p;
	if (lista->h == NULL) {
		return NULL;
	}

	if (lista->h==lista->t)	{
		p=lista->h;
		lista->h=NULL;
		lista->t=NULL;
		return p;
	}

	p=lista->h;
	lista->h=lista->h->sig;
	lista->h->ant=NULL;
	p->sig=NULL;
	return p;
}

TNodo * ExtraerNombre(TLista * lista, char * nombre) {
	TNodo *p;
	p = lista->h;
	while((p!=NULL) && (strcmp(p->nom, nombre)!=0))
		p=p->sig;				//Recorre toda la lista
	if (p==NULL) {			//Caso en el que no encuentra el nombre indicado
		return NULL;
	}
	//printf("%s\n", p->nom);

	if (lista->h == lista->t) {	//Lista con un solo elemento
		lista->h=NULL;
		lista->t=NULL;
		return p;
	}
	if (p==lista->h) {  			//Elemento en la primera posición de la lista
		lista->h = p->sig;
		lista->h->ant=NULL;
		p->sig=NULL;
		return p;
	}
	if (p==lista->t) { 		//Elemento en la ultima posición de la lista
		lista->t = p->ant;
		lista->t->sig=NULL;
		p->ant=NULL;
		return p;
	}
								//En otro caso
	printf("otro Caso\n");
	(p->ant)->sig=p->sig;
	(p->sig)->ant=p->ant;
	p->sig=NULL;
	p->ant=NULL;
	return p;
}

void InsertaNombres(TLista * lista, int n) {
	printf("Ingresa %d nombres\n", n);
	for (int i = 0; i < n; ++i) {
		TNodo * nod;		//Declaramos un nodo
		char * s;			//Declaramos una variable donde colocaremos los nombres
		s=(char*)malloc(sizeof(char)*30);	//Los nombres deben de ser de maximo 30 carateres
		printf("\nNombre %d: ", i+1);
		scanf("%s", s);
		nod = nuevoNodo(s);
		enqueue(lista, nod);
	}
}

void ExtraerNombres(TLista * lista, int n) {
	printf("Ingrese el nombre a extraer\n");
	for (int i = 0; i < n; ++i) {
		TNodo *p;
		char * s;			//Declaramos una variable donde colocaremos los nombres
		s=(char*)malloc(sizeof(char)*30);	//Los nombres deben de ser de maximo 30 carateres
		printf("\nNombre %d: ", i+1);
		scanf("%s", s);
		p=ExtraerNombre(lista, s);
		if (p== NULL) {
			printf("El nombre %s no fue encontrado en la lista\n", s);
		}
		else {
			printf("El nombre %s fue extraido con exito\n", s);
		}
	}
}

void Imprime(TLista * lista) {
	if (lista->h==NULL) {
		printf("No ha ingresado datos vacia\n");
		return;
	}
	TNodo *p;
	p=lista->h;
	printf("\n");
	while(p->sig!=NULL) {
		printf("%s\n", p->nom);
		p=p->sig;
	}
	printf("%s\n\n", p->nom);
}

void Clear() {
	#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}