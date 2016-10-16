//
// Created by sutil on 13/10/16.
//

#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include "readgrammar.h"
#include "conjunto.h"
#include "follow.h"
//#include <regex.h>

Conjunto conjunto;
Conjunto *conjuntos;

char keyAtual;
int quantidadeDeproducoes = 0;
FollowSet *f;
FirstSet *firsts;


//int isTerminal(char producao){
//    char *str = &producao;
//    size_t maxGroup = 1;
//    regmatch_t groupArray[maxGroup];
//
//    regex_t regex;
//    if(regcomp(&regex, "[a-z]", REG_EXTENDED))
//        printf("Erro ao compilar regex");
//
//    return !(regexec(&regex, str, maxGroup, groupArray, 0));
//}


FollowSet *criaConjuntosFollow(GrammarRule *gramaticalRules) {
    GrammarRule *atual = gramaticalRules;
    if (atual != NULL) {
        f = (FollowSet *) malloc(sizeof(FollowSet));
        f->key = atual->key;
        f->set = "";
        f->next = criaConjuntosFollow(atual->next);
        return f;
    }
    return NULL;
}

FollowSet *pesquisaConjuntoFollow(char key) {
    FollowSet *pesquisa = f;
    while (pesquisa != NULL && pesquisa->key != key)
        pesquisa = pesquisa->next;

    return pesquisa;
}

void addFollow(char key, char simbolo) {
    FollowSet *followSet = pesquisaConjuntoFollow(key);
    if(!containinset(followSet->set, simbolo))
        followSet->set = strcat(followSet->set, &simbolo);
}

void addFollows(char key, char *simbolo) {
    int tamanho = strlen(simbolo);
    for (int i = 0; i < tamanho; ++i)
        addFollow(key, simbolo[i]);

}

char *getFirst(char simbolo) {
    FirstSet *pesquisa = firsts;

    while (pesquisa != NULL && pesquisa->key != simbolo)
        pesquisa = pesquisa->next;
    return pesquisa->set;
}

int houveMudancas(){
    FollowSet *conjuntosFollow = f;

}


Conjunto *follow(GrammarRule *gramaticalRules, FirstSet *firstSet) {
    firsts = firstSet;
    criaConjuntosFollow(gramaticalRules);

    int mudou = 0;
    GrammarRule *atual = gramaticalRules;

    do {
        mudou = 0;
        while(atual != NULL) {
            char *rule = atual->rule;
            int qtdeSimbolos = sizeof(rule);
            for (int i = 0; i < qtdeSimbolos; ++i) {
                char simbolo = rule[i];
                if (isupper(simbolo)) {
                    char proximo = rule[i + 1];
                    if (proximo != '\0') {
                        if (islower(proximo))
                            addFollow(simbolo, proximo);
                        else
                            addFollows(simbolo, getFirst(proximo));
                    }
                }
            }
        }
        atual = gramaticalRules;

        mudou = houveMudancas();
    }while(mudou);


    return NULL;
}