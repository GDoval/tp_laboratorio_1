#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

int agregarPelicula(eMovie movie)
{
    FILE* miArchivo;
    int resultado = 1, validar;

    if ((miArchivo = fopen("prueba.bin", "rb+")) == NULL)
        if((miArchivo = fopen("prueba.bin", "wb+")) == NULL)
        {
            printf("\nNo se pudo abrir el archivo\n");
            resultado = 0;
            return resultado;
        }


    printf("Ingrese el nombre de la pelicula: ");
    setbuf(stdin, NULL);
    fgets(movie.titulo, 51, stdin);
    sacarEnter(movie.titulo);
    validar = validaString(movie.titulo);
    while (validar != -1)
    {
        printf("\nError! Reingrese: ");
        setbuf(stdin, NULL);
        fgets(movie.titulo, 51, stdin);
        sacarEnter(movie.titulo);
        validar = validaString(movie.titulo);
    }

    printf("\nIngrese el genero de la pelicula: ");
    setbuf(stdin, NULL);
    fgets(movie.genero, 21, stdin);
    sacarEnter(movie.genero);
    validar = validaString(movie.genero);
    while (validar != -1)
    {
        printf("\nError! Reingrese: ");
        setbuf(stdin, NULL);
        fgets(movie.genero, 51, stdin);
        sacarEnter(movie.genero);
        validar = validaString(movie.genero);
    }

    printf("\nIngrese la duracion en minutos: ");
    scanf("%d", &movie.duracion);


    printf("\nIngrese la descripcion de la pelicula: ");
    setbuf(stdin, NULL);
    fgets(movie.descripcion, 51, stdin);
    sacarEnter(movie.descripcion);
    validar = validaString(movie.descripcion);
    while (validar != -1)
    {
        printf("\nError! Reingrese: ");
        setbuf(stdin, NULL);
        fgets(movie.descripcion, 51, stdin);
        sacarEnter(movie.descripcion);
        validar = validaString(movie.descripcion);
    }

    printf("\nIngrese el puntaje de la pelicula: ");
    scanf("%d", &movie.puntaje);
    validar = validaInt(movie.puntaje, 0, 10);
    while (validar == -1)
    {
        printf("\nError! Reingrese un numero entre 0 y 10: ");
        scanf("%d", &movie.puntaje);
        validar = validaInt(movie.puntaje, 0, 10);
    }

    printf("\nIngrese un link de imagen para la portada: ");
    setbuf(stdin, NULL);
    fgets(movie.linkImagen, 51, stdin);
    sacarEnter(movie.linkImagen);
    movie.estado = 1;
    fseek(miArchivo, 0L, SEEK_END);
    setbuf(stdin, NULL);
    fwrite(&movie, sizeof(eMovie), 1, miArchivo);
    fclose(miArchivo);
    return resultado;

}



void imprimirMovies ()
{
    eMovie pelis;
    FILE* miArchivo;
    int i;
    miArchivo = fopen("prueba.bin", "rb");
    rewind(miArchivo);
    while (!feof(miArchivo))
    {
        if ((i = fread(&pelis, sizeof(eMovie), 1, miArchivo)) != 0)
        {
            if(pelis.estado != 0)
                printf("\n%s -- %s -- %s\n", pelis.titulo, pelis.genero, pelis.descripcion);
        }

    }
    fclose(miArchivo);
}

void modificarPelicula ()
{
    eMovie peli;
    int i,flag;
    char titulo[50];
    printf("\nIngrese el titulo de la pelicula a modificar: ");
    setbuf(stdin, NULL);
    fgets(titulo, 51, stdin);
    sacarEnter(titulo);
    FILE* miArchivo;
    if ((miArchivo = fopen("prueba.bin", "rb+")) == NULL)
    {
        printf("\nError al abrir el archivo!");
        exit(1);
    }

    while (!feof(miArchivo))
    {
        i = fread(&peli, sizeof(eMovie), 1, miArchivo);
        if (i != 0)
        {
            if ((strcmp(titulo, peli.titulo) == 0))
            {
                printf("Ingrese el nombre de la pelicula: ");
                setbuf(stdin, NULL);
                fgets(peli.titulo, 51, stdin);
                sacarEnter(peli.titulo);
                printf("\nIngrese el genero de la pelicula: ");
                setbuf(stdin, NULL);
                fgets(peli.genero, 21, stdin);
                sacarEnter(peli.genero);
                printf("\nIngrese la duracion en minutos: ");
                scanf("%d", &peli.duracion);
                printf("\nIngrese la descripcion de la pelicula: ");
                setbuf(stdin, NULL);
                fgets(peli.descripcion, 51, stdin);
                sacarEnter(peli.descripcion);
                printf("\nIngrese el puntaje de la pelicula: ");
                scanf("%d", &peli.puntaje);
                printf("\nIngrese un link de imagen para la portada: ");
                setbuf(stdin, NULL);
                fgets(peli.linkImagen, 51, stdin);
                sacarEnter(peli.linkImagen);
                peli.estado = 1;
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
        }
    }
    if (flag == 1)
        printf("\n\nPelicula no encontrada\n\n");
    else
    {
        fseek(miArchivo,(long) (-1)*sizeof(eMovie), SEEK_CUR);
        fwrite(&peli, sizeof(eMovie), 1, miArchivo);
        fclose(miArchivo);
    }

}



void borrarPelicula()
{
    eMovie peli;
    int i,flag;
    char titulo[50];
    printf("\nIngrese el titulo de la pelicula a eliminar: ");
    setbuf(stdin, NULL);
    fgets(titulo, 51, stdin);
    sacarEnter(titulo);
    FILE* miArchivo;
    if ((miArchivo = fopen("prueba.bin", "rb+")) == NULL)
    {
        printf("\nError al abrir el archivo!");
        exit(1);
    }

    while (!feof(miArchivo))
    {
        i = fread(&peli, sizeof(eMovie), 1, miArchivo);
        if (i != 0)
        {
            if ((strcmp(titulo, peli.titulo) == 0))
            {
                peli.estado = 0;
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
        }

    }
    if (flag  == 1)
    {
        printf("\nPelicula no encontrada\n");
    }
    else
    {
        fseek(miArchivo,(long) (-1)*sizeof(eMovie), SEEK_CUR);
        fwrite(&peli, sizeof(eMovie), 1, miArchivo);
        fclose(miArchivo);
    }


}


void sacarEnter(char vec[]) // borra el enter que queda en la ultima posicion del string cuando se usa fgets().
{
    int cant;
    cant = strlen(vec);
    vec[cant-1] = '\0';
}



int validaString (char cadena[]) //Recibe una cadena, y valida que no se hayan ingresado otra cosa que no sean letras.
{
                                // Devuelve un 0 si la cadena no fue validada, un -1 si es una cadena valida.
    char letra;
    int respuesta, len;
    letra = cadena[0];
    len = strlen(cadena);
    for (int i = 0; i < len; i++)
    {
        letra = cadena[i];
        if (!isalpha(letra))
        {
            respuesta = 0;
            break;
        }
        else
        {
            respuesta = -1;
        }
    }

    return respuesta;
}



int validaInt (int input, int lowLimit, int hiLimit)
{
    int resultado = 0;
    if (input < lowLimit || input > hiLimit)
    {
        resultado = -1;
    }
    return resultado;
}
