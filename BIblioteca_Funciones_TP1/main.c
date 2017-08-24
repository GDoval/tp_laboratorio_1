#include <stdio.h>
#include <stdlib.h>
int Generica(char texto[], char texto2[]);
int Resta (int n1, int n2);
int Suma(int n1, int n2);
int Multi(int n1, int n2);
float Divi(int n1, int n2);
int main()
{
    int num, num2;
    float div;
    num = Generica("Ingrese un operando: ", "Operando A = ");
    num2 = Generica("Ingrese otro operando: ", "Operando B = ");
    div = Divi(num, num2);
    printf("El resultado de la division es: %1.f\n", div);
    printf("la concha tuya");
    return 0;
}

int Generica(char texto[], char texto2[]) // Funciona
{
    int numero;
    printf("%s", texto);
    scanf("%d", &numero);
    printf("%s""%d \n", texto2, numero);
    return numero;
}

int Suma(int n1, int n2)
{
    int suma;
    suma = n1 + n2;
    return suma;
}

int Resta (int n1, int n2)
{
    int resta;
    resta = n1 - n2;
    return resta;
}

int Multi(int n1, int n2)
{
    int multi;
    multi = n1 * n2;
    return multi;
}

float Divi(int n1, int n2)  //Validar por cero dentro del case del main????
{
    float divi = 0.0;
    switch(n2)
    {
        case 0:
        printf("Ingrese un divisor distinto a cero.\n");
        break;
        default:
        divi = n1 / n2;
    }
    return divi;
}
