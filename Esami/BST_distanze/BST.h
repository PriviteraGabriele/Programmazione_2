#ifndef BST_H
#define BST_H

#include "BSTNode.h"
#include<iostream>

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
            if(this->isEmpty()) {
                root = new BSTNode<T>(key);
                return;
            }
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

        // NON FUNZIONA IN COMBO CON  LA FUNZIONE DI MIRKO
        // int distanzaRoot(BSTNode<T>* node, BSTNode<T>* root){
        //     int counter = 0;
            
        //     //CASO 1: Il nodo in questione è la radice
        //     if(node->getParent() == nullptr){
        //         return counter;
        //     }
        //     //CASO 2: Il nodo è figlio della radice 
        //     else if(node->getParent() == root){
        //         counter++;
        //         return counter;
        //     }
        //     //CASO 3: In questo caso il padre del mio nodo non è la radice e quindi mi richiamo ricorsivamente la mia 
        //     //funzione finche non mi riconduco al secondo caso e mi salvo un +1 per la distanza ogni volta 
        //     else if(node->getParent() != root){
        //         counter++;
        //         distanzaRoot(node->getParent(), root);
        //     }
        // }

        // int distanzaChiavi(T x, T y){
        //     BSTNode<T>* node_x = search(x);
        //     BSTNode<T>* node_y = search(y);

        //     int distanza = 0;

        //     //Uno nel sottoalbero sx e uno nel sottoalbero dx
        //     if(x <= root->getKey() && y > root->getKey() || y <= root->getKey() && x > root->getKey()){
        //         distanza = distanzaRoot(node_x, root) + distanzaRoot(node_y, root);
        //         return distanza;
        //     }
        //     else if(x <= root->getKey() && y <= root->getKey() || y > root->getKey() && x > root->getKey()){
        //         distanza = distanzaRoot(node_x, root) - distanzaRoot(node_y, root);
        //         if(distanza < 0){
        //             distanza = distanza * (-1);
        //         }
        //         distanza++;
        //         return distanza;
        //     }          
        // }

        int distanzaRoot(BSTNode<T>* nodo_h, BSTNode<T>* partenza){
			if(partenza->getKey() == nodo_h->getKey()){
				return 0;
            }

			BSTNode<T>* tmp = partenza;
			int counter = 0;
			while(tmp && tmp->getKey() != nodo_h->getKey()){
				if(nodo_h->getKey() > tmp->getKey()){ 
					tmp = tmp->getRight();
                }
                else{ 
					tmp = tmp->getLeft();
                }
                counter++;
			}
			
			if(!tmp){ 
				return -1;
            }
            else{ 
				return counter;
            }
		}

        int distanzaChiavi(T k, T h) {
			BSTNode<T>* nodo_k = search(k);
			BSTNode<T>* nodo_h = search(h);
			int counter = 0;
			if(!nodo_k || !nodo_h)
				throw out_of_range("Chiavi errate!");
				if(k <= h){
					BSTNode<T>* tmp = nodo_k;
					bool flag = true;
					while(tmp && flag) {
						int distance = distanzaRoot(nodo_h, tmp); 
						if(distance == 0){
							flag = false;
						}
                        else if(distance == -1){
							tmp = tmp->getParent(); 
							counter++; 
						}
                        else{
							counter += distance;
							flag = false;
						}
				}
				return counter;
			}
            else{
				return distanzaChiavi(h, k);
			}
		}
};

#endif