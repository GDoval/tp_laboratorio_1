typedef struct
{
    int dni;
    int edad;
    int flag;
    char nombre[20];

}ePersona;

/*------------------------------------------------------------------*/

void Ingreso (ePersona[],int);
/**brief Inserta registros dentro de un array de tipo estructura
/*param recibe un array del tipo estructura
/*param recibe un entero con la cantidad de elementos del array
**/


/*------------------------------------------------------------------*/

void mostrarPersonas(ePersona[], int);
/**brief Imprime por pantalla un listado de los elementos cargados en el array
/*param recibe un array del tipo estructura
/*param recibe un entero con la cantidad de elementos del array
**/

/*------------------------------------------------------------------*/
void sacarEnter(char[]);
/**brief Reemplaza el enter que queda al final del string al leerlo con la funcion fgets() por un '\0'
/*param recibe un array de caracteres
**/



/*------------------------------------------------------------------*/
void ordenarStrings(ePersona[], int);
/**brief Ordena el array que se le pasa como argumento utilizando dos criterios simultáneos
/*param recibe un array del tipo estructura
/*param recibe un entero con la cantidad de elementos del array
**/



/*------------------------------------------------------------------*/
int validaInt (int, int, int);
/**brief Valida si el entero pasado como paramentro se encuentra en el rango deseado
/*param recibe un entero a validar
/*param recibe un entero como rango minimo
/*param recibe un entero como rango maximo
/*return retorna un -1 si el entero a validar está dentro del rango, o un 0 en caso contrario.
**/




/*------------------------------------------------------------------*/

int validaDni (int);

/**brief Valida si el entero pasado como paramentro se encuentra en el rango deseado
/*param recibe un entero a validar
/*return retorna un 0 si el entero a validar está dentro del rango, o un -1 en caso contrario.
**/


/*------------------------------------------------------------------*/
void borrarPersona (ePersona [], int, int);
/**brief Realiza una baja lógica dentro del array que recibe como parámetro
/*param recibe un array del tipo estructura
/*param recibe un entero con la cantidad de elementos del array
**/



/*------------------------------------------------------------------*/
void graficoEdades (ePersona[], int );
/**brief Imprime por pantalla un gráfico que indica la cantidad de elementos que se corresponden con los criterios de selección de la función
/*param recibe un array del tipo estructura.
/*param recibe un entero con la cantidad de elementos del array
**/



/*------------------------------------------------------------------*/
int buscarVacio (ePersona[], int);
/**brief Busca dentro del array algún índice que esté cargado con 0
/*param recibe un array del tipo estructura
/*param recibe un entero con la cantidad de elementos del array
/*return retorna el  índice donde se cumplie la condicion, o un -1 si no se encontró un índice cargado en 0
**/




/*------------------------------------------------------------------*/
int sacarMayor(int, int, int);
/**brief Devuelve el mayor de los numeros ingresados como parametro
/*param recibe 3 enteros
/*return retorna un entero
**/



