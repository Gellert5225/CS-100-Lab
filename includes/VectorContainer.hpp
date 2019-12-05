#ifndef __VECTOR_CONTAINER_HPP__
#define __VECTOR_CONTAINER_HPP__

#include "sort.hpp"
#include "container.hpp"
#include <iostream>
#include <vector>

class VectorContainer : public Container {
public:
    VectorContainer(); 
    VectorContainer(Sort* function);
    
    void set_sort_function(Sort* sort_function);

    void add_element(Base* element);

    void print();

    void sort();
    
    // helper functions
    void swap(int i, int j);

    Base* at(int i);

    int size();

private:
    std::vector<Base*> vec;
};

#endif

