#include "dcmat.hpp"
#include "includes.hpp"

float h_view_lo = -2.500000;
float h_view_hi = 6.500000;
float v_view_lo = -3.500000;
float v_view_hi = 3.500000;
int precision = 6;
int integral_steps = 1000;
bool Axis = true;
bool Erase_Plot = true;



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

void DCMAT::ShowSymbols(){
    for(int i=0;i<211;i++){
        if(hash[i].size() > 0){
            for(int j = 0; j < hash[i].size() ; j++){
                std::cout << hash[i][j].name << " - " << hash[i][j].type << "\n";
            }
        }
    }
};

Expressao *DCMAT::CreateExp(int oper, Expressao *termo, Expressao *exp){
    Expressao *new_exp = new Expressao(); 
    
    if(termo->type == FLOAT_KEY || exp->type ==FLOAT_KEY){
        new_exp->type = FLOAT_KEY; 
    }else{
        new_exp->type = INT_KEY;
    };
            
    new_exp->oper = oper; 
    new_exp->left = termo; 
    new_exp->right = exp;
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
    if(termo->element == FUNCTION_KEY || exp->element == FUNCTION_KEY){ 
        new_exp->element = FUNCTION_KEY;
    }else{
        new_exp->element = EXPRESSION_KEY;
    };

    return new_exp;
}


Expressao *DCMAT::CreateSheet(int type, int oper, float value, Expressao *exp){
    Expressao *new_exp = new Expressao(); 

    new_exp->oper = oper;
    new_exp->value = value;
    new_exp->type = type;
    new_exp->left = nullptr;
    new_exp->right = nullptr;
    new_exp->exp = exp;

    if(type == VAR_KEY || type == SUBVAR_KEY){
        new_exp->element = FUNCTION_KEY;
    }else{
        new_exp->element = EXPRESSION_KEY;
    }

    return new_exp;
}
