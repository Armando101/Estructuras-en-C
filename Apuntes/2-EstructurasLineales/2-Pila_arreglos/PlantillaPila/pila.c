#include "pila.h"

// Cabeceras y definiciones privadas
#include <stdio.h>
#include <stdlib.h>

// Definir la estructura del tipo de dato
// Mi estructura de nombre pila tiene tres campos:
// -El tamaño del contenido de la pila (Datos)
// -Un apuntador de nombre contenido que guarda una dirección de memoria donde encontramos un dato de tipo TipoDato
// - Un entero que guarda el indice de mi tope

struct pila {
    int tamanio;
    TipoDato * contenido;
    int tope;
};

// Funciones de creación y destrucción de la pila
// Creación de una nueva pila
Pila * Pila_Nueva(int tamanio)
{
    if (tamanio < 1) {	// Si el usuario me ingresa un tamaño negativo defino la pila con una tamanio de 10
        tamanio = 10;
    }

    // Reservo memoria dinámicamente para crear mi estructura de datos llamada pila
    Pila * nueva_pila = RESERVAR(1, Pila);

    // Si la memoria no se pudo asignar regreso un apuntador a null
    if (nueva_pila == NULL)
        return NULL;

    // Asigno los campos de mi estructura pila
    nueva_pila->tamanio=tamanio;
    // Reservo memoria dinámica para el contenido de mi pila
    nueva_pila->contenido = RESERVAR(tamanio, TipoDato);
    // Asigno el tope de mi pila a -1, esto porque está vacía
    nueva_pila->tope=-1;
	
	// Consideramos el caso en el que no se haya podido asignar memoria para el contendio de mi pila   
    if (nueva_pila->contenido == NULL) {
    	// En dado caso que no se haya podido asignar memoria para el contendio de mi pila, liberamos el espacio que ya habiamos reservado para mi estructura pila.
        free(nueva_pila);
        // Regresamos un apuntador a NULL
        return NULL;
    }

    // En el caso en el que hayamos podido asignar memoria dinámicamente correctamente
    // Regresamos el apuntador que guarda la dirección de memoria de mi estructura pila.
    return nueva_pila;
}

void  Pila_Liberar(Pila ** pila)
{	
	// Liberamos la memoria que habíamos reservado para el contenido de mi pila
    free((*pila)->contenido);

    // Liberamos la memoria que habíamos asignado para la estructura pila
    free(*pila);
    // Hacemos que la variable pila (que anteriormente guardaba una dirección de memoria donde encuentro una estrctura de datos de tipo pila) ahora guarde un apuntador a NULL.
    *pila = NULL;
}

// Funciones para insertar/eliminar
bool Pila_Insertar(Pila * pila, TipoDato dato)
{	
	// Vemos si la pila está llena
    if (Pila_Llena(pila)) {
    	// Si la pila está llena reasigno la variable tamaño al doble
        pila->tamanio *= 2;

        // Creo una variable que guarde una dirección de memoria donde voy a encontrar un dato de tipo Tipo Dato, en dicha variable guardo la primera dirección de memoria de un nuevo espacio que voy a crear dinámicamente con la función REDIM
        TipoDato * nuevo_espacio = REDIM(pila->contenido, pila->tamanio, TipoDato);

        // Si el espacio que queria asignar en la línea anterior no se pudo reservar....
        if (nuevo_espacio == NULL) {
        	// Regreso el campo tamanio a su valor original, esto lo logro dividiendolo entre dos ya que en un paso anterior la había multiplicado por 2
            pila->tamanio /= 2;
            // Regreso un falso para indicar que no se pudo asignar el dato que me indicó el usuario
            return false;
        }

        // La siguiente línea se ejecuta si la Pila estaba llena y se pudo redimensionar el espacio correctamente
        // La dirección de memoria del nuevo espacio creado lo guardo en el campo contenido de mi estructura pila 
        pila->contenido = nuevo_espacio;
    }

 	// En la siguiente línea guardo el dato que el usuario me dio a ingresar
 	// Primero le sumo uno al tope, esto lo hago con el ++, una vez que puse mi tope como tope++ asigno el dato en ese nuevo tope 
    pila->contenido[++pila->tope] = dato;
    // Regreso un true para indicar que el dato se pudo asignar correctamente
    return true;
}

bool Pila_Eliminar(Pila * pila, TipoDato * dato)
{	
	// Si la pila está vacía regreso un false que indica que no se pudo eliminar ningún dato (porque no hay dato).
    if (Pila_Vacia(pila))
        return false;

    // Si pila tiene datos, regreso el dato que está en el tope y le resto uno al índice del tope
    *dato = pila->contenido[pila->tope--];
    return true;
}

// Funciones para consultar datos sin modificarlos
TipoDato Pila_ChecarTope(const Pila * pila)
{	
    if (Pila_Vacia(pila)) {
    	printf("La pila esta vacia\n");
    	return (TipoDato){0};
    }

    // Regreso el dato que está en el tope
    return pila->contenido[pila->tope];
}

// Función que nos permite ver que dato está en la posición N, contando desde el tope(Indice 0)
TipoDato Pila_ChecarPosN(const Pila * pila, int posicionDesdeTope)
{
    if (posicionDesdeTope < 0 || posicionDesdeTope > pila->tope) {
 		printf("Indie invalido\n");
		return (TipoDato){0};
    }

    return pila->contenido[pila->tope - posicionDesdeTope];
}

bool Pila_Vacia(const Pila * pila)
{
    return pila->tope == -1;
}

bool Pila_Llena(const Pila * pila)
{
    return pila->tope == pila->tamanio - 1;
}

int  Pila_NumeroElementos(const Pila * pila)
{
    return pila->tope + 1;
}

void Pila_Imprimir(const Pila * pila, enum orden orden)
{
    printf("\n");
    if (orden == ORD_INVERSO)
        Pila_RecorrerInv(pila, imprimirDato);
    else
        Pila_Recorrer(pila, imprimirDato);
}

// Función que recorre mi pila, recibe como segundo parámetro una función que devuelve void y que recibe como parámetro in apuntador a TipoDato, el nombre que le estoy dando a la función que se pasa como parámetro se llama operación.
void Pila_Recorrer(const Pila * pila, void (*operacion)(TipoDato * dt))
{
    for (int i = 0; i <= pila->tope; ++i) {	// Recorro el contenido de pila y ejecuto la función que el usuario me pasó como parámetro sobre cada elemento de la pila.
        operacion(&pila->contenido[i]);
    }
}

void Pila_RecorrerInv(const Pila * pila, void (*operacion)(TipoDato * dt))
{
    for (int i = pila->tope; i >= 0; --i) {
        operacion(&pila->contenido[i]);
    }
}
