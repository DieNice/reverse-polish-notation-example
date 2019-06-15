//
// Created by pda on 31.05.19.
//

#ifndef RPN_DTORPN_H
#define RPN_DTORPN_H

#include "AbstractOperation.h"
#include <vector>
#include <string.h>

using namespace std;

struct node {
    float *val;
    char *sign;
    bool state; //1-val 0 -sign operation
};

class DtoRpn {
private:
    vector<node> chain_nodes;
public:
    int add_node(node);

    int get_size();

    node get_node(int);


};


#endif //RPN_DTORPN_H
