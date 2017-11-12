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
            persona = lista->get(lista, 5);
            lista->push(lista, 6, persona);
            break;
        case 4:
            system("clear");
            printf("Ingrese ID a eliminar: ");
            scanf("%d", &r);
            lista->remove(lista, r);
            break;


        }
    }
    return 0;
}
