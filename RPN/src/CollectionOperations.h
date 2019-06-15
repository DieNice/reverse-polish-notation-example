//
// Created by pda on 25.05.19.
//

#ifndef RPN_COLLECTIONOPERATIONS_H
#define RPN_COLLECTIONOPERATIONS_H

#include <vector>
#include "AbstractOperation.h"

class CollectionOperations {
private:
    std::vector<AbstractOperation *> Collection;

public:
    int add(AbstractOperation *opr);

    bool is_empty();

    int del();

    int get_size();

    AbstractOperation *get_operation(char);

    bool have_symbol(char);

};


#endif //RPN_COLLECTIONOPERATIONS_H
