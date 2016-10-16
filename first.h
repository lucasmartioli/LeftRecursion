//
// Created by Lucas on 10/15/2016.
//

#ifndef PREDICTIONTABLE_FIRST_H
#define PREDICTIONTABLE_FIRST_H

    #include "readgrammar.h"

    struct firstset
    {
        struct firstset *next;
        char *set;
        char key;
    };

    typedef struct firstset FirstSet;

    FirstSet *first(GrammarRule *headgramaticalrule);
    int containinset(char *rule, char c);
    void copysetwithoutempty(char *setsource, char *setdestination);
    void copyset(char *setsource, char *setdestination);
    void unionset(char *setsource1, char *setsource2);
    FirstSet *seekkey(FirstSet *firstset, char key);
    void queuingpointer(FirstSet *head, FirstSet *current);

#endif //PREDICTIONTABLE_FIRST_H
