#include <stdio.h>

int main(int argc, char const *argv[])
{
	struct mascota {
	char * especie;
	int meses;
	int limite_edad;
};

typedef struct mascota dt_mascota;

enum sexo {
	MACHO, HEMBRA
};
typedef enum sexo Genero;

struct hamster {
	dt_mascota datos;
	Genero g;
};

struct perro {
	dt_mascota datos;
	Genero g;
};


void aumentarEdad(struct perro * p) {
	// p.datos.meses++; No es valida
	//(*p).datos.meses++;
	p->datos.meses++;
}

	struct hamster cuye = {
		{ 
		"Hamster ciberiano",
		4,
		18
		},
		MACHO
	};
	
					/*
				struct perro Luna = {
					.datos.meses = 24,
					.datos.especie = "Doverman",
					.datos.limite_edad = 120,
					.g = HEMBRA
				};
				*/
	
	
	struct perro Luna = {
		.datos = {
			.meses = 24,
			.especie = "Doverman",
			.limite_edad = 120
		},
		.g = HEMBRA
	};


	printf("Los datos de Luna, son:\n");
	printf("La edad es %d meses\n", Luna.datos.meses);
	aumentarEdad(&Luna);
	printf("La edad es %d meses\n", Luna.datos.meses);
	printf("La especie de Luna es: %s\n", Luna.datos.especie);
	printf("El genero de Luna es: %s\n", Luna.g == MACHO ? "macho" : "hembra");

	if (Luna.g == MACHO)
		printf("Es macho\n");
	else
		printf("Es hembra\n");
	return 0;
}