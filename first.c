//
// Created by Lucas on 10/15/2016.
//

#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include "first.h"
#include "grammar.h"

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
                currentfirstset->set = (char*) malloc(TAMANHO_MAXIMO_DA_REGRA);
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
                    char *newfirst = (char *) malloc(TAMANHO_MAXIMO_DA_REGRA);
                    strcpy(newfirst, "");
                    copysetwithoutempty(notterminalset->set, newfirst);
                    unionset(currentfirstset->set, newfirst);

                    int i = 0;
                    while ( i < (strlen(currentrule->rule) - 1) && isupper(currentrule->rule[i]) && (notterminalset = seekkey(head,currentrule->rule[i])) != NULL && containinset(notterminalset->set, CARACTER_VAZIO))
                    {
                        if ((notterminalset = seekkey(head,currentrule->rule[i + 1])) != NULL)
                        {
                            char *newfirst = (char *) malloc(TAMANHO_MAXIMO_DA_REGRA);
                            strcpy(newfirst, "");
                            copysetwithoutempty(notterminalset->set, newfirst);
                            unionset(currentfirstset->set,newfirst);
                        }
                        i++;
                    }

                    if (i == strlen(currentrule->rule) && (notterminalset = seekkey(head,currentrule->rule[i + 1])) != NULL && containinset(notterminalset->set, CARACTER_VAZIO))
                        unionset(currentfirstset->set, "*");
                }

                if (containinset(currentrule->rule, CARACTER_VAZIO))
                    unionset(currentfirstset->set, "*");

            }


            if (!mudou)
                mudou = beforelength != strlen(currentfirstset->set);

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

    int endindexsetsource1 = strlen(setsource1);
    for (int i = 0; i < strlen(setsource2); i++) {
        if(containinset(setsource1, setsource2[i]))
            continue;

        setsource1[endindexsetsource1] = setsource2[i];
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


