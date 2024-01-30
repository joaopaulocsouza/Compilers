#include "includes.hpp"
#include "functions.hpp"

Functions::Functions(/* args */){}


int Functions::LexicAnalizer(std::vector<std::string> tokens){
    int initialState = 1;
    int currentState = 1;
    int lastFinal = 0;
    int indexLastFinal = 0;
    bool brokenLine = false;

    int readingCursor = 0;
    int acceptCursor = 0;

    std::string acceptedInput;
    std::string tempInput;

    while (1){
        if(str[readingCursor] == '\0'){
            break;
        }
        currentState = edges[currentState][GetColumn(str[readingCursor])];

        if(currentState == 0){
            if(brokenLine){
                std::cout << "\n";
            }
            if(lastFinal == 0){
                std::cout << "ERRO";
                readingCursor = indexLastFinal+1;
                indexLastFinal += 1;
            }else{
                std::cout << tokens[lastFinal];
                if(tokens[lastFinal] == "INTEIRO" || tokens[lastFinal] == "REAL"){
                    std::cout << " " << acceptedInput;
                }
                readingCursor = indexLastFinal+1;
                indexLastFinal += 1;
            }
            lastFinal = 0;
            currentState = initialState;
            acceptedInput.clear();
            tempInput.clear();
            brokenLine = true;
        }else{
            if(finalStates[currentState]){
                lastFinal = currentState;
                indexLastFinal = readingCursor;
            }
            acceptCursor = readingCursor;
            readingCursor++;
        }


    }
    

    return 0;
};

int Functions::GetColumn(char character){
    if(character >= 'a' && character <= 'z'){
        return static_cast<int>(character) - 87;
    }
    if(character >= '0' && character <= '9'){
        return static_cast<int>(character) - 48; 
    }
    if(character == '-'){
        return 37;
    }else if(character == '+'){
        return 36;
    }

    return 38;
};
