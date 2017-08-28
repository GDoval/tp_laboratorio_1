#include <stdio.h>
#include <stdlib.h>
float Generica(char texto[], char texto2[]);
float Resta (float n1, float n2);
float Suma(float n1, float n2);
float Multi(float n1, float n2);
float Divi(float n1, float n2);
int main()
{
    float num, num2;
    float div;
    num = Generica("Ingrese un operando: ", "Operando A = ");
    num2 = Generica("Ingrese otro operando: ", "Operando B = ");
    div = Divi(num, num2);
    printf("El resultado de la division es: %.3f\n", div);
    return 0;
}

float Generica(char texto[], char texto2[]) // Funciona
{
    float numero;
    printf("%s", texto);
    scanf("%f", &numero);
    printf("%s""%f \n", texto2, numero);
    return numero;
}

float Suma(float n1, float n2)
{
    float suma;
    suma = n1 + n2;
    return suma;
}

float Resta (float n1, float n2)
{
    float resta;
    resta = n1 - n2;
    return resta;
}

float Multi(float n1, float n2)
{
    float multi;
    multi = n1 * n2;
    return multi;
}

float Divi(float n1, float n2)  //Validar por cero dentro del case del main????
{
    float divi;
    divi = n1 / n2;
    return divi;
}
