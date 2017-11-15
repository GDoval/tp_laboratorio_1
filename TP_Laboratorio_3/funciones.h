

typedef struct{
    char titulo[50];
    char genero[20];
    int  duracion;
    char descripcion[1000];
    int  puntaje;
    char linkImagen[500];
    int estado;
}eMovie;

/*------------------------------------------------------------------*/
/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *
 */
void agregarPelicula(eMovie);

/*------------------------------------------------------------------*/

/**
 /* brief Borra una pelicula del archivo binario
 */
void borrarPelicula();

/*------------------------------------------------------------------*/
/**
 /*Brief Modifica la informacion de una pelicula dentro del archivo binario
 **/

void modificarPelicula ();

/*------------------------------------------------------------------*/
/**brief Valida que la cadena que se pasa como parametro contenga solo letras
/*param recibe un array del tipo estructura
/*return retorna -1 si la cadena es valida, 0 en caso contrario.
**/
int validaString (char[]);

/*------------------------------------------------------------------*/
/**brief Valida si el entero pasado como paramentro se encuentra en el rango deseado
/*param recibe un entero a validar
/*param recibe un entero como rango minimo
/*param recibe un entero como rango maximo
/*return retorna un -1 si el entero a validar está dentro del rango, o un 0 en caso contrario.
**/

int validaInt (int,int, int);

/*------------------------------------------------------------------*/
/**
 /*Brief  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 **/


void generarHtml();

/*------------------------------------------------------------------*/

/**brief Reemplaza el enter que queda al final del string al leerlo con la funcion fgets() por un '\0'
/*param recibe un array de caracteres
**/

void sacarEnter(char[]);
