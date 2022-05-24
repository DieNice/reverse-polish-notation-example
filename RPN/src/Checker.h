//
// Created by pda on 24.05.19.
//

#ifndef RPN_CHECKER_H
#define RPN_CHECKER_H

#include <string.h>
#include "CollectionOperations.h"

using namespace std;

class Checker {
private:
    CollectionOperations collectionOperations;

public:

    bool set_operations(CollectionOperations);
    bool check(char*);
};


#endif //RPN_CHECKER_H
