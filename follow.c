//
// Created by sutil on 13/10/16.
//

#include <malloc.h>
#include <string.h>
#include "readgrammar.h"
#include "conjunto.h"
#include "follow.h"
#include <regex.h>

Conjunto conjunto;
Conjunto *conjuntos;

char keyAtual;
int quantidadeDeproducoes = 0;
FollowSet *f;

int isTerminal(char producao){
    char *str = &producao;
    size_t maxGroup = 1;
    regmatch_t groupArray[maxGroup];

    regex_t regex;
    if(regcomp(&regex, "[a-z]", REG_EXTENDED))
        printf("Erro ao compilar regex");

    return !(regexec(&regex, str, maxGroup, groupArray, 0));
}

FollowSet *criaConjuntosFollow(GrammarRule *gramaticalRules){
    GrammarRule* atual = gramaticalRules;
    if(atual != NULL){
        f = (FollowSet*) malloc(sizeof(FollowSet));
        f->key = atual->key;
        f->set = "";
        f->next = criaConjuntosFollow(atual->next);
        return f;
    }
    return NULL;
}

FollowSet *pesquisaConjuntoFollow(char key){
    FollowSet *pesquisa = f;
    while (pesquisa != NULL && pesquisa->key != key)
        pesquisa = pesquisa->next;

    return pesquisa;
}

void addFollow(char key, char simbolo){
    FollowSet *followSet = pesquisaConjuntoFollow(key);
    followSet->set = strcat(followSet->set, &simbolo);
}

char getFirst(char simbolo){
    return '\0';
}


Conjunto *follow(GrammarRule *gramaticalRules) {

    criaConjuntosFollow(gramaticalRules);

    int mudou = 0;
    GrammarRule *atual = gramaticalRules;
    while(atual != NULL) {
        char *rule = atual->rule;
        int qtdeSimbolos = sizeof(rule);
        for (int i = 0; i < qtdeSimbolos; ++i) {
            char simbolo = rule[i];
            if (!isTerminal(simbolo)) {
                char proximo = rule[i + 1];
                if (proximo != '\0') {
                    if (isTerminal(proximo))
                        addFollow(simbolo, proximo);
                    else
                        addFollow(simbolo, getFirst(proximo));
                }
            }
        }
    }




    return NULL;
}