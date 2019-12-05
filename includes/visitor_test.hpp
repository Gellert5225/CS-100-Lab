#ifndef __VISITOR_TEST_HPP__
#define __VISITOR_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "Abs.hpp"
#include "Ceil.hpp"
#include "Floor.hpp"
#include "Add.hpp"
#include "Mult.hpp"
#include "Sub.hpp"
#include "ParseFactory.hpp"
#include "visitor.hpp"

CountVisitor* setupComposite() {
    char* argv[] = {"calculator", "1", "*", "2", "+", "3", "-", "4"};

    Parse *p = new Parse();
    Base* b = p->parse(argv, 8);

    CountVisitor* cv = new CountVisitor();
    b->accept(cv);
    b->get_left()->accept(cv);
    b->get_left()->get_left()->accept(cv);

    return cv;
}

CountVisitor* setupDecorator() {
    char* argv[] = {"calculator", "1", "*", "abs", "2", "+", "ceil", "3"};

    Parse *p = new Parse();
    Base* b = p->parse(argv, 8);

    CountVisitor* cv = new CountVisitor();
    b->accept(cv);
    b->get_right()->accept(cv);
    b->get_left()->get_right()->accept(cv);

    return cv;
}

TEST(VisitorTestSet, Composite_add) {
    EXPECT_EQ(setupComposite()->add_count(), 1);
}

TEST(VisitorTestSet, Composite_sub) {
    EXPECT_EQ(setupComposite()->sub_count(), 1);
}

TEST(VisitorTestSet, Composite_mult) {
    EXPECT_EQ(setupComposite()->mult_count(), 1);
}

TEST(VisitorTestSet, Decorator_ceil) {
    EXPECT_EQ(setupDecorator()->ceil_count(), 1);
}

TEST(VisitorTestSet, Decorator_floor) {
    EXPECT_EQ(setupDecorator()->floor_count(), 0);
}

TEST(VisitorTestSet, Decorator_abs) {
    EXPECT_EQ(setupDecorator()->abs_count(), 1);
}

#endif
