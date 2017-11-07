#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"


ArrayList* al_newArrayList(void)
{
    ArrayList* this;
    ArrayList* returnAux = NULL;
    void* pElements;
    this = (ArrayList *)malloc(sizeof(ArrayList));

    if(this != NULL)
    {
        pElements = malloc(sizeof(void *)*TAM_INICIAL );
        if(pElements != NULL)
        {
            this->size=0;
            this->pElements=pElements;
            this->reservedSize=TAM_INICIAL;
            this->add=al_add;
            this->len=al_len;
            this->set=al_set;
            this->remove=al_remove;
            this->clear=al_clear;
            this->clone=al_clone;
            this->get=al_get;
            this->contains=al_contains;
            this->push=al_push;
            this->indexOf=al_indexOf;
            this->isEmpty=al_isEmpty;
            this->pop=al_pop;
            this->subList=al_subList;
            this->containsAll=al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort = al_sort;
            returnAux = this;
        }
        else
        {
            free(this);
        }
    }

    return returnAux;
}


int al_add(ArrayList* pList,void* pElement)
{
    int validar = 0;
    if (pList == NULL || pElement == NULL) // se chequea que ningun puntero sea NULL
        return -1;
    if (pList->size == pList->reservedSize) //Si el array esta lleno se hace un resizeup()
    {
        validar = resizeUp(pList);
    }
    if (validar != -1) // si el realloc se pudo hacer o no hizo falta  se procede a guardar el nuevo elemento dentro del array de punteros del Arraylist
    {
        pList->pElements[pList->size] = pElement;
        pList->size++; // se incrementa en uno el size para que quede registrado que se ingreso un nuevo elemento.
        return 0;
    }
    else
    {
        printf("No se pudo agregar el nuevo elemento.");
        return -1;
    }
}

int al_len(ArrayList* lista)
{
    if (lista == NULL)
        return -1;
    return lista->size;
}


int al_contains(ArrayList* pList, void* pElement) //Funciona. Se le pasan dos punteros, y se fija que en el puntero al array de punteros dentro de ArrayList se encuentre
{
    // el otro puntero que se le pasa como parametro.
    if (pList == NULL || pElement == NULL)
        return -1;
    for (int i = 0; i < pList->size; i++)
    {
        if (pList->pElements[i] == pElement)
            return 1;
    }
    return 0;
}

int al_set(ArrayList* pList, int index,void* pElement) // Funciona
{
    if (pList == NULL || pElement == NULL)
        return -1;
    if (index > pList->size || index < 0)
        return -1;
    pList->pElements[index] = pElement;
    return 0;
}

//Asi como esta funciona pero hay que ver de hacerla usando resize, contract y esas funciones
int al_remove(ArrayList* pList,int index)
{
    if (pList == NULL || index > pList->size)
        return -1;
    contract(pList, index);
    pList->size--;
    return 0;
}



int al_clear(ArrayList* pList) // Funciona. Si en vez de NULL se intenta hacer un free() solo libera el primer indice del array. ¿?
{
    if (pList == NULL)
        return -1;
    free(pList->pElements);
    pList->size = 0;
    return 0;
}

int al_push(ArrayList* pList, int index, void* pElement) // Funciona
{
    if (pList == NULL || pElement == NULL)
        return -1;
    int validar = 0;
    if (index <= pList->size && index >= 0)
    {
        if(pList->size == pList->reservedSize)
        {
            resizeUp(pList);
        }
        validar = expand(pList, index);
        if (validar != -1)
        {
            pList->pElements[index] = pElement;
            pList->size++;
            return 0;
        }
    }
    else
    {
        return -1;
    }
}


int al_indexOf(ArrayList* pList, void* pElement)
{
    if (pList == NULL || pElement == NULL)
        return -1;
    for (int i = 0; i < pList->size; i++)
    {
        if (pList->pElements[i] == pElement)
            return i;
    }
    return 0;
}


int al_isEmpty(ArrayList* pList)
{
    if (pList == NULL)
        return -1;
    if (pList->size > 0)
        return 0;
    return 1;
}

void* al_get(ArrayList* pList, int index) //Funciona
{
    if (pList == NULL)
        return NULL;
    void* aux;
    if (index >= 0 && index < pList->size)
    {
        aux = pList->pElements[index];
        return aux;
    }
    else
    {
        return NULL;
    }
}

