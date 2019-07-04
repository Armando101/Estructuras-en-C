#include <stdio.h>
#include "lista.h"

int main()
{
	Lista* l = crearL();

	for (int i = 0; i < 5; ++i)
	{
		insert_Front(l,i*3);
	}
	for (int i = 0; i < 5; ++i)
	{
		insert_Back(l,i*5);
	}

	printf("\n********************************************\n");
	printf("Elementos de tu lista:\n");

	for (int i = 0; i < l->num_nodos; ++i)
	{
		printf("%d ",getFrom(l,i));
	}
	printf("\n********************************************\n");

	insert_X(l,5,100);

	printf("\n********************************************\n");
	printf("Elementos de tu lista:\n");

	for (int i = 0; i < l->num_nodos; ++i)
	{
		printf("%d ",getFrom(l,i));
	}
	printf("\n********************************************\n\n");
	
	remove_Front(l);
	remove_Back(l);
	remove_x(l,3);
	printf("********************************************\n\n");

	printf("Elementos de tu lista:\n");

	for (int i = 0; i < l->num_nodos; ++i)
	{
		printf("%d ",getFrom(l,i));
	}
	printf("\nEl numero de nodos que hay en tu lista son %d\n",l->num_nodos);
	return 0;
}