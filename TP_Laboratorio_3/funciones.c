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
    printf("\nIngrese el genero de la pelicula: ");
    setbuf(stdin, NULL);
    fgets(movie.genero, 21, stdin);
    sacarEnter(movie.genero);
    printf("\nIngrese la duracion en minutos: ");
    scanf("%d", &movie.duracion);
    printf("\nIngrese la descripcion de la pelicula: ");
    setbuf(stdin, NULL);
    fgets(movie.descripcion, 1001, stdin);
    sacarEnter(movie.descripcion);
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
    fgets(movie.linkImagen, 500, stdin);
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
    rewind(miArchivo);
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


int validaInt (int input, int lowLimit, int hiLimit)
{
    int resultado = 0;
    if (input < lowLimit || input > hiLimit)
    {
        resultado = -1;
    }
    return resultado;
}


void generarHtml()
{
    FILE* archivoBin;
    FILE* archivoHtml;
    eMovie pelis;
    int cont = 0, i;
    archivoBin = fopen("prueba.bin", "rb");
    rewind(archivoBin);
    while (!feof(archivoBin))
    {
        if ((i = fread(&pelis, sizeof(eMovie), 1, archivoBin)) != 0)
        {
            if(pelis.estado == 1)
                cont++;
        }
    }
    rewind(archivoBin);
    eMovie array[cont];
    eMovie* puntero;
    puntero = &array;
    for (int j = 0; j < cont; j++)
    {
        if(pelis.estado != 0)
            fread(puntero+j, sizeof(eMovie), 1, archivoBin);
    }
    fclose(archivoBin);

    if((archivoHtml = fopen("pagina.html", "wb+")) == NULL)
    {
          printf("No se pudo abrir el archivo\n");
            exit(1);
    }

    fseek(archivoHtml, 0L, SEEK_SET);
    fprintf(archivoHtml, "<!DOCTYPE html>\n<html lang='en'>\n<head>\n<meta charset='utf-8'>\n<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n<meta name='viewport' content='width=device-width, initial-scale=1'>\n<title>Lista peliculas</title>\n<link href='css/bootstrap.min.css' rel='stylesheet'>\n<link href='css/custom.css' rel='stylesheet'>\n</head>\n<body>\n<div class='container'>\n<div class='row'>\n");
    for (int i = 0; i < cont; i++)
    {
            if ((puntero+i)->estado == 1)
            {
                fseek(archivoHtml, 0L, SEEK_END);
                fprintf(archivoHtml, "<article class='col-md-4 article-intro'>\n<a href='#'>\n<img class='img-responsive img-rounded' src='%s'alt=''>\n</a>\n", (puntero+i)->linkImagen);
                fseek(archivoHtml, 0L, SEEK_END);
                fprintf(archivoHtml,"<h3>\n<a href='#'>%s</a>\n</h3>\n", (puntero+i)->titulo);
                fseek(archivoHtml, 0L, SEEK_END);
                fprintf(archivoHtml, "<ul>\n<li>Género:%s</li>\n<li>Puntaje:%d</li>\n<li>Duración:%d</li>\n</ul>\n", (puntero+i)->genero, (puntero+i)->puntaje, (puntero+i)->duracion);
                fseek(archivoHtml, 0L, SEEK_END);
                fprintf(archivoHtml, "<p>%s</p>\n</article>\n", (puntero+i)->descripcion);
            }
    }
    fseek(archivoHtml, 0L, SEEK_END);
    fprintf(archivoHtml, "</div>\n</div>\n<script src='js/jquery-1.11.3.min.js'>\n</script>\n<script src='js/bootstrap.min.js'>\n</script>\n<script src='js/ie10-viewport-bug-workaround.js'>\n</script>\n<script src='js/holder.min.js'>\n</script>\n</body>\n</html>\n");
    fclose(archivoHtml);
}
