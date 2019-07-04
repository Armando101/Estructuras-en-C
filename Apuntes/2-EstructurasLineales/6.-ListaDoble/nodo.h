//Archivo de cabecera
typedef struct Nodo  
{	
	int dato; //Entero
	struct Nodo *sig; //Apuntador a otro Nodo 
	struct Nodo *ant; //Apuntador a otro Nodo 

}Nodo; //Definimos una estructura Nod llamada Nodo

//Declaracion de Funciones
Nodo* crearNodo(); //CrearNodo
Nodo* iniciarNodo(int dato); //Inicializa el Nodo
