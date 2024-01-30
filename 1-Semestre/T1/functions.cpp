#include "includes.hpp"
#include "functions.hpp"

struct token_data{
    std::string token;
    std::string input;
    int line;
    int column;
};

std::queue <token_data> read_tokens;
std::stack <std::string> syntatic_stack;
std::string current_token, current_input;
int current_line, current_column;

void Expressao();
void ListaComandos();
void ListaComandosLinha();

Functions::Functions(){}

bool Functions::LexicalAnalizer(std::string string, std::vector<std::string> tokens){
    int initialState = 1, currentState = 1, lastFinal = 0, readingCursor = 0;
    int indexLastFinal = 0, line = 1, column = 2, cash_column = 1;
    bool hasError = false, alter_column_value = false;
    std::string acceptedInput, tempInput;

    while (1){
        if(string[readingCursor] == '\0'){
            break;
        }
        currentState = edges[currentState][static_cast<int>(string[readingCursor])];

        if(currentState == 0){
            if(lastFinal == 0 || lastFinal == 174){
                std::cout << "ERRO LEXICO. Linha: "; 
                std::cout << (alter_column_value? line-1 : line);
                std::cout << " Coluna: ";
                std::cout << (alter_column_value?
                    cash_column - acceptedInput.size():
                    column - acceptedInput.size() - 1);
                std::cout << " -> \'";
                std::cout << string[indexLastFinal];
                std::cout << "\'";
                readingCursor = indexLastFinal+1;
                indexLastFinal += 1;
                hasError = true;
                exit(0);
            }else{
                readingCursor = indexLastFinal+1;
                indexLastFinal += 1;
                if(tokens[lastFinal] != "EOL" && tokens[lastFinal] != "WHITESPACE" &&
                   tokens[lastFinal] != "BLOCKCOMMENT" && tokens[lastFinal] != "LINECOMMENT"){
                        token_data temp_token_data;
                        temp_token_data.line = alter_column_value?line-1:line;
                        temp_token_data.column = (alter_column_value?cash_column - acceptedInput.size():column - acceptedInput.size() - 1);
                        cash_column = column;
                        temp_token_data.input =  acceptedInput; 
                        temp_token_data.token = tokens[lastFinal];
                        read_tokens.push(temp_token_data);
                    }
            }
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
                acceptedInput.push_back(string[readingCursor]);
                tempInput.clear();
            }else if(currentState != lastFinal){
                tempInput.push_back(string[readingCursor]);
            }

            readingCursor++;

            if(alter_column_value){
                cash_column = column;
                alter_column_value = false;
            }

            if(string[readingCursor] == '\n'){
                line++;
                column = 1;
                alter_column_value = true;
            }else{
                column += 1;
                cash_column += 1;
            }

        }
    }
    
    return hasError;
};

void advance(){
    if(read_tokens.size() == 0){
        std::cout << "Acabaram os tokens";
        exit(0);
    }
    read_tokens.pop();
    current_token = read_tokens.front().token;
    current_line = read_tokens.front().line;
    current_column = read_tokens.front().column;
    current_input = read_tokens.front().input;
}


void syntatic_error(){
    std::cout << "ERRO DE SINTAXE. Linha: "; 
    std::cout << current_line;
    std::cout << " Coluna: ";
    std::cout << current_column;
    std::cout << " -> \'";
    std::cout << current_input;
    std::cout << "\'";
    exit(0);
}

void eat(std::string token){
    if(token == current_token){
        advance();
    }else{
        syntatic_error();
    }
}

bool isDeclare(){
    bool verify = false;
    verify = current_token == "TIPO"?true:verify;
    verify = current_token == "INTEIRO"?true:verify;
    verify = current_token == "REAL"?true:verify;
    verify = current_token == "CARACTERE"?true:verify;
    verify = current_token == "LOGICO"?true:verify;
    verify = current_token == "ID"?true:verify;
    return verify;
}

void TipoBasico(){
    bool verify = false;
    verify = current_token == "INTEIRO"?true:verify;
    verify = current_token == "REAL"?true:verify;
    verify = current_token == "CARACTERE"?true:verify;
    verify = current_token == "LOGICO"?true:verify;
    verify = current_token == "ID"?true:verify;
    verify?advance():syntatic_error();
}

void VetorMatriz(){
    if(current_token == "VETOR"){
        eat("VETOR");
    }else if(current_token == "MATRIZ"){
        eat("MATRIZ");
    }else{
        syntatic_error();
    }
}

void DimensaoLinha(){
    if(current_token == "VIRGULA"){
        eat("VIRGULA"); eat("NUM"); eat("DOISPONTOS"); 
        eat("NUM"); DimensaoLinha();
    }
}

