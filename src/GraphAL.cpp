#include"GraphAL.h"
/**
Construtor do Grafos
@param numVertex - Quantidade de vertices será criada dinamicamente.
Descrição - Recebe a quantidade de vertices para criar os vertices com a lista
de adjacẽncias a que serão colocados as arestas.
*/
GraphAL::GraphAL(int numVertexs){
    this->numVertexs = numVertexs; //Pega a quantidade de vertices
    this->numEdges = 0;//Nímero de arestas inicializadas com zero.
    adj = new list<AdjacencyList*> [numVertexs];//cria as listas para cada no da lista definidada como arestas.
};

/**
Método getNVertices
Descrição - retorna o numero de vertices criado.
*/
int GraphAL::getNVertexs(){
    return this->numVertexs;
};

/**
Método hasEdge - Verifica se existe aresta
@param vertexBegin - vertice de verificação se existe aresta para outro vertice
@param vertex - vertice de verificação se tem uma resta que liga o primeiro vertice com ele.
Descrição - percorre a lista e retorna o objeto de cada vertice criado e verifica se o vertice passado por parametro
e igual ao vertice do objeto.
return true/false - caso a condição seja positiva e caso a condição seja negativa.
*/
bool GraphAL::hasEdge(int vertexBegin, int vertex){

    for (list<AdjacencyList*>::iterator it = adj[vertexBegin].begin(); it != adj[vertexBegin].end(); ++it){
        AdjacencyList *edge = *it;
        if(edge->getVertex() == vertex)
            return true;
    }
    return false;
};

/**
Método inserEdge - Insere um vertice ao grafos assim construindo a aresta.
@param vertexBegin - vertece a ser inserido uma nova aresta
@param vertex - vertece que recebe o direcionamento da aresta do vertexBegin
@param directional - informa se é direcional ou unidirecional.
@param cost - informa o custo da aresta.
Descrição - O método primeiro verifica se a aresta existe, caso ainda não exista prosegue
então cria um objeto de adjacência e seta os valores da com as devidas regras e seta o nova aresta na lista
caso não seja direcional no caso false ele coloca unidirecional colocando a aresta para o vertexBegin também.
*/
bool GraphAL::insertEdge(int vertexBegin,int vertex,int directional, int cost){

    if(hasEdge(vertexBegin,vertex)){
        return false;
    }

    AdjacencyList *edge = new AdjacencyList();
    edge->setLabel("");
    edge->setVertex(vertex);
    edge->setDirectional(directional);
    edge->setCost(cost);
    adj[vertexBegin].push_back(edge);

    this->numEdges++;

    if(!directional)
    {
        AdjacencyList *edge = new AdjacencyList();
        edge->setLabel("");
        edge->setVertex(vertexBegin);
        edge->setCost(cost);
        edge->setDirectional(directional);
        adj[vertex].push_back(edge);

        this->numEdges++;
    }

    return true;
}

/**
Método isDirected - Verifica se a aresta é direcional ou unidirecional
@param vertexBegin - vertice para verifca a aresta do mesmo
@param vertex - verificar a aresta que interligam o vertexBegin com vertex
Descrição - percorrer toda a lista retornando o objeto de cada indice e verifica se aquela aresta é igual a aresta que foi passada
por paramentro, se sim, verifica se ele é direcional, se sim
return true/false se posotivo e se for falso.
*/
bool GraphAL::isDirected(int vertexBegin, int vertex){

    for (list<AdjacencyList*>::iterator it = adj[vertexBegin].begin(); it != adj[vertexBegin].end(); ++it)
    {
        AdjacencyList *edge = *it;
        if(edge->getVertex() == vertex)
            if(edge->getDirectional())
                return true;
    }
    return false;
}

/**
Método isEdgeValued - verifica se a aresta é valorada ou não.
@param vertexBegin - vertice a ser verificado a aresta.
@param vertex - vertice a ser verifado a aresta.
Descrição - percorre todos os vertices que tem ligação por aresta do vertexBegin
verifica se ele é igual ao vertice passado por parametro e verifica se o custo dele é maior que zero
assim definindo que ele tem um valor.
return true/false caso positivo e negativo
*/
bool GraphAL::isEdgeValued(int vertexBegin, int vertex){

    for (list<AdjacencyList*>::iterator it = adj[vertexBegin].begin(); it != adj[vertexBegin].end(); ++it){
        AdjacencyList *edge = *it;
        if(edge->getVertex() == vertex)
            if(edge->getCost() > 0)
                return true;
    }
    return false;
}

