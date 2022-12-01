#include<iostream>
#include<fstream>
using namespace std;

#define MAX_SIZE 200

template<typename H>
class StaticQueue {
	
	H* array;
	int size = 0;
	int maxSize = MAX_SIZE;
	
	int head = -1;
	int tail = -1;
	
	public:
        StaticQueue(int maxSize = MAX_SIZE) :  maxSize(maxSize) {
            this->array = new H[maxSize];
        }
        
        void enqueue(H val) {
            if(size == maxSize){
                return;
            }
            if(head == -1){
                head = 0;
            }
            tail = (++tail % maxSize);
            array[tail] = val;
            size++;
        }

        H dequeue() {
            H val = array[head];
            head = (++head % maxSize);
            size--;
            return val;
        }
        
        void Print_queue(StaticQueue<H>& queue, ostream& out) {
            for(int i=queue.head, count=0; count<queue.size; count++) {
                out << queue.array[i] << " ";
                i = (i+1) % queue.maxSize;
            }
            out << endl;
        }
};

template<typename H>
class StaticStack : public StaticQueue<H>{
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

        void travasa(StaticStack<H>& s, StaticQueue<H>& sq, int n){
            for(int i=s.top; i >= 0; i--){
                sq.enqueue(s.array[i]);
                s.pop();
            }
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
            StaticQueue<int> sq(n);
            StaticStack<int> ss(n);

            for(int j = 0; j<n; j++){
                if(vett[j].find("e:") != string::npos){
                    int l = vett[j].length();
                    string tmp = "";
                    for(int x = 2; x<l; x++){
                        tmp += vett[j][x];
                    }
                    int key = stoi(tmp);
                    sq.enqueue(key);
                }
                else if(vett[j].find("p:") != string::npos){
                    int l = vett[j].length();
                    string tmp = "";
                    for(int x = 2; x<l; x++){
                        tmp += vett[j][x];
                    }
                    int key = stoi(tmp);
                    ss.push(key);
                }
                else if(vett[j] == "dequeue"){
                    sq.dequeue();
                }
                else if(vett[j] == "pop"){
                    ss.pop();
                }
                else if(vett[j] == "travasa"){
                    ss.travasa(ss, sq, n);
                }
            }
            sq.Print_queue(sq, out);
        }
        else if(tipo == "double"){
            StaticQueue<double> sq(n);
            StaticStack<double> ss(n);

            for(int j = 0; j<n; j++){
                if(vett[j].find("e:") != string::npos){
                    int l = vett[j].length();
                    string tmp = "";
                    for(int x = 2; x<l; x++){
                        tmp += vett[j][x];
                    }
                    double key = stod(tmp);
                    sq.enqueue(key);
                }
                else if(vett[j].find("p:") != string::npos){
                    int l = vett[j].length();
                    string tmp = "";
                    for(int x = 2; x<l; x++){
                        tmp += vett[j][x];
                    }
                    double key = stod(tmp);
                    ss.push(key);
                }
                else if(vett[j] == "dequeue"){
                    sq.dequeue();
                }
                else if(vett[j] == "pop"){
                    ss.pop();
                }
                else if(vett[j] == "travasa"){
                    ss.travasa(ss, sq, n);
                }
            }
            sq.Print_queue(sq, out);
        }
        else if(tipo == "bool"){
            StaticQueue<bool> sq(n);
            StaticStack<bool> ss(n);

            for(int j = 0; j<n; j++){
                if(vett[j].find("e:") != string::npos){
                    int l = vett[j].length();
                    string tmp = "";
                    tmp += vett[j][2];
                    int key = stoi(tmp);  
                    sq.enqueue(key);
                }
                else if(vett[j].find("p:") != string::npos){
                    int l = vett[j].length();
                    string tmp = "";
                    tmp += vett[j][2];
                    int key = stoi(tmp);  
                    ss.push(key);
                }
                else if(vett[j] == "dequeue"){
                    sq.dequeue();
                }
                else if(vett[j] == "pop"){
                    ss.pop();
                }
                else if(vett[j] == "travasa"){
                    ss.travasa(ss, sq, n);
                }
            }
            sq.Print_queue(sq, out);
        }
        else if(tipo == "char"){
            StaticQueue<char> sq(n);
            StaticStack<char> ss(n);

            for(int j = 0; j<n; j++){
                if(vett[j].find("e:") != string::npos){
                    int l = vett[j].length();
                    char key = vett[j][2];
                    sq.enqueue(key);
                }
                else if(vett[j].find("p:") != string::npos){
                    int l = vett[j].length();
                    char key = vett[j][2];
                    ss.push(key);
                }
                else if(vett[j] == "dequeue"){
                    sq.dequeue();
                }
                else if(vett[j] == "pop"){
                    ss.pop();
                }
                else if(vett[j] == "travasa"){
                    ss.travasa(ss, sq, n);
                }
            }
            sq.Print_queue(sq, out);
        }
    }
}