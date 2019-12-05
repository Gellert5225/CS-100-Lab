#ifndef __BUBBLE_SORT_HPP__
#define __BUBBLE_SORT_HPP__

#include "sort.hpp"
#include "container.hpp"

class BubbleSort : public Sort {
public:
    BubbleSort();

    void sort(Container* container);
};

#endif
