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
    ABS_KEY = 10,
    EXP_KEY = 11
};

enum Types {
    VAR_KEY,
    SUBVAR_KEY,
    INT_KEY,
    FLOAT_KEY,
    MATRIX_KEY,
    ID_KEY
};

enum Element {
    FUNCTION_KEY,
    EXPRESSION_KEY
};

class MatrixClass{
    public:
        std::vector<float> line;
        std::vector<std::vector<float>> matrix;
        int lines;
        int columns;

        MatrixClass(){};
};

class Expressao {
    public:
        float value;
        int element;
        int type;
        int oper;
        bool saved;
        MatrixClass *matrix;
        Expressao *left;
        Expressao *right;
        Expressao *exp;

        Expressao(){};

        float GetValue(float x, Expressao *exp){
            if(exp->oper == EXP_KEY || exp->oper == SEN_KEY || exp->oper == COS_KEY ||
                exp->oper == TAN_KEY || exp->oper == ABS_KEY){
                return CalcFunctionValue(x, exp);
            }
            switch (exp->type){
                case VAR_KEY:
                    return x;
                case SUBVAR_KEY:
                    return -x;
                case ID_KEY:
                    return x;
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
                case EXP_KEY:
                    result = CalcFunctionValue(x, aux->exp);
                    break;
                case OP:
                    return GetValue(x, aux);
            }
            return result;

        };

        Expressao *CreateExp(int oper, Expressao *termo, Expressao *exp){
            Expressao *new_exp = new Expressao(); 
            
            if(termo->type == FLOAT_KEY || exp->type ==FLOAT_KEY){
                new_exp->type = FLOAT_KEY; 
            }else{
                new_exp->type = INT_KEY;
            };
                    
            new_exp->oper = oper; 
            new_exp->left = termo; 
            new_exp->right = exp;
            if(termo->type == FLOAT_KEY ||termo->type == INT_KEY ||
                exp->type == FLOAT_KEY ||exp->type == INT_KEY ){
                switch (oper) {
                    case ADD_KEY:
                        new_exp->value = termo->value + exp->value;
                        break;
                    case SUB_KEY:
                        new_exp->value = termo->value - exp->value;
                        break;
                    case MULTIPLY_KEY:
                        new_exp->value = termo->value * exp->value;
                        break;
                    case DIV_KEY:
                        new_exp->value = termo->value / exp->value;
                        break;
                    case REST_KEY:
                        new_exp->value = static_cast<int>(termo->value) % static_cast<int>(exp->value);
                        break;
                    case POW_KEY:
                        new_exp->value = pow(termo->value, exp->value);
                        break;
                }
            };
            if(termo->element == FUNCTION_KEY || exp->element == FUNCTION_KEY){ 
                new_exp->element = FUNCTION_KEY;
            }else{
                new_exp->element = EXPRESSION_KEY;
            };

            return new_exp;
        }


        Expressao *CreateSheet(int type, int oper, float value, Expressao *exp, int element = EXPRESSION_KEY){
            Expressao *new_exp = new Expressao(); 

            new_exp->oper = oper;
            new_exp->value = value;
            new_exp->type = type;
            new_exp->left = nullptr;
            new_exp->right = nullptr;
            new_exp->exp = exp;
            new_exp->element = element;

            if(type == VAR_KEY || type == SUBVAR_KEY){
                new_exp->element = FUNCTION_KEY;
            }

            return new_exp;
        }

        Expressao *CreateMatrix(MatrixClass *matrix){
            Expressao *new_exp = new Expressao();

            new_exp->type = MATRIX_KEY;
            new_exp->left = nullptr;
            new_exp->right = nullptr;
            new_exp->matrix = matrix;
            new_exp->element = EXPRESSION_KEY; 

            return new_exp;
        }
};

class Vetor {
    public:
        std::vector<std::string> vetor;

        Vetor(){};
};


#endif