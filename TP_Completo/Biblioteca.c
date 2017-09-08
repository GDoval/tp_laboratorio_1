#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#include <math.h>

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

int Posibilidades(float numFac, float numDiv)
{
    int posibilidad, respuestaFac;
    char respuestaDiv;
    respuestaFac = validarFacto(numFac); // Devuelve 1 si puede hacerse el factorial, 2 si el numero no es entero, 3 si es negativo.
    respuestaDiv = NoEsCero(numDiv); // devuelve 's' si no es cero, 'n' si es cero

    if (respuestaDiv == 's' && respuestaFac == 1) // 1 es que ambas operaciones son validas
    {
        posibilidad = 1;
        return posibilidad;
    }else
    {
        if (respuestaDiv == 's' && respuestaFac == 2) //2 es que la division es valida y el factorial no se puede xq el numero no es entero
        {
            posibilidad = 2;
            return posibilidad;
        }else
        {
            if (respuestaDiv == 's' && respuestaFac == 3) //3 es que la division sea valida y el factorial invalido xq el numero es negativo
            {
                posibilidad = 3;
                return posibilidad;
            }else
            {
                if (respuestaDiv != 's' && respuestaFac == 1) //4 es que la division es invalida, y el factorial valido
                {
                    posibilidad = 4;
                    return posibilidad;
                }
                else
                {
                    if (respuestaDiv !='s' && respuestaFac == 2) //5 es que la division es invalida, y el factorial es invalido xq el numero no es entero
                    {
                        posibilidad = 5;
                        return posibilidad;
                    }else
                    {
                        if (respuestaDiv !='s' && respuestaFac == 3) //6 es que la division es invalida y el factorial es un numero negativo.
                        {
                            posibilidad = 6;
                            return posibilidad;
                        }
                    }
                }
            }
        }
    }

}





int validarFacto(float numero)
{
    int respuesta;
    double fraccion, entero;
    fraccion = modf(numero,&entero);
    if (fraccion == 0.00000)
    {
        if (entero >= 0)
        {
            respuesta = 1; // Es valido realizar el factorial.
        }else
        {
            respuesta = 3; //EL numero ingresado es negativo.
        }
    }else
    {
        respuesta = 2;// El numero ingresado no es un entero.
    }
    return respuesta;

}
