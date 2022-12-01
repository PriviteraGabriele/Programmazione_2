#include<iostream>
#include<fstream>
using namespace std;

#define MAX_SIZE 200

template<typename H>
class StaticStack{
	H* array;
	int top = -1;
	int size = 0;
	int maxSize = -1;
	
	public:
		StaticStack(int _maxSize = MAX_SIZE) : maxSize(_maxSize){
			array = new H[maxSize];
		}
		
		void push(H val){
			if(top == maxSize-1){
				return;
            }
			array[++top] = val;
		}
		
        void Print_Stack(StaticStack<H>& s, ostream& out){
            for(int i=s.top; i >= 0; i--){
				out << s.array[i] << " ";
            }
			out << endl;
        }
};

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i = 0; i<100; i++){
        string tipo;
        in >> tipo;

        int n;
        in >> n;

        if(tipo == "int"){
            StaticStack<int> ss(n);
            for(int j = 0; j<n; j++){
                int key;
                in >> key;
                ss.push(key);
            }
            ss.Print_Stack(ss, out);
        }
        else if(tipo == "double"){
            StaticStack<double> ss(n);
            for(int j = 0; j<n; j++){
                double key;
                in >> key;
                ss.push(key);
            }
            ss.Print_Stack(ss, out);
        }
        else if(tipo == "bool"){
            StaticStack<bool> ss(n);
            for(int j = 0; j<n; j++){
                bool key;
                in >> key;
                ss.push(key);
            }
            ss.Print_Stack(ss, out);
        }
        else if(tipo == "char"){
            StaticStack<char> ss(n);
            for(int j = 0; j<n; j++){
                char key;
                in >> key;
                ss.push(key);
            }
            ss.Print_Stack(ss, out);
        }
    }
}