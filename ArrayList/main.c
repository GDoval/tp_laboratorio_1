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
    ArrayList* clonada;
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
    clonada = lista->clone(lista);
    imprimir(lista);
    printf("---------------------------------------\n\n");
    lista->sort(clonada, compararNombre, 1);
    imprimir(clonada);
    printf("---------------------------------------\n\n");
    imprimir(lista);
    return 0;
}
