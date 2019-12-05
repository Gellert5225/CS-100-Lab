#ifndef __LIST_CONTAINER_HPP__
#define __LIST_CONTAINER_HPP__

#include "sort.hpp"
#include "container.hpp"
#include <iostream>
#include <list>

class ListContainer : public Container {
public:
    ListContainer();
    ListContainer(Sort* function);

    void set_sort_function(Sort* sort_function);

    void add_element(Base* element);

    void print();

    void sort();

    // helper functions
    void swap(int i, int j);

    Base* at(int i);

    int size();

private:
    std::list<Base*> list;
};

#endif
