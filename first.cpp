//
// Created by Lucas on 10/15/2016.
//

#include "first.h"
#include "readgramar.h"

FirstSet *first(GramaticalRule *gramaticalrule)
{
    FirstSet *head = (FirstSet*) malloc(sizeof(FirstSet));
    int mudou = false;

    //CARACTER_VAZIO esta definido em readgramar.h

    do
    {
        GramaticalRule *currentrule = gramaticalrule;
        while (currentrule != NULL)
        {
            char key = currentrule->key;
            FirstSet *currentfirstset = seekkey(head,key);
            if (currentfirstset == NUlL)
            {
                currentfirstset = (FirstSet*) malloc(sizeof(FirstSet));
                currentfirstset->key = key;
                currentfirstset->set = (char*) malloc(500);
            }

            for (int i = 0; i < strlen(currentrule->rule); i++)
            {
                char crule = currentrule->rule[i];
                if (islower(crule))
                {
                    strncat(currentfirstset->set, crule, 1);
                    mudou = true;
                } else {


                }
            }

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
