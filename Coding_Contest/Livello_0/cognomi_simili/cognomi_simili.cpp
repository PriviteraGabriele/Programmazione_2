#include<iostream>
#include<fstream>
using namespace std;

bool Cognomi_simili(string s1, string s2, int n){
    int counter = 0;
    for(int i = 0; i<n+1; i++){
        if(s1[i] == s2[i]){
            counter++;
        }
    }
    
    if(counter == n){
        return true;
    }
    else{
        return false;
    }
}

void Solve(string* vett, int l, int n, ofstream& out){
    if((Cognomi_simili(vett[0], vett[1], n)) && (Cognomi_simili(vett[1], vett[2], n)) && (Cognomi_simili(vett[0], vett[2], n))){
        out << vett[0] << " " << vett[1] << " " << vett[2];
    }
    else if(!(Cognomi_simili(vett[0], vett[1], n)) && !(Cognomi_simili(vett[1], vett[2], n)) && (Cognomi_simili(vett[0], vett[2], n))){
        out << vett[0] << " " << vett[2];
    }
    else if((Cognomi_simili(vett[0], vett[1], n)) && (Cognomi_simili(vett[1], vett[2], n)) && !(Cognomi_simili(vett[0], vett[2], n))){
        out << vett[0] << " " << vett[1];
    }
    else if(!(Cognomi_simili(vett[0], vett[1], n)) && (Cognomi_simili(vett[1], vett[2], n)) && (Cognomi_simili(vett[0], vett[2], n))){
        out << vett[0] << " " << vett[2];
    }
    else if((Cognomi_simili(vett[0], vett[1], n)) && !(Cognomi_simili(vett[1], vett[2], n))){
        out << vett[0] << " " << vett[1];
    }
    else if(!(Cognomi_simili(vett[0], vett[1], n)) && (Cognomi_simili(vett[1], vett[2], n))){
        out << vett[1] << " " << vett[2];
    }
    else if((Cognomi_simili(vett[0], vett[2], n)) && !(Cognomi_simili(vett[1], vett[2], n))){
        out << vett[1] << " " << vett[2];
    }
    out << endl;
}



int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i = 0; i<100; i++){
        int n;
        in >> n;

        string* vett = new string[3];
        for(int j = 0; j<3; j++){
            in >> vett[j];
        }

        Solve(vett, 3, n, out);
        delete [] vett;
    }
}
    