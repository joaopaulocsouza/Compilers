#ifndef REGALLOC_HPP
#define REGALLOC_HPP

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <map>


class Graph;

class Vertex {
    public:
        int vertex;
        std::vector<int> edges;
        int color;
        bool virtualReg;
        bool spill;
        bool removed;
        int countEdge;

        Vertex(int vertex, int colors) {
            this->vertex = vertex;
            this->color = -1;
            this->virtualReg = vertex>=colors;
            this->spill = false;
            this->countEdge = 0;
            this->removed = false;
        }

        void addEdge(int vertex, Vertex *v) {
           for( int i = 0; i < edges.size(); i++) {
                if (edges[i] == vertex) {
                    return;
                }
            }
            edges.push_back(vertex);
            v->edges.push_back(this->vertex);
        }

        int getVertex() {
            return vertex;
        }

        std::vector<int> getEdge() {
            return edges;
        }

        int getColor() {
            return color;
        }

        void setColor(int color) {
            this->color = color;
        }
};

class Graph {
    struct ResultType {
        bool spill;
        int k;
    };
    public:
        int G;
        int colors;
        int virtualRegs;
        std::map<int, Vertex*> vertices;
        std::vector<ResultType> result;
        Vertex *max, *min;

        Graph() {
            this->G = 0;
            this->colors = 0;
            this->virtualRegs = 0;
            this->max = nullptr;
            this->min = nullptr;
        }

        Graph(int V) {
            this->G = V;
        }

        void addVertex(Vertex* vertex) {
            if(!vertices[vertex->vertex]) {
                vertices[vertex->vertex] = vertex;
                if(vertex->virtualReg) {
                    virtualRegs++;
                }
            }
        }

        bool findVertex(int vertex) {
            if (vertices[vertex]) {
                return true;
            }
            return false;
        }

        void removeVertex(int vertex) {
            if (vertices[vertex] && vertices[vertex]->virtualReg) {
                vertices[vertex]->removed = true;
            }
        }

        Vertex *getVertex(int vertex) {
            if (vertices[vertex]) {
                return vertices[vertex];
            }
            return NULL;
        }

        int countEdge(int vertex) {
            int count = 0;
            Vertex *v = vertices[vertex];
            for (int i = 0; i < v->edges.size(); i++) {
                Vertex *u = getVertex(v->edges[i]);
                if (!u->removed) {
                    count++;
                }
            }
            v->countEdge = count;
            return count;
        }

        int countVirtualEdge(int vertex) {
            int count = 0;
            Vertex *v = vertices[vertex];
            for (int i = 0; i < v->edges.size(); i++) {
                Vertex *u = getVertex(v->edges[i]);
                if (!u->removed && u->virtualReg) {
                    count++;
                }
            }
            return count;
        }

        void setMaxMinVertex(){
            for(auto v: vertices){
                if(v.second->virtualReg && !v.second->removed){
                    countEdge(v.first);
                    //min
                    if (min == nullptr || v.second->countEdge < min->countEdge) {
                        min = v.second;
                    }else if(v.second->countEdge == min->countEdge && v.second->vertex < min->vertex){
                        min = v.second;
                    }

                    //max
                    if (max == nullptr || v.second->countEdge > max->countEdge) {
                        max = v.second;
                    }else if(v.second->countEdge == max->countEdge && v.second->vertex < max->vertex){
                        max = v.second;
                    }
                }
            }
        }

        void getColor(int vertex, int maxColor){
            std::vector<int> avaliableColors;
            Vertex *v = vertices[vertex];

            for(int i = 0; i <= maxColor; i++){
                avaliableColors.push_back(i);
            }
            for(int i = 0; i < v->edges.size(); i++){
                Vertex *u = getVertex(v->edges[i]);
                if(!u->virtualReg){
                    avaliableColors.erase(std::remove(avaliableColors.begin(), avaliableColors.end(), u->vertex), avaliableColors.end());
                }else if(!u->removed){
                    avaliableColors.erase(std::remove(avaliableColors.begin(), avaliableColors.end(), u->color), avaliableColors.end());
                }
            }

            v->color = avaliableColors.size() > 0? avaliableColors[0]:-1;
        }
     
        void resetVertexes() {
            auto iter = vertices.begin();
            while (iter != vertices.end()) {
                iter->second->color = -1;
                iter->second->spill = false;
                iter->second->removed = false;
                ++iter;
            }   
        }

        void destroyGraph() {
            auto iter = vertices.begin();
            while (iter != vertices.end()) {
                delete iter->second;
                ++iter;
            }
        }

};

#endif