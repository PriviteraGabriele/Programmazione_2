#ifndef LNODE_FILM_H
#define LNODE_FILM_H

#include <iostream>
using namespace std;

class Node {
	string data;			//Ordinamento in base alla data
	string nome;
	string genere;
	Node* next;
	
	friend class List;
	
	public:
	
	Node(string data, string nome, string genere) : data(data), nome(nome), genere(genere) {
		next = nullptr;
	}
	
	Node* getNext() const{ 
		return this->next; 
	}
	
	string& getData(){
		return this->data; 
	}

	string& getGenere(){
		return this->genere; 
	}

	string& getNome(){
		return this->nome; 
	}

	void setNext(Node* next){
		this->next = next;
	}
	
	friend ostream& operator<<(ostream& out, const Node &node){
		out << "- Nome = " << node.nome << ", Genere = " << node.genere << ", Data uscita = " << node.data;
		return out;
	}
};

#endif