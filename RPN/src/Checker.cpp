//
// Created by pda on 24.05.19.
//

#include "Checker.h"

bool Checker::check(char *data) {
    int len = strlen(data);
    bool flag = false;

    int open_bracket = 0;
    int close_bracket = 0;

    for (int i = 0; i < len; i++) {
        if (data[i] == ')') { open_bracket++; }
        if (data[i] == '(') { close_bracket++; }
    }

    bool have_operations = false;
    for (int i = 0; i < len; i++) {
        if (collectionOperations.have_symbol(data[i])) {
            have_operations = true;
            i = len;
        }
    }

    if (close_bracket != open_bracket) { return true; }
    if (have_operations == false) { return true; }

    for (int i = 0; i < len; i++) {
        if (!(data[i] >= '0' && data[i] <= '9') && collectionOperations.have_symbol(data[i]) == false) {
            if (data[i] != ')' && data[i] != '(') {
                flag = true;
            }
        }
    }
    return flag;

}

bool Checker::set_operations(CollectionOperations collection) {
    if (collection.is_empty())
        return 1;
    collectionOperations = collection;
}