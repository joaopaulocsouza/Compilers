#ifndef REGALLOC_HPP
#define REGALLOC_HPP

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>


class Graph;

class Vertex {
    public:
        int vertex;
        std::vector<int> edges;
        int color;
        bool virtualReg;
        bool spill;
        bool removed;

        Vertex(int vertex, int colors) {
            this->vertex = vertex;
            this->color = -1;
            this->virtualReg = vertex>=colors;
            this->spill = false;
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
        std::vector<Vertex*> vertices;
        std::vector<ResultType> result;

        Graph() {
            this->G = 0;
            this->colors = 0;
        }

        Graph(int V) {
            this->G = V;
        }

        void addVertex(Vertex* vertex) {
            if(!findVertex(vertex->getVertex())) {
                vertices.push_back(vertex);
            }
        }

        bool findVertex(int vertex) {
            for (int i = 0; i < vertices.size(); i++) {
                if (vertices[i]->getVertex() == vertex) {
                    return true;
                }
            }
            return false;
        }

        void removeVertex(int vertex) {
            for (int i = 0; i < vertices.size(); i++) {
                if (vertices[i]->getVertex() == vertex && vertices[i]->virtualReg) {
                    vertices[i]->removed = true;
                    break;
                }
            }
        }

        Vertex *getVertex(int vertex) {
            for (int i = 0; i < vertices.size(); i++) {
                if (vertices[i]->getVertex() == vertex) {
                    return vertices[i];
                }
            }
            return NULL;
        }

        bool hasVirtualReg(){
            for (int i = 0; i < vertices.size(); i++) {
                if (vertices[i]->virtualReg && !vertices[i]->removed) {
                    return true;
                }
            }
            return false;
        }

        int countEdge(int vertex) {
            int count = 0;
            Vertex *v = getVertex(vertex);
            for (int i = 0; i < v->edges.size(); i++) {
                Vertex *u = getVertex(v->edges[i]);
                if (!u->removed) {
                    count++;
                }
            }
            return count;
        }

        int countVirtualEdge(int vertex) {
            int count = 0;
            Vertex *v = getVertex(vertex);
            for (int i = 0; i < v->edges.size(); i++) {
                Vertex *u = getVertex(v->edges[i]);
                if (!u->removed && u->virtualReg) {
                    count++;
                }
            }
            return count;
        }

        Vertex *getVertexWithMinEdges() {
            Vertex *v = NULL;
            for (int i = 0; i < vertices.size(); i++) {
                if (!vertices[i]->removed && vertices[i]->virtualReg) {
                    if (v == NULL || countEdge(vertices[i]->vertex) < countEdge(v->vertex)) {
                        v = vertices[i];
                    }else if(countEdge(vertices[i]->vertex) == countEdge(v->vertex) && vertices[i]->vertex < v->vertex){
                        v = vertices[i];
                    }
                }
            }
            return v;
        }

        Vertex *getVertexWithMaxEdges(){
            Vertex *v = NULL;
            for (int i = 0; i < vertices.size(); i++) {
                if (!vertices[i]->removed && vertices[i]->virtualReg) {
                    if (v == NULL || countEdge(vertices[i]->vertex) > countEdge(v->vertex)) {
                        v = vertices[i];
                    }else if(countEdge(vertices[i]->vertex) == countEdge(v->vertex) && vertices[i]->vertex < v->vertex){
                        v = vertices[i];
                    }
                }
            }
            return v;
        }

        void getColor(int vertex, int maxColor){
            std::vector<int> avaliableColors;
            Vertex *v = getVertex(vertex);

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
           for( int i = 0; i < vertices.size(); i++) {
                vertices[i]->color = -1;
                vertices[i]->spill = false;
                vertices[i]->removed = false;
            }
        }

        void destroyGraph() {
            for (int i = 0; i < vertices.size(); i++) {
                delete vertices[i];
            }
            vertices.clear();
        }

        std::vector<Vertex *> getVertices() {
            return vertices;
        }

};

#endif