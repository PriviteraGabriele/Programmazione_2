#ifndef BST_NODE_H
#define BST_NODE_H

#include <iostream>
using namespace std;

template<typename H>
class BSTNode {
    protected:
        H key;
        BSTNode<H>* left;
        BSTNode<H>* right;
        BSTNode<H>* parent;
        bool verbose;

        template<typename U>
	    friend class BST;

    public:
        BSTNode(H key, bool verbose = false) : key(key), verbose(verbose){
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

        void setKey(H key){
            this->key = key;
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
            if(b.verbose){
                os << "BSTNode: " << &b << endl;
                os << "Key =" << b.key << endl;
                os << "left->" << b.left << "\t right->" << b.right << "\t parent->" << b.parent << endl;
                return os;
            }
            return os << "\tKey = " << b.key << endl;
	    }
};

#endif