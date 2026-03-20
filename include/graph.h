
#pragma once 
#define GRAPH 
#include <vector>

class Graph {

    public:
        virtual  ~Graph() {}

        virtual void add (int i, int j) = 0; 

        virtual void remove (int i, int j) = 0;

        virtual bool hasEdge(int i, int j) const = 0;

        virtual std::vector<int> outEdges(int i) const = 0;

        virtual std::vector<int> inEdges(int i) const = 0;

        virtual int getCountVertices() const = 0; 

};
