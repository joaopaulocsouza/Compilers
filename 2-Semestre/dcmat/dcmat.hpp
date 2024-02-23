#ifndef DCMAT_HPP
#define DCMAT_HPP
#include "includes.hpp"
#include "ast.hpp"

struct DeclaredVar {
    bool exists;
    Expressao *value;
    int type;
};

class DCMAT {
    public:
        DCMAT();
        void ShowSettings();
        void ResetSettings();
        void CreateHashItem(char *name, Expressao *exp, int type);
        DeclaredVar FindHashItem(char *name);
        void ShowSymbols();
        void PlotChart(Expressao *exp);
        void ShowMatrix(MatrixClass *matrix);
        void SolveDeterminant(MatrixClass *matrix);

        int CalcRest(int x, int y){
            return (x%y);
        };
};


#endif