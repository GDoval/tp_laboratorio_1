#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"
#define TAM 20


int main()
{
    ePersona listaPersonas[TAM];
    ePersona listaOrdenada[TAM];
    char seguir='s';
    int opcion=0;
    for (int i = 0; i <TAM; i++)
    {
        listaPersonas[i].flag = 0;
    }

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("clear");
                Ingreso(listaPersonas, TAM);
                break;
            case 2:
                system("clear");
                printf("Ingrese el DNI de la persona a eliminar: ");
                scanf("%d", &opcion);
                borrarPersona(listaPersonas, opcion, TAM);
                break;
            case 3:
                system("clear");
                for (int i = 0; i < TAM; i++)
                    listaOrdenada[i] = listaPersonas[i];
                mostrarPersonas(listaOrdenada, TAM);
                break;
            case 4:
                system("clear");
                graficoEdades(listaPersonas, TAM);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}


