
// Tipo de dato que estaremos manejando. Se puede modificar en cualquier
// momento
typedef int TipoDato;

// Definición incompleta del arreglo. Aquellos que tengan esta definición
// podrán crear variables que apunten al arreglo pero no podrán acceder
// a los datos internos de este.
struct arreglo;

// Funciones para crear y eliminar los arreglos
struct arreglo * crearArreglo(int tamanio);
void liberarArreglo(struct arreglo * arr);

// Operaciones con arreglos
void putArreglo(struct arreglo * arr, TipoDato dato, int pos);
TipoDato checarPosArreglo(struct arreglo * arr, int pos);

int tamArr(struct arreglo * arr);
void redimensionarArr(struct arreglo * arr, int nuevo_tam);
