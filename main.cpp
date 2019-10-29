#include <iostream>
#include "GraphAL.h"
using namespace std;

int main(){
     //criando um grafo de quatro vertices
     /**
           10
       0--------->1
       |         /|
       |        / |
       |       /  |
    20 |      /   |30
       |     /    |
       |    /     |
       |   /      |
       |  /       |
       v /        v
       3--------->2
           40
     */

     GraphAL graph(4);
     cout<<"Number Vertexs : "<<graph.getNVertexs()<<endl<<endl;
     cout<<"Number Edge: "<<graph.getNEdges()<<endl<<endl;

     if(graph.insertEdge(0,1,true,10)){
        cout <<"Edge (0 ---> 1) create success"<<endl<<endl;
     }

     cout<<"Number Edge: "<<graph.getNEdges()<<endl<<endl;

     if(graph.insertEdge(0,3,true,20)){
        cout <<"Edge (0 ---> 3) create success"<<endl<<endl;
     }

     cout<<"Number Edge: "<<graph.getNEdges()<<endl<<endl;

     if(graph.insertEdge(1,2,true,30)){
        cout <<"Edge (1 ---> 2) create success"<<endl<<endl;
     }

     cout<<"Number Edge: "<<graph.getNEdges()<<endl<<endl;

     if(graph.insertEdge(3,1,false,0)){
        cout <<"Edge (3 ---> 1) and (3 <----1) create success"<<endl<<endl;
     }

     cout<<"Number Edge: "<<graph.getNEdges()<<endl<<endl;

     if (graph.insertEdge(3,2,true,40)){
        cout <<"Edge (3 ---> 2) create success"<<endl<<endl;
     }

     cout<<"Number Edge: "<<graph.getNEdges()<<endl<<endl;
     cout <<"Exist Edge (3 --->1) and (3 < ---1) ?"<<endl<<endl;

     if(graph.hasEdge(3,1)){
        cout<<"Exist Edge (3 ---> 1) ";
     }

     if(graph.hasEdge(1,3)){
        cout <<"Exist Edge (3 <--- 1)"<<endl<<endl;
     }

     cout <<"Exist Edge (3 ---> 0) ?"<<endl<<endl;
     if(!graph.hasEdge(3,0)){
       cout <<"No exist Edge (3 ---> 0) ?"<<endl<<endl;
     }

    cout<<"(3 --->1) is directional?"<<endl<<endl;
    if(!graph.isDirected(3,1)){
        cout <<"(3 --->1) no directional"<<endl<<endl;
    }

    cout<<"(1 --->2) is directional?"<<endl<<endl;
    if(graph.isDirected(1,2)){
        cout <<"(1 --->2) is directional"<<endl<<endl;
    }

    cout <<"Edge (3 --->1) exist value?"<<endl<<endl;
    if(!graph.isEdgeValued(3,1)){
        cout <<"Edge (3 --->1) no valued "<<graph.getEdgeValue(3,1)<<endl<<endl;
    }

    cout <<"Edge (1 --->2) exist value?"<<endl<<endl;


    if(graph.isEdgeValued(1,2)){
        cout <<"Edge (1 --->2) exist valued : "<<graph.getEdgeValue(1,2)<<endl<<endl;
    }

    cout <<"Vertex 1 Adjacency:"<<endl;
    graph.getAdjacencyVertex(1);
    cout <<"Vertex 3 Incident:"<<endl;
    graph.getIncidentEdges(3);

    graph.setVertexLabel(0,"Home");
    cout <<"Label Edje 1"<<endl;
    graph.setVertexLabel(1,"Dogs");
    cout<<graph.getVertexLabel(1)<<endl;

    graph.printGraph();
    return 0;
}
