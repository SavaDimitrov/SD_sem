#include <iostream>

using namespace std;

template <typename T>
struct TNode {
	T data;
	TNode<T> *left, *right;

	TNode(T _data, TNode<T>* _left = nullptr, TNode<T>* _right = nullptr)
		:data(_data), left(_left), right(_right) {}
};

template <typename T>
class BinaryTree{
private:
	TNode<T>* root;

public:
	BinaryTree() :root(nullptr) {}
	
	BinaryTree(T& data, BinaryTree<T> const& left, BinaryTree<T> const& right){
		root = &TNode<T>(data, left.root, right.root);
	}

	BinaryTree(BinaryTree<T> const& other) 
		:root(copyNode(other.root)) {}
	
	BinaryTree& operator=(BinaryTree<T> const& other) {
		if (this != &other){
			cutTheTree();
			root = copyNode(other.root); // important!!
		}

		return *this;
	}

	~BinaryTree(){
		cutTheTree();
	}
	
	



private:

	//TNode<T>* copyNode(const TNode<T>* node) const; - no permision to change data in the struct
	TNode<T>* copyNode(TNode<T>* node) {

		if (node == nullptr) {
			return nullptr;
		}
		cout << "COPY" << endl; //testing how many times the copy func will be called

		return new TNode<T>(node->data, 
			copyNode(node->left), 
			copyNode(node->right));
	}

	void eraseNode(TNode<T>* node){
		if (node != nullptr) {
			eraseNode(node->left);
			eraseNode(node->right);
			delete node;
		}
	}

	void cutTheTree(){
		eraseNode(root);
		root = nullptr;
	}
};