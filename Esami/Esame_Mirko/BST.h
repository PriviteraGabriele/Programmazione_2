#ifndef BST_H
#define BST_H

template<typename T>
class BSTNode{

	T key;
	BSTNode<T>* parent;
	BSTNode<T>* right;
	BSTNode<T>* left;
	bool verbose;

	template<typename C>
	friend class BST;

public:

	BSTNode(T key, bool verbose = false) : key(key), verbose(verbose){
		parent = nullptr;
		right = nullptr;
		left = nullptr;
	}

	//Getter
	BSTNode<T>* getParent(){return this->parent;}
	BSTNode<T>* getRight(){return this->right;}
	BSTNode<T>* getLeft(){return this->left;}
	T getKey(){return this->key;}

	//Setter
	void setParent(BSTNode<T>* parent){this->parent = parent;}
	void setRight(BSTNode<T>* right){this->right = right;}
	void setLeft(BSTNode<T>* left){this->left = left;}
	void setKey(T key){this->key = key;}

	friend ostream& operator<< (ostream& os, const BSTNode<T>& b){
		if(b.verbose){
			os << "BSTNode: " << &b << endl;
			os << "Key =" << b.key << endl;
			os << "left->" << b.left << "\t right->" << b.right << "\t parent->" << b.parent << endl;
			return os;
		}
		return os << "Key = " << b.key << endl;
	}
	
};

template<typename T>
class BST{
    private:

	    BSTNode<T>* root;

	public:

		BST(){
            root = nullptr;
            }
		
		BSTNode<T>* getRoot(){
            return this->root;
            }

		bool isEmpty(){
            return root == nullptr;
            }

		void insert(T key){
			if(isEmpty()){
				root = new BSTNode<T>(key);
				return;
			}
			insert(root, key);
		}

		void insert(BSTNode<T>* ptr, T key){
			if(!ptr->left && key <= ptr->key){
				ptr->left = new BSTNode<T>(key);
				ptr->left->setParent(ptr);
				return;
			}
			if(!ptr->right && key > ptr->key){
				ptr->right = new BSTNode<T>(key);
				ptr->right->setParent(ptr);
				return;
			}
			if(key <= ptr->key){
				insert(ptr->left, key);
            }else{
                insert(ptr->right, key);
                }
		}

		void visit(BSTNode<T>* ptr){ 
            cout << *ptr; 
            }
 
		void in_order(BSTNode<T>* ptr){
			if(!ptr){
				return;
                }
			in_order(ptr->left);
			visit(ptr);
			in_order(ptr->right);
		}

		void in_order(){
            in_order(root);
            }

        BSTNode<T>* max(){
            return max(root);
            }

		BSTNode<T>* max(BSTNode<T>* from){

			if(isEmpty()){
                throw out_of_range("Empty bst...");
                }

			BSTNode<T>* ptr = from;
			while(ptr->right){
				ptr = ptr->right;
                }
			return ptr;
		}

		BSTNode<T>* min(){
            return min(root);
            }

		BSTNode<T>* min(BSTNode<T>* from){

			if(isEmpty()){
                throw out_of_range("Empty bst...");
                }

			BSTNode<T>* ptr = from;
			while(ptr->left){
				ptr = ptr->left;
                }
			return ptr;
		}

        BSTNode<T>* predecessor(T key){
            BSTNode<T>* ptr = search(key);
            if(!ptr || ptr == min()){
                throw out_of_range("...predecessor doesn't exist...");
                }
            return predecessor(ptr);
        }

		BSTNode<T>* predecessor(BSTNode<T>* x){
			if(isEmpty()){
				return nullptr;
                }

			if(x->left){
				return max(x->left);
                }

			BSTNode<T>* y = x->parent;
			while(x && x == y->left){
				x = y;
				y = y->parent;
			}
			
			return y;
		}

        BSTNode<T>* successor(T key){

            BSTNode<T>* ptr = search(key);
            if(!ptr || ptr == max()){
                throw out_of_range("...successor doesn't exist...");
                }
            return successor(ptr);
        }

		BSTNode<T>* successor(BSTNode<T>* x){
			if(isEmpty()){
				return nullptr;
                }
			if(x->right){ 
				return min(x->right);
                }

			BSTNode<T>* y = x->parent;
			while(x && x == y->right){
				x = y;
				y = y->parent;
			}

			return y;
		}

        BSTNode<T>* search(T key){
			if(isEmpty()){
                throw out_of_range("Empty BST...");
                }
			return search(root, key);
		}

		BSTNode<T>* search(BSTNode<T>*ptr , T key){

			if(!ptr){
				return nullptr;
                }
			if(ptr->key == key){
				return ptr;
                }

			if(key <= ptr->key){
				return search(ptr->left, key);
            }else{
				return search(ptr->right, key);
                }
		}

		int Dist_successor(T key){

            int count=0;
            BSTNode<T> * ptr = search(key);

            if(!ptr || ptr == max()) {
                	return 0;
                }

            if(ptr->right){
                ptr = ptr->right;
                count++;
                while(ptr->left){
                    ptr = ptr->left;
                    count++;
                }
                return count;
            }
            BSTNode<T>* y = ptr->parent;
            count++;

            while(ptr && ptr == y->right){
                ptr = ptr->parent;
                y = y->parent;
                count ++;
            }

            return count;
        }

        int Dist_root(BSTNode<T>* nodo_h, BSTNode<T>* partenza){
			if(partenza->key == nodo_h->key){
				return 0;
                }
			BSTNode<T>* tmp = partenza;
			int counter = 0;
			while(tmp && tmp->key != nodo_h->key){
				if(nodo_h->key > tmp->key){ 
					tmp = tmp->right;
                }else{ 
					tmp=tmp->left;
                    }
                counter++;
			}
			
			if(!tmp){ 
				return -1;
            }else{ 
				return counter;
                } 
			
		}

		int Dist_fra_2Nodi(T k, T h) {
			BSTNode<T>* nodo_k = search(k);
			BSTNode<T>* nodo_h = search(h);
			int counter=0;
			if(!nodo_k || !nodo_h)
				throw out_of_range("Chiavi errate!");
				if(k <= h){
					BSTNode<T>* tmp = nodo_k;
					bool flag = true;
					while(tmp && flag) {
						int distance = Dist_root(nodo_h, tmp); 
						if(distance == 0){
							flag = false;
						}else if(distance == -1){
							tmp = tmp->parent; 
							counter++; 
						}else{
							counter += distance;
							flag = false;
						}
				}
				return counter;
			}else{
				return Dist_fra_2Nodi(h, k);
				}
		}


};
#endif