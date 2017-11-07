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
    ePersona extra;
    persona = &extra;
    int r, f;
    int opcion;
    char resp = 's';
    while (resp == 's')
    {
        printf("1) Parse\n");
        printf("2) Imprimir listado\n");
        printf("3) Ordenar por nombre\n");
        printf("4) Clonar lista\n");
        printf("5) Ordenar lista clonada\n");
        printf("6) Imprimir lista origen y lista clonada\n");
        printf("7) Eliminar persona\n");
        printf("8) Agregar persona\n");
        printf("9) Imprimir desde hasta\n");
        printf("10) Size lista origen\n");
        printf("11) Size lista clonada\n");
        printf("12) Contains en lista clonada lo de la lista origen\n");
        printf("13) Clear lista origen\n");
        printf("14) Indice del elemento\n");
        printf("15) Comprar lista clon y origen a ver si son iguales\n");
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
            lista->sort(lista, compararNombre, 1);
            break;
        case 4:
            clonada = lista->clone(lista);
            break;
        case 5:
            clonada->sort(clonada, compararNombre, 1);
            break;
        case 6:
            system("clear");
            imprimir(lista);
            printf("\n-----------------------------------------------\n");
            imprimir(clonada);
            break;
        case 7:
            system("clear");
            printf("Ingrese ID a eliminar: ");
            scanf("%d", &r);
            lista->remove(lista, r);
            break;
        case 8:
            system("clear");
            printf("Ingrese ID: ");
            scanf("%d", &persona->id);
            printf("\nIngrese nombre: ");
            setbuf(stdin, NULL);
            fgets(persona->nombre, 100, stdin);
            sacarEnter(persona->nombre);
            printf("\nIngrese apellido: ");
            setbuf(stdin, NULL);
            fgets(persona->apellido, 100, stdin);
            sacarEnter(persona->apellido);
            lista->add(lista, persona);
            break;
        case 9:
            system("clear");
            printf("Ingrese indice desde: ");
            scanf("%d", &r);
            printf("\nIngrese indice hasta: ");
            scanf("%d", &f);
            sublista = lista->subList(lista, r, f);
            imprimir(sublista);
            break;
        case 10:
            system("clear");
            printf("Tamanio lista origen: %d\n\n", lista->size);
            break;
        case 11:
            system("clear");
            printf("Tamanio lista clonada: %d\n\n", clonada->size);
            break;
        case 12:
            system("clear");
            r = lista->containsAll(lista, clonada);
            if (r == 1)
            {
                printf("Listas iguales RAAAAAAAAAAUUUUUUUUUULLLLLLLLLLL\n\n");
            }else
            {
                printf("Son distintas !!!!!!!!!!!!!!! \n\n");
            }
            break;
        case 13:
            system("clear");

        }
    }
    return 0;
}
