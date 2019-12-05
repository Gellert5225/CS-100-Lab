#ifndef __LIST_CONTAINER_TEST_HPP__
#define __LIST_CONTAINER_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "ListContainer.hpp"

ListContainer* setupList() {
    Op* seven = new Op(7);
    Op* six = new Op(6);
    Op* one = new Op(1);
    Op* three = new Op(3);
    Op* nine = new Op(9);
    
    // [7, 6, 1, 3, 7, 9]
    ListContainer* test = new ListContainer();
    test->add_element(seven);
    test->add_element(six);
    test->add_element(one);
    test->add_element(three);
    test->add_element(seven);
    test->add_element(nine);

    return test;
}

TEST(ListContainerTestSet, SwapTest) {
    ListContainer* test_container = setupList();
    // Exercise some functionality of hte test elements                 

    // Assert that the container has at least a single element
    ASSERT_EQ(test_container->size(), 6);

    test_container->swap(1, 3);

    EXPECT_EQ(test_container->at(1)->evaluate(), 3);
    EXPECT_EQ(test_container->at(3)->evaluate(), 6);
}

TEST(ListContainerTestSet, IndexTest) {
    ListContainer* test_container = setupList();
    EXPECT_EQ(test_container->at(0)->evaluate(), 7);
    EXPECT_EQ(test_container->at(1)->evaluate(), 6);
    EXPECT_EQ(test_container->at(2)->evaluate(), 1);
    EXPECT_EQ(test_container->at(3)->evaluate(), 3);
    EXPECT_EQ(test_container->at(4)->evaluate(), 7);
    EXPECT_EQ(test_container->at(5)->evaluate(), 9);
}

TEST(ListContainerTestSet, PrintTest) {
    ListContainer* test_container = setupList();
    std::cout << "EXPECTED: 7 6 1 3 7 9 " << std::endl;
    std::cout << "YOURS:    ";
    test_container->print();
}

#endif
