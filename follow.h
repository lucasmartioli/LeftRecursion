//
// Created by Lucas on 10/16/2016.
//

#ifndef PREDICTIONTABLE_FOLLOW2_H
#define PREDICTIONTABLE_FOLLOW2_H

#include "first.h"

struct followset
{
    struct followset *next;
    char *set;
    char key;
};

typedef struct followset FollowSet;
FollowSet *follow(GrammarRule *gramaticalRules, FirstSet* firstset);
FirstSet *seekkeyfirst(FirstSet *firstset, char key);
FollowSet *pesquisaConjuntoFollow(FollowSet* head, char key);

#endif //PREDICTIONTABLE_FOLLOW2_H
