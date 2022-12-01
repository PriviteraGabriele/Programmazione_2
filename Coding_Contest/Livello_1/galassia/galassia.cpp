#include<iostream>
#include<fstream>
using namespace std;

void Maggiore(string* vett, int n, ostream& out){
    string max = vett[0];        

    for(int i = 1; i<n; i++){
        if(max.length() < vett[i].length()){
            max = vett[i];
        }
        else if(max.length() == vett[i].length()){
            bool pippo = false;
            int p = 0;
            while(!pippo){
                if(max[p] == vett[i][p]){
                    p++;
                }
                else if(max[p] < vett[i][p]){
                    max = vett[i];
                    pippo = true;
                }
                else{
                    pippo = true;
                }
            }
        }
    }
    out << max << endl;
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

        Maggiore(vett, n, out);
        delete [] vett;
    }
}