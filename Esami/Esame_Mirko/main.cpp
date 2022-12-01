#include<iostream>

#define DIM 6

using namespace std;

#include "BST.h"

int main(){
	
	BST<int> bst;
	BST<char> bst2;

	for(int i=0; i<DIM; i++){
        bst.insert(rand()%50);
        bst2.insert(rand()%('z' - 'a' + 1 ) + 'a');
        }

	cout << "BST di Interi" << endl;

    cout << "BST Root:" << endl;
    cout << *(bst.getRoot());

	cout << "\nVisita in order: " << endl;
	bst.in_order();

    cout << "\n\nBST di Char" << endl;
    cout << "BST Root:" << endl;
    cout << *(bst2.getRoot());

	cout << "\nVisita in order: " << endl;
	bst2.in_order();
    cout << "BST di Interi : " << endl;
    cout << "Distanza dal successore di 12 : " << bst.Dist_successor(12) << endl;
    cout << "Distanza tra i Nodi 12 e 43 : " << bst.Dist_fra_2Nodi(12, 43) << endl;
    cout << "\nBST di Char : " << endl;
    cout << "Distanza dal successore di r : " << bst2.Dist_successor('r') << endl;
    cout << "Distanza tra i Nodi r e h : " << bst2.Dist_fra_2Nodi('r', 'h') << endl;
    
    }