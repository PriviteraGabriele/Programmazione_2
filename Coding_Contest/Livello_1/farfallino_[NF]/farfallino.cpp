#include<iostream>
#include<fstream>
using namespace std;

void farfallino(string s, ostream& out){
    int l = s.length();     //lunghezza stringa base
    int nv = 0;         //numero vocali contenute nella stringa
    for(int i = 0; i<l; i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            nv++;
        }
    }
    int k = l + (nv * 2);       //lunghezza stringa tradotta

    char vett[k] = {};
    int j = 0;
    for(int i = 0; i<l; i++){
        cout << "s[i]=" << s[i] << "-----";
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            vett[j] = s[i];
            cout << vett[j];
            j++;
            vett[j] = 'f';
            cout << vett[j];
            j++;
            vett[j] = s[i];
            cout << vett[j];
            j++;;
        }
        else{
            vett[i] = s[i];
            cout << vett[j];
            j++;
        }
        cout << " - ";
    }

    for(int i = 0; i<k; i++){
        out << vett[i];
        cout << vett[i];
    }
    out << " ";
    cout << " ";
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i = 0; i<100; i++){
        string* vett = new string[10];
        for(int i = 0; i<10; i++){
            vett[i] = "0";
            in >> vett[i];
        }

        for(int i = 0; i<10; i++){
            if(vett[i] != "0"){
                farfallino(vett[i], out);
            }
        }
        out << endl;
        delete [] vett;

    }
}