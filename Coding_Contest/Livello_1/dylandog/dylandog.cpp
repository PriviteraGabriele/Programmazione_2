#include<iostream>
#include<fstream>
using namespace std;

void Solve(int* vett, int n, int key, ostream& out){
    for(int i = 0; i<n; i++){
        if(key == vett[i]){
            out << (i + 1) << endl;
            return;
        }
    }
    out << 0 << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i = 0; i<100; i++){
        int n;      //Grandezza array
        in >> n;

        int key;    //Numero del volume cercato
        in >> key;

        int* vett = new int[n];
        for(int j = 0; j<n; j++){
            in >> vett[j];
        }

        Solve(vett, n, key, out);
        delete [] vett;
    }
}