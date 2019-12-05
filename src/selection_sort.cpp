#include "../includes/selection_sort.hpp"

SelectionSort::SelectionSort() {}

void SelectionSort::sort(Container* container) {
    int minIndex;
    for (int i = 0; i < container->size() - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < container->size(); j++) {
            if (container->at(j)->evaluate() < container->at(minIndex)->evaluate()) 
                container->swap(minIndex, j);
        }
    }
}
