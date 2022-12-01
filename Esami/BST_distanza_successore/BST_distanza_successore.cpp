#include<iostream>
#include "BST.h"
using namespace std;

#define DIM 6

int main(){
	
	BST<int> bst1;
	BST<char> bst2;

	for(int i=0; i<DIM; i++){
        bst1.Insert(rand() % 50);
        bst2.Insert(rand() % ('z' - 'a' + 1 ) + 'a');
    }

	//BST interi
    cout << "BST di Interi:" << endl;

    cout << "\tBST Root: ";
    cout << *(bst1.getRoot()) << endl;
	cout << "\tVisita in order: " << endl;
	bst1.Inorder();
    cout << "\n\tDistanza dal successore di 12 : " << bst1.distanzaSuccessore(12) << endl;

    //BST char
    cout << "\nBST di Char:"  << endl;
    cout << "\tBST Root: ";
    cout << *(bst2.getRoot()) << endl;

	cout << "\tVisita in order: " << endl;
	bst2.Inorder();
    cout << "\n\tDistanza dal successore di r : " << bst2.distanzaSuccessore('r') << endl;    
}