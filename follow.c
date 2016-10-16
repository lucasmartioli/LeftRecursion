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

struct mudanca
{
    struct mudanca *next;
    int tamanho;
    char key;
};

typedef struct mudanca Mudanca;

char keyAtual;
int quantidadeDeproducoes = 0;
FollowSet *f;
Mudanca *m;
FirstSet *firsts;


Mudanca *criaMudancas(GrammarRule *grammarRule){
    GrammarRule *atual = grammarRule;
    if (atual != NULL) {
        m->key = atual->key;
        m->tamanho = 0;
        m->next = criaMudancas(atual->next);
        return m;
    }
    return NULL;
}

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

Mudanca *getMudanca(char key){
    Mudanca *pesquisa = m;
    while (pesquisa != NULL){
        if(pesquisa->key ==  key)
            return pesquisa;
    }
    return NULL;
}

int houveMudancas(){
    int mudou = 0;
    FollowSet *conjuntosFollow = f;
    while(conjuntosFollow != NULL){
        Mudanca *m = getMudanca(f->key);
        if(m->tamanho != strlen(f->set)) {
            mudou = 1;
            m->tamanho = strlen(f->set);
        }
    }
}


FollowSet *follow(GrammarRule *gramaticalRules, FirstSet *firstSet) {
    firsts = firstSet;
    criaConjuntosFollow(gramaticalRules);
    criaMudancas(gramaticalRules);

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


    return f;
}