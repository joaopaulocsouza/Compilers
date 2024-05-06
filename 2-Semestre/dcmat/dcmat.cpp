#include "dcmat.hpp"
#include "includes.hpp"

float h_view_lo = -6.500000;
float h_view_hi = 6.500000;
float v_view_lo = -3.500000;
float v_view_hi = 3.500000;
int precision = 6;
int integral_steps = 1000;
bool Axis = true;
bool Erase_Plot = true;

std::string Chart[25][80];

struct HashElement {
    std::string name;
    Expressao *value;
    int type;
};

std::vector<HashElement> hash[211];

DCMAT::DCMAT(){}

void DCMAT::ShowSettings(){
    std::cout << "\nh_view_lo: " << std::fixed << std::setprecision(6) << h_view_lo << "\nh_view_hi: " << h_view_hi;
    std::cout << "\nv_view_lo: " << v_view_lo << "\nv_view_hi: "  << v_view_hi;
    std::cout << "\nfloat precision: " << precision << "\nintegral_steps: " << integral_steps;


    Axis?std::cout << "\n\nDraw Axis: " << "ON":std::cout << "\n\nDraw Axis: " << "OFF";
    Erase_Plot?std::cout << "\nErase Plot: " << "ON":std::cout << "\nErase Plot: " << "OFF";
    std::cout << "\n\n";
};

void DCMAT::ResetSettings(){
    h_view_lo = -6.500000;
    h_view_hi = 6.500000;
    v_view_lo = -3.500000;
    v_view_hi = 3.500000;
    precision = 6;
    integral_steps = 1000;
    Axis = true;
    Erase_Plot = true;
};

//Hash

void DCMAT::CreateHashItem(char *name, Expressao *exp, int type){
    int ascii = 0;
    for(int i = 0; i < std::strlen(name);i++) ascii += int(name[i]);
    ascii = ascii % 211;

    if(exp->left != nullptr) exp->DeleteExpression(exp->left);
    if(exp->right != nullptr) exp->DeleteExpression(exp->right);
    if(exp->exp != nullptr) exp->DeleteExpression(exp->exp);

    exp->left, exp->right, exp->exp = nullptr;
    exp->oper = OP;

    if(hash[ascii].size() > 0){
       for(int i = 0; i < hash[ascii].size(); i++){
            if(hash[ascii][i].name == name){
                hash[ascii][i].value = exp;
                hash[ascii][i].type = type;
                return;
            }
       };
       hash[ascii].push_back({name: name, value: exp, type: type});
    }else{
        hash[ascii].push_back({name: name, value: exp, type: type});
    }
};

DeclaredVar DCMAT::FindHashItem(char *name){
    int ascii = 0;
    for(int i = 0; i < std::strlen(name);i++) ascii += int(name[i]);
    ascii = ascii % 211;
    DeclaredVar result;

    if(hash[ascii].size() > 0){
        for(int i = 0; i < hash[ascii].size(); i++){
            if(hash[ascii][i].name == name){
                result.exists = true;
                result.value = hash[ascii][i].value;
                result.type = hash[ascii][i].type;
                return result;
            }
       };
    }

    result.exists = false;
    return result;
};

void DCMAT::DeleteHash(){

    for(int i = 0; i < hash->size(); i++){
        for(int j = 0; j < hash[i].size(); j++){
            hash[i][j].value->DeleteExpression(hash[i][j].value);
        }
        hash[i].clear();
    }
}

void DCMAT::ShowSymbols(){
    std::cout << "\n";
    for(int i=0;i<211;i++){
        if(hash[i].size() > 0){
            for(int j = 0; j < hash[i].size() ; j++){
                std::cout << hash[i][j].name << " - ";
                switch (hash[i][j].value->type){
                    case FLOAT_KEY: case INT_KEY:
                        std::cout << "FLOAT" << std::endl; break;
                    case MATRIX_KEY:
                        std::cout << "MATRIX [" << hash[i][j].value->matrix->lines <<  "][" << hash[i][j].value->matrix->columns << "]" << std::endl; break;
                }
            }
        }
    }
    std::cout << "\n";
};


 float TransformPoint(float y) {
    float new_y = 0+((y - v_view_lo) * 24) / (v_view_hi - v_view_lo);
    return new_y;
}

void DCMAT::PlotChart(Expressao *exp){

    float h = (h_view_hi - h_view_lo) / 80;
    float v = (v_view_hi - v_view_lo) / 25;

    if(Erase_Plot){
        for(int i = 0; i<80;i++){
            for(int j = 0; j<25;j++){
                Chart[j][i] = " ";
            }
        };
    };

    if(Axis){
        for(int j = 0; j<25;j++){
            Chart[j][40] = "|";
        };
        for(int i = 0; i<80;i++){
            Chart[12][i] = "-";
        };
        Chart[12][40] = "*";
    }else{
         for(int j = 0; j<25;j++){
            if(Chart[j][40] == "|") Chart[j][40] = " ";
        };
        for(int i = 0; i<80;i++){
            if(Chart[12][i] == "-") Chart[12][i] = " ";
        };
    };

    for(int i = 0; i<80;i++){
       float y = -exp->CalcFunctionValue(i*h + h_view_lo, exp);
       auto yTranformed = TransformPoint( y);
       if(y >= v_view_lo && y <= v_view_hi){
            Chart[(int)yTranformed][i] = "*";
       }
    }
    

    for(int i = 0; i<25;i++){
        for(int j = 0; j<80;j++){
            std::cout << Chart[i][j];
        }
        std::cout << std::endl;
    }
    
};

