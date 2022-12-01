#include <iostream>
#include <fstream>

using namespace std;

template <typename T>
/*void bubbleSort(T*arr, int n) {
    bool scambio = true;
    int appoggio;
    while (scambio) {
        scambio = false;
        for (int i=0; i<n; i++) {
        if (arr[i] > arr[i + 1]) {
            appoggio = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = appoggio;
            scambio = true;
        }
      }
    }
}*/

void selectionSort(T array[], int n) {
	int indexMin;
	
	for(int i=0; i < n; i++) {
		indexMin = i;
		for(int j=i+1; j < n; j++) {
			if(array[j] < array[indexMin])
				indexMin = j;
		}
		
		swap(array[i], array[indexMin]);
	}
}

template <typename T>
void selectionSort(T array[], T arrayDue[], int n) {
	int indexMin;
    
	for(int i=0; i < n; i++) {
		indexMin = i;
		for(int j=i+1; j < n; j++) {
			if(array[j] < array[indexMin])
				indexMin = j;
		}
		swap(array[i], array[indexMin]);
        swap(arrayDue[i], arrayDue[indexMin]);
	}
}

template <typename T>
struct Nodo {
    T valore;
    Nodo<T> *succ;
};

template <typename T>
class Lista {
    private :
    Nodo<T> *testa;

    public :
    Lista() : testa(nullptr) {}

     Nodo<T>* search(T indice) {
	 Nodo<T>* p;
	 for (p=this->testa; p!=NULL; p=p->succ)
		if (p->valore==indice)
			return p;
	 return NULL;
    }

    void insert(T val) {
        /*Nodo<T> *nuovo = new Nodo<T>;
        nuovo -> valore = val;
        nuovo -> succ = this -> testa;
        this -> testa = nuovo;*/

        Nodo<T> *nuovo = new Nodo<T>;
    nuovo -> valore = val;
    nuovo -> succ = nullptr;

    Nodo<T> *iter = this -> testa;
    if (iter == nullptr) {
        this -> testa = nuovo;
    }
    else {
        while (iter -> succ != nullptr) {
            iter = iter -> succ;
        }
        iter -> succ = nuovo;
    }
    }

    Nodo<T> *getTesta() {return testa;}

    void print() {
        Nodo<T> *iter = getTesta();
        while (iter != nullptr) {
            cout << iter -> valore << "-->";
            iter = iter -> succ;
        }
        cout << "NULL" << endl;
    }
};

template <typename T>
class LGraph {
    int len;
    int n; 
    int m;

    T **Lpunta;
    Lista<int> **Adj;

    int findIndex(T x) {
        for (int i=0; i<n; i++) 
            if (*Lpunta[i] == x) return i;
            return - 1;
    } 

    public :
    LGraph(int len) {
        this -> len = len;
        n = m = 0;
        Lpunta = new T*[len];
        for (int i=0; i<len; i++) {
            Lpunta[i] = NULL;
        }
        Adj = new Lista<int>*[len];
        for (int i=0; i<len; i++) {
            Adj[i] = new Lista<int>();
        }
    }

    LGraph<T>* addNode(T k) {
        if (n == len) return this;
        if (findIndex(k) >= 0) return this;
        Lpunta[n] = new T(k);
        n++;
        return this;
    }

    LGraph<T>* addEdge(T x, T y) {
        int i = findIndex(x);
        int j = findIndex(y);
        if (i < 0 || j < 0) return this;
        if (!Adj[i] -> search(j)) {
            Adj[i] -> insert(j);
            m++;
        }
        return this;
    }

    void print (ostream& out) {
        for (int i=0; i<n; i++) {
            out << "(" << *Lpunta[i];
            Nodo<int>* iter =&(*Adj[i]->getTesta());
            //Nodo<T> *iter = Adj[i] -> getTesta();
            for(int c=0; iter!=NULL; iter=iter->succ, c++){
            //for (; iter != NULL; iter = iter -> succ) {
                out << " " << *Lpunta[iter -> valore];
            }
            out << ") ";
        }
        out << endl;
    }
};

template<typename T>
void Processing(int n, int m, string tipo, ifstream& in, ofstream& out){
    T* vertici = new T[n];         //Array contenente i vertici da inserire nel grafo
    for(int i = 0; i<n; i++){
        in >> vertici[i];
    }

    // //PROVA STAMPA VERTICI
    // for(int i = 0; i<n; i++){
    //     cout << vertici[i] << " ";
    // }
    // cout << endl;

    //Salvataggio degli archi in un array di supporto
    string supporto[2*m];
    for(int i = 0; i<(2*m); i++){
        in >> supporto[i];
    }

    // //PROVA STAMPA ARRAY SUPPORTO
    // for(int i = 0; i<(2*m); i++){
    //     cout << supporto[i] << " - ";
    // }
    // cout << endl;

    T* sorgente = new T[m];      //Array dove salvo la sorgente dell'Arco
    T* destinazione = new T[m];     //Array dove salvo la destinazione dell'Arco

    int k = 0;      //Mi serve per scorrermi gli array sorgente e dsestinazione

    //Mi ricavo i vertici e li inserisco negli array sorgente e dsestinazione
    for(int i = 0; i<(2*m); i++){
        int l = supporto[i].length();
        string tmp = "";
        for(int j = 0; j<l; j++){
            if(supporto[i][j] >= '0' && supporto[i][j] <= '9' || supporto[i][j] == '.' || supporto[i][j] >= 'A' && supporto[i][j] <= 'Z'){
                tmp += supporto[i][j];
            }
        }

        if(i % 2 == 0){
            if(tipo == "int"){
                
                sorgente[k] = stoi(tmp);
            }
            else if(tipo == "double"){
                sorgente[k] = stod(tmp);
            }
            else{
                sorgente[k] = tmp[0];
            }
        }
        else{
            if(tipo == "int"){
                destinazione[k] = stoi(tmp);
            }
            else if(tipo == "double"){
                destinazione[k] = stod(tmp);
            }
            else{
                destinazione[k] = tmp[0];
            }
            k++;
        }
    }

    // //PROVA STAMPA ARRAY SORGENTE E DESTINAZIONE
    // cout << "sorgente = [";
    // for(int i = 0; i<m; i++){
    //     cout << sorgente[i] << " ";
    // }
    // cout << "]" << endl;

    // cout << "destinazione = [";
    // for(int i = 0; i<m; i++){
    //     cout << destinazione[i] << " ";
    // }
    // cout << "]" << endl;

    LGraph<T> g(100);

    //Inserimento dei vertici nel grafo
    for(int i = 0; i<n; i++){
        g.addNode(vertici[i]);
    }

    //Setting degli archi nel grafo
    for(int i = 0; i<m; i++){
        g.addEdge(sorgente[i], destinazione[i]);
    }

    g.print(out);
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i = 0; i<100; i++){
        int n;      //Numero Vertici
        in >> n;

        int m;      //Numero Archi
        in >> m;

        string tipo;
        in >> tipo;

        if(tipo == "int"){
            Processing<int>(n, m, tipo, in, out);
        }
        else if(tipo == "double"){
            Processing<double>(n, m, tipo, in, out);
        }
        else if(tipo == "char"){
            Processing<char>(n, m, tipo, in, out);
        }
    }
}