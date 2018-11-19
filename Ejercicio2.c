#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arista {
    char * dest;
    struct arista *prox;

}TArista;

typedef struct vertice { 
    char * estado;
    TArista *aris;
    struct vertice *prox;
}TVertice;

TVertice * addNodo(TVertice * grafo, char * estado) {
    TVertice * nuevo;
    TVertice *p = grafo;
    if (grafo == NULL) {    //Primer nodo insertado
        nuevo = (TVertice*)malloc(sizeof(TVertice));
        nuevo -> estado = estado;
        //nuevo -> id=id;
        nuevo -> aris = NULL;
        nuevo -> prox = NULL;
        return nuevo;
    }
    while(p->prox != NULL) {
        p = p->prox;
    }
    nuevo = (TVertice*)malloc(sizeof(TVertice));
    nuevo->estado = estado;
    //nuevo->id=id;
    nuevo->aris=NULL;
    nuevo->prox=NULL;
    p->prox=nuevo;
    return grafo;
}

TVertice * addEdge(TVertice * grafo, char* id_1, char* id_2) {
    TVertice *p = grafo;
    TArista *nuevo, *q;

    while(p->estado != id_1) {
        p=p->prox;
    }
    q=p->aris;

    nuevo = (TArista*)malloc(sizeof(TArista));
    nuevo->dest=id_2;
    if (q==NULL) {
        nuevo->prox=NULL;
        p->aris=nuevo;
    }else {
        while(q->prox!=NULL) {
            q=q->prox;
        }
        q->prox=nuevo;
        nuevo->prox=NULL;
    }
    p=grafo;
    q=nuevo=NULL;

    while(p->estado != id_2) {
        p=p->prox;
    }
    q=p->aris;

    nuevo = (TArista*)malloc(sizeof(TArista));
    nuevo->dest=id_1;
    if (q==NULL) {
        nuevo->prox = NULL;
        p->aris=nuevo;
    }else {
        while(q->prox!=NULL) {
            q=q->prox;
        }
        q->prox=nuevo;
        nuevo->prox=NULL;
    }
    return grafo;
}


