#include<iostream>
#include<fstream>
using namespace std;

void Sottostringa(string* vett, int n, string s, ostream& out){
    for(int i = 0; i<n; i++){
        if(vett[i].find(s) != string::npos){
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

        string s;
        in >> s;

        string* vett = new string[n];
        for(int j = 0; j<n; j++){
            in >> vett[j];
        }

        Sottostringa(vett, n, s, out);
        delete [] vett;
    }
}