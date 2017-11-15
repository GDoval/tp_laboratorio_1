#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "estructuras.h"

int main()
{
    FILE* miArchivo;
    ArrayList* lista = al_newArrayList();
    ArrayList* clonada;
    ArrayList* sublista;
    ePersona* persona;
    ePersona* extra;
    int r;
    int opcion;
    char resp = 's';
    while (resp == 's')
    {
        printf("1) Parse\n");
        printf("2) Imprimir listado\n");
        printf("3) Sublista\n");
        printf("4) Eliminar de a uno\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            miArchivo = fopen("data.csv", "r");
            parseArchivo(miArchivo, lista);
            break;
        case 2:
            system("clear");
            imprimir(lista);
            break;
        case 3:
            lista->remove(lista, 4);
            break;
        case 4:
            lista->remove(lista, 5);
            break;


        }
    }
    return 0;
}
