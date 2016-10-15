//
// Created by Lucas on 10/15/2016.
//

#include "first.h"

FirstSet *first(GramaticalRule *gramaticalrule)
{
    int mudou = 0;
    do
    {
        GramaticalRule currentrule = gramaticalrule;
        while (currentrule != NULL)
        {

            currentrule = currentrule.next;
        }


    } while (mudou);

}
