#define AST_HPP
#ifdef AST_HPP
#include "includes.hpp"

class AST {
    public:
        AST();
        
};

class Expressao {
    public:
        float value;
        bool function;
        std::string type;
        std::string oper;
        Expressao *left;
        Expressao *right;
        Expressao *exp;

        Expressao(){};
};


#endif