#include <iostream>
#include "ParseFactory.hpp"
#include "iterator.hpp"
#include "visitor.hpp"
#include "Add.hpp"
#include "op.hpp"

int main(int argc, char** argv) {
    Parse* p = new Parse();
    Base* b = p->parse(argv, argc);
    Add* dummy = new Add(b, new Op(5));

    CountVisitor* cv = new CountVisitor();
    PreorderIterator* preorder = new PreorderIterator(dummy);
    preorder->first();
    while (!preorder->is_done()) {
        preorder->current()->accept(cv);
        preorder->next();
    }

    printf("number of +: %i\n", cv->add_count());
    printf("number of operands: %i\n", cv->op_count() - 1); // subtract the dummy
    
    std::cout << b->stringify() << std::endl;
    return 0;
}