//
// Created by sutil on 13/10/16.
//

#ifndef PREDICTIONTABLE_FOLLOW_H
#define PREDICTIONTABLE_FOLLOW_H

#include "conjunto.h"
#include "readgrammar.h"
#include "first.h"

struct followset
{
    struct followset *next;
    char *set;
    char key;
};

typedef struct followset FollowSet;


Conjunto* follow(GrammarRule* gramaticalRules, FirstSet* firstSet);

#endif //PREDICTIONTABLE_FOLLOW_H
