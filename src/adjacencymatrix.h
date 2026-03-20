#pragma once 
#define ADJACENCTMATRIX

#include "../include/graph.h"

#include <stdexcept>
#include <vector>


class AdjacentMatrix : public Graph {
    private: 
        
        int numvertices;
        bool** matrix;

        void checkVertex(int x) const {
            if ( x < 0 || x >= numvertices) {
                throw std::out_of_range("Out of bounds");
            }
        }

    public:

        AdjacentMatrix (int vertices) {
            numvertices = vertices;
            
            matrix = new bool*[numvertices];

            for (int i = 0; i < numvertices; i++){
                matrix[i] = new bool[numvertices]{false};
            } 
        }
        ~AdjacentMatrix() {
            for (int i = 0; i < numvertices; i++){
                delete[] matrix[i];
            }

                delete[] matrix;
        }
        
        
        void add (int i , int j) override {
            checkVertex(i);
            checkVertex(j);
            matrix[i][j] = true;
        }

        void remove (int i, int j) override {
            checkVertex(i);
            checkVertex(j);
            matrix[i][j] = false;
        }

        bool hasEdge (int i, int j) const override {
            checkVertex(i);
            checkVertex(j);
            return matrix[i][j]; 
        }

        std::vector<int> outEdges(int i) const override {
            checkVertex(i);
            std::vector<int> edges; 

            for (int j = 0; j < numvertices; j++) {

                if (matrix[i][j]) {
                    edges.push_back(j);
                }
            }
            return edges;
        }

        std::vector<int> inEdges (int i) const override {
            checkVertex(i);
            std::vector<int> edges;

            for (int k = 0; k < numvertices; k++){

                if (matrix[k][i]) {
                    edges.push_back(k);
                }
            }
            return edges;
        }

        int getCountVertices() const override {
            return numvertices;
        }

};
