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
    int r;
    miArchivo = fopen("data.csv", "r");
    r = parseArchivo(miArchivo, lista);
    persona = lista->pElements[15];
    printf("\n%s\n", persona->nombre);
    persona = lista->pElements[5];
    printf("\n\nSize: %d\n", lista->size);
    printf("%s", persona->nombre);
    lista->remove(lista, 5);
    persona = lista->pElements[5];
    printf("\n%s\n", persona->nombre);
    printf("\n\nSize: %d\n", lista->size);
    persona = lista->pElements[14];
    printf("\n%s\n", persona->nombre);
    free(lista);
    return 0;
}
