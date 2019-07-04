#include "pila.h"

//#if PILA_EN_PRUEBAS == true
//#undef NDEBUG

#include <stdio.h>
#include <assert.h>

int main(void)
{
    Pila * p = Pila_Nueva(5);

    // Al principio la pila debe de estar vacía
    assert(Pila_Vacia(p));
    assert(Pila_NumeroElementos(p) == 0);

    // Se insertan elementos hasta que se llene
    assert(Pila_Insertar(p, 1));
    assert(Pila_Insertar(p, 2));
    assert(Pila_Insertar(p, 3));
    assert(Pila_Insertar(p, 4));
    assert(Pila_Insertar(p, 5));

    // La pila tiene que reportarse llena ahora
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
    int sacado;
    // Saca un dato de la pila y lo guarda en la varibale sacado
    assert(Pila_Eliminar(p, &sacado) == true);
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
    assert(Pila_Eliminar(p, &sacado) == false);

    // La pila tiene que reportarse vacía una vez sacados los elementos
    assert(Pila_Vacia(p) == true);
    assert(Pila_NumeroElementos(p) == 0);

    Pila_Liberar(&p);
}
//#endif // PILA_EN_PRUEBAS