void* al_pop(ArrayList* pList,int index) //Funciona. Se guarda el puntero del indice indicado en un auxiliar, se llama a la funcion al_remove(),
{
                                        // se retorna el puntero y listo.
    if (pList == NULL)
        return NULL;
    void* aux;
    if (index >= 0 && index < pList->size)
    {
        aux = pList->pElements[index];
        pList->remove(pList, index);
        return aux;
    }
    else
    {
        return NULL;
    }
}


int al_containsAll(ArrayList* pList,ArrayList* pList2) //Aparentemente funciona. Si alguno de los punteros del array de punteros de una lista
{
    // es distinto que su homonimo en la otra lista, la funcion devuelve 0. Si nunca entro al if
    if (pList == NULL || pList2 == NULL)               // devuelve 1.
        return -1;
    int tam;
    if (pList->size > pList2->size)
    {
        tam = pList->size;
    }
    else
    {
        tam = pList2->size;
    }
    for (int i = 0; i < tam; i++)
    {
        if (pList2->pElements[i] != pList->pElements[i])
            return 0;
    }
    return 1;
}

// tiene que quedar como si fuese un new_arraylist, no destruirlo
int al_deleteArrayList(ArrayList* pList) // Funciona???? Los campos del ArrayList devuelven basura cuando se los invoca desde el main(), asique...
{
    if (pList == NULL)
        return -1;
    free(pList);
    return 0;
}


ArrayList* al_clone(ArrayList* pList) // Funciona.
{
    if (pList == NULL)
        return NULL;
    ArrayList* clone;
    void** aux;
    clone = al_newArrayList();
    aux = (void**) realloc(clone->pElements, sizeof(void*) *pList->reservedSize);
    if (aux != NULL)
    {
        clone->pElements = aux;
        for (int i = 0; i < pList->size; i++)
        {
            pList->add(clone, pList->get(pList, i));
        }
    }
    return clone;
}


ArrayList* al_subList(ArrayList* pList,int from,int to) // En teoria funciona, falto validar que to no sea mayor que from (o sea, que el destino no sea menor al origen)
{
    if (pList == NULL)
        return NULL;
    if (from < 0 || from > pList->size || to < 0 || to > pList->size)
        return NULL;
    ArrayList* sublista = al_newArrayList();
    sublista->reservedSize = (to - from);
    sublista->size = 0;
    void** aux;
    aux = (void**) realloc(sublista->pElements, sizeof(void*)* sublista->reservedSize);
    if (aux != NULL)
        sublista->pElements = aux;
    for (int i = from; i < to+1; i++)
    {
        pList->add(sublista, pList->pElements[i]);
    }
    return sublista;
}



int resizeUp(ArrayList* pList)
{
    if (pList == NULL)
        return -1;
    void** aux;
    aux = (void**) realloc(pList->pElements, sizeof(void*)* (pList->reservedSize +CONSTANTE));
    if (aux != NULL)
    {
        pList->reservedSize = pList->reservedSize + CONSTANTE;
        pList->pElements = aux;
        return 1;
    }
    else
    {
        return -1;
    }
}


int expand(ArrayList* pList,int index)// Hace lugar en el array para que entre un nuevo elemento. Se guarda el size en una variable, y se empieza
{
    // a desplazar los elementos desde el ultimo hasta el indice donde se va a guardar la nueva variable.
    if (pList == NULL)
        return -1;
    int auxTam = pList->size;
    while (auxTam >= index)
    {
        pList->pElements[auxTam+1] = pList->pElements[auxTam];
        auxTam--;
    }
    return 1;
}


int contract(ArrayList* pList,int index)
{
    if (pList == NULL)
        return -1;
    void** auxArray;
    int f = 0;
    auxArray = (void**)realloc(pList->pElements, sizeof(void*) * (pList->reservedSize));
    if (auxArray != NULL)
    {
        if (index <= pList->size && index >= 0)
        {
            for (int i = 0; i < pList->size; i++)
            {
                if ( i != index)
                {
                    auxArray[f] = pList->pElements[i];
                    f++;
                }
            }
            pList->pElements = auxArray;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }

}



int al_sort(ArrayList* pList, int (*pFunc)(void*,void*), int order)
{
    if (pList == NULL)
        return -1;
    int criterio;
    void* aux;
    for (int i = 0; i < pList->size; i++)
    {
        for (int j = i+1; j < pList->size; j++)
        {
            criterio = pFunc(pList->get(pList, i), pList->get(pList, j));
            if (criterio == order)
            {
                aux = pList->get(pList, i);
                pList->pElements[i] = pList->pElements[j];
                pList->pElements[j] = aux;
            }
        }
    }
    return 0;
}



int resizeDown(ArrayList* pList) {}


