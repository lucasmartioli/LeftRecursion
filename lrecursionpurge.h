//
// Created by Lucas on 1/2/2017.
//

#ifndef PREDICTIONTABLE_LRECURSIONPURGE_H
#define PREDICTIONTABLE_LRECURSIONPURGE_H

#include "readgrammar.h"

bool lrecursionpurge(GrammarRule* s);
void addNewRecursion(char k, char newk, GrammarRule* s);

#endif //PREDICTIONTABLE_LRECURSIONPURGE_H
