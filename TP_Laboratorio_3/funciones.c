#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int agregarPelicula(eMovie movie)
{
    FILE* miArchivo;
    int resultado = 1;
    char buffer[500];
    printf("Ingrese el nombre de la pelicula: ");
    setbuf(stdin, NULL);
    fgets(movie.titulo, 51, stdin);
    sacarEnter(movie.titulo);
    printf("\nIngrese el genero de la pelicula: ");
    setbuf(stdin, NULL);
    fgets(movie.genero, 21, stdin);
    sacarEnter(movie.genero);
    printf("\nIngrese la duracion en minutos: ");
    scanf("%d", &movie.duracion);
    printf("\nIngrese la descripcion de la pelicula: ");
    setbuf(stdin, NULL);
    fgets(movie.descripcion, 51, stdin);
    sacarEnter(movie.descripcion);
    printf("\nIngrese el puntaje de la pelicula: ");
    scanf("%d", &movie.puntaje);
    printf("\nIngrese un link de imagen para la portada: ");
    setbuf(stdin, NULL);
    fgets(movie.linkImagen, 51, stdin);
    sacarEnter(movie.linkImagen);
    if ((miArchivo = fopen("prueba.bin", "rb"))== NULL)
    {
        miArchivo = fopen("prueba.bin", "wb");
        fwrite(&movie, sizeof(eMovie), 1, miArchivo);
        fclose(miArchivo);
    }
    else
    {
        miArchivo = fopen("prueba.bin", "ab");
        fwrite(&movie, sizeof(eMovie), 1, miArchivo);
        fclose(miArchivo);
    }
    return resultado;

}



void imprimirMovies ()
{
    eMovie pelis;
    FILE* miArchivo;
    int opcion = 1;
    int i;
    miArchivo = fopen("prueba.bin", "rb");
    while ((i = fgetc(miArchivo)) != EOF)
    {
        fread(&pelis, sizeof(eMovie), 1, miArchivo);
        printf("\n%s -- %s -- %s\n", pelis.titulo, pelis.genero, pelis.descripcion);
    }
    fclose(miArchivo);
}

void modificarPelicula ()
{
    eMovie movie;
    int i, j, flag;
    char titulo[50];
    printf("\nIngrese el titulo de la pelicula a modificar: ");
    setbuf(stdin, NULL);
    fgets(titulo, 51, stdin);
    sacarEnter(titulo);
    FILE* miArchivo;
    miArchivo = fopen("prueba.bin", "rb");

    while ((i = fgetc(miArchivo)) != EOF)
    {
        fread(&movie, sizeof(eMovie), 1, miArchivo);
        if ((strcmp(titulo, movie.titulo) == 0))
        {
            j = fseek(miArchivo, (long)(-1)*sizeof(eMovie), SEEK_CUR);
            if (j == 0)
            {
                printf("Ingrese el nombre de la pelicula: ");
                setbuf(stdin, NULL);
                fgets(movie.titulo, 51, stdin);
                sacarEnter(movie.titulo);
                printf("\nIngrese el genero de la pelicula: ");
                setbuf(stdin, NULL);
                fgets(movie.genero, 21, stdin);
                sacarEnter(movie.genero);
                printf("\nIngrese la duracion en minutos: ");
                scanf("%d", &movie.duracion);
                printf("\nIngrese la descripcion de la pelicula: ");
                setbuf(stdin, NULL);
                fgets(movie.descripcion, 51, stdin);
                sacarEnter(movie.descripcion);
                printf("\nIngrese el puntaje de la pelicula: ");
                scanf("%d", &movie.puntaje);
                printf("\nIngrese un link de imagen para la portada: ");
                setbuf(stdin, NULL);
                fgets(movie.linkImagen, 51, stdin);
                sacarEnter(movie.linkImagen);
                flag = 0;
                break;
            }

        }
        else
        {
            flag = 1;
        }
    }
    fclose(miArchivo);
    if (flag == 1)
        printf("\n\nPelicula no encontrada\n\n");
    else
    {
        miArchivo = fopen("prueba.bin", "ab");
        fwrite(&movie, sizeof(eMovie), 1, miArchivo);
        fclose(miArchivo);
    }




}



void sacarEnter(char vec[]) // borra el enter que queda en la ultima posicion del string cuando se usa fgets().
{
    int cant;
    cant = strlen(vec);
    vec[cant-1] = '\0';
}
