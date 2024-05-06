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
        void DeleteHash();
        void ShowSymbols();
        void PlotChart(Expressao *exp);
        void ShowMatrix(MatrixClass *matrix);
        float SolveDeterminant(MatrixClass *matrix);
        void SolveLinearSystem(MatrixClass *matrix);
        void Integrate(float superior, float inferior, Expressao *exp);
        void Sum(float inferior, float superior, Expressao *exp);
        void ReversePolishNotation(Expressao *exp);

        int CalcRest(int x, int y){
            return (x%y);
        };
};


#endif