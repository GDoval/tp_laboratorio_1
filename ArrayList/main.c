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
    int a = 15;
    ArrayList* lista = al_newArrayList();
    ePersona* persona;
    ePersona* aux;
    ePersona agregar;
    aux = &agregar;
    strcpy(aux->nombre, "Gaston");
    strcpy(aux->apellido, "Doval");
    aux->id = 1988;
    int r;
    miArchivo = fopen("data.csv", "r");
    r = parseArchivo(miArchivo, lista);
    printf("\nSize: %d\n", lista->size);
    persona = lista->pElements[a];
    printf("%s", persona->nombre);
    printf("\n\nMomento de la verdad!!\n\n");
    lista->set(lista, a, aux);
    persona = lista->pElements[a];
    printf("%s", persona->nombre);
    persona = lista->pElements[a+1];
    printf("\n%s\n", persona->nombre);
    printf("\nSize: %d\n", lista->size);
    free(lista);
    return 0;
}
