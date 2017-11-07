#pragma once
#include <iostream>

template <typename T>
struct QueueElement {
	T data;
	QueueElement<T>* next;

	/*QueueElement(T _data = T(), QueueElement* _next = NULL) {
	 //Will generate a deffault constructor
	}*/
};

template <typename T>
class LinkedQueue {
	QueueElement<T>* front;
	QueueElement<T>* back;

	void copyQueue(LinkedQueue<T> const& other) {
		for (QueueElement<T>* f = other.front; f != nullptr; f = f->next) {
			enqueue(f->data);
		}
		/*
		QueueElement<T>* f = other.front;
		while (f != NULL){
			enqueue(f->data);
			f = f->next;
		}
		*/
	}
	void clearQueue() {
		while (!empty()) {
			dequeue();
		}
	}
public:
	LinkedQueue();
	LinkedQueue(LinkedQueue<T> const& other);
	LinkedQueue<T>& operator=(LinkedQueue<T> const& other);
	~LinkedQueue();

	bool empty() const;
	T first() const;
	void enqueue(T const& data);
	void dequeue();
};

template<typename T>
inline LinkedQueue<T>::LinkedQueue() :front(nullptr), back(nullptr) {}

template<typename T>
inline LinkedQueue<T>::LinkedQueue(LinkedQueue<T> const& other) {
	copyQueue(other);
}

template<typename T>
inline LinkedQueue<T>& LinkedQueue<T>::operator=(LinkedQueue<T> const& other) {
	if (this != &other) {
		clearQueue();
		copyQueue(other);
	}
	return *this;
}

template<typename T>
inline LinkedQueue<T>::~LinkedQueue() {
	clearQueue();
}

template<typename T>
inline bool LinkedQueue<T>::empty() const {
	return front == nullptr;
}

template<typename T>
inline T LinkedQueue<T>::first() const {
	//T tmp;
	if (!empty()) {
		//tmp = front->data;
		return front->data;
	}
	return T(); //return tmp;
}

template<typename T>
inline void LinkedQueue<T>::enqueue(T const & newData) {
	QueueElement<T>* newQueueEle = new QueueElement<T>(newData, nullptr);
	if (empty()) {
		front = newQueueEle;
	}
	else {
		back->next = newQueueEle;
	}
	back = newQueueEle;
}

template<typename T>
inline void LinkedQueue<T>::dequeue() {
	if (empty()) {
		cerr << "Empty queue!";
	}
	else {
		QueueElement<T>* oldFront = front;
		front = front->next;
		delete oldFront;
		if (front == nullptr) {
			back = front;
		}
	}
}
