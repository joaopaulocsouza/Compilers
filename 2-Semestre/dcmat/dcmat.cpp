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
    std::cout << "\nh_view_lo: " << std::fixed << std::setprecision(precision) << h_view_lo << "\nh_view_hi: " << h_view_hi;
    std::cout << "\nv_view_lo: " << v_view_lo << "\nv_view_hi: "  << v_view_hi;
    std::cout << "\nfloat precision: " << precision << "\nintegral_steps: " << integral_steps;


    Axis?std::cout << "\n\nDraw Axis: " << "ON":std::cout << "\n\nDraw Axis: " << "OFF";
    Erase_Plot?std::cout << "\nErase Plot: " << "ON":std::cout << "\nErase Plot: " << "OFF";
    std::cout << "\n";
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

    if(hash[ascii].size() > 0){
       for(int i = 0; i < hash[ascii].size(); i++){
            if(hash[ascii][i].name == name){
                hash[ascii][i].value = exp;
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

void GetType(Expressao *value){
    switch (value->type){
        case INT_KEY:
            std::cout << "INT" << std::endl;
        case FLOAT_KEY:
            std::cout << "FLOAT"  << std::endl;
        case MATRIX_KEY:
            std::cout << "MATRIZ [" << value->matrix->lines <<  "][" << value->matrix->columns << "]" << std::endl ;
    }
}

void DCMAT::ShowSymbols(){
    for(int i=0;i<211;i++){
        if(hash[i].size() > 0){
            for(int j = 0; j < hash[i].size() ; j++){
                std::cout << hash[i][j].name << " - ";
                GetType(hash[i][j].value);
            }
        }
    }
};


 double TransformPoint(double y) {
    double new_y = 0+((y - v_view_lo) * 24) / (v_view_hi - v_view_lo);
    return new_y;
}

void DCMAT::PlotChart(Expressao *exp){

    double h = (h_view_hi - h_view_lo) / 80;
    double v = (v_view_hi - v_view_lo) / 25;

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
       double y = -exp->CalcFunctionValue(i*h + h_view_lo, exp);
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
                isNegative[j] = true;
            }
        }
        if(lineSize < result) lineSize = result;
    }
    lineSize -= 1;
    for(int k = 0; k < matrix->columns; k++){
        if(isNegative) lineSize += 1;
    }

    std::cout << "+-";
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
    std::cout << "-+\n";
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

void DCMAT::SolveDeterminant(MatrixClass *matrix){
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

    std::cout << std::fixed << std::setprecision(precision) << det << std::endl;

};