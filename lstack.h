#pragma once
#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
struct Node {
	T data;
	Node* next;
};

template <typename T>
class Stack {
	Node<T>* top;

public:
	bool empty();
	void push(T);
	void pop();
	T peek();

	Stack();
	~Stack();
	/*
	for copy and op= - need one more struct stack(tmp) ;(
	*/
	Stack(Stack other);
	Stack& operator=(Stack other);

};

template<typename T>
inline bool Stack<T>::empty()
{
	return top == nullptr;
}

template<typename T>
inline void Stack<T>::push(T _data) {
	Node<T>* newNode = new Node<T>();
	newNode->data = _data;
	newNode->next = top;

	top = newNode;
}

template<typename T>
inline void Stack<T>::pop() {
	if (!empty()) {
		Node<T>* oldTop = top;
		top = top->next;
		delete oldTop;
	}
}

template<typename T>
inline T Stack<T>::peek()
{
	if (!empty()) {
		return top->data;
	}
	return T();
}

template<typename T>
inline Stack<T>::Stack() {
	top = nullptr;
}

template<typename T>
inline Stack<T>::~Stack() {
	while (!empty()) {
		pop(); //this->
	}
}
