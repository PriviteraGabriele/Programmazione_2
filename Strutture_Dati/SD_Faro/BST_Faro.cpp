#include <iostream>
#include <ctime>
#include <math.h>
using namespace std;

template <class T> class Set {
	public:
		virtual Set<T>* insert(T x) = 0;
		virtual int search(T x) = 0;
		virtual Set<T>* del(T x) = 0;
};

template <class Pippo> class LIFO {
	public:
		virtual LIFO<Pippo>* push(Pippo x) = 0;
		virtual Pippo* pop() = 0;
};

#define WHITE 0
#define GRAY 1
#define BLACK 2

template <class Pippo> class ArrayStack: public LIFO<Pippo> {
	private:
		Pippo *S;
		int length;
		int size;
		
	public:
		ArrayStack() {
			length = 100;
			S = new Pippo[100];
			size = 0;	
		}
		ArrayStack(int length) {
			this->length = length;
			S = new Pippo[length];	
			size = 0;	
		}
		ArrayStack<Pippo>* push(Pippo x) {
			if( isFull() ) cout << "Stack Pieno" << endl;
			else {
				S[size] = x;
				size++;
			}
			return this;
		}
		Pippo* pop() {
			if( isEmpty() ) cout << "Stack Vuoto" << endl;
			else {
				size --;
				return &S[size];
			}
			return NULL;
		}
		int isFull() {
			return (length==size)?1:0;
		}
		int isEmpty() {
			return (size==0)?1:0;
		}
		void print() {
			for(int i=0; i<size; i++)
				cout << S[i] << " ";
			cout << endl;
		}
		int getSize() { return size; }
};

template <class A> class Node {
	private:
		A key;
		int color;
		Node<A> *left, *right, *parent;
		int mul;
	public:
		Node<A>() {}
		Node<A>(A key) { 
			this->key = key; 
			left = right = parent = NULL;
			mul = 1;
		}
		A getKey() { return key;}		
		int getMul() { return mul;}		
		Node<A> *getLeft() { return left;}		
		Node<A> *getRight() { return right;}		
		Node<A> *getParent() { return parent;}		
		void setKey(A key) { this->key = key; }
		void setMul(int mul) { this->mul = mul; }
		void decMul() { this->mul--; }
		void incMul() { this->mul++; }
		void setLeft(Node<A> *left) { this->left = left; }
		void setRight(Node<A> *right) { this->right = right; }
		void setParent(Node<A> *parent) { this->parent = parent; }
		int getColor() {return color;}
		void setColor(int color) {this->color=color;}
		int isLeaf() { 
			if( !getLeft() && !getRight() ) return 1;
			return 0; 
		}
};


