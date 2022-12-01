#ifndef BST_H
#define BST_H

#include "BSTNode.h"
#include<iostream>

static int counter = 0;

template<typename T>
class BST {
    private:
        BSTNode<T>* root;

    public:
        BST(){
            root = nullptr;
        }

        bool search(T key) {
            return search(root, key);
        }
	
        bool search(BSTNode<T>* ptr, T key) {
            if(ptr == nullptr){ 
                return false;
            }
            if(ptr->getKey() == key){
                return true;
            }
            if(key <= ptr->getKey()){
                return search(ptr->getLeft(), key);
            }
            else{
                return search(ptr->getRight(), key);
            }
            return false;
        }

        void Insert(T key){
            Insert(root, key);
        }

        void Insert(BSTNode<T>* p, T key){
            
            if(this->root == nullptr){
                this->root = new BSTNode<T>(key);
                return;
            }

            if(search(key)){
                if(counter % 2 == 0){
                    if(key <= p->getKey() && p->getLeft() == nullptr){
                        BSTNode<T>* node = new BSTNode<T>(key);
                        p->setLeft(node);
                        node->setParent(p);
                        cout << "key = " << key << endl;
                        cout << "LA METTO A SINISTRA" << endl << endl;
                        counter++;
                        return;
                    }
                    else if(key > p->getKey() && p->getRight() == nullptr){
                        BSTNode<T>* node = new BSTNode<T>(key);
                        p->setRight(node);
                        node->setParent(p);
                        cout << "key = " << key << endl;
                        cout << "LA METTO A SINISTRA" << endl << endl;
                        counter++;
                        return;
                    }
                    else if(key <= p->getKey() && p->getLeft() != nullptr){
                        Insert(p->getLeft(), key);
                    }
                    else if(key > p->getKey() && p->getRight() != nullptr){
                        Insert(p->getRight(), key);
                    }
                }
                else{
                    if(key < p->getKey() && p->getLeft() == nullptr){
                        BSTNode<T>* node = new BSTNode<T>(key);
                        p->setLeft(node);
                        node->setParent(p);
                        cout << "key = " << key << endl;
                        cout << "LA METTO A DESTRA" << endl << endl;
                        counter++;
                        return;
                    }
                    else if(key >= p->getKey() && p->getRight() == nullptr){
                        BSTNode<T>* node = new BSTNode<T>(key);
                        p->setRight(node);
                        node->setParent(p);
                        cout << "key = " << key << endl;
                        cout << "LA METTO A DESTRA" << endl << endl;
                        counter++;
                        return;
                    }
                    else if(key < p->getKey() && p->getLeft() != nullptr){
                        Insert(p->getLeft(), key);
                    }
                    else if(key >= p->getKey() && p->getRight() != nullptr){
                        Insert(p->getRight(), key);
                    }
                }
            }
            else{
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
        }

        void Inorder(){
            Inorder(root);
        }

        void Inorder(BSTNode<T>* p){
            if(p != nullptr){
                Inorder(p->getLeft());
                cout << p->getKey() << " ";
                Inorder(p->getRight());
            }
        }
};

#endif