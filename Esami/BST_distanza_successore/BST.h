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

        BSTNode<T>* getRoot(){
            return this->root;
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
        
        void Inorder(){
            Inorder(root);
        }

        void Inorder(BSTNode<T>* p){
            if(p != nullptr){
                Inorder(p->getLeft());
                cout << *p;
                Inorder(p->getRight());
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

        BSTNode<T>* max(){
            return max(root);
            }

		BSTNode<T>* max(BSTNode<T>* from){

			if(isEmpty()){
                throw out_of_range("Empty bst...");
                }

			BSTNode<T>* p = from;
			while(p->right){
				p = p->right;
                }
			return p;
		}

        int distanzaSuccessore(T key){
            int count=0;
            BSTNode<T> *p = search(key);

            if(!p || p == max()) {
                return 0;
            }

            if(p->getRight()){
                p = p->getRight();
                count++;
                while(p->getLeft()){
                    p = p->getLeft();
                    count++;
                }
                return count;
            }
            BSTNode<T>* y = p->getParent();
            count++;

            while(p && p == y->getRight()){
                p = p->getParent();
                y = y->getParent();
                count ++;
            }

            return count;
        }
};

#endif