int countDigits(int number) {
    std::string numeroString = std::to_string(number);
    return numeroString.length();
}


void DCMAT::ShowMatrix(MatrixClass *matrix){
    int lineSize = 0;
    bool isNegative[matrix->columns];
    
    for(int k = 0; k < matrix->columns; k++){
        isNegative[k] = false;
    }

    for(int i = 0; i < matrix->lines; i++){
        int result = 0;
        for(int j = 0; j < matrix->columns; j++){
            if(matrix->matrix[i][j] >= 0){
                result += countDigits((int)matrix->matrix[i][j]) + precision;
                if(precision > 0){
                    result += 1;
                }
            }else{
                result += countDigits((int)matrix->matrix[i][j]) + precision;
                if(precision > 0){
                    result += 1;
                }
                isNegative[j] = true;
                result +=1;
            }
            if(j < matrix->columns-1) result+=1;
        }
        if(lineSize < result) lineSize = result;
    }

    std::cout << "\n+-";
    for(int k = 0; k < lineSize; k++) std::cout << " ";
    std::cout << "-+\n";
    
    for(int i = 0; i < matrix->lines; i++){
        std::cout << "| ";
        for(int j = 0; j < matrix->columns; j++){
            if(matrix->matrix[i][j]){
                if(matrix->matrix[i][j] >= 0 && isNegative[j]){
                    std::cout << " ";
                }
                std::cout << std::fixed << std::setprecision(precision) << matrix->matrix[i][j] << " ";
            }else{
                 if(isNegative[j]){
                    std::cout << " ";
                }
                std::cout << std::fixed << std::setprecision(precision) << (float)0 << " ";
            }
        }
        std::cout <<  "|" << std::endl;
    }


    std::cout << "+-";
    for(int k = 0; k < lineSize; k++) std::cout << " ";
    std::cout << "-+\n\n";
};

float SolveDeterminantAux(  std::vector<std::vector<float>> matrix){
    float det = 0;

    if(matrix.size() == 1){
        det = matrix[0][0];
    }else if(matrix.size() == 2){
         det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }else{
          for (int i = 0; i < matrix.size(); ++i) {
            std::vector<std::vector<float>> submatrix(matrix.size() - 1, std::vector<float>(matrix.size() - 1));

            for (int j = 1; j < submatrix.size() ; ++j) {
                int k = 0;
                for (int l = 0; l < matrix.size(); ++l) {
                    if (l != i) {
                       submatrix[j - 1][k] = submatrix[j][l];
                        ++k;
                    }
                }
            }

            det += submatrix[0][i] * SolveDeterminantAux(submatrix) * ((i % 2 == 0) ? 1 : -1);
        }
    
    }

    return det;
};

float DCMAT::SolveDeterminant(MatrixClass *matrix){
    float det = 0;

    if(matrix->columns == 1){
        det = matrix->matrix[0][0];
    }else if(matrix->columns == 2){
         det = matrix->matrix[0][0] * matrix->matrix[1][1] - matrix->matrix[0][1] * matrix->matrix[1][0];
    }else{
          for (int i = 0; i < matrix->columns; ++i) {
            std::vector<std::vector<float>> submatrix(matrix->columns - 1, std::vector<float>(matrix->columns - 1));

            for (int j = 1; j < matrix->columns; ++j) {
                int k = 0;
                for (int l = 0; l < matrix->columns; ++l) {
                    if (l != i) {
                        submatrix[j - 1][k] = matrix->matrix[j][l];
                        ++k;
                    }
                }
            }

            det += matrix->matrix[0][i] * SolveDeterminantAux(submatrix) * ((i % 2 == 0) ? 1 : -1);
        }
    
    }
    
    return det;

};

