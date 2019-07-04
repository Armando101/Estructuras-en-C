#include "pila.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
// Main con el que vamos a hacer las pruebas y a verificar que las implementaciones de nuestra pila funcionen correctamente

// Ocuparemos la función assert que se encuentra en la biblioteca assert.h

// Función assert(valor_booleano)
// La función assert recibe un valor booleando, si ese valor es true, no pasa nada, si es flase el programa manda un error y termina.

// La implenetación de la función assert es similar a la siguiente

/*	// Descomenta este bloque de código, haz que en le programa la función assert reciba un false; por ejemplo, inserta un dato de más y ve lo que sucede.

#undef assert
void assert(bool valor) {
	if (valor == false) {
		printf("Error en el código\n");
		exit(1); // Indico que el programa terminó con errores
	}
}
*/

int main(void)
{	
	// Creo una nueva pila de tamaño 5
    Pila * p = Pila_Nueva(5);

    // Al principio la pila debe de estar vacía
    // Pila_Vacia me devuelve true o false, en este caso me debe devolver un true ya que la pila la acabo de crear y esta vacía. Al recibir la función assert un true no sucede nada, el programa continua.
    // Si por ejemplo hubiera implementado mal mi función y en este caso Pila_Vacia regresara un false siendo que debe regresar un true; la función assert recibiria un false y por lo tanto mandaria un error en mi programa y terminaría.
    assert(Pila_Vacia(p));

    // En un principio el número de elementos debe ser cero
    assert(Pila_NumeroElementos(p) == 0);

    // Se insertan elementos hasta que se llene
    assert(Pila_Insertar(p, 1));
    assert(Pila_Insertar(p, 2));
    assert(Pila_Insertar(p, 3));
    assert(Pila_Insertar(p, 4));
    assert(Pila_Insertar(p, 5));
    //assert(Pila_Insertar(p, 6));	// Descomenta esta línea y ve lo que sucede
    
    // La pila tiene que reportarse llena ahora porque ya le ingresé 5 (El tamanio que me indicó el usuario fueron 5)
    // Si intentamos agregar otro dato mandaria un error.
    // assert(Pila_Insertar(p, 6)); // Si ejecutamos esta línea habría un error y el programa terminaría
    
    assert(Pila_Llena(p));
    assert(Pila_NumeroElementos(p) == 5);

    // El primer elemento tiene que ser el 5 que se insertó al final
    assert(Pila_ChecarTope(p) == 5);

    // Los siguientes elementos tienen que corresponderse al orden de inserción
    assert(Pila_ChecarPosN(p, 0) == 5);
    assert(Pila_ChecarPosN(p, 1) == 4);
    assert(Pila_ChecarPosN(p, 2) == 3);
    assert(Pila_ChecarPosN(p, 3) == 2);
    assert(Pila_ChecarPosN(p, 4) == 1);

    // Funciones que implican recorridos
    printf("Pila en orden normal: ");  Pila_Imprimir(p, ORD_NORMAL);
    printf("Pila en orden inverso: "); Pila_Imprimir(p, ORD_INVERSO);

    // Estoy multiplicando por 5 todos mis datos, la función multiplicar 5 la implementamos en tipo_entero.c
    Pila_Recorrer(p, multiplicar5);

    assert(Pila_ChecarPosN(p, 0) == 25);
    assert(Pila_ChecarPosN(p, 1) == 20);
    assert(Pila_ChecarPosN(p, 2) == 15);
    assert(Pila_ChecarPosN(p, 3) == 10);
    assert(Pila_ChecarPosN(p, 4) == 5);

    puts("Tras multiplicar por 5:");
    printf("Pila en orden normal: ");  Pila_Imprimir(p, ORD_NORMAL);
    printf("Pila en orden inverso: "); Pila_Imprimir(p, ORD_INVERSO);

    Pila_Recorrer(p, dividir5);

    assert(Pila_ChecarPosN(p, 0) == 5);
    assert(Pila_ChecarPosN(p, 1) == 4);
    assert(Pila_ChecarPosN(p, 2) == 3);
    assert(Pila_ChecarPosN(p, 3) == 2);
    assert(Pila_ChecarPosN(p, 4) == 1);

    puts("Tras dividir por 5:");
    printf("Pila en orden normal: ");  Pila_Imprimir(p, ORD_NORMAL);
    printf("Pila en orden inverso: "); Pila_Imprimir(p, ORD_INVERSO);

    // Sacando elementos que existen. Todas las eliminaciones tiene que
    // ser exitosas

    // Declaramos una variable de tipo entero, en esta variable vamos a guardar los datos que saquemos de la pila
    int sacado;
    
    // Saca un dato de la pila y lo guarda en la varibale sacado
    assert(Pila_Eliminar(p, &sacado) == true);
    // Verificamos que en realidad el valor que sacamos sea el que estaba en el tope (5)
    assert(sacado == 5);

    assert(Pila_Eliminar(p, &sacado) == true);
    assert(sacado == 4);

    assert(Pila_Eliminar(p, &sacado) == true);
    assert(sacado == 3);

    assert(Pila_Eliminar(p, &sacado) == true);
    assert(sacado == 2);

    assert(Pila_Eliminar(p, &sacado) == true);
    assert(sacado == 1);

    // Una vez terminadas las eliminaciones, las eliminaciones subsecuentes
    // tienen que fallar
    // Al ya no tener mas elementos si yo intento sacar uno más, Pila_Eliminar(p, &sacado) me devuelve un false, posteriormete lo estoy comparando con false, es decir false == false, la condición anterior me devuelve un true, por lo tanto la función assert recibe un true y no sucede nada
    assert(Pila_Eliminar(p, &sacado) == false);

    // La pila tiene que reportarse vacía una vez sacados los elementos
    assert(Pila_Vacia(p) == true);
    assert(Pila_NumeroElementos(p) == 0);

    // Finalmente liberamos la memoria que reservamos tanto para nuestra estructura pila como para el contenido de la pila, como recordarás, la función Pila_Liberar tiene como parámetro un apuntador a un apuntador, por esa razón le estoy pasando la dirección de memoria de una dirección de memoria donde encuentro una estructra de datos de tipo Pila.
    Pila_Liberar(&p);
}