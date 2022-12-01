#include<iostream>
using namespace std;

#include "BST.h"

int main(){
    BST<int> bst;

    cout << "Prima: counter = " << counter << endl << endl;

    bst.Insert(12);
    bst.Insert(34);
    bst.Insert(15);
    bst.Insert(23);
    bst.Insert(76);
    bst.Insert(23);
    bst.Insert(83);
    bst.Insert(15);
    bst.Insert(76);
    bst.Insert(8);
    bst.Insert(2);
    bst.Insert(8);
    bst.Insert(8);

    bst.Inorder();

    cout  << endl << endl << "Dopo: counter = " << counter << endl;
}