#ifndef __VECTOR_CONTAINER_TEST_HPP__
#define __VECTOR_CONTAINER_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "VectorContainer.hpp"

VectorContainer* setupVector() {
    Op* seven = new Op(7);
    Op* six = new Op(6);
    Op* one = new Op(1);
    Op* three = new Op(3);
    Op* nine = new Op(9);
    
    // [7, 6, 1, 3, 7, 9]
    VectorContainer* test = new VectorContainer();
    test->add_element(seven);
    test->add_element(six);
    test->add_element(one);
    test->add_element(three);
    test->add_element(seven);
    test->add_element(nine);

    return test;
}

TEST(VectorContainerTestSet, SwapTest) {
    VectorContainer* test_container = setupVector();
    // Exercise some functionality of hte test elements                 
    test_container->swap(1, 3);

    // Assert that the container has at least a single element
    ASSERT_EQ(test_container->size(), 6);
    EXPECT_EQ(test_container->at(1)->evaluate(), 3);
    EXPECT_EQ(test_container->at(3)->evaluate(), 6);
}

TEST(VectorContainerTestSet, IndexTest) {
    VectorContainer* test_container = setupVector();
    EXPECT_EQ(test_container->at(0)->evaluate(), 7);
    EXPECT_EQ(test_container->at(1)->evaluate(), 6);
    EXPECT_EQ(test_container->at(2)->evaluate(), 1);
    EXPECT_EQ(test_container->at(3)->evaluate(), 3);
    EXPECT_EQ(test_container->at(4)->evaluate(), 7);
    EXPECT_EQ(test_container->at(5)->evaluate(), 9);
}

TEST(VectorContainerTestSet, PrintTest) {
    VectorContainer* test_container = setupVector();
    std::cout << "EXPECTED: 7 6 1 3 7 9 " << std::endl;
    std::cout << "YOURS:    ";
    test_container->print();
}

#endif
