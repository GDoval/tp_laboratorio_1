#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

float IngresoFloat(char texto[])
{
    float numero;
    printf("%s", texto);
    scanf("%f", &numero);
    return numero;
}

float Resta (float n1, float n2)
{
    float resta;
    resta = n1 - n2;
    return resta;
}

float Suma(float n1, float n2)
{
    float suma;
    suma = n1 + n2;
    return suma;
}

float Multi(float n1, float n2)
{
    float multi;
    multi = n1 * n2;
    return multi;
}

float Divi(float n1, float n2)
{
    float divi;
    divi = n1 / n2;
    return divi;
}

char NoEsCero(float numero)
{
    char resultado = 's';
    if (numero == 0)
    {
        resultado = 'n';
    }
    return resultado;
}


long long int Factorial (int num)
{
    long long int factorial = 1;
    for (int i = num; i > 0; i--)
    {
        factorial = factorial * i;
    }
    return factorial;
}

char MayorCero (int numero)
{
    char respuesta = 's';
    if (numero < 0)
    {
        respuesta = 'n';
    }
    return respuesta;

}
