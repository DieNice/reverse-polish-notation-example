#include "gtest/gtest.h"

#include "src/BuildReversePolishNotation.h"
#include "src/Calculator.h"
#include "src/CollectionOperations.h"
#include "src/Plus.h"
#include "src/Minus.h"
#include "src/Multiplication.h"
#include "src/Division.h"

TEST(RPNTest, normal_test) {

    CollectionOperations collectionOperations;
    BuildReversePolishNotation buildReversePolishNotation;
    Calculator calculator;

    collectionOperations.add(new Plus('+', 2));
    collectionOperations.add(new Minus('-', 2));
    collectionOperations.add(new Multiplication('*', 3));
    collectionOperations.add(new Division('/', 3));

    buildReversePolishNotation.set_operations(collectionOperations);
    calculator.set_operations(collectionOperations);


    ASSERT_FLOAT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("0/2"))->get_val(), 0);
    ASSERT_FLOAT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("0-2"))->get_val(), -2);
    ASSERT_FLOAT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("0+2"))->get_val(), 2);
    ASSERT_FLOAT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("0*2"))->get_val(), 0);

    ASSERT_FLOAT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("2+2"))->get_val(), 4);
    ASSERT_FLOAT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("2-2"))->get_val(), 0);
    ASSERT_FLOAT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("3/2"))->get_val(), 1.5);
    ASSERT_FLOAT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("3*2"))->get_val(), 6);
    ASSERT_FLOAT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("(2+2)"))->get_val(), 4);
    ASSERT_FLOAT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("(2+2)-3"))->get_val(), 1);
    ASSERT_FLOAT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("0*(0+3-4/2)"))->get_val(), 0);
    ASSERT_FLOAT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("((2+2)-3*2)/4"))->get_val(), -0.5);
    ASSERT_FLOAT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("(2+3-4/2)"))->get_val(), 3);

    ASSERT_FLOAT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("(2*(2*(2*(2*(2*(2-2))))))"))->get_val(),
                    0);
    ASSERT_FLOAT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("(1+(2-(3*(4/5))))"))->get_val(), 0.6);
    ASSERT_FLOAT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("2*(2+2)"))->get_val(), 8);
    ASSERT_FLOAT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("2*2+2"))->get_val(), 6);
    ASSERT_FLOAT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("2+2*2"))->get_val(), 6);

}

TEST(RPNTest, critical_test) {

    CollectionOperations collectionOperations;

    collectionOperations.add(new Plus('+', 2));
    collectionOperations.add(new Minus('-', 2));
    collectionOperations.add(new Multiplication('*', 3));
    collectionOperations.add(new Division('/', 3));

    BuildReversePolishNotation buildReversePolishNotation;
    Calculator calculator;

    buildReversePolishNotation.set_operations(collectionOperations);

    calculator.set_operations(collectionOperations);


    ASSERT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("(())"))->get_err(), true);

    ASSERT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("0"))->get_err(), true);
    ASSERT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("2"))->get_err(), true);
    ASSERT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("((2))"))->get_err(), true);

    ASSERT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("-3"))->get_err(), true);
    ASSERT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("2*-3"))->get_err(), true);
    ASSERT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("+3"))->get_err(), true);
    ASSERT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("-3"))->get_err(), true);
    ASSERT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("*3"))->get_err(), true);
    ASSERT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("/3"))->get_err(), true);

    ASSERT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("3+"))->get_err(), true);
    ASSERT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("3-"))->get_err(), true);
    ASSERT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("3*"))->get_err(), true);
    ASSERT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("3/"))->get_err(), true);

    ASSERT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("(2+3))"))->get_err(), true);
    ASSERT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("(((2+3)"))->get_err(), true);
    ASSERT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("777/0"))->get_err(), true);
    ASSERT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("0/0"))->get_err(), true);
    ASSERT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn(""))->get_err(), true);

    ASSERT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("1/(2-(2*2-2))"))->get_err(), true);
    ASSERT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("1/(2-(2*2-2))"))->get_err(), true);

    ASSERT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("1/(2-(2*2gs-2))"))->get_err(), true);
    ASSERT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("1/(2-(2**2-2))"))->get_err(), true);
    ASSERT_EQ(calculator.culculate(buildReversePolishNotation.get_rpn("1!(2-(2**2-2))"))->get_err(), true);
}