void Clear() {
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

void VerInformacion(TVertice * grafo, char * s) {
    Clear();
    TArista *p;
    if (grafo==NULL) {
        printf("No ha agregado nada aun\n");
        return;
    }
    while(grafo!=NULL) {
        if (!strcmp(grafo->estado, s)) {
        printf("%s", grafo->estado);
        p=grafo->aris;
        while(p!=NULL) {
            printf("->%s\n",p->dest);
            p=p->prox;
        }
        printf("------------------\n\n");
        return;
    }
        grafo=grafo->prox;
    }

    printf("Opcion incorrecta, Vuelva a seleccionar otro estado\n");
}

void imprimirEstados(TVertice *grafo) {
    Clear();
    TArista *p;
    printf("\n\n------------------\n\n");
    if (grafo==NULL) {
        printf("No ha agregado nada aun\n");
        return;
    }
    printf("Estados de la republica\n\n");
    while(grafo!=NULL) {
        printf("%s \n", grafo->estado);
        p=grafo->aris;
        grafo=grafo->prox;
    }
    printf("\n\n------------------\n\n");
}


TVertice* Inicializar(TVertice * grafo) {
    grafo=addNodo(grafo, "Chihuahua");
    grafo=addNodo(grafo, "Sonora");
    grafo=addNodo(grafo, "Durango");
    grafo=addNodo(grafo, "Coahuila");
    grafo=addNodo(grafo, "Sinaloa");
    grafo=addNodo(grafo, "Baja_California");
    grafo=addNodo(grafo, "Baja_California_Sur");
    grafo=addNodo(grafo, "Zacatecas");
    grafo=addNodo(grafo, "Guadalajara");
    grafo=addNodo(grafo, "Aguas_Calientes");
    grafo=addNodo(grafo, "San_Luis_Potosi");
    grafo=addNodo(grafo, "Nayarit");
    grafo=addNodo(grafo, "Nuevo_Leon");
    grafo=addNodo(grafo, "Tamaulipas");
    grafo=addNodo(grafo, "Colima");
    grafo=addNodo(grafo, "Michoacan");
    grafo=addNodo(grafo, "Guanajuato");
    grafo=addNodo(grafo, "Queretaro");
    grafo=addNodo(grafo, "Hidalgo");
    grafo=addNodo(grafo, "CDMX");
    grafo=addNodo(grafo, "Guerrero");
    grafo=addNodo(grafo, "Morelos");
    grafo=addNodo(grafo, "Tlaxcala");
    grafo=addNodo(grafo, "Puebla");
    grafo=addNodo(grafo, "Estado_de_Mexico");
    grafo=addNodo(grafo, "Veracruz");
    grafo=addNodo(grafo, "Oaxaca");
    grafo=addNodo(grafo, "Tabasco");
    grafo=addNodo(grafo, "Chiapas");
    grafo=addNodo(grafo, "Campeche");
    grafo=addNodo(grafo, "Yucatan");
    grafo=addNodo(grafo, "Quintana_Roo");

    addEdge(grafo, "Yucatan", "Campeche");
    addEdge(grafo, "Yucatan", "Quintana_Roo");
    addEdge(grafo, "Quintana_Roo", "Campeche");
    addEdge(grafo, "Chiapas", "Oaxaca");
    addEdge(grafo, "Veracruz", "Chiapas");
    addEdge(grafo, "Tabasco", "Campeche");
    addEdge(grafo, "Tabasco", "Chiapas");
    addEdge(grafo, "Veracruz", "Tabasco");
    addEdge(grafo, "Veracruz", "Oaxaca");
    addEdge(grafo, "Veracruz", "Puebla");
    addEdge(grafo, "Veracruz", "Hidalgo");
    addEdge(grafo, "Veracruz", "San_Luis_Potosi");
    addEdge(grafo, "Veracruz", "Tamaulipas");
    addEdge(grafo, "CDMX", "Morelos");
    addEdge(grafo, "CDMX", "Estado_de_Mexico");
    addEdge(grafo, "Puebla", "Morelos");
    addEdge(grafo, "Puebla", "Hidalgo");
    addEdge(grafo, "Puebla", "Tlaxcala");
    addEdge(grafo, "Tlaxcala", "Estado_de_Mexico");
    addEdge(grafo, "Tlaxcala", "Hidalgo");
    addEdge(grafo, "Morelos", "Guerrero");
    addEdge(grafo, "Morelos", "Estado_de_Mexico");
    addEdge(grafo, "Estado_de_Mexico", "Michoacan");
    addEdge(grafo, "Guerrero", "Michoacan");
    addEdge(grafo, "Estado_de_Mexico", "Guerrero");
    addEdge(grafo, "Estado_de_Mexico", "Queretaro");
    addEdge(grafo, "Hidalgo","Estado_de_Mexico");
    addEdge(grafo, "Hidalgo","Queretaro");
    addEdge(grafo, "Hidalgo","San_Luis_Potosi");
    addEdge(grafo, "Queretaro","Michoacan");
    addEdge(grafo, "Queretaro","Guanajuato");
    addEdge(grafo, "Queretaro","San_Luis_Potosi");
    addEdge(grafo, "Chihuahua","Sonora");
    addEdge(grafo, "Colima","Michoacan");
    addEdge(grafo, "Michoacan", "Guanajuato");
    addEdge(grafo, "Guanajuato", "Guadalajara");
    addEdge(grafo, "Guanajuato", "San_Luis_Potosi");
    addEdge(grafo, "Michoacan", "Guadalajara");
    addEdge(grafo, "Coahuila","Nuevo_Leon");
    addEdge(grafo, "Nuevo_Leon", "San_Luis_Potosi");
    addEdge(grafo, "Nuevo_Leon", "Tamaulipas");
    addEdge(grafo, "Tamaulipas", "San_Luis_Potosi");
    addEdge(grafo, "Aguas_Calientes","Guadalajara");
    addEdge(grafo, "Sinaloa","Nayarit");
    addEdge(grafo, "Nayarit","Guadalajara");
    addEdge(grafo, "Durango","Nayarit");
    addEdge(grafo, "Zacatecas","Guadalajara");
    addEdge(grafo, "Zacatecas","Aguas_Calientes");
    addEdge(grafo, "Zacatecas","San_Luis_Potosi");
    addEdge(grafo, "Durango","Zacatecas");
    addEdge(grafo, "Coahuila","Zacatecas");
    addEdge(grafo, "Chihuahua","Durango");
    addEdge(grafo, "Chihuahua","Coahuila");
    addEdge(grafo, "Chihuahua","Sinaloa");
    addEdge(grafo, "Sonora","Sinaloa");
    addEdge(grafo, "Sinaloa","Durango");
    addEdge(grafo, "Durango","Coahuila");
    addEdge(grafo, "Baja_California","Sonora");
    addEdge(grafo, "Baja_California_Sur","Baja_California");

    return grafo;
}

int main(int argc, char const *argv[]) {
    char * s = malloc(sizeof(char)*30);
    TVertice *grafo=NULL;
    int op;
    grafo=Inicializar(grafo);
    while(1){
    printf("Bienvenido seleccione una opcion\n1:Ver estados de la republica\n2:Ver con que estados hace frontera un estado\n3:Salir del programa\n");
    scanf("%d", &op);
        switch (op) {
            case 1:
            imprimirEstados(grafo);
            break;
            case 2:
            printf("Ingrese el estado del que desea obtener informacion\n");
            scanf("%s",s);
            VerInformacion(grafo, s);
            break;
            case 3:
            printf("Vuelva pronto\n");
            return 0;
            default :
            printf("opcion invalida\n");
            break;
        }
    }
    return 0;
}