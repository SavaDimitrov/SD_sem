#include <iostream>
#include <fstream>
#include <cstring>
//#include <stack>, #include <queue> //we have them but we cant use them, sadly, R.I.P ;(
using namespace std;

const unsigned MAX_SIZE = 10;
const int EMPTY_DATA = -1;

//struct Stack {
//private:
//	int data[MAX_SIZE];
//	int current;
//
//	bool full() {
//		return current == MAX_SIZE - 1;
//	}
//public:
//	bool empty() {
//		return current == EMPTY_DATA;
//	}
//	int top() {
//		if (!empty()) {
//			return data[current];
//		}
//		return int();
//	}
//
//	void push(int element) {
//		//if(if full - resize)
//		if (!full()) {
//			data[++current] = element;
//		}
//	}
//
//	int pop() { 
//		if (!empty()) {
//			return data[current--];
//		}
//		//poprincip po() - void current--; , no mojem i bool pop(T &el)
//	}
//
//	Stack() {
//		current = EMPTY_DATA;
//	}
//	//dynamic memory - THE BIG 4 O.O
//};
//
//template <typename T> //vsichko stava dinamichno
//struct ResizableStack {
//private:
//	T* data;
//	int current;
//	int size;
//
//	bool full() {
//		return current == size - 1;
//	}
//
//	void add(T element) {
//
//	}
//	void resize() {
//
//	}
//	void delStack() {
//		delete data;
//		data = nullptr;
//	}
//
//public:
//	bool empty() {
//		return current == EMPTY_DATA;
//	}
//	int top() {
//		if (!empty()) {
//			return data[current];
//		}
//		return int();
//	}
//
//	void push(int element) {
//		//if(if full - resize)
//		if (!full()) {
//			data[++current] = element;
//		}
//	}
//
//	int pop() {
//		if (!empty()) {
//			return data[current--];
//		}
//	}
//
//	ResizableStack() {
//		size = MAX_SIZE;
//		data = new T[size]
//		current = EMPTY_DATA;
//	}
//
//	~ResizableStack() {
//		delStack();
//	}
//};
//


int main() {





	system("pause");
	return 0;
}