void DCMAT::SolveLinearSystem(MatrixClass *matrix){

    std::vector<std::vector<float>> L(matrix->lines, std::vector<float>(matrix->lines, 0)), U;
    U = matrix->matrix;
    float aux[matrix->lines];

    for (int i = 0; i < matrix->lines; ++i) {
        L[i][i] = 1;
        for (int j = i + 1; j < matrix->lines; ++j) {
            float ratio = U[j][i] / U[i][i];
            L[j][i] = ratio;
            for (int k = i; k < matrix->lines+1; ++k) {
                U[j][k] -= ratio * U[i][k];
            }
        }
    }

    for(int i=0; i < matrix->lines; i++) {
        for(int j=i+1; j < matrix->lines; j++) {
            for(int k= 0; k < matrix->lines; k++) {
                if(fmod(matrix->matrix[i][k], matrix->matrix[j][k]) != 0 && fmod(matrix->matrix[j][k], matrix->matrix[i][k]) != 0) {
                    break;
                }
                aux[k] = matrix->matrix[i][k] > matrix->matrix[j][k]?matrix->matrix[i][k]/matrix->matrix[j][k]:
                 matrix->matrix[j][k]/matrix->matrix[i][k];
            }

            for(int k= 0; k < matrix->lines; k++) {
                if(aux[k] != aux[0]) break;
                if(k == matrix->lines-1 && (matrix->matrix[i][matrix->lines]/aux[0] == matrix->matrix[j][matrix->lines] ||
                     matrix->matrix[j][matrix->lines]/aux[0] == matrix->matrix[i][matrix->lines])) {
                    std::cout << "\nSPI - The Linear System has infinitely many solutions\n\n";
                    return;
                } else if(k == matrix->lines-1 && ( matrix->matrix[i][matrix->lines]/aux[0] !=  matrix->matrix[j][matrix->lines] && 
                    matrix->matrix[j][matrix->lines]/aux[0] !=  matrix->matrix[i][matrix->lines])) {
                    std::cout << "\nSI - The Linear System has no solution\n\n";
                    return;
                }
            }
        }
    }

    std::vector<float> y(matrix->lines);

    for (int i = 0; i < matrix->lines; ++i) {
        float sum = 0;
        for (int j = 0; j < i; ++j) {
            sum += L[i][j] * y[j];
        }
        y[i] = (matrix->matrix[i][matrix->columns-1] - sum) / L[i][i];
    }

    
    std::vector<float> result(matrix->lines);
    for (int i = matrix->lines - 1; i >= 0; --i) {
        float sum = 0;
        for (int j = i + 1; j < matrix->lines; ++j) {
            sum += U[i][j] * result[j];
        }
        result[i] = (y[i] - sum) / U[i][i];
    }

    int verify = 0;

    for (int i = 0; i < matrix->lines; ++i) {
        if (U[i][i] != 0) verify++;
    }


    if(verify == matrix->lines){
        std::cout << "\nMatrix X:\n\n";
        for(int i = 0; i < matrix->lines; i++){
            std::cout << std::fixed << std::setprecision(precision) << result[i] << std::endl;
        }
        std::cout << std::endl;
    }

};

void DCMAT::Integrate(float superior, float inferior, Expressao *exp){
    float subInterval = (superior - inferior) / integral_steps;
    float result = 0;

    for(int i = 0; i < integral_steps; i++){
        result += subInterval * exp->CalcFunctionValue(inferior + subInterval * i, exp);
    }

    std::cout << "\n" << std::fixed << std::setprecision(precision) << result << "\n\n";
    exp->DeleteExpression(exp);
};

void DCMAT::Sum(float inferior, float superior, Expressao *exp){
    float result = 0;
    for(int i = inferior; i <= superior; i++){
        result += exp->CalcFunctionValue(i, exp);
    };
    std::cout << "\n" << std::fixed << std::setprecision(precision) << result << "\n\n";
    exp->DeleteExpression(exp);
};

void DCMAT::ReversePolishNotation(Expressao *exp){
    if(exp->type != OP){
        if(exp->left != nullptr) ReversePolishNotation(exp->left);
        if(exp->right != nullptr) ReversePolishNotation(exp->right);
    }

     switch (exp->oper) {
        case SUB_KEY:
            std::cout << "- "; 
            break;  
        case ADD_KEY:
            std::cout << "+ "; break;  
        case DIV_KEY:
            std::cout << "/ "; break;  
        case MULTIPLY_KEY:
            std::cout << "* "; break;  
        case POW_KEY:
            std::cout << "^ "; break;  
        case SEN_KEY:
            ReversePolishNotation(exp->exp); std::cout << "SEN "; break;  
        case COS_KEY:
            ReversePolishNotation(exp->exp); std::cout << "COS "; break;  
        case TAN_KEY:
           ReversePolishNotation(exp->exp); std::cout << "TAN "; break;  
        case ABS_KEY:
          ReversePolishNotation(exp->exp); std::cout << "ABS "; break;  
        case EXP_KEY:
            ReversePolishNotation(exp->exp); break;
        case OP:
            switch (exp->type){
                case VAR_KEY:
                    std::cout << "x "; break;  
                case SUBVAR_KEY:
                    std::cout << "x - "; break;
                case FLOAT_KEY: case INT_KEY:
                    if(exp->id.compare("NULL")){
                        std::cout << exp->id  << " "; break; 
                    }else{
                        std::cout << std::fixed << std::setprecision(precision) << exp->value << " ";
                        break;
                    } 
                case ID_KEY: case MATRIX_KEY:
                    std::cout << exp->id << " "; 
                }
    }


};