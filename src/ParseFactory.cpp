#include "ParseFactory.hpp"
#include <sstream>
#include <iostream>
#include <vector>
#include "op.hpp"
#include "Add.hpp"
#include "Div.hpp"
#include "Mult.hpp"
#include "Sub.hpp"
#include "Abs.hpp"
#include "Ceil.hpp"
#include "Floor.hpp"

#include <cstring>

bool isBinaryOperator(const char* a);
bool isUnaryOperator(const char* a);

ParseFactory::ParseFactory() {}

Parse::Parse()
:ParseFactory() {}

Base* Parse::parse(char** input, int length) {
    std::vector<std::string> buffer;
    std::string arg;
    Base* root = nullptr;
    Base* left = nullptr;

    for(int i = 1; i < length; i++) {
        char* arg = input[i];
        char* next = input[i + 1];
        if (isBinaryOperator(arg)) {
            if (i == 1) {
                std::cerr << "Expecting a number before binary operator " << arg << std::endl;
                return nullptr;
            }

            if(i == length - 1 || isBinaryOperator(next)) {
                std::cerr << "Expecting a number after binary operator " << arg << std::endl;
                return nullptr;
            }
            
            if (strcmp(arg,"+") == 0) {
                if (isUnaryOperator(next)) {
                    if (strcmp(next, "abs") == 0) {
                        left = new Add(left, new Abs(new Op(std::stoi(input[i + 2]))));
                    } else if (strcmp(next, "floor") == 0) {
                        left = new Add(left, new Floor(new Op(std::stoi(input[i + 2]))));
                    } else {
                        left = new Add(left, new Ceil(new Op(std::stoi(input[i + 2]))));
                    }
                    i += 2;
                } else {
                    left = new Add(left, new Op(std::stoi(next)));
                }
            } else if (strcmp(arg,"-") == 0) {
                if (isUnaryOperator(next)) {
                    if (strcmp(next, "abs") == 0) {
                        left = new Sub(left, new Abs(new Op(std::stoi(input[i + 2]))));
                    } else if (strcmp(next, "floor") == 0) {
                        left = new Sub(left, new Floor(new Op(std::stoi(input[i + 2]))));
                    } else {
                        left = new Sub(left, new Ceil(new Op(std::stoi(input[i + 2]))));
                    }
                    i += 2;
                } else {
                    left = new Sub(left, new Op(std::stoi(next)));
                }
            } else if (strcmp(arg,"*") == 0) {
                if (isUnaryOperator(next)) {
                    if (strcmp(next, "abs") == 0) {
                        left = new Mult(left, new Abs(new Op(std::stoi(input[i + 2]))));
                    } else if (strcmp(next, "floor") == 0) {
                        left = new Mult(left, new Floor(new Op(std::stoi(input[i + 2]))));
                    } else {
                        left = new Mult(left, new Ceil(new Op(std::stoi(input[i + 2]))));
                    }
                    i += 2;
                } else {
                    left = new Mult(left, new Op(std::stoi(next)));
                }
            } else if (strcmp(arg,"/") == 0) {
                if (isUnaryOperator(next)) {
                    if (strcmp(next, "abs") == 0) {
                        left = new Div(left, new Abs(new Op(std::stoi(input[i + 2]))));
                    } else if (strcmp(next, "floor") == 0) {
                        left = new Div(left, new Floor(new Op(std::stoi(input[i + 2]))));
                    } else {
                        left = new Div(left, new Ceil(new Op(std::stoi(input[i + 2]))));
                    }
                    i += 2;
                } else {
                    left = new Div(left, new Op(std::stoi(next)));
                }
            }
        } else if (isUnaryOperator(arg)) {
            if (strcmp(arg, "abs") == 0) {
                left = new Abs(new Op(std::stoi(input[i + 1])));
            } else if (strcmp(arg, "floor") == 0) {
                left = new Floor(new Op(std::stoi(input[i + 1])));
            } else {
                left = new Ceil(new Op(std::stoi(input[i + 1])));
            }
            i++;
        } else {
            if (i == 1)
                left = new Op(std::stoi(arg));
        }
    }
    return left;
}

bool isBinaryOperator(const char* a) {
    return (strcmp(a,"+") == 0 ||
            strcmp(a,"-") == 0 ||
            strcmp(a,"*") == 0 ||
            strcmp(a,"/") == 0 ||
            strcmp(a,"pow") == 0);
}

bool isUnaryOperator(const char* a) {
    return (strcmp(a,"floor") == 0 ||
            strcmp(a,"ceil") == 0 ||
            strcmp(a,"abs") == 0);
}