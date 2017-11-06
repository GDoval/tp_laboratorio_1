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
    int devuelve = -1;
    void** puntero; // Se crea un doble puntero a void. Sirve para guardar la nueva direccion de memoria de los elementos del array si hay que usar realloc()
    int flag = 0;
    if (pList == NULL || pElement == NULL) // se chequea que ningun puntero sea NULL
        return devuelve;
    if (pList->size == pList->reservedSize) //si el tamaño de la lista (size) es igual al tamaño total reservado (reservedSize) hay que hacer un realloc()
    {
        //Se guarda en una variable auxiliar erl nuevo puntero a array de punteros (por si devuelve NULL el nuevo puntero) . El nuevo array de punteros se crea multiplicando el tamaño de un puntero a void por el tamaño total reservado sumado a la constante.
        //Esto crea un nuevo array de reservedSize + 10 elementos, con lo que se evita tener que hacer un realloc por cada campo extra que se quiera agregar. Aca se generan 10 mas por las dudas, si se llenan se llenan.
        puntero = (void**) realloc(pList->pElements, sizeof(void*) * (pList->reservedSize + CONSTANTE));
        if (puntero != NULL)
        {
            pList->reservedSize = pList->reservedSize + CONSTANTE; //si el nuevo puntero no es NULL hay que modificar el valor de la variable del ArrayList reservedSize, para que quede registrado el nuevo tamaño del array de punteros
            pList->pElements = puntero; // se le pasa al array de punteros la nueva direccion de memoria
        }
        else
        {
            flag = 1; // en caso de que no se haya podido hacer el realloc()
        }
    }
    if (flag == 0) // si el realloc se pudo hacer o no hizo falta (flag se inicializa en 0) se procede a guardar el nuevo elemento dentro del array de punteros del Arraylist
    {
        pList->pElements[pList->size] = pElement;
        pList->size++; // se incrementa en uno el size para que quede registrado que se ingreso un nuevo elemento.
        devuelve = 0;
    }
    else
    {
        printf("No se pudo agregar el nuevo elemento.");
        return devuelve;
    }
    return devuelve;
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

int al_set(ArrayList* pList, int index,void* pElement) // ¿Se duplica con la funcion al_push ()?
{
    if (pList == NULL || pElement == NULL)
        return -1;
    int auxTam = pList->size;
    if (index < pList->size && index >= 0)
    {
        while (auxTam >= index)
        {
            pList->pElements[auxTam+1] = pList->pElements[auxTam];
            auxTam--;
        }
        pList->pElements[index] = pElement;
        pList->size++;

    }
    else
    {
        return -1;
    }
}


int al_remove(ArrayList* pList,int index) //Funciona. Se  lee el array de punteros del ArrayList
{                                         // y se lo guarda en un array auxiliar, menos la posicion que se quiere eliminar. Para eso se crea una variable
    if (pList == NULL)                    // de control que no se asocia a ningun ciclo repetitivo, para que sea el indice del nuevo array, mientras que
        return -1;                        // la variable de control del for() se usa como indice del viejo array para poder descartar el puntero que se
    void** auxArray;                      // elimina, y se disminuye en 1 el tamaño del size.
    int f = 0;
    auxArray = (void**)realloc(pList->pElements, sizeof(void*) * (pList->reservedSize));

    if (auxArray != NULL)
    {
        for (int i = 0; i < pList->size; i++)
        {
            if ( i != index)
            {
                auxArray[f] = pList->pElements[i];
                f++;
            }
        }
        pList->size--;
        pList->pElements = auxArray;

    }
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

int al_push(ArrayList* pList, int index, void* pElement)
 {
    if (pList == NULL || pElement == NULL)
        return -1;
    int auxTam = pList->size;
    if (index < pList->size && index >= 0)
    {
        while (auxTam >= index)
        {
            pList->pElements[auxTam+1] = pList->pElements[auxTam];
            auxTam--;
        }
        pList->pElements[index] = pElement;
        pList->size++;

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
    }else
    {
        return NULL;
    }
}

void* al_pop(ArrayList* pList,int index) //Funciona. Se guarda el puntero del indice indicado en un auxiliar, se llama a la funcion al_remove(),
{                                        // se retorna el puntero y listo.
    if (pList == NULL)
        return NULL;
    void* aux;
     if (index >= 0 && index < pList->size)
     {
        aux = pList->pElements[index];
        pList->remove(pList, index);
        return aux;
     }else
     {
        return NULL;
     }
}


int al_containsAll(ArrayList* pList,ArrayList* pList2) //Aparentemente funciona. Si alguno de los punteros del array de punteros de una lista
{                                                      // es distinto que su homonimo en la otra lista, la funcion devuelve 0. Si nunca entro al if
    if (pList == NULL || pList2 == NULL)               // devuelve 1.
        return -1;
    int tam;
    if (pList->size > pList2->size)
    {
        tam = pList->size;
    }else
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
    if (pList == NULL)
        return -1;
    free(pList);
    return 0;
}


ArrayList* al_clone(ArrayList* pList) // Aparentemente funciona. Si se leen  las direcciones de memoria
{                                     // de las listas desde el main se ve que son distintas. Si se hace un
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

ArrayList* al_subList(ArrayList* pList,int from,int to) {}

int al_sort(ArrayList* pList, int (*pFunc)(void*,void*), int order) {}

int resizeUp(ArrayList* pList) {}

int expand(ArrayList* pList,int index) {}

int contract(ArrayList* pList,int index) {}

