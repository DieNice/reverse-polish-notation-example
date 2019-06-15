//
// Created by pda on 31.05.19.
//

#include "DtoRpn.h"

int DtoRpn::add_node(node object) {
    chain_nodes.push_back(object);
}

node DtoRpn::get_node(int k) {
    return chain_nodes.at(k);
}

int DtoRpn::get_size() {
    return chain_nodes.size();
}