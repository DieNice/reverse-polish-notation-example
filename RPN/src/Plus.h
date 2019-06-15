//
// Created by pda on 26.05.19.
//

#ifndef RPN_PLUS_H
#define RPN_PLUS_H

#include "AbstractOperation.h"

class Plus : public AbstractOperation {
public:
    Plus(char s, int p) : AbstractOperation(s,p) {

    };

    float culculate(float, float) override;

};


#endif //RPN_PLUS_H
