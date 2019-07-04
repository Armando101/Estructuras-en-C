#include "nodo.h"

typedef struct Lista
{
	Nodo* head; 
	Nodo* tail; 
	int num_nodos; 
}Lista;


Lista* crearL(); 
int isEmpty(Lista* lista); 
void insert_Front(Lista* lista,int dato); 
void insert_Back(Lista* lista,int dato); 
void insert_X(Lista* lista,int pos,int dato); 
int remove_Front(Lista* lista); 
int remove_Back(Lista* lista); 
int remove_x(Lista* lista, int pos); 
int getFrom(Lista* lista, int pos); 
