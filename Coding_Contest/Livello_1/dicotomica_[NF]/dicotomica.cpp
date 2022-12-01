#include<iostream>
#include<fstream>
using namespace std;

void Dicotomica(int* vett, int n, int key, ostream& out){
    int contatore = 0;      
    int low = 0;
	int high = n-1;
	
	while(low<=high) {
		int mid = (low+high)/2;
		if(vett[mid]==key) {
            contatore++;
            cout << contatore << " ";
			// out << contatore << endl;       //Key trovata
            // break;
	    }
		else if (vett[mid]<key){
			low = mid + 1;
            contatore++;
            cout << contatore << " ";
		}
		else{
			high = mid - 1;
            contatore++;
            cout << contatore << " ";
		}
	}
	out << contatore << endl;       //Key non trovata	
    cout << contatore << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i = 0; i<100; i++){
        int n;
        in >> n;

        int* vett = new int[n];
        for(int i = 0; i<n; i++){
            in >> vett[i];
        }

        int key;
        in >> key;

        Dicotomica(vett, n, key, out);
        delete [] vett;
    }
}