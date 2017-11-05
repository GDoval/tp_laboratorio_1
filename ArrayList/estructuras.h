#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{

    int id;
    char nombre[100];
    char apellido[100];
    int vacio;

}ePersona;

ePersona* persona_constructor();

