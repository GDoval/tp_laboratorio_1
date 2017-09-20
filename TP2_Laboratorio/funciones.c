#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

void Ingreso (ePersona personita[], int tam) // Sin problemas hasta ahora
{

        int validar, validarEdad;
        validar = buscarVacio(personita, tam);
         if (validar != -1)
            {
                printf("Ingrese Nombre: ");
                setbuf(stdin, NULL);
                fgets(personita[validar].nombre, 20, stdin);
                sacarEnter(personita[validar].nombre);
                printf("Ingrese edad: ");
                scanf("%d", &personita[validar].edad);
                validarEdad = validaInt(personita[validar].edad,0,150);
                while (validarEdad == -1)
                {
                    printf("Error. Por favor ingrese una edad mayor a cero y menor a 150: ");
                    scanf("%d", &personita[validar].edad);
                    validarEdad = validaInt(personita[validar].edad,0,150);
                }
                printf("Ingrese DNI: ");
                scanf("%lli",&personita[validar].dni);
                personita[validar].flag = 1;
            }else
            {
                printf("\nNo hay mas lugar en el sistema.\n");
            }


}

void mostrarPersonas(ePersona imprimir [], int tam)
{

    ordenarStrings(imprimir, tam);
    int x, len,y;
    printf("Nombre\t\tEdad\t\tDNI  \n");
    printf("\n------------------------------------------\n");
    for (int i = 0; i < tam; i++)
    {
        if (imprimir[i].flag !=0)
        {
            len = strlen(imprimir[i].nombre);
            x = 20 - len;
            y = x + len;
            printf("\n%s%*d%*lli\n", imprimir[i].nombre,x, imprimir[i].edad,y, imprimir[i].dni);
        }

    }
    printf("\n------------------------------------------\n");

}



void sacarEnter(char vec[]) // borra el enter que queda en la ultima posicion del string cuando se usa fgets().
{
    int cant;
    cant = strlen(vec);
    vec[cant-1] = '\0';
}



void ordenarStrings(ePersona ordenar[], int filas) // El primer criterio de ordenamiento es el nombre, el segundo el DNI.
{

    int i, j;
    ePersona temporal;
    for (i = 1; i < filas; i++)
    {
        temporal = ordenar[i];
        j = i-1;
        while(strcmp(temporal.nombre,ordenar[j].nombre) < 0 && j >= 0)
        {
            ordenar[j+1] = ordenar[j];
            j--;
        }
        if (strcmp(temporal.nombre, ordenar[j]. nombre) == 0)
        {
            while(temporal.dni < ordenar[j].dni && j >= 0)
            {
                ordenar[j+1] = ordenar[j];
                j--;
            }
        }
        ordenar[j+1] = temporal;
    }
}




int validaInt (int input, int lowLimit, int hiLimit)
{
    int resultado = 0;
    if (input < lowLimit || input > hiLimit)
    {
        resultado = -1;
    }
    return resultado;
}



void borrarPersona (ePersona borrado[], int dni, int tam)
{

    char respuesta;
    int posicion, x, y, len, flag = 0;
    for (int i = 0; i < tam; i++)
    {
        if(borrado[i].dni == dni)
        {
            posicion = i;
            printf("Nombre\t\tEdad\tDNI  \n");
            len = strlen(borrado[i].nombre);
            x = 20 - len;
            y = x + len;
            printf("\n%s%*d%*lli\n", borrado[posicion].nombre,x, borrado[posicion].edad,y, borrado[posicion].dni);
            printf("\n¿Confirma que desea borrar este registro? s/n: ");
            setbuf(stdin, NULL);
            scanf("%c", &respuesta);
            flag = 1;
            if (respuesta == 's')
                {
                    borrado[posicion].flag = 0;
                    printf("\nRegistro eliminado\n\n");
                }else
                    {
                        printf("\nEl usuario cancelo el borrado del registro\n\n");
                    }
            break;
        }

    }
    if (flag == 0)
        printf("\nNo se encontro el DNI ingresado. \n");

}

void graficoEdades (ePersona lista[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        if (lista[i].flag !=0)
        {
             if (lista[i].edad <= 18)
        {
            printf("\n*");
        }else
            {
                if (lista[i].edad > 35)
                {
                    printf("\n\t\t*");
                }else
                {
                    printf("\n\t*");
                }
            }
        }

    }
    printf("\n<18\t19-35\t>35\n");
}





int buscarVacio (ePersona listado[], int tam)
{
    int resultado = -1;
    for (int i = 0; i < tam; i++)
    {
        if (listado[i].flag == 0)
        {
            resultado = i;
            break;
        }
    }
    return resultado;
}
