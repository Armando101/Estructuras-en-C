//Archivo de cabecera
typedef struct Nodo  
{	
	int dato; //Entero
	struct Nodo *sig; 
	struct Nodo *ant;  

}Nodo;

Nodo* crearNodo();
Nodo* iniciarNodo(int dato);
