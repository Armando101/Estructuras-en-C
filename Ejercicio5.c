#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct nodo{
 struct nodo *padre;
 struct nodo *izquierdo;
 struct nodo *derecho;
 int valor;
}TNodo;

TNodo *crear_arbol(TNodo *padre, int valor);
void agregar_nodo(TNodo *arbol, int valor);
TNodo * buscar(TNodo*, int);
void Clear();

int main(){
  TNodo *arbol;
  int op, dato;
  int sw = 1;
  printf("\n\n\tBienvenido\n");
while (1) {
  printf("\n\nSeleccione una opcion\n");
  printf("1: Insertar un valor en el arbol\n");
  printf("2: Buscar un valor en el arbol\n");
  printf("3: Salir del programa\n");
  scanf("%d", &op);
  Clear();
  switch (op) {
    case 1:
      printf("Ingrese el dato que desea insertar\n");
      scanf("%d", &dato);
      Clear();
      if (sw) {
        arbol = crear_arbol(NULL,dato);
        printf("El valor %d se ha incertado al inicio del arbol\n", dato);
        sw = 0;
      }else {
        agregar_nodo(arbol, dato);
      }
      break;
    case 2:
      if (sw) {
        printf("No ha ingresado datos\n");
      break;
      } else {
        printf("Ingrese el dato que desea buscar\n");
        scanf("%d", &dato);
        Clear();
        buscar(arbol, dato);
      }
    break;
    case 3:
      printf("Vuelva pronto\n");
      return 0;
    default :
      printf("Ingrese una opcion valida\n");
    break;
    }
  }
  return 0;
}

TNodo * buscar(TNodo* arbol, int valor) {
  TNodo * temp, * pivote;
  temp = arbol;
  pivote = NULL;
  int i=0;
  while(temp!=NULL) {
    pivote = temp;
    if (valor == temp->valor) {
      printf("\nEl valor %d fue encontrado en la iteracion %d\n", valor, i);
      return temp;
    }
    if (valor > temp->valor) {
      temp = temp->derecho;
      i++;
    } else {
      temp = temp->izquierdo;
      i++;
    }
  }

  printf("Su nodo no fue encontrado en el arbol\n");
  return NULL;
}

TNodo *crear_arbol(TNodo *padre, int valor){
 TNodo *n = malloc(sizeof(TNodo));
 n->padre = padre;
 n->valor = valor;
 return n;
}

void agregar_nodo(TNodo *arbol, int valor){
 TNodo *temp, *pivote;
 int derecho = 0;
 if(arbol){
  temp = arbol;
  while(temp !=NULL){
   pivote = temp;
   if(valor>temp->valor){
    temp = temp->derecho;  
    derecho = 1;    
   }else{
    temp = temp->izquierdo;
    derecho = 0;
   }
  }
  temp = crear_arbol(pivote,valor);
  if(derecho){
   printf("Insertando el numero %d del lado derecho de %d\n",valor,pivote->valor); 
   pivote->derecho = temp;
  }else{
   printf("Insertando el numero %d del lado izquierdo de %d\n",valor,pivote->valor);
   pivote->izquierdo = temp;
  }
 }else{
  printf("EL arbol no esta inicializado");
 }
}

void Clear() {
  #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}