#include "ArrayList.h"
#include "estructuras.h"


ArrayList* al_newArrayList()
{
    ArrayList* lista;
    ArrayList* auxiliar = NULL;
    void** arrayPuntero;
    lista = (ArrayList *)malloc(sizeof(ArrayList));

    if (lista != NULL)
    {
        arrayPuntero = (void**) malloc(sizeof(void*)* TAM_INICIAL);
        if (arrayPuntero != NULL)
        {
            lista->size = 0;
            lista->pElements = arrayPuntero;
            lista->reservedSize = TAM_INICIAL;
            lista->add = al_add;
            lista->len = al_len;
            lista->set = al_set;
            lista->remove = al_remove;
            lista->clear = al_clear;
            lista->get = al_get;
            lista->contains = al_contains;
            lista->containsAll = al_containsAll;
            lista->clone = al_clone;
            lista->indexOf = al_indexOf;
            lista->push = al_push;
            lista->isEmpty = al_isEmpty;
            lista->pop = al_pop;
            lista->subList = al_subList;
            lista->deleteArrayList = al_deleteArrayList;
            auxiliar = lista;
        }
    }
    return auxiliar;
}


int al_add(ArrayList* pList,void* pElement)
{
    void** puntero; // Se crea un doble puntero a void. Sirve para guardar la nueva direccion de memoria de los elementos del array si hay que usar realloc()
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
    pList->pElements[index] = pElement;
    return 0;
}

//Asi como esta funciona pero hay que ver de hacerla usando resize, contract y esas funciones
int al_remove(ArrayList* pList,int index)
{
    if (pList == NULL)
        return -1;
    contract(pList, index);
    pList->size--;
    return 0;
}



int al_clear(ArrayList* pList) // Funciona. Si en vez de NULL se intenta hacer un free() solo libera el primer indice del array. ¿?
{
    if (pList == NULL)
        return -1;
    pList->pElements = NULL;
    /*while(i < pList->size)
    {
        pList->pElements[i] = NULL;
        i++;
    }*/

    return 0;
}

int al_push(ArrayList* pList, int index, void* pElement) // Funciona
{
    if (pList == NULL || pElement == NULL)
        return -1;
    int auxTam = pList->size;
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
        }
    }
    else
    {
        return -1;
    }
}


int al_indexOf(ArrayList* pList, void* pElement)
{
    if (pList == NULL)
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
        return 1;
    return 0;
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


int al_deleteArrayList(ArrayList* pList) // Funciona???? Los campos del ArrayList devuelven basura cuando se los invoca desde el main(), asique...

{
    // tiene que quedar como si fuese un new_arraylist, no destruirlo											// tiene que quedar como si fuese un new_arraylist, no destruirlo
    if (pList == NULL)
        return -1;
    free(pList);
    return 0;
}


ArrayList* al_clone(ArrayList* pList) // Aparentemente funciona. Si se leen  las direcciones de memoria
{
    // de las listas desde el main se ve que son distintas. Si se hace un
    if (pList == NULL)                // al_deleteArraylist() de la lista original, del clone pueden seguir
        return NULL;                  // sacandose datos y de la original no.
    ArrayList* clone;
    void** aux;
    clone = al_newArrayList();
    clone->size = pList->size;
    clone->reservedSize = pList->reservedSize;
    free(clone->pElements);
    aux = (void**) realloc(clone->pElements, sizeof(void*) *pList->reservedSize);
    if (aux != NULL)
    {
        aux = pList->pElements;
        clone->pElements = aux;
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



int al_sort(ArrayList* pList, int (*pFunc)(void*,void*), int order) {}






int resizeDown(ArrayList* pList) {}

