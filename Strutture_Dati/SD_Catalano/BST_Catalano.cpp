#include<iostream>
#include<sstream>
#include<fstream>
#include<typeinfo>

using namespace std;

template<class H>
class Nodo{
	private:
		H key;
		Nodo<H>* left;
		Nodo<H>* right;
		Nodo<H>* parent;
		
	public:
		Nodo(H key){
			this->key = key;
			parent = left = right = NULL;
		}
		
		H getKey(){ return key;}
		Nodo<H>* getLeft(){ return left;}
		Nodo<H>* getRight(){ return right;}
		Nodo<H>* getParent(){ return parent;}
		
		void setKey(H key){this->key = key;}
		void setLeft(Nodo<H>* left){ this->left = left;}
		void setRight(Nodo<H>* right){ this->right = right;}
		void setParent(Nodo<H>* parent){ this->parent = parent;}
};

template<class H>
class BST{
	private:
		Nodo<H>* root;
		
		void trapianta(Nodo<H>* u, Nodo<H>* v){
			if(u->getParent() == NULL) root = v;
			else if(u == u->getParent()->getLeft()) u->getParent()->setLeft(v);
			else u->getParent()->setRight(v);
			
			if(v != NULL) v->setParent(u->getParent());
		}
		
		Nodo<H>* minimo(Nodo<H>* x){
			Nodo<H>* iter = x;
			
			while(iter->getLeft()) iter = iter->getLeft();
			
			return iter;
		}
		
		Nodo<H>* search(H key){
			Nodo<H>* iter = root;
			
			while(iter && iter->getKey() != key){
				if(key <= iter->getKey()) iter = iter->getLeft();
				else iter = iter->getRight();
			}
			
			if(iter->getKey() == key) return iter;
			
			return NULL;
		}
		
		void preOrder(Nodo<H>* p, ofstream& out){
			if(p){
				out << p->getKey() << " ";
				preOrder(p->getLeft(), out);
				preOrder(p->getRight(), out);
			}
		}
		
		void inOrder(Nodo<H>* p, ofstream& out){
			if(p){
				inOrder(p->getLeft(), out);
				out << p->getKey() << " ";
				inOrder(p->getRight(), out);
			}
		}
		
		void postOrder(Nodo<H>* p, ofstream& out){
			if(p){
				postOrder(p->getLeft(), out);
				postOrder(p->getRight(), out);
				out << p->getKey() << " ";
			}
		}
	
	public:
		BST(){ root = NULL;}
		
		void ins(H key){
			Nodo<H>* nuovo = new Nodo<H>(key);
			
			if(!root) root = nuovo;
			else{
				Nodo<H>* preiter;
				Nodo<H>* iter = root;
				
				while(iter){
					preiter = iter;
					
					if(iter->getKey() >= key) iter = iter->getLeft();
					else iter = iter->getRight();
				}
				
				nuovo->setParent(preiter);
				
				if(preiter->getKey() >= key) preiter->setLeft(nuovo);
				else preiter->setRight(nuovo); 
			}
		}
		
		void canc(H key){
			Nodo<H>* z = search(key);
			
			if(z->getLeft() == NULL) trapianta(z, z->getRight());
			else if(z->getRight() == NULL) trapianta(z, z->getLeft());
			else{
				Nodo<H>* y = minimo(z->getRight());
				
				if(y->getParent() != z){
					trapianta(y, y->getRight());
					y->setRight(z->getRight());
					y->getRight()->setParent(y);
				}
				
				trapianta(z, y);
				y->setLeft(z->getLeft());
				y->getLeft()->setParent(y);
			}
			
			delete z;
		}
		
		void stampa(ofstream& out, string visita){
			if(visita == "inorder") inOrder(root, out);
			else if(visita == "preorder") preOrder(root, out);
			else postOrder(root, out);
			out << endl;
		}
};

template<class H>
void bst_canc(string* v, ofstream& out){
	int n;
	stringstream(v[1]) >> n;
	
	string visita = v[2];
	
	BST<H>* bst = new BST<H>();
	
	for(int i = 0; i < n; i++){
		string s = v[i+3];
		
		int j = 0;
		while(s[j] != ':') j++;
		
		string istruzione;
		if(j == 3) istruzione = "ins";
		else istruzione = "canc";
			
		string valore = "";
		j++;
		while(s[j] != ' '){
			valore += s[j];
			j++;
		}
		
		if(typeid(H) == typeid(char)){
		
			if(istruzione == "ins") bst->ins(valore[0]);
			else bst->canc(valore[0]);
		
		}else{
			double key;
			stringstream(valore) >> key;
			if(istruzione == "ins") bst->ins(key);
			else bst->canc(key);
		}	
	}
	
	bst->stampa(out, visita);
}

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	int n = 10000;
	string* v = new string[n];
	string str = "";
	
	while(getline(in, str)){
		stringstream ss(str);
		for(int i = 0; i < n; i++) ss >> v[i];
		if(v[0] == "double") bst_canc<double>(v, out);
		else if(v[0] == "int") bst_canc<int>(v, out);
		else if(v[0] == "bool") bst_canc<bool>(v, out);
		else bst_canc<char>(v, out);
	}
	
	in.close();
	out.close();
}
