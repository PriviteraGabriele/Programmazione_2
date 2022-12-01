#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define MAX_SIZE 200

template<typename H>
class StaticStack {
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
		
		H pop(){
			return array[top--];
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

        string* vett = new string[n];
        for(int j = 0; j<n; j++){
            in >> vett[j];
        }

        if(tipo == "int"){
            StaticStack<int> ss(n);
            for(int i = 0; i<n; i++){
                //Push
                if(vett[i][0] == 'i'){
                    int l = vett[i].length();
                    string tmp = "";
                    for(int j = 1; j<l; j++){
                        tmp += vett[i][j];
                    }
                    int key = stoi(tmp);
                    ss.push(key);
                }
                //Pop
                else{
                    ss.pop();
                }
            }
            ss.Print_Stack(ss, out);
        }
        else if(tipo == "double"){
            StaticStack<double> ss(n);
            for(int i = 0; i<n; i++){
                //Push
                if(vett[i][0] == 'i'){
                    int l = vett[i].length();
                    string tmp = "";
                    for(int j = 1; j<l; j++){
                        tmp += vett[i][j];
                    }
                    double key = stod(tmp);
                    ss.push(key);
                }
                //Pop
                else{
                    ss.pop();
                }
            }
            ss.Print_Stack(ss, out);
        }
        else if(tipo == "bool"){
            StaticStack<bool> ss(n);
            for(int i = 0; i<n; i++){
                //Push
                if(vett[i][0] == 'i'){
                    string tmp = "";
                    tmp += vett[i][1];
                    int key = stoi(tmp);
                    ss.push(key);
                }
                //Pop
                else{
                    ss.pop();
                }
            }
            ss.Print_Stack(ss, out);
        }
        else if(tipo == "char"){
            StaticStack<char> ss(n);
            for(int i = 0; i<n; i++){
                //Push
                if(vett[i][0] == 'i'){
                    char key = vett[i][1];
                    ss.push(key);
                }
                //Pop
                else{
                    ss.pop();
                }
            }
            ss.Print_Stack(ss, out);
        }
    }
}