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
    persona = lista->pop(lista,0);
    printf("\n%s\n", persona->nombre);
    ePersona* otro = lista->get(lista, 0);
    printf("\n\n%s", otro->nombre);
    /*persona = lista->pop(lista, 1);
    ePersona* otro = lista->get(lista, 1);
    printf("\n\n%s", otro->nombre);
    printf("\n\n%s", persona->nombre);*/
    free(lista);
    return 0;
}
