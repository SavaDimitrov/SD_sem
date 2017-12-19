#include <iostream>

using namespace std;

template <typename T>
struct Node{
	T data;
	Node<T>* left, *right;

	Node(T _data, Node<T>* _left, Node<T>* _right)
		:data(_data), left(_left), right(_right) {}

};

template <typename T>
class PBBinTree {




private:
	Node<T>* root;

};


template <typename T>
class BinTreePosition {
public:
	BinTreePosition(Node<T>*& rp) : p(&rp); //rp = rootPointer

	operator bool() const {
		return *p != nullptr;
	}

	bool operator!() const{
		return *p == nullptr;
	}

	//vrushta stoinost na korena
	T& operator*() const {
		return (*p)->data;
	}


	//pravi premestvane nadqsno, ako e vuzmojno
	BinTreePosition operator+() const {
		if (*p == nullptr){
			return *this;
		}

		return BinTreePosition((*p)->right);
	}
	//nalqvo
	BinTreePosition operator-() const {
		if (*p == nullptr){
			return *this;
		}

		return BinTreePosition((*p)->left);
	}


	friend class PBBinTree<T>;

private:

	Node<T>** p;
};