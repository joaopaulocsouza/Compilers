#include "includes.hpp"
#include "functions.hpp"

Functions::Functions(/* args */){}


int Functions::LexicAnalizer(std::string string, std::vector<std::string> tokens){

    int initialState = 1;
    int currentState = 1;
    int lastFinal = 0;
    int readingCursor = 0;
    int acceptCursor = 1;
    int startWord = 1;
    int lastIndexAccepted = 0;
    std::string currentInput;

    while(1){
        currentState = edges[currentState][GetColumn(string[readingCursor])];
        if(string[acceptCursor] == '\0'){
            break;
        }
        if(currentState == 0){  
            if(tokens[lastFinal] != "white space"){
                std::cout << currentInput << " ";
            }
            std::cout << tokens[lastFinal] << "\n";
            currentInput.clear();
            currentState = 1;
            lastFinal = 0;
        }else{
            if(finalStates[currentState] == 1){
                lastFinal = currentState;
            }
            if(string[readingCursor] != '\n'){
                currentInput.push_back(string[readingCursor]);
            }
            acceptCursor = readingCursor;
        }
        readingCursor++;
    }


    return 0;
};

int Functions::GetColumn(char character){
    if(character >= 'a' && character <= 'z'){
        return static_cast<int>(character) - 86;
    }
    if(character >= '0' && character <= '9'){
        return static_cast<int>(character) - 47; 
    }
    if(character == '-'){
        return 37;
    }else if(character == '.'){
        return 36;
    }else if(character == '\n'){
        return 38;
    }else if(character == '\t' || character == ' '){
        return 39;
    }

    return 40;
};
