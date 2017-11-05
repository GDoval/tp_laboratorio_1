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
    ArrayList* lista = al_newArrayList();
    ePersona* persona;
    int r;
    miArchivo = fopen("data.csv", "r");
    r = parseArchivo(miArchivo, lista);
    ePersona* aBuscar = lista->pElements[18];
    printf("%s", aBuscar->nombre);
    printf("%d", lista->len(lista));
    r = lista->contains(lista, aBuscar);
    if (r == 1)
        printf("\nEncontrado\n");
    free(lista);
    return 0;
}
