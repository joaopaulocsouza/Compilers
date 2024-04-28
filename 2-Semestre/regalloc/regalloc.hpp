#ifndef REGALLOC_HPP
#define REGALLOC_HPP
#include <vector>
#include <string>

class Graph;

class Vertex {

    public:
        int vertex;
        std::vector<int> edges;
        int color;

        Vertex(int vertex) {
            this->vertex = vertex;
            this->color = -1;
        }

        void addEdge(int vertex, Vertex *v) {
            for(int i = 0; i < edges.size(); i++) {
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
    public:
        int G;
        int colors;
        std::vector<Vertex*> vertices;
        std::vector<std::string> result;

        Graph() {
            this->G = 0;
            this->colors = 0;
        }

        Graph(int V) {
            this->G = V;
            // for (int i = 0; i < V; i++) {
            //     vertices.push_back(i);
            // }
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
                if (vertices[i]->getVertex() == vertex) {
                    vertices.erase(vertices.begin() + i);
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

        // void addEdge(int u, int v) {
        //     vertices[u].addEdge(v);
        //     vertices[v].addEdge(u);
        // }

        std::vector<Vertex *> getVertices() {
            return vertices;
        }

};

#endif