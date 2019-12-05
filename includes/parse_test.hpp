#ifndef __PARSE_TEST_HPP__
#define __PARSE_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "Abs.hpp"
#include "Ceil.hpp"
#include "Floor.hpp"
#include "Add.hpp"
#include "Mult.hpp"
#include "Sub.hpp"
#include "ParseFactory.hpp"

TEST(ParseTestSet_Simple, Test_1) {
    char* argv[] = {"calculator", "1", "*", "2"};

    Parse *p = new Parse();

    EXPECT_EQ(p->parse(argv, 4)->evaluate(), 2);
}

TEST(ParseTestSet_Simple, Test_1_2) {
    char* argv[] = {"calculator", "1", "*", "2"};

    Parse *p = new Parse();

    EXPECT_EQ(p->parse(argv, 4)->stringify(), "1 * 2");
}

TEST(ParseTestSet_Complex, Test_2) {
    char* argv[] = {"calculator", "1", "*", "2", "+", "3", "-", "4"};

    Parse *p = new Parse();

    EXPECT_EQ(p->parse(argv, 8)->evaluate(), 1);
}

TEST(ParseTestSet_Complex, Test_2_2) {
    char* argv[] = {"calculator", "1", "*", "2", "+", "3", "-", "4"};

    Parse *p = new Parse();

    EXPECT_EQ(p->parse(argv, 8)->stringify(), "1 * 2 + 3 - 4");
}

TEST(ParseTestSet_NULL, Test_3) {
    char* argv[] = {"calculator", "*", "2", "+", "3", "-", "4"};

    Parse *p = new Parse();

    EXPECT_EQ(p->parse(argv, 7), nullptr);
}

TEST(ParseTestSet_NULL, Test_3_2) {
    char* argv[] = {"calculator", "1", "*", "2", "+", "3", "-"};

    Parse *p = new Parse();

    EXPECT_EQ(p->parse(argv, 7), nullptr);
}

#endif