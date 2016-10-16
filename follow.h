//
// Created by sutil on 13/10/16.
//

#ifndef PREDICTIONTABLE_FOLLOW_H
#define PREDICTIONTABLE_FOLLOW_H

#include "conjunto.h"
#include "readgramar.h"

struct followset
{
    struct followset *next;
    char *set;
    char key;
};

typedef struct followset FollowSet;

Conjunto *follow(GramaticalRule *gramaticalRules);

#endif //PREDICTIONTABLE_FOLLOW_H
