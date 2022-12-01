#include<iostream>
#include<fstream>
using namespace std;

void Operazioni(string* vett, int n, ostream& out){
    for(int i = 0; i<n; i++){
        int pos_segno = 0;

        //Cerco la posizione del segno
        for(int j = 1; j<vett[i].length(); j++){
            if(!(vett[i][j] >= '0' && vett[i][j] <= '9')){
                pos_segno = j;
                break;
            }
        }

        //Mi ricavo il primo operando
        string val1;
        for(int j = 0; j<pos_segno; j++){
            val1 += vett[i][j];
        }
        int valore1 = stoi(val1);

        //Mi ricavo il secondo operando
        string val2;
        for(int j = pos_segno + 1; j<vett[i].length(); j++){
            val2 += vett[i][j];
        }
        int valore2 = stoi(val2);

        //Eseguo l'operazione
        int operazione = 0;
        if(vett[i][pos_segno] == '+'){
            operazione = valore1 + valore2;
        }
        else if(vett[i][pos_segno] == '-'){
            operazione = valore1 - valore2;
        }
        else if(vett[i][pos_segno] == '*'){
            operazione = valore1 * valore2;
        }

        out << operazione << " ";
    }
    out << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i = 0; i<100; i++){
        int n;
        in >> n;

        string* vett = new string[n];
        for(int j = 0; j<n; j++){
            in >> vett[j];
        }

        Operazioni(vett, n, out);
        delete [] vett;
    }
}