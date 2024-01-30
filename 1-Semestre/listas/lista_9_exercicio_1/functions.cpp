#include "includes.hpp"
#include "functions.hpp"
int initialState = 1;
int currentState = 1;
int lastFinal = 0;
int indexLastFinal = 0;
int line = 1;
int column = 0;
int readingCursor = 0;
bool eol = false;
bool eof = false;
bool consumed = false;
bool hasSyntaticError = false;
std::string token;

Functions::Functions(/* args */){}

bool Functions::LexicAnalizer(std::vector<std::string> tokens){
    bool finalize = false;
    bool hasError = false;

    std::string acceptedInput;
    std::string tempInput;

    while (1){
        if(str[readingCursor] == '\0'){
            currentState = 0;
            finalize = true;
        }else{
            currentState = edges[currentState][GetColumn(str[readingCursor])];
        }

        if(currentState == 0){
            if(lastFinal == 0){
                std::cout << "ERRO LEXICO. Linha: " << line << " Coluna: " << column-1 << " -> \'" << str[indexLastFinal] <<"\'\n";
                readingCursor = indexLastFinal+1;
                indexLastFinal += 1;
                hasError = true;
                return "ERRO";
            }else if(lastFinal != 28){
                readingCursor = indexLastFinal+1;
                indexLastFinal += 1;
            }
            column++;
            lastFinal = 0;
            currentState = initialState;
            acceptedInput.clear();
            tempInput.clear();
        }else{
            if(finalStates[currentState]){
                lastFinal = currentState;
                indexLastFinal = readingCursor;
            }
            if(currentState == lastFinal){
                acceptedInput += tempInput;
                acceptedInput.push_back(str[readingCursor]);
                tempInput.clear();
            }else if(currentState != lastFinal){
                tempInput.push_back(str[readingCursor]);
            }

            readingCursor++;

            if(str[readingCursor] == '\n'){
                line++;
                column = 0;

            }else{
                column++;
            }

        }
        if(finalize) break;
    }
    
    return hasError;
};


std::string Functions::GetToken(std::vector<std::string> tokens){
    std::string acceptedInput;
    std::string tempInput;

    while (1){
        if(str[readingCursor] == '\0'){
            eof = true;
            currentState = 0;
        }else{
            currentState = edges[currentState][GetColumn(str[readingCursor])];
        }

        if(currentState == 0){
            if(lastFinal == 0){
                std::cout << "ERRO LEXICO. Linha: " << line << " Coluna: " << column-1 << " -> \'" << str[indexLastFinal] <<"\'\n";
                readingCursor = indexLastFinal+1;
                indexLastFinal += 1;
                return "ERRO";
            }else if(lastFinal != 28){
                readingCursor = indexLastFinal+1;
                indexLastFinal += 1;
                token = tokens[lastFinal];
                // std::cout << " " << lastFinal << " " <<  tokens[lastFinal] << "\n";
                consumed = false;
            }
            column++;
            lastFinal = 0;
            currentState = initialState;
            if(token.size() >= 1 && !consumed){
                return token;
            }
        }else{
            if(finalStates[currentState]){
                lastFinal = currentState;
                indexLastFinal = readingCursor;
            }
            readingCursor++;

            if(str[readingCursor] == '\n'){
                line++;
                column = 0;
                eol = true;

            }else{
                column++;
            }

        }
    }
}    

void Functions::eat(std::string t, std::vector<std::string> tokens){
    if(eol){
        return;
    };
    if(token == t){
        GetToken(tokens);
        consumed = true;
    }else{
        // std::cout << "ERRO";
        return;
    }
};

void Functions::E(std::vector<std::string> tokens){
    eat("num", tokens); eat("eq", tokens); eat("num", tokens);
};

void Functions::L(std::vector<std::string> tokens){
    if(token == "end"){
        eat("end", tokens);
    }else if(token == "semi"){
        S(tokens);
        L(tokens);
    }else{
        hasSyntaticError = true;
        std::cout << "ERRO SINTATICO EM: " << token << " ESPERADO: end, semi";
    }
};

void Functions::S(std::vector<std::string> tokens){
    if(token == "if"){
        eat("if", tokens);
        E(tokens);
        eat("then", tokens);
        S(tokens);
        eat("else", tokens);
        S(tokens);
    }else if(token == "begin"){
        eat("begin", tokens); S(tokens); L(tokens);
    }else if(token == "print"){
        eat("print", tokens); E(tokens);
    }else{
        hasSyntaticError = true;
        std::cout << "ERRO SINTATICO EM: " << token << " ESPERADO: if, print, begin";
    }
};

bool Functions::SyntaticAnalizer(std::string string, std::vector<std::string> tokens){
    while (!eof){
        GetToken(tokens);
        consumed = true;
        if(eol){
            eol = false;
        }

        hasSyntaticError = false;
        S(tokens);
        if(!hasSyntaticError){
            std::cout << "CADEIA ACEITA.";
        }
        
         std::cout << "\n";
    }

    return false;
};


int Functions::GetColumn(char character){
    if(character >= '0' && character <= '9'){
        return static_cast<int>(character) - 48; 
    }
    if(character == ' ' || character == '\t' || character == '\n'){
        return 27;
    }
    switch (character){
        case 'b':
            return 10;
        case 'd':
            return 11;
        case 'e':
            return 12;
        case 'f':
            return 13;
        case 'g':
            return 14;
        case 'h':
            return 15;
        case 'i':
            return 16;
        case 'l':
            return 17;
        case 'n':
            return 18;
        case 'p':
            return 19;
        case 'r':
            return 20;
        case 's':
            return 21;
        case 't':
            return 22;
        case '+':
            return 23;
        case '-':
            return 24;
        case ';':
            return 25;
        case '=':
            return 26;
        default:
            return 28;
    }
};