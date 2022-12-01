#ifndef BST_H
#define BST_H

#include<iostream>
using namespace std;

#include "BSTNode.h"

template<typename T>
class BST {
    private:
        BSTNode<T>* root;

    public:
        BST(){
            root = nullptr;
        }

        bool isEmpty() {
		    return root == nullptr;
	    }

        void Insert(T key){
            Insert(root, key);
        }

        void Insert(BSTNode<T>* p, T key){
            if(this->root == nullptr){
                this->root = new BSTNode<T>(key);
                return;
            }

            if(key <= p->getKey() && p->getLeft() == nullptr){
                BSTNode<T>* node = new BSTNode<T>(key);
                p->setLeft(node);
                node->setParent(p);
                return;
            }
            else if(key > p->getKey() && p->getRight() == nullptr){
                BSTNode<T>* node = new BSTNode<T>(key);
                p->setRight(node);
                node->setParent(p);
                return;
            }
            else if(key <= p->getKey() && p->getLeft() != nullptr){
                Insert(p->getLeft(), key);
            }
            else if(key > p->getKey() && p->getRight() != nullptr){
                Insert(p->getRight(), key);
            }
        }

        BSTNode<T>* min(){
		    return min(root);
	    }
	
        BSTNode<T>* min(BSTNode<T>* from){   
            if(this->isEmpty()) {
                return nullptr;
            }

            BSTNode<T>* p = from;
            while(p->getLeft()) {
                p = p->getLeft();
            }
            return p;
        }

        BSTNode<T>* search(T key) {
            return search(root, key);
        }
        
        BSTNode<T>* search(BSTNode<T>* p, T key) {
            if(p == nullptr){
                return nullptr;
            }
            if(p->getKey() == key){
                return p;
            }
            if(key <= p->getKey()){
                return search(p->getLeft(), key);
            }
            else{
                return search(p->getRight(), key);
            }
            return nullptr;
        }

        void trapianta(BSTNode<T>* u, BSTNode<T>* v){
			if(u->getParent() == NULL) root = v;
			else if(u == u->getParent()->getLeft()) u->getParent()->setLeft(v);
			else u->getParent()->setRight(v);
			
			if(v != NULL) v->setParent(u->getParent());
		}

        void remove(T key){
			BSTNode<T>* p = search(key);
			
			if(p->getLeft() == NULL) trapianta(p, p->getRight());
			else if(p->getRight() == NULL) trapianta(p, p->getLeft());
			else{
				BSTNode<T>* y = min(p->getRight());
				
				if(y->getParent() != p){
					trapianta(y, y->getRight());
					y->setRight(p->getRight());
					y->getRight()->setParent(y);
				}
				
				trapianta(p, y);
				y->setLeft(p->getLeft());
				y->getLeft()->setParent(y);
			}
			
			delete p;
		}

        int altezza(){
            return altezza(root);
        }
        
        int altezza(BSTNode<T>* p){
            if (p == nullptr){
                return 0;
            } 

            int left_height = altezza(p->getLeft());
            int right_height = altezza(p->getRight());

            if(left_height > right_height){
                return (left_height + 1);
            }   
            else{
                return (right_height + 1);
            }       
        }
};

#endif