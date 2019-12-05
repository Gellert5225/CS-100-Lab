#include "../includes/VectorContainer.hpp"

VectorContainer::VectorContainer() {
    sort_function = nullptr;
}

VectorContainer::VectorContainer(Sort* function) {
    sort_function = function;
}

void VectorContainer::set_sort_function(Sort* sort_function) {
    this->sort_function = sort_function;
}

void VectorContainer::add_element(Base* element) {
    vec.push_back(element);
}

void VectorContainer::print() {
    for (auto e : vec)
        std::cout << e->stringify() << " ";
}

void VectorContainer::sort() {
    if (sort_function == nullptr)
        throw "ACCESS VIOLATION: sort_function is NULL";
    sort_function->sort(this);
}

void VectorContainer::swap(int i, int j) {
    Base* temp;
    temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}

Base* VectorContainer::at(int i) {
    return vec[i];
}

int VectorContainer::size() {
    return vec.size();
}
