#include<iostream>
#include<fstream>
using namespace std;

#include "BST.h"

template<typename S>
void Process_Input(string* vett, int n, string tipo, ostream& out){
	BST<S> bst;

    S key;

	for(int i = 0; i<n; i++){
        int l = vett[i].length();

        //Inserimento
        if(vett[i][0] == 'i'){
            string tmp = "";
            for(int x = 4; x<l; x++){
                tmp += vett[i][x];
            }

            if(tipo == "int"){
                key = stoi(tmp);
            }
            else if(tipo == "double"){
                key = stod(tmp);
            }

            bst.Insert(key);
        }
        //Cancellazione
        else if(vett[i][0] == 'c'){
            string tmp = "";
            for(int x = 5; x<l; x++){
                tmp += vett[i][x];
            }

            if(tipo == "int"){
                key = stoi(tmp);
            }
            else if(tipo == "double"){
                key = stod(tmp);
            }

            bst.remove(key);
        }
    }

    out << bst.altezza() << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i = 0; i<100; i++){
        string tipo;
        in >> tipo;

        int n;
        in >> n;

        string* vett = new string[n];
        for(int i = 0; i<n; i++){
            in >> vett[i];
        }

		if(tipo == "int"){
			Process_Input<int>(vett, n, tipo, out);
		}
		else if(tipo == "double"){
			Process_Input<double>(vett, n, tipo, out);
		}
    }
}