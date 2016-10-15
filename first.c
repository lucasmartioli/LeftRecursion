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
    //CARACTER_FINAL_ARQUIVO

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

            int beforelength = strlen(currentrule->rule);
            if (strlen(currentrule->rule) >= 1)
            {
                FirstSet *notterminalset;
                char crule = currentrule->rule[0];
                if (islower(crule))
                {
                    int length = strlen(currentfirstset->set);
                    currentfirstset->set[ length + 1] = crule;
                    currentfirstset->set[length + 2] = '\0';
                } else if ((notterminalset = seekkey(head,crule)) != NULL) {
                    char *newfirst = (char *) malloc(500);
                    copysetwithoutempty(notterminalset->set, newfirst);
                    unionset(currentfirstset->set, newfirst);

                    int i = 0;
                    int todostemvazio;
                    while ( i < strlen(currentrule->rule) && isupper(currentrule->rule[i]) && (notterminalset = seekkey(head,crule)) != NULL && containinset(notterminalset->set, CARACTER_VAZIO))
                    {} //Nao precisa de nada aqui dentro mesmo
                    todostemvazio = (i+1) == strlen(currentrule->rule);
                    if (todostemvazio)
                    {
                        int length = strlen(currentfirstset->set);
                        currentfirstset->set[length + 1] = CARACTER_VAZIO;
                        currentfirstset->set[length + 2] = '\0';
                    }

                }

                if (containinset(currentrule->rule, CARACTER_VAZIO))
                {
                    int length = strlen(currentfirstset->set);
                    currentfirstset->set[length + 1] = CARACTER_VAZIO;
                    currentfirstset->set[length + 2] = '\0';
                }
            }

            if (!mudou)
                mudou = beforelength != strlen(currentrule->rule);

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

void copysetwithoutempty(char *setsource, char *setdestination)
{
    int j= 0;
    for (int i = 0; i < strlen(setsource); i++) {
        if(setsource[i] == CARACTER_VAZIO)
            continue;

        setdestination[j] = setsource[i];
        j++;
    }

    setdestination[j] = '\0';

    return;
}

void copyset(char *setsource, char *setdestination)
{
    int i;
    for (i = 0; i < strlen(setsource); i++) {
        setdestination[i] = setsource[i];
    }

    setdestination[i] = '\0';

    return;
}


void unionset(char *setsource1, char *setsource2)
{
    char *newset2 = (char*) malloc(500);
    copysetwithoutempty(setsource2, newset2);

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


