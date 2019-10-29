#ifndef GRAPHAL_H
#define GRAPHAL_H

#include<algorithm>
#include<list>
#include"AdjacencyList.h"

using namespace std;

class GraphAL{

private:
    int numVertexs; /*Número de vertices a ser criada no grafos*/
    list<AdjacencyList*> *adj; /*Ponteiro para um array contendo as listas de adjacências*/
    int numEdges;/*Numero de arestas do grafos*/

public:
   GraphAL(int numVertexs);
   int getNVertexs();
   bool insertEdge(int vertexBegin,int vertex,int directional, int cost);
   bool hasEdge(int vertexBegin,int vertex);
   bool isDirected(int vertexBegin,int vertex);
   bool isEdgeValued(int vertexBegin,int vertex);
   int getEdgeValue(int vertexBegin,int vertex);
   int getNEdges();
   void removeEdge(int vertexBegin,int vertex);
   void getAdjacencyVertex(int vertex);
   void getIncidentEdges(int vertex);
   void setVertexLabel(int vertex,string label);
   string getVertexLabel(int vertex);
   void printGraph();
};

#endif // GRAPHAL_H
