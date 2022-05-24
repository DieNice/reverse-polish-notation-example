//
// Created by pda on 26.05.19.
//

#ifndef RPN_MULTIPLICATION_H
#define RPN_MULTIPLICATION_H

#include "AbstractOperation.h"

class Multiplication : public AbstractOperation {
public:
    Multiplication(char s, int p) : AbstractOperation(s, p) {

    };

    float culculate(float, float) override;
};


#endif //RPN_MULTIPLICATION_H
