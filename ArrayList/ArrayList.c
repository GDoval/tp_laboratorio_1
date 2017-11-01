#include "ArrayList.h"



ArrayList* al_newArrayList(void)
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
        }
    }
    return auxiliar;
}
