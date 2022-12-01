#include<iostream>
#include<fstream>
using namespace std;

void Dispari(int* vett, int n, ostream& out){
    for(int i = 0; i<n; i++){
        if(vett[i] % 2 == 1){
            out << vett[i] << " ";
        }
    }
    out << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i = 0; i<100; i++){
        int n;
        in >> n;

        int* vett = new int[n];
        for(int j = 0; j<n; j++){
            in >> vett[j];
        }

        Dispari(vett, n, out);
        delete [] vett;
    }
}