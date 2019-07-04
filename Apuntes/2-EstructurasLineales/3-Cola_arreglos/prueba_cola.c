#include "cola.h"

#if COLA_EN_PRUEBAS == true
#undef NDEBUG

#include <stdio.h>
#include <assert.h>

int main(void)
{
    Cola * c = Cola_Nueva(5);

    // Al principio la cola debe de estar vacía
    assert(Cola_Vacia(c) == true);
    assert(Cola_NumeroElementos(c) == 0);

    // Se insertan elementos hasta que se llene
    assert(Cola_Insertar(c, 1) == true);
    assert(Cola_Insertar(c, 2) == true);
    assert(Cola_Insertar(c, 3) == true);
    assert(Cola_Insertar(c, 4) == true);
    assert(Cola_Insertar(c, 5) == true);

    // La cola tiene que reportarse llena ahora
    assert(Cola_Llena(c) == true);
    assert(Cola_NumeroElementos(c) == 5);

    // El primer elemento tiene que ser el 1 que se insertó al principio
    assert(Cola_ChecarPrimero(c) == 1);

    // Los siguientes elementos tienen que corresponderse al orden de inserción
    assert(Cola_ChecarPosN(c, 0) == 1);
    assert(Cola_ChecarPosN(c, 1) == 2);
    assert(Cola_ChecarPosN(c, 2) == 3);
    assert(Cola_ChecarPosN(c, 3) == 4);
    assert(Cola_ChecarPosN(c, 4) == 5);

    // Funciones que implican recorridos
    printf("Cola en orden normal: ");  Cola_Imprimir(c, ORD_NORMAL);
    printf("Cola en orden inverso: "); Cola_Imprimir(c, ORD_INVERSO);

    Cola_Recorrer(c, multiplicar5);

    assert(Cola_ChecarPosN(c, 0) == 5);
    assert(Cola_ChecarPosN(c, 1) == 10);
    assert(Cola_ChecarPosN(c, 2) == 15);
    assert(Cola_ChecarPosN(c, 3) == 20);
    assert(Cola_ChecarPosN(c, 4) == 25);

    puts("Tras multiplicar por 5:");
    printf("Cola en orden normal: ");  Cola_Imprimir(c, ORD_NORMAL);
    printf("Cola en orden inverso: "); Cola_Imprimir(c, ORD_INVERSO);

    Cola_Recorrer(c, dividir5);

    assert(Cola_ChecarPosN(c, 0) == 1);
    assert(Cola_ChecarPosN(c, 1) == 2);
    assert(Cola_ChecarPosN(c, 2) == 3);
    assert(Cola_ChecarPosN(c, 3) == 4);
    assert(Cola_ChecarPosN(c, 4) == 5);

    puts("Tras dividir por 5:");
    printf("Cola en orden normal: ");  Cola_Imprimir(c, ORD_NORMAL);
    printf("Cola en orden inverso: "); Cola_Imprimir(c, ORD_INVERSO);

    int sacado;
    assert(Cola_Eliminar(c, &sacado) == true);
    assert(sacado == 1);

    assert(Cola_Eliminar(c, &sacado) == true);
    assert(sacado == 2);

    assert(Cola_Eliminar(c, &sacado) == true);
    assert(sacado == 3);

    assert(Cola_Eliminar(c, &sacado) == true);
    assert(sacado == 4);

    assert(Cola_Eliminar(c, &sacado) == true);
    assert(sacado == 5);

    // Una vez terminadas las eliminaciones, las eliminaciones subsecuentes
    // tienen que fallar
    assert(Cola_Eliminar(c, &sacado) == false);

    // La cola tiene que reportarse vacía una vez sacados los elementos
    assert(Cola_Vacia(c) == true);
    assert(Cola_NumeroElementos(c) == 0);

    Cola_Liberar(c);
}
#endif // COLA_EN_PRUEBAS
