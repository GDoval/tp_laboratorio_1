#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    eMovie peli;

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Imprimir peliculas\n");
        printf("6- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("clear");
                agregarPelicula(peli);
                break;
            case 2:
                system("clear");
                borrarPelicula();
                break;
            case 3:
                system("clear");
                modificarPelicula();
               break;
            case 4:
                generarHtml();
                break;
            case 5:
                system("clear");
                imprimirMovies();
                break;
            case 6:
                seguir = 'n';
                break;
            default:
                printf("\nOpcion incorrecta\n");
                break;
        }
    }

    return 0;
}
