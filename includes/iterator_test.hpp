#ifndef __ITERATOR_TEST_HPP__
#define __ITERATOR_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "Abs.hpp"
#include "Ceil.hpp"
#include "Floor.hpp"
#include "Add.hpp"
#include "Mult.hpp"
#include "Sub.hpp"
#include "ParseFactory.hpp"

Base* setup() {
    char* argv[] = {"calculator", "1", "*", "2", "+", "3", "-", "4"};

    Parse *p = new Parse();
    return p->parse(argv, 8);
}

Base* setupUnary() {
    char* argv[] = {"calculator", "abs", "-5"};

    Parse *p = new Parse();
    return p->parse(argv, 3);
}

Base* setupNull() {
    char* argv[] = {"calculator", "-5"};

    Parse *p = new Parse();
    return p->parse(argv, 2);
}

/*Binary Operator*/

// current()
TEST(IteratorTestSet_Binary, Test_current_1) {
    BinaryIterator* binaryIter = new BinaryIterator(setup());
    EXPECT_EQ(binaryIter->current()->stringify(), "1 * 2 + 3");
}

TEST(IteratorTestSet_Binary, Test_current_2) {
    BinaryIterator* binaryIter = new BinaryIterator(setup()->get_left());
    EXPECT_EQ(binaryIter->current()->stringify(), "1 * 2");
}

TEST(IteratorTestSet_Binary, Test_current_null) {
    BinaryIterator* binaryIter = new BinaryIterator(setup()->get_right());
    EXPECT_EQ(binaryIter->current(), nullptr);
}

// next()
TEST(IteratorTestSet_Binary, Test_next_1) {
    BinaryIterator* binaryIter = new BinaryIterator(setup());
    binaryIter->next();
    EXPECT_EQ(binaryIter->current()->stringify(), "4");
}

TEST(IteratorTestSet_Binary, Test_next_null) {
    BinaryIterator* binaryIter = new BinaryIterator(setup());
    binaryIter->next();
    binaryIter->next();
    EXPECT_EQ(binaryIter->current(), nullptr);
}

// is_done()
TEST(IteratorTestSet_Binary, Test_is_done_1) {
    BinaryIterator* binaryIter = new BinaryIterator(setup());
    EXPECT_EQ(binaryIter->is_done(), false);
}

TEST(IteratorTestSet_Binary, Test_is_done_2) {
    BinaryIterator* binaryIter = new BinaryIterator(setup());
    binaryIter->next();
    EXPECT_EQ(binaryIter->is_done(), false);
}

TEST(IteratorTestSet_Binary, Test_is_done_3) {
    BinaryIterator* binaryIter = new BinaryIterator(setup());
    binaryIter->next();
    binaryIter->next();
    EXPECT_EQ(binaryIter->is_done(), true);
}

/*Unary Operator*/

// current()
TEST(IteratorTestSet_Unary, Test_current_1) {
    UnaryIterator* unaryIter = new UnaryIterator(setupUnary());
    EXPECT_EQ(unaryIter->current()->stringify(), "-5");
}

TEST(IteratorTestSet_Unary, Test_current_null) {
    UnaryIterator* unaryIter = new UnaryIterator(setupUnary()->get_right());
    EXPECT_EQ(unaryIter->current(), nullptr);
}

// next()
TEST(IteratorTestSet_Unary, Test_next_null) {
    UnaryIterator* unaryIter = new UnaryIterator(setupUnary());
    unaryIter->next();
    EXPECT_EQ(unaryIter->current(), nullptr);
}

// is_done()
TEST(IteratorTestSet_Unary, Test_is_done_1) {
    UnaryIterator* unaryIter = new UnaryIterator(setupUnary());
    EXPECT_EQ(unaryIter->is_done(), false);
}

TEST(IteratorTestSet_Unary, Test_is_done_2) {
    UnaryIterator* unaryIter = new UnaryIterator(setupUnary());
    unaryIter->next();
    EXPECT_EQ(unaryIter->is_done(), true);
}

/*Null Iterator*/

// current()
TEST(IteratorTestSet_Null, Test_current_1) {
    NullIterator* nullIter = new NullIterator(setupUnary());
    EXPECT_EQ(nullIter->current(), nullptr);
}

// is_done()
TEST(IteratorTestSet_Null, Test_is_done_1) {
    NullIterator* nullIter = new NullIterator(setupUnary());
    EXPECT_EQ(nullIter->is_done(), true);
}

#endif