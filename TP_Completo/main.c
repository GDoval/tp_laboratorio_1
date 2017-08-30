#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
int main()
{
    char seguir='s';
    int opcion=0, flagDiv = 0, flagFac = 0;
    float num1 = 0;
    float num2 = 0;
    float sum, res, mul, div;
    char noEsCero, mayorQueCero;
    long long int facto;


    while(seguir =='s')
    {
        printf("1- Ingresar 1er operando (A=%.3f)\n", num1);
        printf("2- Ingresar 2do operando (B=%.3f)\n", num2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
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
                system("clear");
                printf("\nLa suma de los operandos es: %.3f\n", sum);
                printf("\n\n");
                break;
            case 4:
                res = Resta(num1,num2);
                system("clear");
                printf("\nLa resta de los operandos es: %.3f\n", res);
                printf("\n\n");
                break;
            case 5:
                noEsCero = NoEsCero(num2);
                if ( noEsCero == 'n' )
                {
                    system("clear");
                    printf("\nNo se puede dividir por cero, papafrita!\n");
                    printf("\n\n");

                }else
                {
                    div = Divi(num1,num2);
                    system("clear");
                    printf("\nLa division de los operandos es: %.3f\n", div);
                    printf("\n\n");
                }
                break;
            case 6:
                mul = Multi(num1,num2);
                system("clear");
                printf("\nLa multiplicacion de los operandos es: %.3f\n", mul);
                printf("\n\n");
                break;
            case 7:
                mayorQueCero = MayorCero(num1);
                if (mayorQueCero == 's')
                {
                    facto = Factorial(num1);
                    system("clear");
                    printf("\nEl factorial de %.0f es %lli \n", num1, facto);
                    printf("\n\n");
                }else
                {
                    system("clear");
                    printf("\nNo puede hacerse el factorial de un numero negativo. \n");
                    printf("\n\n");
                }

                break;
            case 8:
                sum = Suma(num1,num2);
                res = Resta(num1,num2);
                mul = Multi(num1,num2);
                noEsCero = NoEsCero(num2);
                mayorQueCero = MayorCero(num1);
                if ( noEsCero == 'n' )
                {
                    flagDiv = 1;

                }else
                {
                    div = Divi(num1,num2);
                    flagDiv = 0;

                }
                if (mayorQueCero == 's')
                {
                    facto = Factorial(num1);
                    flagFac = 0;

                }else
                {
                    flagFac = 1;
                }
                if (flagDiv == 1 && flagFac == 1)
                {
                    system("clear");
                    printf("\nLa suma de los operandos es: %.3f\nSu resta es: %.3f\nSu multiplicacion es: %.3f\nNo puede dividirse por cero\nNo puede realizarse el factorial de un numero negativo\n", sum, res, mul);
                    printf("\n\n");
                }else
                {
                    if (flagDiv == 0 && flagFac == 1)
                    {
                        system("clear");
                        printf("\nLa suma de los operandos es: %.3f\nSu resta es: %.3f\nSu multiplicacion es: %.3f\nSu division es: %.3f \nNo puede realizarse el factorial de un numero negativo\n", sum, res, mul, div);
                        printf("\n\n");
                    }else
                    {
                        if (flagDiv == 1 && flagFac == 0)
                        {
                            system("clear");
                            printf("\nLa suma de los operandos es: %.3f\nSu resta es: %.3f\nSu multiplicacion es: %.3f\nNo puede dividirse por cero\nEl factorial del operando A es: %lli\n", sum, res, mul, facto);
                            printf("\n\n");
                        }else
                        {
                            if (flagDiv == 0 && flagFac == 0)
                            {
                                system("clear");
                                printf("\nLa suma de los operandos es: %.3f\nSu resta es: %.3f\nSu multiplicacion es: %.3f\nSu division es: %.3f \nEl factorial del operando A es: %lli\n", sum, res, mul, div, facto);
                                printf("\n\n");
                            }
                        }
                    }
                }

                break;
            case 9:
                seguir = 'n';
                break;
        }



    }
    return 0;
}
