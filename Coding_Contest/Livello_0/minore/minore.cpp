#include<iostream>
#include<fstream>
using namespace std;

#define MAX_SIZE 10000

void Minimo(int* vett, int n, ofstream &out){
    int min = 10001;
    for(int i = 0; i<n; i++){
        if(vett[i] < min){
            min = vett[i];
        }
    }
    out << min << endl;
}

int main(){

    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i = 0; i<100; i++){
        int* vett = new int[MAX_SIZE];

        string tmp;     //Stringa temporanea per controllare lo STOP
        in >> tmp;

        int j = 0;      //indice array e contatore elementi array

        //Ciclo while per riempirmi l'arrey con i valori dati in input      
        while(tmp != "STOP"){
            int val = stoi(tmp);    //Funzione per convertire una stringa in numero
            vett[j] = val;
            j++;
            in >> tmp;
        }
        
        Minimo(vett, j, out);
        delete [] vett;
    }
}


