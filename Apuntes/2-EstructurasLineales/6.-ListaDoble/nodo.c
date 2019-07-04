//Bibliotecas
#include <stdlib.h> 
#include "nodo.h"

Nodo* crearNodo() 
{
	Nodo* nodo =malloc(sizeof(Nodo)); //Creamos un apuntador a una estructura de tipo Nodo y apartamos su memoria
	return nodo;
}

Nodo* iniciarNodo (int dato) //Le pasamos el nodo
{
	Nodo* nodo = crearNodo(); //Apartamos el espacio para el nodo
	nodo->dato = dato; //En la casilla dato le damos el valor de dato
	nodo->sig = NULL; //El apuntador a siguiente va a ser igual a NULL
	nodo->ant=NULL;
	return nodo;
}

