#include "estructuras.h"
#include "ArrayList.h"



int parseArchivo(FILE* archivo, ArrayList* lista)
{
    char auxId[100];
    char auxNom[100];
    char auxApe[100];
    char auxVacio[100];
    ePersona* nuevaPersona;
    if (archivo == NULL || lista == NULL)
        return -1;

    fscanf(archivo, "%[^,],%[^,],%[^,],%s\n", auxId, auxNom, auxApe, auxVacio);
    while(!feof(archivo))
    {
        fscanf(archivo, "%[^,],%[^,],%[^,],%s\n", auxId, auxNom, auxApe, auxVacio);
        nuevaPersona = persona_constructor();
        if (nuevaPersona != NULL)
        {
            nuevaPersona->id = atoi(auxId);
            strcpy(nuevaPersona->nombre, auxNom);
            strcpy(nuevaPersona->apellido, auxApe);
            if (strcmp(auxVacio, "false") == 0)
            {
                nuevaPersona->vacio = 0;
            }else
            {
                nuevaPersona->vacio = 1;
            }
        }
        lista->add(lista, nuevaPersona);

    }
    return 0;
}



ePersona* persona_constructor()
{
    ePersona* auxiliar;
    auxiliar = (ePersona*) malloc(sizeof(ePersona));
    if (auxiliar != NULL)
    {
        auxiliar->id = 0;
        strcpy(auxiliar->nombre, "");
        strcpy(auxiliar->apellido, "");
        auxiliar->vacio = 0;
    }
    return auxiliar;
}
