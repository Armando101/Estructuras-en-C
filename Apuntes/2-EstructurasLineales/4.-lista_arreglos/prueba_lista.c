#include "lista.h"

#if defined(LISTA_EN_PRUEBAS)
#undef NDEBUG

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

int main(void)
{
    Lista * l = Lista_Nueva(5);

    // Al principio la lista debe estar vacía
    assert(Lista_Vacia(l) == true);
    assert(Lista_NumeroElementos(l) == 0);

    // Insertando y eliminando por el inicio
    for (int i = 1; i <= 5; ++i) {
        assert(Lista_InsertarPosI(l, i));
        assert(Lista_NumeroElementos(l) == i);
    }

    // Después de insertar, la lista debe estar llena
    assert(Lista_Llena(l) == true);

    // Revisamos que los elementos se encuentren en orden inverso
    assert(Lista_ChecarPosI(l) == 5);
    assert(Lista_ChecarPosF(l) == 1);
    for (int i = 0; i < 5; ++i) {
        assert(Lista_ChecarPosN(l, i) == 5 - i);
    }

    // Recorridos para imprimir
    printf("Lista en orden normal: ");  Lista_Imprimir(l, ORD_NORMAL);
    printf("Lista en orden inverso: "); Lista_Imprimir(l, ORD_INVERSO);

    Lista_Recorrer(l, multiplicar5);
    assert(Lista_ChecarPosI(l) == 25);
    assert(Lista_ChecarPosF(l) == 5);
    for (int i = 0; i < 5; ++i) {
        assert(Lista_ChecarPosN(l, i) == (5 - i) * 5);
    }

    puts("Tras multiplicar por 5:");
    printf("Lista en orden normal: ");  Lista_Imprimir(l, ORD_NORMAL);
    printf("Lista en orden inverso: "); Lista_Imprimir(l, ORD_INVERSO);

    Lista_Recorrer(l, dividir5);
    assert(Lista_ChecarPosI(l) == 5);
    assert(Lista_ChecarPosF(l) == 1);
    for (int i = 0; i < 5; ++i) {
        assert(Lista_ChecarPosN(l, i) == (5 - i));
    }

    puts("Tras dividir por 5:");
    printf("Lista en orden normal: ");  Lista_Imprimir(l, ORD_NORMAL);
    printf("Lista en orden inverso: "); Lista_Imprimir(l, ORD_INVERSO);

    // Sacamos los elementos de la lista
    for (int i = 0; i < 5; ++i) {
        int sacado;
        assert(Lista_EliminarPosI(l, &sacado) == true);
        assert(sacado == 5 - i);
        assert(Lista_NumeroElementos(l) == 5 - i - 1);
    }

    // La lista nuevamente debe estar vacía
    assert(Lista_Vacia(l) == true);

    // Insertando y eliminando por el final
    for (int i = 1; i <= 5; ++i) {
        assert(Lista_InsertarPosF(l, i));
        assert(Lista_NumeroElementos(l) == i);
    }

    // Después de insertar, la lista debe estar llena
    assert(Lista_Llena(l) == true);

    // Revisamos que los elementos se encuentren en orden ascendente
    assert(Lista_ChecarPosI(l) == 1);
    assert(Lista_ChecarPosF(l) == 5);
    for (int i = 0; i < 5; ++i) {
        assert(Lista_ChecarPosN(l, i) == i + 1);
    }

    // Recorridos para imprimir
    printf("Lista en orden normal: "); Lista_Imprimir(l, ORD_NORMAL);
    printf("Lista en orden inverso: "); Lista_Imprimir(l, ORD_INVERSO);

    Lista_Recorrer(l, multiplicar5);
    assert(Lista_ChecarPosI(l) == 5);
    assert(Lista_ChecarPosF(l) == 25);
    for (int i = 0; i < 5; ++i) {
        assert(Lista_ChecarPosN(l, i) == (i + 1) * 5);
    }

    puts("Tras multiplicar por 5:");
    printf("Lista en orden normal: ");  Lista_Imprimir(l, ORD_NORMAL);
    printf("Lista en orden inverso: "); Lista_Imprimir(l, ORD_INVERSO);

    Lista_Recorrer(l, dividir5);
    assert(Lista_ChecarPosI(l) == 1);
    assert(Lista_ChecarPosF(l) == 5);
    for (int i = 0; i < 5; ++i) {
        assert(Lista_ChecarPosN(l, i) == i + 1);
    }

    puts("Tras dividir por 5:");
    printf("Lista en orden normal: ");  Lista_Imprimir(l, ORD_NORMAL);
    printf("Lista en orden inverso: "); Lista_Imprimir(l, ORD_INVERSO);

    // Sacamos los elementos de la lista
    for (int i = 0; i < 5; ++i) {
        int sacado;
        assert(Lista_EliminarPosF(l, &sacado) == true);
        assert(sacado == 5 - i);
        assert(Lista_NumeroElementos(l) == 5 - i - 1);
    }

    // La lista nuevamente debe estar vacía
    assert(Lista_Vacia(l) == true);

    // Insertando y eliminando en posiciones aleatorios
    srand(time(NULL));
    for (int caso_prueba = 0; caso_prueba < 1000; ++caso_prueba) {
        int n = 1;
        for (int i = 0; i < 5; ++i, ++n) {
            int pos_insertar = rand() % n;
            TipoDato anteriores[pos_insertar];
            for (int j = 0; j < pos_insertar; ++j) {
                anteriores[j] = Lista_ChecarPosN(l, j);
            }
            TipoDato siguientes[Lista_NumeroElementos(l) - pos_insertar];
            for (int j = 0; j < Lista_NumeroElementos(l) - pos_insertar; ++j) {
                siguientes[j] = Lista_ChecarPosN(l, j + pos_insertar);
            }
            assert(Lista_InsertarPosN(l, i, pos_insertar) == true);
            assert(Lista_NumeroElementos(l) == n);

            for (int j = 0; j < pos_insertar; ++j) {
                assert(anteriores[j] == Lista_ChecarPosN(l, j));
            }
            for (int j = 0; j < Lista_NumeroElementos(l) - pos_insertar - 1; ++j) {
                assert(siguientes[j] == Lista_ChecarPosN(l, j + pos_insertar + 1));
            }
        }

        assert(Lista_Llena(l) == true);
        assert(Lista_Buscar(l, 5) == -1);

        Lista_Ordenar(l, ORD_NORMAL);
        for (int i = 0; i < 5; ++i) {
            assert(Lista_ChecarPosN(l, i) == i);
            assert(Lista_Buscar(l, i) == i);
        }

        Lista_Ordenar(l, ORD_INVERSO);
        for (int i = 0; i < 5; ++i) {
            assert(Lista_ChecarPosN(l, i) == 5 - i - 1);
            assert(Lista_Buscar(l, 5 - i - 1) == i);
        }

        for (int i = 0; i < 5; ++i) {
            n--;
            int sacado;
            assert(Lista_EliminarPosN(l, &sacado, rand() % n));
            assert(Lista_NumeroElementos(l) == n - 1);
        }
    }

    Lista_Liberar(l);
}
#endif // LISTA_EN_PRUEBAS
