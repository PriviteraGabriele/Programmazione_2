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
void Process_Input(int n, string visita, ifstream& in, ostream& out){
	S* vett = new S[n];
	for(int j = 0; j<n; j++){
		in >> vett[j];
	}

	BST<S> bst;
	for(int j = 0; j<n; j++){
		bst.Insert(vett[j]);
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
			Process_Input<int>(n, visita, in, out);
		}
		else if(tipo == "double"){
			Process_Input<double>(n, visita, in, out);
		}
		else if(tipo == "bool"){
			Process_Input<bool>(n, visita, in, out);
		}
		else if(tipo == "char"){
			Process_Input<char>(n, visita, in, out);
		}
    }
}