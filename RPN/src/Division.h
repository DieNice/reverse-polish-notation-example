//
// Created by pda on 26.05.19.
//

#ifndef RPN_DIVISION_H
#define RPN_DIVISION_H

#include "AbstractOperation.h"

class Division : public AbstractOperation {
public:
    Division(char s, int p) : AbstractOperation(s, p) {

    };

    float culculate(float, float) override;

};


#endif //RPN_DIVISION_H
