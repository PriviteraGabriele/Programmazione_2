#include<iostream>
#include<fstream>
using namespace std;

void Change_vowel(string* vett, int n, ostream& out){
    //Array per le vocali cambiate
    char vocali[5];       
    for(int i = 0; i<5; i++){
        vocali[i] = vett[i][2];
    }

    //Array per le stringhe da trattare
    string stringhe[n - 5];       
    int j = 5;
    for(int i = 0; i<(n - 5); i++){
        stringhe[i] = vett[j];
        j++;
    }

    for(int i = 0; i<(n - 5); i++){
        for(int j = 0; j<stringhe[i].length(); j++){
            if(stringhe[i][j] == 'a'){
                stringhe[i][j] = vocali[0];
            }
            else if(stringhe[i][j] == 'e'){
             stringhe[i][j] = vocali[1];
            }
            else if(stringhe[i][j] == 'i'){
                stringhe[i][j] = vocali[2];
            }
            else if(stringhe[i][j] == 'o'){
                stringhe[i][j] = vocali[3];
            }
            else if(stringhe[i][j] == 'u'){
                stringhe[i][j] = vocali[4];
            }
        }
        if(i==n-5){
            break;
        }
        out << stringhe[i] << " ";
    }
    out << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i = 0; i<100; i++){
        string vett[1000];      //Mi vado a creare un array e lo inizializzo tutto a "";
        for(int i = 0; i<1000; i++){
            vett[i] = "";
        }

        string tmp;         //stringa temporanea dove mi salvo l'intera riga dell'input
        getline(in, tmp);

        int p = 0;          //contatore per scorrere l'array
        for(int i = 0; i<tmp.length(); i++){
            if(tmp[i] != ' '){
                vett[p] += tmp[i];
            }
            else{
                p++;
            }
        }

        int counter = 0;
        for(int i = 0; i<1000; i++){     //Mi trovo la lunghezza del mio array
            if(vett[i] != ""){
                counter++;
            }
        }

        string* vett_ok = new string[counter];      //mi creo l'arrey con la dimensione corretta
        for(int i = 0; i<counter; i++){
            vett_ok[i] = vett[i];
        }

        Change_vowel(vett_ok, counter, out);
        delete [] vett_ok;
    }
}