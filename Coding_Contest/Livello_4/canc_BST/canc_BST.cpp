#include<iostream>
#include<fstream>
using namespace std;

template<typename H>
class BSTNode {
    protected:
        H key;
        BSTNode<H>* left;
        BSTNode<H>* right;
        BSTNode<H>* parent;

        template<typename U>
	    friend class BST;

    public:
        BSTNode(H key) : key(key){
            left = nullptr;
            right = nullptr;
            parent = nullptr;
        }

        void setLeft(BSTNode<H>* left){
            this->left = left;
        }

        void setRight(BSTNode<H>* right){
            this->right = right;
        }

        void setParent(BSTNode<H>* parent){
            this->parent = parent;
        }

        BSTNode<H>* getLeft(){
            return left;
        }

        BSTNode<H>* getRight(){
            return right;
        }

        BSTNode<H>* getParent(){
            return parent;
        }

        H getKey(){
            return key;
        }
};

template<typename T>
class BST {
    private:
        BSTNode<T>* root;

    public:
        BST(){
            root = nullptr;
        }

        bool isEmpty() {
		    return root == nullptr;
	    }

        void Insert(T key){
            Insert(root, key);
        }

        void Insert(BSTNode<T>* p, T key){
            if(this->root == nullptr){
                this->root = new BSTNode<T>(key);
                return;
            }

            if(key <= p->getKey() && p->getLeft() == nullptr){
                BSTNode<T>* node = new BSTNode<T>(key);
                p->setLeft(node);
                node->setParent(p);
                return;
            }
            else if(key > p->getKey() && p->getRight() == nullptr){
                BSTNode<T>* node = new BSTNode<T>(key);
                p->setRight(node);
                node->setParent(p);
                return;
            }
            else if(key <= p->getKey() && p->getLeft() != nullptr){
                Insert(p->getLeft(), key);
            }
            else if(key > p->getKey() && p->getRight() != nullptr){
                Insert(p->getRight(), key);
            }
        }

        BSTNode<T>* min(){
		    return min(root);
	    }
	
        BSTNode<T>* min(BSTNode<T>* from){   
            if(this->isEmpty()) {
                return nullptr;
            }

            BSTNode<T>* p = from;
            while(p->getLeft()) {
                p = p->getLeft();
            }
            return p;
        }

        BSTNode<T>* search(T key) {
            return search(root, key);
        }
        
        BSTNode<T>* search(BSTNode<T>* p, T key) {
            if(p == nullptr){
                return nullptr;
            }
            if(p->getKey() == key){
                return p;
            }
            if(key <= p->getKey()){
                return search(p->getLeft(), key);
            }
            else{
                return search(p->getRight(), key);
            }
            return nullptr;
        }

        void trapianta(BSTNode<T>* u, BSTNode<T>* v){
			if(u->getParent() == NULL) root = v;
			else if(u == u->getParent()->getLeft()) u->getParent()->setLeft(v);
			else u->getParent()->setRight(v);
			
			if(v != NULL) v->setParent(u->getParent());
		}

        void remove(T key){
			BSTNode<T>* p = search(key);
			
			if(p->getLeft() == NULL) trapianta(p, p->getRight());
			else if(p->getRight() == NULL) trapianta(p, p->getLeft());
			else{
				BSTNode<T>* y = min(p->getRight());
				
				if(y->getParent() != p){
					trapianta(y, y->getRight());
					y->setRight(p->getRight());
					y->getRight()->setParent(y);
				}
				
				trapianta(p, y);
				y->setLeft(p->getLeft());
				y->getLeft()->setParent(y);
			}
			
			delete p;
		}

        void Inorder(ostream& out){
            Inorder(root, out);
        }

        void Inorder(BSTNode<T>* p, ostream& out){
            if(p != nullptr){
                Inorder(p->getLeft(), out);
                out << p->getKey() << " ";
                Inorder(p->getRight(), out);
            }
        }

        void Preorder(ostream& out){
            Preorder(root, out);
        }

        void Preorder(BSTNode<T>* p, ostream& out){
            if(p != nullptr){
                out << p->getKey() << " ";
                Preorder(p->getLeft(), out);
                Preorder(p->getRight(), out);
            }
        }

        void Postorder(ostream& out){
            Postorder(root, out);
        }

        void Postorder(BSTNode<T>* p, ostream& out){
            if(p != nullptr){
                Postorder(p->getLeft(), out);
                Postorder(p->getRight(), out);
                out << p->getKey() << " ";
            }
        }

        void Print(string s, ostream& out){
			if(s == "inorder"){
				Inorder(root, out); 
				out << endl;
			}
			else if(s == "preorder"){
				Preorder(root, out); 
				out << endl;
			}
			else if(s == "postorder"){
				Postorder(root, out); 
				out << endl;
			}
		}
};

template<typename S>
void Process_Input(int n, string visita, string tipo, ifstream& in, ostream& out){
	string* vett = new string[n];
	for(int i = 0; i<n; i++){
		in >> vett[i];
	}

	BST<S> bst;

    S key;

	for(int i = 0; i<n; i++){
        int l = vett[i].length();

        //Inserimento
        if(vett[i][0] == 'i'){
            string tmp = "";
            for(int x = 4; x<l; x++){
                tmp += vett[i][x];
            }

            if(tipo == "int"){
                key = stoi(tmp);
            }
            else if(tipo == "double"){
                key = stod(tmp);
            }
            else if(tipo == "bool"){
                key = stoi(tmp);
            } 
            else if(tipo == "char"){
                key = tmp[0];
            } 

            bst.Insert(key);
        }
        //Cancellapione
        else if(vett[i][0] == 'c'){
            string tmp = "";
            for(int x = 5; x<l; x++){
                tmp += vett[i][x];
            }

            if(tipo == "int"){
                key = stoi(tmp);
            }
            else if(tipo == "double"){
                key = stod(tmp);
            }
            else if(tipo == "bool"){
                key = stoi(tmp);
            } 
            else if(tipo == "char"){
                key = tmp[0];
            } 

            bst.remove(key);
        }
    }

	bst.Print(visita, out);
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i = 0; i<100; i++){
        string tipo;
        in >> tipo;

        int n;
        in >> n;

        string visita;
        in >> visita;

		if(tipo == "int"){
			Process_Input<int>(n, visita, tipo, in, out);
		}
		else if(tipo == "double"){
			Process_Input<double>(n, visita, tipo, in, out);
		}
		else if(tipo == "bool"){
			Process_Input<bool>(n, visita, tipo, in, out);
		}
		else if(tipo == "char"){
			Process_Input<char>(n, visita, tipo, in, out);
		}
    }
}