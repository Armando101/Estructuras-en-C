#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

Lista* crearL()
{
	Lista* lista= malloc(sizeof(Lista)); //Aparta el espacio para una lista de nodos
	lista->head = lista->tail=NULL; //inicializa los apuntadores de la lista
	lista->num_nodos=0; //inciializa el contador del tamaño de la lista
	return lista;
}

int isEmpty(Lista* lista)  //Verifica si la lista esta vacia a partir de sus apuntadores
{
	if(lista->head == NULL && lista->tail == NULL){
			return 1;
		}
		return 0;
}

void insert_Front(Lista* lista,int dato)
{
	Nodo* nodo = iniciarNodo(dato); //Creo nodo
	if(isEmpty(lista)) //Si la lista esta vacia
	{
		lista-> head=lista->tail =  nodo; //Va a ser mi primer elemento
	}
	else // si no
	{
		nodo->sig =NULL;
		nodo->ant=lista->head;
		lista->head->sig =nodo;
		lista->head=nodo; 
	}
	lista->num_nodos++; //aumenta contador
}

void insert_Back(Lista* lista,int dato) //inserta en la lista
{
	Nodo* nodo = iniciarNodo(dato); //crea el nodo
	if(isEmpty(lista))  //verifica si esta vacia
	{
		lista-> head=lista->tail=nodo; //si si el elemento va a ser el primero
	}
	else
	{	
		nodo->ant=NULL;
		nodo->sig=lista->tail;
		lista->tail->ant=nodo;
		lista->tail=nodo;
	}
	lista->num_nodos++;	 //aumenta el contador
}

void insert_X(Lista* lista, int pos, int dato)
{
	if(pos > lista->num_nodos) // si pos es un numero valido
	{
		return;  //Rompe
	}	
	else if(pos==0) // si pos es 0 va a ser el primer elemento
	{
		insert_Back(lista,dato);
	}
	else if (pos == lista->num_nodos) // si es igual al tamanio de la lista sera el ultimo
	{
		insert_Front(lista,dato);
	}
	else
	{
		Nodo* nodo = iniciarNodo(dato); //Creo nodo
		Nodo* aux = lista->tail;
		for (int i = 0; i < pos-1; ++i)
		{
			aux = aux-> sig; //recorre hasta llegar al anterior
		}
		nodo->sig = aux->sig; // nodo siguiente va a ser siguiente del aux
		aux->sig->ant=nodo;
		aux->sig = nodo; // auxiliar siguiente va a ser igual a nodo
		nodo->ant=aux;
		lista->num_nodos++; //aumenta contador
	}
}
int remove_Front(Lista* lista) //remueve de enfrente de la lista  
{
	if(isEmpty(lista)) //verifica si la lista no esta vacia
	{	
		printf("La lista esta vacia\n");
		return 0;
	}
	Nodo* aux = lista->head;  // auxiliar va a ser igual a primer elemento
	if(lista->head == lista->tail) //si solo hay un elemento
	{
		lista->head = lista->tail = NULL; //head y tail ya no apuntaran a nada
	}
	else if(!isEmpty(lista)) //si la lista tiene algun elemento
	{
		lista->head = lista->head->ant; //head va a ser igual a su siguiente
		lista->head->sig->ant=NULL;
		lista->head->sig=NULL;
	}
	lista->num_nodos--; //habra un decremento en el tamaaño de la lista
	printf("Dato eliminado del frente: %d\n",aux->dato);
	free(aux);
	return 1;
}


int remove_Back(Lista* lista)
{
	if(isEmpty(lista))  //verifica si la lista no esta vacia
	{
		return 0;
	}
	Nodo* aux = lista->tail; //apuntador auxiliar
	if(lista->head == lista->tail) //si solo hay un elemento
	{
		lista->head = lista->tail = NULL; //head y tail ya no apuntan aa nada 
	}
	else if(!isEmpty(lista)) //Si la lista tiene elementos
	{
		lista->tail=lista->tail->sig;
		lista->tail->ant->sig=NULL;
		lista->tail->ant=NULL;
	}	
	lista->num_nodos--; //se decrementa el tamaño de la lista
	printf("Elemento eliminado del back: %d\n",aux->dato);
	free(aux);
	return 1;
}
 
int remove_x(Lista* lista, int pos) //Remueve a partir de la posicion indicada
{
	if(isEmpty(lista))  //verifica si la lista no esta vacia
	{
		return 0;
	}
	if(pos > lista->num_nodos) //revisa si es un numero valido
	{
		return 0;
	}
	if (pos==0) //si es igual al primer elemento
	{
		return remove_Back(lista);
	}
	else if (pos== lista->num_nodos-1)  //si es igual al ultimo elemento
	{
		return remove_Front(lista);
	}
	else
	{
		Nodo* aux;  //Apuntador auxiliar aun nodo
		Nodo* scout = lista->tail;  //Apuntador scout va a ser a el nodo primero
		for (int i = 0; i < pos-1; ++i)
		{
			scout= scout->sig;   //recorre la lista hasta la posicion antes del elemento a eliminar
		}
		aux =scout->sig; //auxiliar va a ser el nodo que se va a eliminar
		scout->sig = aux->sig;  //scout va a apuntar al nodo que apunta el que se va a eliminar
		aux->sig->ant=scout;
		aux->sig=NULL; //el nodo a eliminar ya no apunta a nada
		aux->ant=NULL;
		lista->num_nodos--; //se decrementa el numero de la lista
		printf("Elemento eliminado de la posicion %d: %d\n",pos, aux->dato);
		free(aux);
	}
}

int getFrom(Lista* lista, int pos) //Imprime los datos de usuario del nodo en cierta posicion
{
	if(pos > lista->num_nodos)
	{
		return 0;
	}
	Nodo* aux = lista->tail;
	for (int i = 0; i < pos; ++i)
	{
		aux = aux->sig;
	}
	return aux->dato;	
}