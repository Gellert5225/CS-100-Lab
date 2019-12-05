#include <iostream>
#include "ParseFactory.hpp"

int main(int argc, char** argv) {
    Parse* p = new Parse();
    std::cout << p->parse(argv, argc)->stringify() << std::endl;
    return 0;
}