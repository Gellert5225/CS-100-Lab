#include "base.hpp"

class ParseFactory {
public:
    ParseFactory();

    virtual Base* parse(char** input, int length) = 0;

};

class Parse : public ParseFactory {
public:
    Parse();

    Base* parse(char** input, int length);
};