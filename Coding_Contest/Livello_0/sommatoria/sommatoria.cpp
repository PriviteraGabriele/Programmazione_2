#include<iostream>
#include<fstream>
using namespace std;

void Sommatoria(double* vett, int n, ostream& out){
    double somma = 0;
    for(int i = 0; i<n; i++){
        somma += vett[i];
    }
    out << somma << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i = 0; i<100; i++){
        int n;
        in >> n;

        double* vett = new double[n];
        for(int j = 0; j<n; j++){
            in >> vett[j];
        }

        Sommatoria(vett, n, out);
        delete [] vett;
    }
}