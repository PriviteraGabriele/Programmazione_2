#include<iostream>
#include<fstream>
using namespace std;

#include "graph_list.h"

template<typename T>
void Processing(int n, int m, string tipo, ifstream& in, ofstream& out){
    T* vertici = new T[n];         //Array contenente i vertici da inserire nel grafo
    for(int i = 0; i<n; i++){
        in >> vertici[i];
    }

    // //PROVA STAMPA VERTICI
    // for(int i = 0; i<n; i++){
    //     cout << vertici[i] << " ";
    // }
    // cout << endl;

    //Salvataggio degli archi in un array di supporto
    string supporto[2*m];
    for(int i = 0; i<(2*m); i++){
        in >> supporto[i];
    }

    // //PROVA STAMPA ARRAY SUPPORTO
    // for(int i = 0; i<(2*m); i++){
    //     cout << supporto[i] << " - ";
    // }
    // cout << endl;

    T* sorgente = new T[m];      //Array dove salvo la sorgente dell'Arco
    T* destinazione = new T[m];     //Array dove salvo la destinazione dell'Arco

    int k = 0;      //Mi serve per scorrermi gli array sorgente e dsestinazione

    //Mi ricavo i vertici e li inserisco negli array sorgente e dsestinazione
    for(int i = 0; i<(2*m); i++){
        int l = supporto[i].length();
        string tmp = "";
        for(int j = 0; j<l; j++){
            if(supporto[i][j] >= '0' && supporto[i][j] <= '9' || supporto[i][j] == '.' || supporto[i][j] >= 'A' && supporto[i][j] <= 'Z'){
                tmp += supporto[i][j];
            }
        }

        if(i % 2 == 0){
            if(tipo == "int"){
                
                sorgente[k] = stoi(tmp);
            }
            else if(tipo == "double"){
                sorgente[k] = stod(tmp);
            }
            else{
                sorgente[k] = tmp[0];
            }
        }
        else{
            if(tipo == "int"){
                destinazione[k] = stoi(tmp);
            }
            else if(tipo == "double"){
                destinazione[k] = stod(tmp);
            }
            else{
                destinazione[k] = tmp[0];
            }
            k++;
        }
    }

    // //PROVA STAMPA ARRAY SORGENTE E DESTINAZIONE
    // cout << "sorgente = [";
    // for(int i = 0; i<m; i++){
    //     cout << sorgente[i] << " ";
    // }
    // cout << "]" << endl;

    // cout << "destinazione = [";
    // for(int i = 0; i<m; i++){
    //     cout << destinazione[i] << " ";
    // }
    // cout << "]" << endl;

    GraphList<T> g;

    //Inserimento dei vertici nel grafo
    for(int i = 0; i<n; i++){
        g.addVertex(vertici[i]);
    }

    //Setting degli archi nel grafo
    for(int i = 0; i<m; i++){
        g.addEdge(sorgente[i], destinazione[i]);
    }

    //cout << g << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i = 0; i<100; i++){
        int n;      //Numero Vertici
        in >> n;

        int m;      //Numero Archi
        in >> m;

        string tipo;
        in >> tipo;

        if(tipo == "int"){
            Processing<int>(n, m, tipo, in, out);
        }
        else if(tipo == "double"){
            Processing<double>(n, m, tipo, in, out);
        }
        else if(tipo == "char"){
            Processing<char>(n, m, tipo, in, out);
        }
    }
}