void Dimensao(){
    eat("NUM"); eat("DOISPONTOS"); eat("NUM"); DimensaoLinha();
}

void DeclaraIdLinha(){
    if(current_token == "VIRGULA"){
        eat("VIRGULA");
        eat("ID");
        DeclaraIdLinha();
    }
}

void DeclaraIdentificador(){
    eat("ID"); DeclaraIdLinha();
}

void DeclaracoesLinha(){
    if(current_token == "TIPO"){
        eat("TIPO"); eat("ID"); eat("IGUAL");
        VetorMatriz(); eat("ABRECOLCHETES"); Dimensao();
        eat("FECHACOLCHETES"); TipoBasico(); eat("PONTOVIRGULA");
        DeclaracoesLinha();
    }else if(isDeclare()){
        TipoBasico(); eat("DOISPONTOS"); DeclaraIdentificador();
        eat("PONTOVIRGULA"); DeclaracoesLinha();
    }
}

void Declaracoes(){
    if(current_token == "TIPO"){
        eat("TIPO"); eat("ID"); eat("IGUAL");
        VetorMatriz(); eat("ABRECOLCHETES"); Dimensao();
        eat("FECHACOLCHETES"); TipoBasico(); eat("PONTOVIRGULA");
        DeclaracoesLinha();
    }else{
        TipoBasico(); eat("DOISPONTOS"); DeclaraIdentificador();
        eat("PONTOVIRGULA"); DeclaracoesLinha();
    }
}

void ExprIterLinha(){
    if(current_token == "VIRGULA"){
        eat("VIRGULA"); Expressao(); ExprIterLinha();
    }
}

void ExprIter(){
    Expressao(); ExprIterLinha();
}

void VariavelLinha(){
   if(current_token == "ABRECOLCHETES"){
        eat("ABRECOLCHETES"); ExprIter(); eat("FECHACOLCHETES");
    }
}

void Variavel(){
    eat("ID"); VariavelLinha();
}

void Fator(){
    if(current_token == "ABREPARENTESES"){
        eat("ABREPARENTESES"); Expressao(); eat("FECHAPARENTESES");
    }else if(current_token == "ID"){
        eat("ID"); 
        if(current_token == "ABRECOLCHETES"){
            VariavelLinha();
        }else if(current_token == "ABREPARENTESES"){
            eat("ABREPARENTESES"); ExprIter(); eat("FECHAPARENTESES");
        }

    }else if(current_token == "NAO"){
        eat("NAO");
        Fator();
    }else{
        bool verify = false;
        verify = current_token == "NUM"?true:verify;
        verify = current_token == "NUMREAL"?true:verify;
        verify = current_token == "FALSO"?true:verify;
        verify = current_token == "VERDADEIRO"?true:verify;
        verify = current_token == "STRING"?true:verify;
        
        verify?eat(current_token):syntatic_error();
    }
}

void TermoLinha(){
    if(current_token == "VEZES"){
        eat("VEZES"); Fator(); TermoLinha();
    }else if(current_token == "DIVISAO"){
        eat("DIVISAO"); Fator(); TermoLinha();
    }else if(current_token == "DIV"){
        eat("DIV"); Fator(); TermoLinha();
    }else if(current_token == "E"){
        eat("E"); Fator(); TermoLinha();
    }
}

void Termo(){
    Fator(); TermoLinha();
}

void ExpressaoSimplesLinha(){
    if(current_token == "MAIS"){
        eat("MAIS"); Termo(); ExpressaoSimplesLinha();
    }else if(current_token == "MENOS"){
        eat("MENOS"); Termo(); ExpressaoSimplesLinha();
    }else if(current_token == "OU"){
        eat("OU"); Termo(); ExpressaoSimplesLinha();
    }
}

void ExpressaoSimples(){
    if(current_token == "MAIS"){
        eat("MAIS");
    }else if(current_token == "MENOS"){
        eat("MENOS");
    }
    Termo(); ExpressaoSimplesLinha();
}

void ExpressaoLinha(){
    bool verify = false;
    verify = current_token == "IGUAL"?true:verify;
    verify = current_token == "DIFERENTE"?true:verify;
    verify = current_token == "MENOR"?true:verify;
    verify = current_token == "MENORIGUAL"?true:verify;
    verify = current_token == "MAIORIGUAL"?true:verify;
    verify = current_token == "MAIOR"?true:verify;
    if(verify){
        eat(current_token); ExpressaoSimples(); ExpressaoLinha();
    }
}

void Expressao(){
    ExpressaoSimples(); ExpressaoLinha();
}

