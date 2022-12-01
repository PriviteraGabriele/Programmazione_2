#ifndef BSTNODE_H
#define BSTNODE_H

#include<iostream>
#include<fstream>
using namespace std;

template<typename H>
class BSTNode {
    protected:
        H key;
        BSTNode<H>* left;
        BSTNode<H>* right;
        BSTNode<H>* parent;

        template<typename U>
	    friend class BST;

    public:
        BSTNode(H key) : key(key){
            left = nullptr;
            right = nullptr;
            parent = nullptr;
        }

        void setLeft(BSTNode<H>* left){
            this->left = left;
        }

        void setRight(BSTNode<H>* right){
            this->right = right;
        }

        void setParent(BSTNode<H>* parent){
            this->parent = parent;
        }

        BSTNode<H>* getLeft(){
            return left;
        }

        BSTNode<H>* getRight(){
            return right;
        }

        BSTNode<H>* getParent(){
            return parent;
        }

        H getKey(){
            return key;
        }

        friend ostream& operator<< (ostream& os, const BSTNode<H>& b){
            return os << "Key = " << b.key << endl;
        }
};

#endif