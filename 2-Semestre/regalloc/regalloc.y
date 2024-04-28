%{
    #include <includes.hpp>
    #include <iostream>
    #include <string.h>
    #include <stdbool.h>
    #include <vector>
    #include "regalloc.hpp"

    extern int yylex();
    extern char* yytext;
    void yyerror(char *s);
    void spillError();
    bool spill = false;
    Graph* graph = new Graph();
    std::vector<int> interference;
%}

%union {
    int i;
    char* s;
}

%token <i> INT;
%token K;
%token <s>GRAPH;
%token EQUAL;
%token ARROW;
%token COLON;
%token EOL;

%type <i> Value;

%start Regalloc

%%
    Regalloc: GRAPH Value COLON EOL Def EOL VirtualRegister {graph->G = $2;}

    Def: K EQUAL Value {graph->colors = $3;}

    VirtualRegister: VirtualRegister EOL VirtualRegister
                | Value ARROW Registers {
                        Vertex* v;
                        if(!graph->findVertex($1)){
                            std::cout << "Creating vertex " << $1 << std::endl;
                            v = new Vertex($1);
                        }else{
                            std::cout << "Vertex " << $1 << " already exists" << std::endl;
                            v = graph->getVertex($1);
                        }
                        for(int i = 0; i < interference.size(); i++){
                            if(!graph->findVertex(interference[i])){
                                Vertex* z = new Vertex(interference[i]);
                                std::cout << "Creating vertex interference: " << interference[i] << std::endl;
                                graph->addVertex(z);
                            }
                            v->addEdge(interference[i], graph->getVertex(interference[i]));
                        }
                        interference.clear();
                        graph->addVertex(v);}


    Registers: Registers Value {interference.push_back($2);}
               | Value {
                interference.push_back($1);
               }

    Value: INT {$$ = atoi(yytext);}
%%

void yyerror(char *s) {
    printf("Error: %s\n", s);
}

void spillError(){
    std::cout << "Graph " << graph->G << " -> K = " << graph->colors << ": SPILL";
    exit(0);
}

int main(int argc, char **argv){
    yyparse();

    std::cout << std::endl;
    std::cout << "Graph " << graph->G << " -> Physical Registers: " << graph->colors << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    for(int i = 0 ; i < graph->vertices.size(); i++){
        std::cout << graph->vertices[i]->vertex << " --> ";
        for(int j = 0; j < graph->vertices[i]->edges.size(); j++){
            std::cout << graph->vertices[i]->edges[j] << " ";
        }
        std::cout << std::endl;
    }

    /* for(int i = graph->colors; i > 1; i--){
        std::cout << "Graph " << graph->G << " -> K = " << i << ": " << graph->result.top() << std::endl;
        graph->result.pop();
    } */


    return 0;
}