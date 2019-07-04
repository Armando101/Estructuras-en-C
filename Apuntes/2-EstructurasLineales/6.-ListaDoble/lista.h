#include "nodo.h"

typedef struct Lista //Estructura Lista de Nodos
{
	Nodo* head; //contiene un apuntador 
	Nodo* tail; //contiene un apuntador
	int num_nodos; //contiene un entero, guarda el numero de elementos que tengo en mi lista
}Lista;

//Todas las funciones de lista
Lista* crearL(); //crea lista
int isEmpty(Lista* lista); //Verifica si la lista esta vacia
void insert_Front(Lista* lista,int dato); //inserta elemento enfrente
void insert_Back(Lista* lista,int dato); //inserta elemento atras
void insert_X(Lista* lista,int pos,int dato); //inserta elemento en la posicion X
int remove_Front(Lista* lista); //Quita el primer elemento
int remove_Back(Lista* lista); //Quita el ultimo elemento
int remove_x(Lista* lista, int pos); //Quita un elemento en cierta posicion 
int getFrom(Lista* lista, int pos); //Te muestra los datos de tu Nodo en cierta posicion de la lista
