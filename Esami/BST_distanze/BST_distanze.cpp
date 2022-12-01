#include<iostream>
#include<fstream>
using namespace std;

#include "BST.h"

template<typename T>
void Process_Input(string* vett, int n, string tipo, ifstream& in){
    T key1;
    in >> key1;
    cout << key1 << " ";

    T key2;
    in >> key2;
    cout << key2 << endl;

    BST<T> bst;

    //Conversione e inserimento dell'input nel BST
    for(int j = 0; j<n; j++){
        int l = vett[j].length();
        string tmp = "";
        for(int x = 4; x<l; x++){
            tmp += vett[j][x];
        }
        if(tipo == "int"){
            int key = stoi(tmp);
            bst.Insert(key);
        }
        else if(tipo == "double"){
            T key = stod(tmp);
            bst.Insert(key);
        }
        else if(tipo == "bool"){
            T key = stoi(tmp);
            bst.Insert(key);
        }
        else if(tipo == "char"){
            T key = tmp[0];
            bst.Insert(key);
        }
    }

    //Calcolo distanza tra le due key prese in input
    cout << "Output: ";
    cout << bst.distanzaChiavi(key1, key2) << endl << endl;
}

int main(){
    ifstream in("input.txt");

    for(int i = 0; i<4; i++){       //Dovrebbe essere i<6 ma faccio solo 4 task per provare i vari tipi di dato
        cout << "Input: ";
        
        string tipo;
        in >> tipo;
        cout << tipo << " ";

        int n; 
        in >> n;
        cout << n << " ";

        string* vett = new string[n];
        for(int j = 0; j<n; j++){
            in >> vett[j];
            cout << vett[j] << " ";
        }

        if(tipo == "int"){
            Process_Input<int>(vett, n, tipo, in);
        }
        else if(tipo == "double"){
            Process_Input<double>(vett, n, tipo, in);
        }
        else if(tipo == "bool"){
            Process_Input<bool>(vett, n, tipo, in);
        }
        else if(tipo == "char"){
            Process_Input<char>(vett, n, tipo, in);
        }
    }
}