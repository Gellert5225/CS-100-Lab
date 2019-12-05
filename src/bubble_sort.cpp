#include "../includes/bubble_sort.hpp"
#include <iostream>
BubbleSort::BubbleSort() {}

void BubbleSort::sort(Container* container) {
    int n = container->size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (container->at(j)->evaluate() > container->at(j + 1)->evaluate()) {
                container->swap(j, j + 1);
            }
        }
    }
}
