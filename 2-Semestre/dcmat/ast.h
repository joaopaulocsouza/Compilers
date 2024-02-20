#define AST_HPP
#ifdef AST_HPP
#include "includes.hpp"

class AST {
    public:
        AST();
        
};

class Expressao {
    public:
        float valor;
        std::string tipo;

        Expressao();
};

Expressao::Expressao(){

}

class ExpressaoAdd: public Expressao {
    public:
        Expressao left;
        Expressao right;

        ExpressaoAdd(){

        };
     
};

#endif