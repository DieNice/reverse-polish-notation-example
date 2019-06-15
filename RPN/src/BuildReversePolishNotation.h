//
// Created by pda on 24.05.19.
//

#ifndef RPN_BUILDREVERSEPOLISHNOTATION_H
#define RPN_BUILDREVERSEPOLISHNOTATION_H

#include "CollectionOperations.h"
#include <string>
#include <stack>

#include "Checker.h"
#include "DtoRpn.h"

using namespace std;

class BuildReversePolishNotation {
private:
    CollectionOperations collectionOperations;

public:

    bool set_operations(CollectionOperations &);

    DtoRpn *get_rpn(string);

};


#endif //RPN_BUILDREVERSEPOLISHNOTATION_H