void ComandosLinha(){
    if(current_token == "ABREPARENTESES"){
        eat("ABREPARENTESES"); ExprIter(); eat("FECHAPARENTESES");
    }else if(current_token == "FIM"){
        eat("FIM"); eat("SE"); ComandosLinha();
    }else if(current_token == "SENAO"){
        eat("SENAO"); ListaComandos(); eat("FIM"); eat("SE");
        ComandosLinha();
    }else if(current_token == "FACA"){
        eat("FACA"); ListaComandos(); eat("FIM"); eat("PARA"); 
        ComandosLinha();
    }else if(current_token == "PASSO"){
        eat("PASSO"); Expressao(); eat("FACA"); ListaComandos();
        eat("FIM"); eat("PARA"); ComandosLinha();
    }
}

void Comandos(){
    if(current_token == "ID"){
        eat("ID");
        if(current_token == "ABRECOLCHETES" || current_token == "ATRIBUICAO"){
            VariavelLinha();
            eat("ATRIBUICAO");
            Expressao();
        }else{
            ComandosLinha();
        }
    }else if(current_token == "SE"){
        eat("SE"); Expressao(); eat("ENTAO");
         ListaComandos();  ComandosLinha();
    }else if(current_token == "ENQUANTO"){
        eat("ENQUANTO"); Expressao(); eat("FACA"); ListaComandos();
        eat("FIM"); eat("ENQUANTO");
    }else if(current_token == "PARA"){
        eat("PARA"); eat("ID"); eat("DE"); Expressao();
        eat("ATE"); Expressao(); ComandosLinha();
    }else if(current_token == "REPITA"){
        eat("REPITA"); ListaComandos(); eat("ATE"); Expressao();
    }else if(current_token == "LEIA"){
        eat("LEIA"); eat("ABREPARENTESES"); Variavel(); eat("FECHAPARENTESES");
    }else if(current_token == "IMPRIMA"){
        eat("IMPRIMA"); eat("ABREPARENTESES"); ExprIter(); eat("FECHAPARENTESES");
    }else{
        syntatic_error();
    }
}

void ListaComandosLinha(){
    bool verify = false;

    verify = current_token == "ID"?true:verify;
    verify = current_token == "SE"?true:verify;
    verify = current_token == "ENQUANTO"?true:verify;
    verify = current_token == "PARA"?true:verify;
    verify = current_token == "REPITA"?true:verify;
    verify = current_token == "LEIA"?true:verify;
    verify = current_token == "IMPRIMA"?true:verify;

    if(verify){
        Comandos();
        eat("PONTOVIRGULA");
        ListaComandosLinha();
    }
}

void ListaComandos(){
    Comandos();
    eat("PONTOVIRGULA");
    ListaComandosLinha();
}

void BlocoComandos(){
    eat("INICIO"); ListaComandos(); eat("FIM");
}

void BlocoVariaveis(){
    if(current_token == "VARIAVEIS"){
        eat("VARIAVEIS"); Declaracoes();
    }
}

void DeclaraParametros(){
    if(isDeclare()){
        Declaracoes();
    }
}

void Parametros(){
    if(current_token == "ABREPARENTESES"){
        eat("ABREPARENTESES"); 
        DeclaraIdentificador();
        eat("FECHAPARENTESES"); 
    }
}

void DeclaraProcedimentos(){
    eat("PROCEDIMENTO"); eat("ID");
    Parametros(); eat("PONTOVIRGULA");
    DeclaraParametros(); BlocoVariaveis(); BlocoComandos();
    eat("PONTOVIRGULA");
}

void DeclaraFuncao(){
    eat("FUNCAO"); eat("ID");
    Parametros(); eat("DOISPONTOS"); TipoBasico(); eat("PONTOVIRGULA");
    DeclaraParametros(); BlocoVariaveis(); BlocoComandos();
    eat("PONTOVIRGULA");
}

void ProcedimentoFuncao(){
    if(current_token == "PROCEDIMENTO"){
        DeclaraProcedimentos(); ProcedimentoFuncao();
    }else if(current_token == "FUNCAO"){
        DeclaraFuncao(); ProcedimentoFuncao();
    }
}

void Programa(){
    eat("ALGORITMO"); eat("ID"); eat("PONTOVIRGULA");
    BlocoVariaveis(); ProcedimentoFuncao(); BlocoComandos();
    eat("PONTO");
}

void S(){
    Programa();
}

bool Functions::SyntaticAnalizer(std::string string, std::vector<std::string> tokens){
    current_token = read_tokens.front().token;
    current_line = read_tokens.front().line;
    current_column = read_tokens.front().column;
    current_input = read_tokens.front().input;

    S();
    return false;

}