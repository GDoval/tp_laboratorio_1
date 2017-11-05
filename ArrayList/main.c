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
    ArrayList* otralista = al_newArrayList();
    ePersona* persona;
    ePersona* aux;
    ePersona agregar;
    int r;
    miArchivo = fopen("data.csv", "r");
    otro = fopen("otro.csv", "r");
    r = parseArchivo(miArchivo, lista);
    r = lista->deleteArrayList(lista);
    persona = lista->pElements[10];
    printf("%s", persona->nombre);
    //free(lista);
    return 0;
}
