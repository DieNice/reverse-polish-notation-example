#include <iostream>
#include <string.h>

#include "src/BuildReversePolishNotation.h"
#include "src/Calculator.h"
#include "src/CollectionOperations.h"
#include "src/Plus.h"
#include "src/Minus.h"
#include "src/Multiplication.h"
#include "src/Division.h"

using namespace std;

int main() {
    string input_string;
    cin >> input_string;

    CollectionOperations collectionOperations;
    BuildReversePolishNotation buildReversePolishNotation;
    Calculator calculator;

    collectionOperations.add(new Plus('+', 2));
    collectionOperations.add(new Minus('-', 2));
    collectionOperations.add(new Multiplication('*', 3));
    collectionOperations.add(new Division('/', 3));


    buildReversePolishNotation.set_operations(collectionOperations);

    calculator.set_operations(collectionOperations);

    cout << calculator.culculate(buildReversePolishNotation.get_rpn(input_string));


    return 0;
}