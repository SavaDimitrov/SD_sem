#include <iostream>

using namespace std;
template<typename T>
class List {

	struct Element {
		T data;
		Element* next;
		Element* prev;

		Element(Element* _prev = nullptr, T _data = T(), Element* _next = nullptr)
			:prev(_prev), data(_data), next(_next) {}
	};

	Element *front;

	void copy(List const& other) {
		if (other.front == nullptr) {
			return;
		}
		
		Element* toCopy = other.front;
		Element* newElement = new Element(toCopy->data);
		Element* lastCopied = newElement;

		front = newElement;

		while (toCopy->next != nullptr) {
			toCopy = toCopy->next;
			//newElement = new Element(toCopy->data); correction
			lastCopied->next = newElement;
			newElement->prev = lastCopied;
			lastCopied = newElement;
		}
	}

	void clear() {
		Element* toDelete = front;
		Element* tmp;
		while (toDelete != nullptr) {
			tmp = toDelete;
			toDelete = toDelete->next;
			delete tmp;
		}
	}

	Element* findElement(int index) {
		Element* currentElement = front;
		for (int i = 0; i < index; i++)
		{
			if (currentElement == nullptr) {
				return nullptr;
			}
			currentElement = currentElement->next;
		}

	}
private:
	bool insertBefore(T const& _newElement, int index) {
		if (index < 0) {
			return false;
		}
		if (index == 0 || empty()) {
			Element* tmp = new Element(_newElement, front);
			front->prev = tmp;
			front = tmp;
			return true;
		}

		return insertAfter(_newElement, index - 1);
	}

	bool insertAfter(T const& _newElement, int index) {
		if (empty()) {

			front = new Element(_newElement);
			return true;
		}

		Element* currentElement = findElement(index);
		if (currentElement == nullptr) {
			return false;
		}

		//currentElement->next = new Element(_newElement, currentElement->next); - LinkedList

		Element* newElement = new Element(currentElement, _newElement, currentElement->next);
		currentElement->next = newElement;
		newElement->next->prev = newElement;
		return true;
	}

	bool deleteBefore(T& _element, int index) {
		if (index == 0 || empty()) {
			return false;
		}
		return deleteAt(_element, index - 1);
	}

	bool deleteAt(T& _element, int index) {
		if (empty()) {
			return false;
		}

		if (index == 0) {
			_element = front->data;
			Element* toDelete = front;
			front = front->next;
			front->prev = nullptr;
			delete toDelete;
			return true;
		}
		return deleteAfter(_element, index - 1);
	}

	bool deleteAfter(T& _element, int index) {
		Element* currentElement = findElement(index);
		if (currentElement == nullptr || currentElement->next = nullptr) {
			return false;
		}
		
		Element* toDelete = currentElement->next;
		currentElement->next = toDelete


	}
};

int main() {

	return 0;
}