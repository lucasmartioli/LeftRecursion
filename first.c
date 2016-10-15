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


    //CARACTER_VAZIO esta definido em readgramar.h
    //CARACTER_FINAL_ARQUIVO
    int mudou;
    do
    {
        mudou = false;
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
                strcpy(currentfirstset->set, "");
                currentfirstset->next = NULL;
                if (head == NULL)
                    head = currentfirstset;
                else
                    queuingpointer(head, currentfirstset);
            }

            int beforelength = strlen(currentfirstset->set);
            if (strlen(currentrule->rule) >= 1)
            {
                FirstSet *notterminalset;
                char crule = currentrule->rule[0];
                if (islower(crule))
                {
                    char *setcrule = (char*) malloc(2);
                    setcrule[0] = crule;
                    setcrule[1] = '\0';
                    unionset(currentfirstset->set, setcrule);
                } else if ((notterminalset = seekkey(head,crule)) != NULL) {
                    char *newfirst = (char *) malloc(500);
                    strcpy(newfirst, "");
                    copysetwithoutempty(notterminalset->set, newfirst);
                    unionset(currentfirstset->set, newfirst);

                    int i = 0;
                    int todostemvazio;
                    while ( i < strlen(currentrule->rule) && isupper(currentrule->rule[i]) && (notterminalset = seekkey(head,crule)) != NULL && containinset(notterminalset->set, CARACTER_VAZIO))
                    {i++;} //Nao precisa de nada aqui dentro mesmo
                    todostemvazio = (i+1) == strlen(currentrule->rule);
                    if (todostemvazio)
                        unionset(currentfirstset->set, "*");


                }

                if (containinset(currentrule->rule, CARACTER_VAZIO))
                    unionset(currentfirstset->set, "*");

            }

            int t;
            if (!mudou)
            {
                t = strlen(currentfirstset->set);
                if  (beforelength != t)
                    mudou = true;
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

void copysetwithoutempty(char *setsource, char *setdestination)
{
    int j= 0;
    for (int i = 0; i < strlen(setsource); i++) {
        if(setsource[i] == CARACTER_VAZIO)
            continue;

        setdestination[j] = setsource[i];
        setdestination[j+1] = '\0';
        j++;
    }



    return;
}

void copyset(char *setsource, char *setdestination)
{
    int i;
    for (i = 0; i < strlen(setsource); i++) {
        setdestination[i] = setsource[i];
        setdestination[i+1] = '\0';
    }

    setdestination[i] = '\0';

    return;
}


void unionset(char *setsource1, char *setsource2)
{
    char *newset2 = (char*) malloc(500);
    strcpy(newset2, "");
    copysetwithoutempty(setsource2, newset2);

    int endindexsetsource1 = strlen(setsource1);
    for (int i = 0; i < strlen(newset2); i++) {
        if(containinset(setsource1, newset2[i]))
            continue;

        setsource1[endindexsetsource1] = newset2[i];
        setsource1[endindexsetsource1+1] = '\0';
        endindexsetsource1++;
    }

    setsource1[endindexsetsource1] = '\0';

    return;
}

void queuingpointer(FirstSet *head, FirstSet *current)
{

    if (head == NULL)
        return;

    FirstSet *p = head;
    while (p->next != NULL)
        p = p->next;

    p->next = current;

}


