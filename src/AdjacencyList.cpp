#include "AdjacencyList.h"

void AdjacencyList :: setLabel(string label){
    this->label = label;
}

string AdjacencyList :: getLabel(){
    return this->label;
}

void AdjacencyList :: setVertex(int vertex){
    this->vertex = vertex;
}

int AdjacencyList:: getVertex(){
    return this->vertex;
}

void AdjacencyList:: setDirectional(bool directional){
    this->directional = directional;
}

bool AdjacencyList:: getDirectional(){
    return this->directional;
}

void AdjacencyList::setCost(int cost){
    this->cost = cost;
}

int AdjacencyList::getCost(){
    return this->cost;
}
