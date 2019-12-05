#ifndef __EVALUATE_DECORATOR_TEST_HPP__
#define __EVALUATE_DECORATOR_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "Abs.hpp"
#include "Ceil.hpp"
#include "Floor.hpp"
#include "Add.hpp"
#include "Mult.hpp"
#include "Sub.hpp"

Base* setupEquation() {
    Op* sevenFive = new Op(7.5);
    Op* oneOne = new Op(1.1);
    Op* five = new Op(5);
    Op* half = new Op(0.5);
    Op* fortyFive = new Op(45.4);

    Add* add = new Add(sevenFive, oneOne);
    Mult* mult = new Mult(add, five);
    Add* add2 = new Add(mult, half);
    Sub* sub = new Sub(add2, fortyFive);

    return sub;
}

TEST(EvaluateTestSet, FloorTest) {
    Base* equation = setupEquation();
    Floor* f = new Floor(equation);
    EXPECT_EQ(f->evaluate(), -2);
}

TEST(EvaluateTestSet, CeilTest) {
    Base* equation = setupEquation();
    Ceil* c = new Ceil(equation);
    EXPECT_EQ(c->evaluate(), -1);
}

TEST(EvaluateTestSet, CrossTest) {
    Base* equation = setupEquation();
    Ceil* c = new Ceil(equation);
    Abs* a = new Abs(c);
    EXPECT_EQ(a->evaluate(), 1);
}

#endif


