//
// Created by pda on 26.05.19.
//

#ifndef RPN_MINUS_H
#define RPN_MINUS_H

#include "AbstractOperation.h"

class Minus : public AbstractOperation {
public:
    Minus(char s, int p) : AbstractOperation(s, p) {

    };

    float culculate(float, float) override;
};


#endif //RPN_MINUS_H
