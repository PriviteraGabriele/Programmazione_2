#ifndef GRAPH_LIST_H
#define GRAPH_LIST_H

#include<iostream>
#include "list.h"

using namespace std;

//Estendo la classe list in modo da avere il vertice nella head e la lista di adiacenza dei successori
template<typename T>
class GraphVertex : public List<T> {
    public:
        GraphVertex(T key) : List<T>(){
            List<T>::insert(key);
        }

        GraphVertex() : GraphVertex(NULL) {}

        // friend ostream& operator<<(ostream& out, GraphVertex<T>& v){
        //     out << "Graph Vertex with key " << v.head->getVal() << ": ";
        //     out <<"\tAdjancency List: ";
        //     Node<T> *ptr = v.getHead(); //
        //     while(ptr->getNext()){
        //         out << " -> " << ptr->getVal();
        //         ptr = ptr->getNext();
        //     }
        //     return out;
        // }
};

template<typename T>
class GraphList {
    private:
        List< GraphVertex<T> > vertices;
        int nVertices = 0;
        bool isOriented;

    public:
        GraphList(bool isOriented = true) : isOriented(isOriented) {}

        void addVertex(T key){
            GraphVertex<T> toInsert(key);
            vertices.insertTail(toInsert);
            nVertices++;
        }

        void addEdge(T key1, T key2){
            Node< GraphVertex<T> > *node1 = this->search(key1);
            Node< GraphVertex<T> > *node2 = this->search(key2);

            if(node1 && node2){
                node1->getVal().insertTail(key2);
                if(!this->isOriented){
                    node2->getVal().insertTail(key1);
                }
            }
        }

        Node< GraphVertex<T> >* search(T key){
            if(nVertices == 0){
                return NULL;
            }

            Node< GraphVertex<T> > *ptr = vertices.getHead();
            while(ptr){
                if(key == ptr->getVal().getHead()->getVal()){
                    return ptr;
                }
                ptr = ptr->getNext();
            }
            return NULL;
        }

        // friend ostream& operator<<(ostream& out, GraphList<T>& g){
        //     if(g.nVertices == 0){
        //         return out << "\nEmnpty Graph" << endl;
        //     }
        //     return out << g.vertices << endl;
        // }
};

#endif