/**
Método GetEdgeValue - retorna o valor da aresta caso ela exista.
@param vertexBegin - vertice a ser verificado a aresta.
@param vertex - vertice para verificar a ligação da aresta.
Descrição - percorre a lista dijacênte e verifica se existe uma aresta interligando vertexBegin com vertex
se sim imprime o valor da aresta.
*/
int GraphAL::getEdgeValue(int vertexBegin, int vertex)//Retorna o valor da aresta caso ela exista
{
    for (list<AdjacencyList*>::iterator it = adj[vertexBegin].begin(); it != adj[vertexBegin].end(); ++it)
    {
        AdjacencyList *edge = *it;
        if(edge->getVertex() == vertex)
            return edge->getCost();
    }
    return 0;
}
/**
Método getNEdges - retorna a quantidade de aresta criadas
*/
int GraphAL::getNEdges(){
    return this->numEdges;
}

void GraphAL::removeEdge(int vertexBegin, int vertex){

    for (int i = 0; i < this->numVertexs; i++){
        for (list<AdjacencyList*>::iterator it = adj[vertexBegin].begin(); it != adj[vertexBegin].end(); ++it) {
            AdjacencyList *edge = *it;
            if(edge->getVertex() == vertex){

                bool directional = edge->getDirectional();
                adj[vertexBegin].remove(edge);
                this->numEdges--;

                if(!directional){
                    for (list<AdjacencyList *>::iterator it2 = adj[vertex].begin(); it2 != adj[vertex].end(); ++it2) {
                         AdjacencyList *edge2 = *it2;
                        if(edge2->getVertex() == vertexBegin){
                            adj[vertex].remove(edge2);
                           this->numEdges--;  // subtract an edge from the variable.
                        }
                    return;
                }
            }
        }
    }
}

}

/**
Método getAdjacencyVertex - mostrar todas as adjacências do vertice
*/
void GraphAL::getAdjacencyVertex(int vertex){
    cout << "\n\t( vertex: " << vertex<< " ) Adjacency: ";
    for (list<AdjacencyList*>::iterator it = adj[vertex].begin(); it != adj[vertex].end(); ++it) {
            AdjacencyList *edge = *it;
            cout << edge->getVertex()<<" -> ";
    }
    cout << endl;
}


void GraphAL::getIncidentEdges(int vertex){
    cout << "\n\t( vertex:" << vertex << ") Incident ";

    for (list<AdjacencyList*>::iterator it = adj[vertex].begin(); it != adj[vertex].end(); ++it) {
         AdjacencyList *edge = *it;
        if(hasEdge(edge->getVertex(), vertex) || (hasEdge(vertex, edge->getVertex()))) {
            cout << edge->getVertex() << " -> ";
        }
        }
    cout << endl;
}

/**
Método setVertexLabel - seta um rotulo para o vertice
*/
void GraphAL::setVertexLabel(int vertex,string label){
    list<AdjacencyList*>::iterator it;
    it = adj[vertex].begin();
    AdjacencyList *edge = *it; // Edge receives the vertex memory address entered.
    edge->setLabel(label); // Add a name to the vertex informed.
}

/**
Método getVertexLabel - mostra o rotulo do vertice
*/
string GraphAL::getVertexLabel(int vertex){
    list<AdjacencyList*>::iterator it;
    it = adj[vertex].begin();
    AdjacencyList *edge = *it;
    return edge->getLabel(); // Prints the vertex label v informed.
}

/**
Método - printGraph - mostra todos os dados do grafos
*/
void GraphAL::printGraph() {
    cout <<endl;
    for (int i = 0; i < this->numVertexs; i++){
        cout << "\t Vertex: [ " << i << " ]" << " --> ";
        for (list<AdjacencyList*>::iterator it = adj[i].begin(); it != adj[i].end(); ++it) {
            AdjacencyList *edge = *it;
            cout << edge->getLabel() << " [" << edge->getVertex()<<"]";
        }
        cout <<endl;
    }
    cout <<endl;
}


