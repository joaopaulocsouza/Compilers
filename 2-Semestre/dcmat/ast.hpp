#define AST_HPP
#ifdef AST_HPP
#include "includes.hpp"

enum Operators {
    OP = 0,
    SUB_KEY = 1,
    ADD_KEY = 2,
    DIV_KEY = 3,
    MULTIPLY_KEY = 4,
    REST_KEY = 5,
    POW_KEY = 6,
    SEN_KEY = 7,
    COS_KEY = 8,
    TAN_KEY = 9,
    ABS_KEY = 10
};

enum Types {
    VAR_KEY,
    SUBVAR_KEY,
    INT_KEY,
    FLOAT_KEY,
    MATRIX_KEY
};

enum Element {
    FUNCTION_KEY,
    EXPRESSION_KEY
};

class Expressao {
    public:
        float value;
        int element;
        int type;
        int oper;
        Expressao *left;
        Expressao *right;
        Expressao *exp;

        Expressao(){};

        float GetValue(float x, Expressao *exp){
            switch (exp->type){
                case VAR_KEY:
                    return x;
                case SUBVAR_KEY:
                    return -x;  
                default:
                    return exp->value;
            }
        };

        float CalcFunctionValue(float x, Expressao *exp){
            Expressao *aux = exp;
            float result = 0;           

            if(aux->right != nullptr){
                result = CalcFunctionValue(x, aux->right);
            }

            switch (aux->oper) {
                case SUB_KEY:
                    result = GetValue(x, aux->left) - result;
                    break;  
                case ADD_KEY:
                    result = GetValue(x, aux->left) + result;
                    break;
                case DIV_KEY:
                    result = GetValue(x, aux->left) / result;
                    break;
                case MULTIPLY_KEY:
                    result = GetValue(x, aux->left) * result;
                    break;
                case POW_KEY:
                    result = pow(GetValue(x, aux->left), result);
                    break;
                case SEN_KEY:
                    result = sin(CalcFunctionValue(x, aux->exp));
                    break;
                case COS_KEY:
                    result = cos(CalcFunctionValue(x, aux->exp));
                    break;
                case TAN_KEY:
                    result = tan(CalcFunctionValue(x, aux->exp));
                    break;
                case ABS_KEY:
                    result = abs(CalcFunctionValue(x, aux->exp));
                    break;
                case OP:
                    return GetValue(x, aux);
            }
            return result;

        };
};


#endif