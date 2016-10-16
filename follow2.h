//
// Created by Lucas on 10/16/2016.
//

#ifndef PREDICTIONTABLE_FOLLOW2_H
#define PREDICTIONTABLE_FOLLOW2_H

struct followset
{
    struct followset *next;
    char *set;
    char key;
};

typedef struct followset FollowSet;


#endif //PREDICTIONTABLE_FOLLOW2_H
