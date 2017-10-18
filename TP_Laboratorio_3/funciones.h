

typedef struct{
    char titulo[50];
    char genero[20];
    int  duracion;
    char descripcion[50];
    int  puntaje;
    char linkImagen[50];
    int estado;
}eMovie;


/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(eMovie movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
void borrarPelicula();

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */

void modificarPelicula ();




void generarPagina(eMovie lista[], char nombre[]);


void sacarEnter(char[]);
