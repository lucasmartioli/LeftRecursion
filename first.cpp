//
// Created by Lucas on 10/15/2016.
//

#include "first.h"

FirstSet *first(GramaticalRule *gramaticalrule)
{
    int mudou = 0;
    do
    {
        GramaticalRule currentrule = gramaticalrule;
        while (currentrule != NULL)
        {
            char key = currentrule->key;



            currentrule = currentrule->next;
        }


    } while (mudou);

}

FirstSet *seekkey(FirstSet *firstset, char key)
{
    FirstSet *current = firstset;
    while (current != NULL)
    {
        if (current->key == key)
            return current;

        current = current->next;
    }

    return NULL;
}
