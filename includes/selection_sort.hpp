#ifndef __SELECTION_SORT_HPP__
#define __SELECTION_SORT_HPP__

#include "sort.hpp"
#include "container.hpp"

class SelectionSort : public Sort {
public:
    SelectionSort();

    void sort(Container* container);
};
#endif
