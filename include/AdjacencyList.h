#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include<iostream>
using namespace std;

class AdjacencyList {

private:
    string label; /*Nome do vertice*/
    bool directional; /*Variável que indica se o vertice é direcional ou não direcional*/
    int cost;/*Custo do vertice*/
    int vertex; /*Vertice*/

public:
    //gets sets
    void setLabel(string label);
    string getLabel();

    void setVertex (int vertex);
    int getVertex ();

    void setDirectional(bool directional);
    bool getDirectional();

    void setCost (int cost);
    int getCost();
};
#endif // ADJACENCYLIST_H
