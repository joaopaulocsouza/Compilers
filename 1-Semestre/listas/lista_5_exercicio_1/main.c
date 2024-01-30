#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isFinalState(int state){
    int finals[] = {2,3,4,5,8};
    for(int i = 0; i < sizeof(i); i++){
        if(finals[i] == state){
            return true;
        }
    }
    return false;
};

bool isInAlphabet(char symbol){
    int alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','t','u','v','x','w','y','z'};

    if(symbol >= 'a' && symbol <= 'z'){
        return true;
    }
    
    return false;
};

bool isInAlphanumeric(char symbol){
    int numbers[] = {'0','1','2','3','4','5','6','7','8','9'};

    for(int i = 0; i <= sizeof(i);i++){
        if(symbol == numbers[i]){
            return true;
        }
    }
    return false;
};

void main(){
    int edges [][39] = {/* + - a b c d e f g h i j k l m n o p q r s t u v x y z 0 1 2 3 4 5 6 7 8 9 /n*/
            /*state 1*/   {3,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,5,5,5,5,5,5,5,5,5,5,0},
            /*state 2*/   {0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},
            /*state 3*/   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            /*state 4*/   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            /*state 5*/   {0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5,5,5,5,5,0},
            /*state 6*/   {7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,8,8,8,8,8,8,8,0},
            /*state 7*/   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,8,8,8,8,8,8,8,0},
            /*state 8*/   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,8,8,8,8,8,8,8,0},
    };
    char entrada[2000];

    int lastFinal = 0;
    int atualState = 1;

    int accept = 0;
    int current = 0;

    printf("Insira uma entrada: ");
    char saida[1000];

    while (fgets(entrada, sizeof(entrada), stdin) != EOF) {
        char *ptr = entrada;
        while (1){
            char symbol = ptr[current];
            if(symbol == '\0' || symbol == '\n'){
                break;
            }
            switch (atualState){
                case 1:
                    if(isInAlphabet(symbol)){
                        accept = current;
                        printf("%c", symbol);
                        atualState = 2;
                    }else if(isInAlphanumeric(symbol)){
                        accept = current;
                        printf("%c", symbol);
                        atualState = 5;
                    }else if(symbol == '+'){
                        accept = current;
                        printf("%c", symbol);
                        atualState = 3;
                    }else if(symbol == '-'){
                        accept = current;
                        printf("%c", symbol);
                        atualState = 4;
                    }else if(isFinalState(atualState)){
                        printf("\n");
                    }else{
                        printf("ERRO\n");
                    }
                    break;
                case 2:
                    if(isInAlphabet(symbol) || isInAlphanumeric(symbol)){
                        accept = current;
                        printf("%c", symbol);
                        atualState = 2;
                    }
                    else if(isFinalState(atualState)){
                        printf("\n");
                        current--;
                        lastFinal = 0;
                        atualState = 1;
                    }else{
                        printf("ERRO\n");
                        current--;
                        lastFinal = 0;
                        atualState = 1;
                    }
                    break;
                case 3:
                    if(isFinalState(atualState)){
                        printf("\n");
                        current--;
                        lastFinal = 0;
                        atualState = 1;
                    }else{
                        printf("ERRO\n");
                        current--;
                        lastFinal = 0;
                        atualState = 1;
                    }
                    break;
                case 4:
                    if(isFinalState(atualState)){
                        printf("\n");
                        current--;
                        lastFinal = 0;
                        atualState = 1;
                    }else{
                        printf("ERRO\n");
                        current--;
                        lastFinal = 0;
                        atualState = 1;
                    }
                    break;
                case 5:
                    if(isInAlphanumeric(symbol)){
                        accept = current;
                        printf("%c", symbol);
                        atualState = 5;
                    }else if(symbol == 'e'){
                        accept = current;
                        printf("%c", symbol);
                        atualState = 6;
                    }else if(isFinalState(atualState)){
                        printf("\n");
                        current--;
                        lastFinal = 0;
                        atualState = 1;
                    }else{
                        printf("ERRO\n");
                        current--;
                        lastFinal = 0;
                        atualState = 1;
                    }
                    break;
                case 6:
                    if(isInAlphanumeric(symbol)){
                        accept = current;
                        printf("%c", symbol);
                        atualState = 8;
                    }else if(symbol == '+'){
                        accept = current;
                        printf("%c", symbol);
                        atualState = 7;
                    }else if(symbol == '-'){
                        accept = current;
                        printf("%c", symbol);
                        atualState = 7;
                    }else if(isFinalState(atualState)){
                        printf("\n");
                        current--;
                        lastFinal = 0;
                        atualState = 1;
                    }else{
                        printf("ERRO\n");
                        current--;
                        lastFinal = 0;
                        atualState = 1;
                    }
                    break;
                case 7:
                    if(isInAlphanumeric(symbol)){
                        accept = current;
                        printf("%c", symbol);
                        atualState = 8;
                    }else if(isFinalState(atualState)){
                        printf("\n");
                        current--;
                        lastFinal = 0;
                        atualState = 1;
                    }else{
                        printf("ERRO\n");
                        current--;
                        lastFinal = 0;
                        atualState = 1;
                    }
                    break;
                case 8:
                    if(isInAlphanumeric(symbol)){
                        accept = current;
                        printf("%c", symbol);
                        atualState = 8;
                    }else if(isFinalState(atualState)){
                        printf("\n");
                        current--;
                        lastFinal = 0;
                        atualState = 1;
                    }else{
                        printf("ERRO\n");
                        current--;
                        lastFinal = 0;
                        atualState = 1;
                    }
                    break;
                
            }
            if(isFinalState(atualState)){
                lastFinal = atualState;
            }
            current++;
        }
        printf("\n");
        lastFinal = 0;
        atualState = 1;
        accept = 0;
        current = 0;
    }
}