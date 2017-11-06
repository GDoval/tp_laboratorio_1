#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "estructuras.h"
typedef struct{
    void (*p)();
}pe;

int main()
{
    FILE* miArchivo;
    FILE* otro;
    int a = 15;
    ArrayList* lista = al_newArrayList();
    ePersona* persona;
    ePersona* aux;
    ePersona extra;
    aux = &extra;
    strcpy(aux->nombre, "Gaston");
    strcpy(aux->apellido, "Doval");
    aux->id = 1988;
    ePersona agregar;
    int r;
    miArchivo = fopen("data.csv", "r");
    r = parseArchivo(miArchivo, lista);
    printf("Size antes del push:  %d \n\n", lista->size);
    persona = lista->get(lista, 5);
    printf("Nombre de la posicion 5 antes del push: %s\n\n", persona->nombre);
    lista->push(lista, 5, aux);
    persona = lista->get(lista, 5);
    printf("Nombre de la posicion 5 despues del push: %s\n\n", persona->nombre);
    aux = lista->get(lista, 6);
    printf("Posicion 6 despues del push tiene que ser igual a posicion 5 antes: %s\n\n", aux->nombre);
    printf("Size del array despues del push: %d\n", lista->size);
    aux = lista->get(lista, 16);
    printf("Por las dudas ultima posicion: %s\n", aux->nombre);
    //free(lista);
    return 0;
}
