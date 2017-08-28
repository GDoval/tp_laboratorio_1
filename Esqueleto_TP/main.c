#include <stdio.h>
#include <stdlib.h>
//#include "funciones.h"
float IngresoFloat(char texto[]);
float Suma(float n1, float n2);
float Resta (float n1, float n2);
float Multi(float n1, float n2);
float Divi(float n1, float n2);
char Validacion(float numero);
int main()
{
    char seguir='s';
    int opcion=0;
    float num1 = 0;
    float num2 = 0;
    float sum, res, mul, div;
    char noEsCero;

    while(seguir =='s')
    {
        printf("1- Ingresar 1er operando (A=%.3f)\n", num1);
        printf("2- Ingresar 2do operando (B=%.3f)\n", num2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                num1 = IngresoFloat("Ingrese el operando A: ");
                system("clear");
                break;
            case 2:
                num2 = IngresoFloat("Ingrese operando B: ");
                system("clear");
                break;
            case 3:
                sum = Suma(num1,num2);
                printf("\nLa suma de los operandos es: %.3f\n", sum);
                printf("\n\n");
                break;
            case 4:
                res = Resta(num1,num2);
                printf("\nLa resta de los operandos es: %.3f\n", res);
                printf("\n\n");
                break;
            case 5:
                noEsCero = Validacion(num2);
                if ( noEsCero == 'n' )
                {
                    printf("\nNo se puede dividir por cero, papafrita!\n");
                    printf("\n\n");

                }else
                {
                    div = Divi(num1,num2);
                    printf("\nLa division de los operandos es: %.3f\n", div);
                    printf("\n\n");
                }
                break;
            case 6:
                mul = Multi(num1,num2);
                printf("\nLa multiplicacion de los operandos es: %.3f\n", mul);
                printf("\n\n");
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                seguir = 'n';
                break;
        }



    }
    return 0;
}


float IngresoFloat(char texto[]) // Funciona
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

char Validacion(float numero) // Si el numero ingresado como parametro es igual a 0, retorna 'n'.
{
    char resultado;
    if (numero == 0)
    {
        resultado = 'n';
    }
    return resultado;
}
