//
// Created by Lucas on 10/15/2016.
//

#ifndef PREDICTIONTABLE_FIRST_H
#define PREDICTIONTABLE_FIRST_H

    #include "readgramar.h"

    struct firstset
    {
        struct firstset *next;
        char *set;
        char key;
    };

    typedef struct firstset FirstSet;

    FirstSet *first(GramaticalRule *headgramaticalrule);
    int containinset(char *rule, char c);
    void copyrulewithoutempty(char *rulesource, char *ruledestination);
    void copyrule(char *rulesource, char *ruledestination);
    void unionset(char *setsource1, char *setsource2);
    FirstSet *seekkey(FirstSet *firstset, char key);

#endif //PREDICTIONTABLE_FIRST_H
