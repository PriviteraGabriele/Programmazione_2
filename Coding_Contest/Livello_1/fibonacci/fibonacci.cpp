#include<iostream>
#include<fstream>
using namespace std;

long fibonacci_interattiva(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    long sum_1 = 1;      //rappresenta il valore della sequenza di fibonacci fino alla i-1esima iterazione
    long sum_2 = 1;      //rappresenta il valore della sequenza di fibonacci fino alla i-2esima iterazione
    long x;
    for(int i = 2; i<=n; i++){
        x = sum_2;
        sum_2 = sum_1;
        sum_1 = x + sum_1;
    }
    return sum_1;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    //Creo un array dove vado a salvare la sequenza di fibonacci da 1 fino a 60
    long F_array[61];
    for(int i = 0; i<=60; i++){
        F_array[i] = fibonacci_interattiva(i);
        cout << "F_array[" << i << "]=" << F_array[i] << endl;
    }
    cout << endl;

    for(int i = 0; i<100; i++){
        int n;
        in >> n;

        out << F_array[n-1] << endl;
    }
}