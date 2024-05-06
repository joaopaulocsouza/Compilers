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
    void yyerror(std::string s);
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

    VirtualRegister: Interfence EOL VirtualRegister
                | Interfence
                
    Interfence: Value ARROW Registers {
                        Vertex* v;
                        if(!graph->findVertex($1)){
                            v = new Vertex($1, graph->colors);
                        }else{
                            v = graph->vertices[$1];
                        }
                        for(i = 0; i < interference.size(); i++){
                            if(!graph->findVertex(interference[i])){
                                Vertex* z = new Vertex(interference[i], graph->colors);
                                graph->addVertex(z);
                            }
                            v->addEdge(interference[i], graph->vertices[interference[i]]);
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

void yyerror(std::string s) {
    std::cout << "Error: " << s << std::endl;
}

int main(int argc, char **argv){
    yyparse();

    std::cout << "Graph " << graph->G << " -> Physical Registers: " << graph->colors << std::endl;
    std::cout << "----------------------------------------" << std::endl;


    for( i = graph->colors; i > 1; i--){
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "K = " << i << "\n" << std::endl;

        //Simplify
        while(graph->virtualRegs > 0){
            graph->setMaxMinVertex();
            if(graph->min->countEdge < i){
                std::cout << "Push: " << graph->min->vertex << std::endl;
                s.push(graph->min);
                graph->removeVertex(graph->min->vertex);
            }else{
                std::cout << "Push: " << graph->max->vertex << " *" << std::endl;
                s.push(graph->max);
                graph->removeVertex(graph->max->vertex);
            }
            graph->max = nullptr;
            graph->min = nullptr;
            graph->virtualRegs--;
        }

        //Select
        bool spill = false;
        while(s.size() > 0){
            Vertex *v = s.top();
            graph->virtualRegs++;
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
                graph->virtualRegs++;
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