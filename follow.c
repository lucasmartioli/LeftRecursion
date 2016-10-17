//
// Created by Lucas on 10/16/2016.
//

#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "readgrammar.h"
#include "grammar.h"
#include "follow.h"
#include "first.h"

FollowSet *pesquisaConjuntoFollow(FollowSet* head, char key)
{
    FollowSet* pesquisa = head;
    while (pesquisa != NULL && pesquisa->key != key)
        pesquisa = pesquisa->next;

    return pesquisa;
}

FollowSet *criaConjuntosFollow(GrammarRule *gramaticalRules){
    FollowSet* head = NULL;
    GrammarRule* atual = gramaticalRules;
    while (atual != NULL){
        FollowSet *f = pesquisaConjuntoFollow(head, atual->key);
        if (f == NULL) {
            f = (FollowSet *) malloc(sizeof(FollowSet));
            f->key = atual->key;
            f->set = (char *) malloc(TAMANHO_MAXIMO_DA_REGRA);
            if(f->key == 'S')
            {
                f->set[0] = '$';
                f->set[1] = '\0';
            } else {
                f->set[0] = '\0';
            }

            f->next = NULL;

            if (head == NULL)
                head = f;
            else
            {
                FollowSet *ff = head;
                while (ff->next != NULL)
                {
                    ff = ff->next;
                }
                ff->next = f;
            }
        }

        atual = atual->next;
    }
    return head;
}

FirstSet *seekkeyfirst(FirstSet *firstset, char key)
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

FollowSet *follow(GrammarRule *gramaticalRules, FirstSet* firstset) {

    FollowSet *head = criaConjuntosFollow(gramaticalRules);

    int mudou;
    do {
        mudou = false;
        GrammarRule *atual = gramaticalRules;
        while (atual != NULL) {
            char *rule = atual->rule;
            char *rhs = (char *) malloc(TAMANHO_MAXIMO_DA_REGRA);
            FollowSet *currentfollowset = pesquisaConjuntoFollow(head, atual->key);
            if (currentfollowset != NULL)
                copyset(currentfollowset->set, rhs);
            else
                rhs[0] = '\0';

            for (int i = strlen(rule) - 1; i >= 0; i--) {
                char simbolo = rule[i];
                if (isupper(simbolo)) {
                    FollowSet *newfollowset = pesquisaConjuntoFollow(head, simbolo);
                    int beforelength = strlen(newfollowset->set);
                    unionset(newfollowset->set, rhs);
                    FirstSet *simbolofirstset = seekkeyfirst(firstset, simbolo);
                    copysetwithoutempty(simbolofirstset->set, rhs);
                    if (!mudou)
                        mudou = beforelength != strlen(newfollowset->set);
                } else if (simbolo != CARACTER_VAZIO && simbolo != CARACTER_FINAL_ARQUIVO) {
                    char *newsimb = (char*) malloc(2);
                    newsimb[0] = simbolo;
                    newsimb[1] = '\0';
                    rhs = newsimb;
                }
            }

            atual = atual->next;
        }
    } while (mudou);

    return head;
}