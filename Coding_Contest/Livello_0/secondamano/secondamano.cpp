#include<iostream>
#include<fstream>
using namespace std;

void Controllo(int* vett1, int n, int* vett2, int m, ostream& out){
    int cassa = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(vett1[i] == vett2[j]){
                cassa += 5;
            }
        }
    }
    out << cassa << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i = 0; i<100; i++){
        int n;      //Il numero di fumetti che Nemo possiede
        in >> n;

        int m;      //Il numero di fumetti che Gaspare vuole acquistare
        in >> m;

        //Lista ordinata dei fumetti che Nemo possiede
        int* N_vett = new int[n];
        for(int x = 0; x<n; x++){
            in >> N_vett[x];
        }

        //Lista non ordinata di fumetti che Gaspare vorrebbe
        int* G_vett = new int[m];
        for(int y = 0; y<m; y++){
            in >> G_vett[y];
        }

        Controllo(N_vett, n, G_vett, m, out);

        delete [] N_vett;
        delete [] G_vett;
    }
}