#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

void Ingreso (ePersona personita[], int tam) // Sin problemas hasta ahora
{

        int indice, validar;
        indice = buscarVacio(personita, tam);
         if (indice != -1)
            {
                printf("Ingrese Nombre: ");
                setbuf(stdin, NULL);
                fgets(personita[indice].nombre, 20, stdin);
                sacarEnter(personita[indice].nombre);
                printf("Ingrese edad: ");
                scanf("%d", &personita[indice].edad);
                validar= validaInt(personita[indice].edad,0,150);
                while (validar !=0)
                {
                    printf("Error. Por favor ingrese una edad mayor a cero y menor a 150: ");
                    scanf("%d", &personita[indice].edad);
                    validar= validaInt(personita[indice].edad,0,150);
                }
                printf("Ingrese DNI: ");
                scanf("%d",&personita[indice].dni);
                validar = validaDni(personita[indice].dni);
                while (validar != 0)
                {
                    printf("Error. Por favor ingrese un DNI mayor que cero: ");
                    scanf("%d", &personita[indice].dni);
                    validar = validaDni(personita[indice].dni);
                }
                personita[indice].flag = 1;
            }else
            {
                system("clear");
                printf("\nNo hay mas lugar en el sistema.\n");
            }
        printf("\n\n");

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
            printf("\n%s%*d%*d\n", imprimir[i].nombre,x, imprimir[i].edad,y, imprimir[i].dni);
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

    int i, j,d;
    ePersona temporal, tempDni;
    for (i = 1; i < filas; i++)
    {
        temporal = ordenar[i];
        j = i-1;
        while(strcmp(temporal.nombre,ordenar[j].nombre) < 0 && j >= 0)
        {
            ordenar[j+1] = ordenar[j];
            j--;
        }

        ordenar[j+1] = temporal;
    }
    for (int f = 1; f < filas; f++)
    {
        tempDni = ordenar[f];
        d = f-1;
        while(strcmp(tempDni.nombre, ordenar[d].nombre) == 0 && d >=0)
        {
            if (tempDni.dni < ordenar[d].dni)
            {
                ordenar[d+1] = ordenar[d];
            }else
            {
                break;
            }

            d--;
        }
        ordenar[d+1] = tempDni;
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

    int cont = 0, flag = 0;
    int menor, mayor;
    int contMin = 0, contMed = 0, contMax = 0;
    for (int i = 0; i < tam; i++)
    {
        if (lista[i].flag == 1)
        {
            cont++;
        }
    }
    for (int i = 0; i < cont; i++)
    {
        if (lista[i].edad < 18)
        {
            contMin++;
        }else
        {
            if(lista[i].edad >= 18 && lista[i].edad <= 35)
            {
                contMed++;
            }else
                {
                    contMax++;
                }
        }
    }
    mayor = sacarMayor(contMin, contMed, contMax);
    for (int i = mayor; i > 0; i--)
    {
        if (contMin >= mayor)
        {
            printf("*");
        }
        if (contMed >= mayor)
        {
            flag = 1;
            printf("\t*");
        }
        if (contMax >= mayor)
        {
            if(flag == 0)
            {
                printf("\t\t*");
            }else
            {
                printf("\t*");
            }
        }
        printf("\n");
        mayor--;
    }
    printf("<18\t19-35\t>35\n");
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

int validaDni (int dni)
{
    int resultado = 0;
    if (dni <= 0)
        resultado = -1;
    return resultado;
}




int sacarMayor(int num1, int num2, int num3)
{
    int mayor;
    if (num1 >= num2 && num1 >= num3)
    {
        mayor = num1;
    }else
    {
        if(num2 >= num1 && num2 >= num3 )
        {
            mayor = num2;
        }else
        {
            mayor = num3;
        }
    }
    return mayor;
}
