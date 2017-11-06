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
    persona = lista->get(lista, 4);
    printf("Nombre en posicion 4 antes del remove: %s", persona->nombre);
    aux = lista->get(lista, 5);
    printf("\n\nNombre en posicion 5 antes del remove: %s", aux->nombre);
    lista->remove(lista, 4);
    persona = lista->get(lista, 4);
    printf("\n\nNombre en posicion 4 despues del remove: %s\n", persona->nombre);
    //free(lista);
    return 0;
}
