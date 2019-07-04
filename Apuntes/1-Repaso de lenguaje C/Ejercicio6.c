#include <stdio.h>

int main(int argc, char const *argv[]) {
	int arr[]={0,1,5,7};
    int *p, a;

    p = &a;
    a = *arr + 2; //Nombre del arrglo usado coo expresón deriva o se
                    //convierte en la direcion dl primer de los elementos del
                    //primer arreglo
    printf("%d\n",*arr);
    printf("%d\n",*p);
	return 0;
}