%{
    #include <includes.hpp>
    #include <iostream>
    #include <string.h>
    #include <stdbool.h>
    #include <vector>
    #include <stack>
    #include "regalloc.hpp"

    int i, j;

    extern int yylex();
    extern char* yytext;
    void yyerror(char *s);
    void spillError();
    bool spill = false;
    Graph* graph = new Graph();
    std::vector<int> interference;
    std::stack<Vertex *> s;
%}

%union {
    int integer;
    char* s;
}

%token <integer> INT;
%token K;
%token <s>GRAPH;
%token EQUAL;
%token ARROW;
%token COLON;
%token EOL;

%type <integer> Value;

%start Regalloc

%%
    Regalloc: GRAPH Value COLON EOL Def EOL VirtualRegister {graph->G = $2;}

    Def: K EQUAL Value {graph->colors = $3;}

    VirtualRegister: VirtualRegister EOL VirtualRegister
                | Value ARROW Registers {
                        Vertex* v;
                        if(!graph->findVertex($1)){
                            v = new Vertex($1, graph->colors);
                        }else{
                            v = graph->getVertex($1);
                        }
                        for(i = 0; i < interference.size(); i++){
                            if(!graph->findVertex(interference[i])){
                                Vertex* z = new Vertex(interference[i], graph->colors);
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

    Value: INT {
        $$ = $1;
        }
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

    std::cout << "Graph " << graph->G << " -> Physical Registers: " << graph->colors << std::endl;
    std::cout << "----------------------------------------" << std::endl;


    for( i = graph->colors; i > 1; i--){
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "K = " << i << "\n" << std::endl;

        //Simplify
        while(graph->hasVirtualReg()){
            Vertex* v = graph->getVertexWithMinEdges();
            if(graph->countEdge(v->vertex) < i){
                std::cout << "Push: " << v->vertex << std::endl;
                s.push(v);
                graph->removeVertex(v->vertex);
            }else{
                v = graph->getVertexWithMaxEdges();
                std::cout << "Push: " << v->vertex << " *" << std::endl;
                s.push(v);
                graph->removeVertex(v->vertex);
            }
        }

        //Select
        bool spill = false;
        while(s.size() > 0){
            Vertex *v = s.top();
            graph->addVertex(v);
            s.pop();
            graph->getColor(v->vertex, i-1);
            v->removed = false;
            std::cout << "Pop: " << v->vertex << " -> ";
            if(v->color == -1){
                std::cout << "NO COLOR AVAILABLE" << std::endl;
                spill = true;
                break;
            }else{
                std::cout << v->color << std::endl;
            }
        }

        if(spill){
            while(s.size() > 0){
                graph->addVertex(s.top());
                s.pop();
            }
            graph->result.push_back({spill: true, k: i});
        }else{
            graph->result.push_back({spill: false, k: i});
        }

        graph->resetVertexes();
    }

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "----------------------------------------";
    for(auto element:graph->result){
        std::cout << "\nGraph " << graph->G;
        if(element.k > 9){
            std::cout << " -> K = ";
        }else{
            std::cout << " -> K =  ";
        }
        std::cout << element.k << ": ";
        if(element.spill){
            std::cout << "SPILL";
        }else{
            std::cout << "Successful Allocation";
        }
    }

    graph->destroyGraph();
    delete graph;


    return 0;
}