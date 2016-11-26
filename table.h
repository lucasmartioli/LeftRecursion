//
// Created by Lucas on 11/26/2016.
//

#ifndef PREDICTIONTABLE_TABLE_H
#define PREDICTIONTABLE_TABLE_H

#define TAMANHO_MAXIMO_DA_PRODUCAO 500

#include "first.h"
#include "grammar.h"
#include "follow.h"

struct producao
{
    struct producao *next;
    char *p;
};

typedef struct producao Producao;


void addList(char *List, const char NT);
void table(GrammarRule *gramaticalRules, FollowSet* followSet, FirstSet* firstset);

#endif //PREDICTIONTABLE_TABLE_H
