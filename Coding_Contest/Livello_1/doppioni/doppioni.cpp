#include<iostream>
#include<fstream>
using namespace std;

void ordinamento(int vett[], int n){
    for(int i = 0; i<(n -1); i++)
        for(int j = i + 1; j<n; j++)
            if(vett[i] > vett[j])
                swap(vett[i], vett[j]);
}

void contatore(int* vett, int n, ostream& out){
    ordinamento(vett, n);

    int count = 0;
    int tmp = vett[0];
    for(int i = 1; i<n; i++){
        if(tmp == vett[i])
            count++;
        else
            tmp = vett[i];
    }
    out << count << endl;
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

        contatore(vett, n, out);
        delete [] vett;
    }
}