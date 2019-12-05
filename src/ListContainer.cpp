#include "../includes/ListContainer.hpp"

ListContainer::ListContainer() {
    sort_function = nullptr;
}

ListContainer::ListContainer(Sort* function) {
    sort_function = function;
}

void ListContainer::set_sort_function(Sort* sort_function) {
    this->sort_function = sort_function;
}

void ListContainer::add_element(Base* element) {
    list.push_back(element);
}

void ListContainer::print() {
    for (auto l : list)
        std::cout << l->stringify() << " ";
}

void ListContainer::sort() {
    if (sort_function == nullptr)
        throw "ACCESS VIOLATION: sort_function is NULL";
    sort_function->sort(this);
}

void ListContainer::swap(int i, int j) {
    Base* temp;
    std::list<Base*>::iterator it_i = list.begin();
    std::list<Base*>::iterator it_j = list.begin();

    std::advance(it_i, i);
    std::advance(it_j, j);

    temp = *it_i;
    *it_i = *it_j;
    *it_j = temp;
}

Base* ListContainer::at(int i) {
    std::list<Base*>::iterator it = list.begin();
    std::advance(it, i);
    return *it;
}

int ListContainer::size() {
    return list.size();
}
