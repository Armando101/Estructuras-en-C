#include <stdio.h>
/*
 * Bienvenidos al curso
 */

int main(void) {
	puts(
    "\tHola, ¿Cómo estás?.                                      \n"
    "\t¿Se ve bien el texto?                                    \n"
    "\t                                                         \n"
    "\tTu primer tarea moral consiste en ejecutar este simple   \n"
    "\tprograma y corroborar que tu IDE/compilador funcione y   \n"
    "\tque puedas ver caracteres latinos como acentos y ñ's. En \n"
    "\tcaso de que dichos caracteres no se visualicen 		    \n"
    "\tapropiadamente tendras que añadir un par de banderas como\n"
    "\targumentos al compilador:                                \n"
    "\t     -finput-charset=iso8859-1                           \n"
    "\t     -fexec-charset=cp437                                \n"
    "\tEsas opciones le indican al compilador que use la 		\n"
    "\tcodificación correcta a la hora de compilar de forma que \n"
    "\tse podrán mostrar correctamente caracteres del español.  \n"
    "\tTambién es recomendable que te asegures de que tu 		\n"
    "\tcompilador use la versión correcta del lenguaje con la   \n"
    "\tsiguiente instrucción:                                   \n"
	"\t    -std=c11                                             \n");

	return 0; // Este return 0 se añade por defecto a partir de C99
			  // En C89 y anteriores es necesario para indicar
			  // que el programa terminó correctamente
}