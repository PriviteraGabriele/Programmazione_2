#ifndef LIST_FILM_H
#define LIST_FILM_H

#include<iostream>
#include "node_film.h"

using namespace std;

class List {
	protected:
	Node* head;
	int size = 0;
	
	public:
	
	List(){
		head = nullptr;
	}
	
	bool isEmpty() {
		return head == nullptr;
	}
	
	Node* getHead() const{ 
		return head; 
	}
	
	void insert(string data, string nome, string genere){
		if(this->isEmpty()) {
			head = new Node(data, nome, genere);
			size++;
			return;
		}
	}
	
	void insertHead(string data, string nome, string genere){	
		Node* temp = new Node(data, nome, genere);
		temp->next = head;
		this->head = temp;
		size++;
	}
	
	void insertTail(string data, string nome, string genere){
		if(this->isEmpty()){
			this->insertHead(data, nome, genere);
			return;
		}
		
		Node* p = head;
		while(p->getNext() != nullptr){
			p = p->getNext();
		}
		
		Node* temp = new Node(data, nome, genere);
		p->next = temp;
		size++;
	}
	
	void insertInOrder(string data, string nome, string genere){
		
		if(this->isEmpty()){
			this->insertHead(data, nome, genere);
			return;
		}
		if(data <= head->getData()){
			this->insertHead(data, nome, genere);
			return;
		}
		
		Node* p = head;
		while(p->getNext() && (data >= p->getData())){
			
			if(data <= p->getNext()->getData())
				break;
			
			p = p->getNext();
		}
		
		if(!(p->getNext())){
			this->insertTail(data, nome, genere);
			return;
		}
		
		Node* toInsert = new Node(data, nome, genere);
		toInsert->setNext(p->getNext());
		p->setNext(toInsert);
		size++;
			
	}

	void film_piu_nuovo(){
		Node *ptr = getHead();
		while(ptr != nullptr) {
			if(ptr->getNext() == nullptr){
				cout << "Il film più nuovo è: " << *ptr << endl;
			}
			ptr = ptr->getNext();
		}
	}

	void film_piu_vecchio(){
		Node *ptr = getHead();
		cout << "Il film più vecchio è: " << *ptr << endl;
	}

	void film_dato_un_genere(string genere){
		Node *ptr = getHead();
		cout << "I film di genere " << genere << " presenti in lista sono:" << endl;
		while(ptr != nullptr) {
			if(genere == ptr->getGenere()){
				cout << "\t" << *ptr << endl;
			}
			ptr = ptr->getNext();
		}
		cout << endl;
	}
	
	friend ostream& operator<<(ostream& out, const List &list) {
		out << "Lista Film:" << endl;
		Node *ptr = list.head;
		while(ptr->getNext() != nullptr) {
			out  << "\t" << *ptr << endl;
			ptr = ptr->getNext();
		}
		out  << "\t" << *ptr << endl;
		return out;
	}
};

#endif