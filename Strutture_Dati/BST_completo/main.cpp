#include<iostream>
using namespace std;

#include "BST.h"

int main(){
    BST<int> bst;
	
    //TEST INSERIMENTO
        bst.Insert(40);
        bst.Insert(25);
        bst.Insert(21);
        bst.Insert(18);
        bst.Insert(57);
        bst.Insert(36);
        bst.Insert(46);
        bst.Insert(32);
        bst.Insert(78);
        bst.Insert(52);
        bst.Insert(11);
        bst.Insert(44);
	
    //TEST VISITE
        cout << "VISITE:" << endl;
        cout << "\t- Visita Inorder: ";
        bst.Inorder();
        cout << endl;

        cout << "\t- Visita Preorder: ";
        bst.Preorder();
        cout << endl;

        cout << "\t- Visita Postorder: ";
        bst.Postorder();
        cout << endl;
	
    cout << endl;

    //TEST MINIMO E MASSIMO
        cout << "MINIMO E MASSIMO:" << endl;
	    cout << "\t- MIN: " << *(bst.min()) << endl;
        cout << "\t- MAX: " << *(bst.max()) << endl;
	
	cout << endl;

    //TEST PREDECESSORE E SUCCESSORE
        cout << "PREDECESSORE E SUCCESSORE:" << endl;
        cout << "\t- Il predecessore di " << *(bst.getRoot()) << " è " << *(bst.predecessor(bst.getRoot())) << endl;
        //cout << "Il predecessore di " << *(bst.search(40)) << " è " << *(bst.predecessor(bst.search(40))) << endl;
        cout << "\t- Il predecessore di " << *(bst.search(78)) << " è " << *(bst.predecessor(bst.search(78))) << endl << endl;

        cout << "\t- Il successore di " << *(bst.getRoot()) << " è " << *(bst.successor(bst.getRoot())) << endl;
        //cout << "Il successore di " << *(bst.search(40)) << " è " << *(bst.successor(bst.search(40))) << endl;
        cout << "\t- Il successore di " << *(bst.search(21)) << " è " << *(bst.successor(bst.search(21))) << endl;
	
    cout << endl;

    //TEST RICERCA
    cout << "RICERCA:" << endl;
        cout << "\t- search(42): " << (bst.search(42) ? "found" : "not found") << endl;
        cout << "\t- search(11): " << (bst.search(11) ? "found" : "not found") << endl;
        cout << "\t- search(36): " << (bst.search(36) ? "found" : "not found") << endl;
        cout << "\t- search(7): " << (bst.search(7) ? "found" : "not found") << endl;
        
    cout << endl;

    //TEST LIVELLO
        cout << "LIVELLO:" << endl;
        cout << "\t- Livello 18: " << bst.livello(18) << endl; 
        cout << "\t- Livello 32: " << bst.livello(32) << endl; 
        cout << "\t- Livello 46: " << bst.livello(46) << endl;
        cout << "\t- Livello 40: " << bst.livello(40) << endl;  

    cout << endl;

    //TEST ALTEZZA
        cout << "ALTEZZA:" << endl;
        cout << "\t- L'altezza del BST è " << bst.altezza() << endl;  

    cout << endl;

    //TEST DISTANZA SUCCESSORE
        cout << "DISTANZA SUCCESSORE:" << endl;
        cout << "\t- La distanza da 40 al suo successore è " << bst.Dist_successor(40) << endl;

    cout << endl;

    //TEST DISTANZA TRA DUE NODI
        cout << "DISTANZA TRA DUE NODI:" << endl;
        cout << "\t- La distanza tra i due nodi 18 e 52 è " << bst.distanzaChiavi(18, 52) << endl;
        cout << "\t- La distanza tra i due nodi 52 e 78 è " << bst.distanzaChiavi(52, 78) << endl;
        cout << "\t- La distanza tra i due nodi 11 e 32 è " << bst.distanzaChiavi(11, 32) << endl;

    cout << endl;

    //TEST CANCELLAZIONE
        cout << "CANCELLAZIONE:" << endl;
        cout << "\t- Cancellazione 11!" << " --> ";
        bst.remove(11);
        bst.Inorder();
        cout << endl;

        cout << "\t- Cancellazione 36!" << " --> ";
        bst.remove(36);
        bst.Inorder();
        cout << endl;

        cout << "\t- Cancellazione 57!" << " --> ";
        bst.remove(57);
        bst.Inorder();
        cout << endl;

        cout << "\t- Cancellazione 40 (RADICE)!" << " --> ";
        bst.remove(40);
        bst.Inorder();
        cout << endl;
}