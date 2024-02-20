#ifndef DCMAT_HPP
#define DCMAT_HPP
#include "includes.hpp"
#include "ast.hpp"

struct DeclaredVar {
    bool exists;
    Expressao *value;
    std::string type;
};

class DCMAT {
    public:
        DCMAT();
        void ShowSettings();
        void ResetSettings();
        void CreateHashItem(char *name, Expressao *exp, std::string type);
        DeclaredVar FindHashItem(char *name);
        void ShowSymbols();

        int CalcRest(int x, int y){
            return (x%y);
        };
};

#endif