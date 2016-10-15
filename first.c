//
// Created by Lucas on 10/15/2016.
//

#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include "first.h"
#include "readgramar.h"

FirstSet *first(GramaticalRule *headgramaticalrule)
{
    FirstSet *head = NULL;
    int mudou = false;

    //CARACTER_VAZIO esta definido em readgramar.h

    do
    {
        GramaticalRule *currentrule = headgramaticalrule;
        while (currentrule != NULL)
        {
            char key = currentrule->key;
            FirstSet *currentfirstset = seekkey(head,key);
            if (currentfirstset == NULL)
            {
                currentfirstset = (FirstSet*) malloc(sizeof(FirstSet));
                currentfirstset->key = key;
                currentfirstset->set = (char*) malloc(500);
                if (head == NULL)
                    head = currentfirstset;
            }

            for (int i = 0; i < strlen(currentrule->rule); i++)
            {
                FirstSet *notterminalset;
                char crule = currentrule->rule[i];
                if (islower(crule))
                {
                    int length = strlen(currentfirstset->set);
                    currentfirstset->set[ length + 1] = crule;
                    currentfirstset->set[length + 2] = '\0';
                    mudou = true;
                } else if (notterminalset = seekkey(head,crule) != NULL) {
                    char *newfirst = (char*) malloc(500);



//                    unionset();

//                    if(crule != CARACTER_VAZIO){      //verifica se é o caracter vazio
//                        char crule = currentfirstset->key;  //se não for, entao o crule é first
//                    }
//                    for (int j = 0; j < strlen(currentrule->rule); j++) {  //verifica para o resto das regras se alguma tem vazio inclusive na primeira key
//
//                    }



                }
            }

            currentrule = currentrule->next;
        }


    } while (mudou);

    return head;
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

int containinset(char *rule, char c)
{
    for (int i = 0; i < strlen(rule); i++) {
        if(rule[i] == c)
            return 1;
    }

    return 0;
}

void copyrulewithoutempty(char *rulesource, char *ruledestination)
{
    int j= 0;
    for (int i = 0; i < strlen(rulesource); i++) {
        if(rulesource[i] == CARACTER_VAZIO)
            continue;

        ruledestination[j] = rulesource[i];
        j++;
    }

    ruledestination[j] = '\0';

    return;
}

void copyrule(char *rulesource, char *ruledestination)
{
    int i;
    for (i = 0; i < strlen(rulesource); i++) {
        ruledestination[i] = rulesource[i];
    }

    ruledestination[i] = '\0';

    return;
}


void unionset(char *setsource1, char *setsource2)
{
    char *newset2 = (char*) malloc(500);
    copyrulewithoutempty(setsource2, newset2);

    int endindexsetsource1 = strlen(setsource1);
    for (int i = 0; i < strlen(newset2); i++) {
        if(containinset(setsource1, newset2[i]))
            continue;

        setsource1[endindexsetsource1] = newset2[i];
        endindexsetsource1++;
    }

    setsource1[endindexsetsource1] = '\0';

    return;
}


