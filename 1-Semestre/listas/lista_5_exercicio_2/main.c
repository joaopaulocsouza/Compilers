#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isFinalState(int state){
    int finals[] = {2,3,4,5,6,7,8,9,11,12,13};
    if((state >= 2 && state <= 9) || (state >= 11 && state <= 13)){
        return true;
    }
    return false;
};

bool isInAlphabet(char symbol){

    if(symbol >= 'a' && symbol <= 'z'){
        return true;
    }
    
    return false;
};

bool isInAlphanumeric(char symbol){
    int numbers[] = {'0','1','2','3','4','5','6','7','8','9'};

    if(symbol >= '0' && symbol <= '9'){
        return true;
    }
    return false;
};


int getColumn(char symbol){
    int alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','x','w','y','z'};
    int numbers[] = {'0','1','2','3','4','5','6','7','8','9'};

    if(symbol == '-'){
        return 0;
    }else if(symbol == '.'){
        return 1;
    }else if(symbol >= 'a' && symbol <= 'z'){
        for(int i = 2; i <= 28; i++){
            if(symbol == alphabet[i-2]){
                return i;
            }
        }
    }else if(symbol >= '0' && symbol <= '9'){
        for(int i = 29; i <= 38; i++ ){
            if(symbol == numbers[i - 28]){
                return i;
            }
        };
    }else if(symbol == '\n'){
        return 39;
    }else if(symbol == ' '){
        return 40;
    }
    else{
        return 41;
    }
}

void printToken(int finalState){
    printf(" ");
    switch (finalState){
    case 2:
        printf("ID\n");
        break;
    case 3:
        printf("IF\n");
        break;
    case 4:
        printf("ID\n");
        break;
    case 12:
        printf("white space\n");
        break;
    case 5:
        printf("error\n");
        break;
    case 6:
        printf("REAL\n");
        break;
    case 7:
        printf("NUM\n");
        break;
    case 8:
        printf("REAL\n");
        break;
    case 13:
        printf("error\n");
        break;
    case 9:
        printf("error\n");
        break;
    case 11:
        printf("comment\n");
        break;
    default:
        printf("ERRO\n");
        return;
        break;
    }
}

void main(){

    int edges [][41] = {/* - . a b c d e f g h i j k l m n o p q r s t u v w x y z 0 1 2 3 4 5 6 7 8 9 /n " " other*/
            /*state 1*/   {9,5,4,4,4,4,4,4,4,4,2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7,7,7,13,12,13},
            /*state 2*/   {0,0,4,4,4,4,4,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4, 0, 0, 0},
            /*state 3*/   {0,0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4, 0, 0, 0},
            /*state 4*/   {0,0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4, 0, 0, 0},
            /*state 5*/   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,6,6,6,6, 0, 0, 0},
            /*state 6*/   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,6,6,6,6, 0, 0, 0},
            /*state 7*/   {0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,7,7,7,7,7,7,7, 0, 0, 0},
            /*state 8*/   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,8,8,8,8,8,8,8, 0, 0, 0},
            /*state 9*/   {10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0, 0, 0},
            /*state 10*/  {0,0,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,0,0,0,0,0,0,0,0,0,0,11, 0, 0},
            /*state 11*/  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0, 0, 0},
            /*state 12*/  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0, 12, 0},
            /*state 13*/  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0, 0, 0},
    };
    char entrada[2048];

    char symbol;

    int lastFinal = 0;
    int atualState = 1;

    int accept = 0;
    int current = 0;

    while(fgets(entrada, sizeof(entrada), stdin) != EOF){
       char *ptr = entrada;
        while (1){
            char symbol = ptr[current];
            if(symbol == '\0'){
                break;
            }
            
            if(edges[atualState-1][getColumn(symbol)] != 0){
                accept = current;
                atualState = edges[atualState-1][getColumn(symbol)];
                lastFinal = isFinalState(atualState)?atualState:atualState;
                printf("%c", symbol);
                current++;
            }
            else{
                printToken(lastFinal);
                lastFinal = 0;
                atualState = 1;
                if(symbol != '\n'){
                    current--;
                }
            }
        }
            
        lastFinal = 0;
        atualState = 1;
        accept = 0;
        current = 0;
    }
    
}