template <class H> class BSTree: public Set<H> {
	private:
		int size;
		Node<H>* root;
		Node<H>* getMin(Node<H> *x) {
			if (x==NULL) return NULL;
			while(x->getLeft()!=NULL) x = x->getLeft();
			return x;
		}
		Node<H>* getMax(Node<H> *x) {
			if (x==NULL) return NULL;
			while(x->getRight()!=NULL) x = x->getRight();
			return x;
		}
		Node<H>* getNext(Node<H> *x) {
			if( getMax(root) == x ) return NULL;
			if(x->getRight()) return getMin(x->getRight());
			while(x->getParent()->getKey() <= x->getKey()) x = x->getParent();
			return x->getParent();
		}
		void _inorder(Node<H> *x) {
			if(x==NULL) return;
			_inorder(x->getLeft());
			for(int i=0; i<x->getMul(); i++) cout << x->getKey() << " ";
			_inorder(x->getRight());
		}
		void _postorder(Node<H> *x) {
			if(x==NULL) return;
			_postorder(x->getLeft());
			_postorder(x->getRight());
			cout << x->getKey() << " ";
		}
		void _preorder(Node<H> *x) {
			if(x==NULL) return;
			cout << x->getKey() << " ";
			_preorder(x->getLeft());
			_preorder(x->getRight());
		}
		int getProf(Node<H> *x) {
			int prof = 0;
			while(x!=root) {
				prof++;
				x = x->getParent();
			}
			return prof;
		}
		
	public:
		BSTree<H>() {
			size = 0;
			root = NULL;
		}
		BSTree<H>* insert(H x) {
			Node<H>* t = root;
			Node<H>* p = NULL;
			while(t!=NULL) {
				p = t;
				if( t->getKey()==x ) {
					t->incMul();
					size++;
					return this;
				}
				if(t->getKey()>x) t = t->getLeft();
				else t = t->getRight();
			}
			Node<H>* y = new Node<H>(x);			
			if(root==NULL) root = y;
			else {
				if(p->getKey()>=x) p->setLeft(y);
				else p->setRight(y);
				y->setParent(p);
			}
			size++;
			return this;		
		}
		int search(H x) {
			if( _search(x) ) return 1;
			return 0;
		}
		int rec_search(H x) {
			return _rec_search(x,root)!=NULL?1:0;
		}
		Node<H>* _rec_search(H x, Node<H>*y) {
			if(!y) return NULL;
			if( y->getKey()==x ) return y;
			if( y->getKey() > x ) return _rec_search(x, y->getLeft());
			else return _rec_search(x, y->getRight());
		}
		Node<H>* _search(H x) {
			Node<H>* t = root;
			while(t!=NULL) {
				if(t->getKey()==x) return t;
				if(t->getKey()>x) t = t->getLeft();
				else t = t->getRight();
			}
			return NULL;
		}
		int multiplicity(H x) {
			Node<H> *t = _search(x);
			if(!t) return 0;
			return t->getMul();
		}
		
		BSTree<H>* del(H x) {
			_del(root, x);
			return this;
		}
		
		BSTree<H>* _del(Node<H>*r, H x) {
			Node<H> *t = _rec_search(x, r);
			if( !t ) return this;
			if( t->getMul()>1 ) {
				t->decMul();
				size--;
				return this;
			}
			if( t->isLeaf() ) {
				size--;
				Node<H> *p = t->getParent();
				if(p==NULL) {root=NULL; return this;}
				if(p->getLeft()==t) p->setLeft(NULL);
				else p->setRight(NULL);
				return this;
			}
			if( !(t->getLeft() && t->getRight()) ) {
				size--;
				Node<H> *p = t->getParent();
				Node<H> *f = t->getLeft();
				if(!f) f = t->getRight();
				if(p==NULL) {root=f; return this;}
				if( p->getRight()==t ) p->setRight(f);
				else p->setLeft(f);
				f->setParent(p);				
				return this;
			}
			Node<H> *n =  getNext(t);
			t->setKey(n->getKey());
			_del(t->getRight(), n->getKey());
			return this;
		}
		
		void inorder() {
			cout << "(" << size << ") ";
			Node<H> *t = getMin(root);
			while(t!=NULL) {
				cout << t->getKey() << " ";
				t = getNext(t);
			}
			cout << endl;
		}

		void reset_color() {
			Node<H> *t = getMin(root);
			while(t!=NULL) {
				t->setColor(WHITE);
				t = getNext(t);
			}
		}

		void color_inorder() {
			reset_color();
			Node<H> *t = root;
			while( t!=NULL ) {
				if( t->getColor()==WHITE ) {
					t->setColor(GRAY);
					if(t->getLeft()!=NULL) t=t->getLeft();
				}
				else if( t->getColor()==GRAY ) {
					t->setColor(BLACK);
					if(t->getRight()!=NULL) t=t->getRight();				
				}
				else {
					cout << t->getKey() << " ";
				 	t=t->getParent();
				}
			}
			cout << "\n";
		}
		
		void stack_preorder() {
			Node<H> *t;
			ArrayStack< Node<H> > *S = new ArrayStack< Node<H> >();
			S->push(*root);
			while( !S->isEmpty() ) {
				cout << "(" << S->getSize() << ") ";
				t = S->pop();
				cout << t->getKey() << " ";
				if(t->getRight()) S->push(*(t->getRight()));
				if(t->getLeft()) S->push(*(t->getLeft()));
			}
			cout << "\n";
		}
		
		void rec_inorder() {
			_inorder(root);
			cout << endl;
		}		
		void rec_postorder() {
			_postorder(root);
			cout << endl;
		}		
		void rec_preorder() {
			_preorder(root);
			cout << endl;
		}		
		int getAltezza() {
			int max = 0;
			Node<H> *t = getMin(root);
			while(t!=NULL) {
				if( t->isLeaf() && getProf(t) > max ) max = getProf(t);
				t = getNext(t);
			}
			return max;
		}
		int getProf(H x) {
			Node<H> *y = _search(x);
			if(!y) return -1;
			return getProf(y);
		}
		
		void naturalFill(H* v) {
			int i=0;
			Node<H> *tmp = getMin(root);
			while(tmp!=NULL) {
				tmp->setKey(v[i]);
				i++;
				tmp = getNext(tmp);
			}
		}
		
		void printLevel(int l) {
			Node<H> *tmp = getMin(root);
			while(tmp!=NULL) {
				if(getProf(tmp) == l) cout << tmp->getKey() << " ";
				tmp = getNext(tmp);
			}			
			cout << endl;
		}
		
		int rank(H x) {
			int r = 0;
			Node<H> *t = getMin(root);
			while(t!=NULL && t->getKey()!=x) {
				r += t->getMul();
				t = getNext(t);
			}
			if( t==NULL ) return 0;
			return r+1;
		}
		
		void _mod_search(Node<H> *t, H x) {
			
		}
};


int main() {
	BSTree<int> *T = new BSTree<int>();
	T->insert(23)->insert(4)->insert(6)->insert(8)->insert(12)->insert(21)->insert(5)->color_inorder();//insert(9);
	//T->insert(7)->insert(3)->insert(16)->insert(2)->insert(24);
	//T->insert(8)->insert(16);
	
	/*T->rec_inorder();
	T->del(8);
	T->rec_inorder();
	T->del(8);
	T->rec_inorder();
	cout << T->rank(12) << endl;*/
	return 0;
	
}

