#include<iostream>
using namespace std;

template <class T>
class LinkedList
{
public:
	
	struct Node
	{
	
		T value;
		Node* next;

		Node(const T& value) :value(value), next(nullptr) {}

		void print() const
		{
			cout << value;
		}
	};

	Node* head;
	LinkedList() : head{ nullptr }
	{}

	void add(const T& value);
	void remove();
	Node* find(const T& value) const {
		for (Node* nodePtr = head;
			nodePtr != nullptr;
			nodePtr = nodePtr->next)
		{
			if (nodePtr->value == value) {
				return nodePtr;
			}
		}
		return nullptr;
	}
	Node* addAfter(const T& value, Node* afterPtr) {
		if (afterPtr == nullptr) return nullptr;

		Node* nodePtr = new Node(value);
		nodePtr->next = afterPtr->next;
		afterPtr->next = nodePtr;
		return afterPtr->next;
	}
	Node* removeAfter(Node* afterPtr) {
		if (afterPtr != nullptr && afterPtr->next != nullptr)
		{
			Node* nodePtr = afterPtr->next;
			afterPtr->next = afterPtr->next->next;
			delete nodePtr;
		}

		return afterPtr;
	}
	void clear();
	void doForEach(void (*func)(Node* nodePtr));
	static void printNode(Node* nodePtr) {
		nodePtr->print();
		cout << " -> ";
	}

	void print() {
		cout << " -> ";
		doForEach(printNode);
		cout << '\n';
	}

};

	int main() {
	

	cout << "Linked list" << endl << endl;
	LinkedList<int> list;
	list.add(2);
	list.add(5);
	list.add(15);
	list.add(25);
	list.print();
	list.remove();
	list.print();

	 LinkedList<int>::Node* node = list.find(5);
	if (node != 0) {
		node->value = 35;
	}
	list.print();

	list.addAfter(135, node);
	list.print();
	list.clear();
	list.print();
	list.addAfter(135, node);
	list.print();
	list.clear();
	list.print();


}


template <class T>
void LinkedList<T>::add(const T& value)
{
	Node* nodePtr = new Node(value);
	nodePtr->next = head;
	head = nodePtr;
}

template <class T>
void LinkedList<T>::remove()
{
	if (head != nullptr)
	{
		Node* nodePtr = head;
		head = head->next;
		delete nodePtr;
	}
}


template<class T>
void LinkedList<T>::clear() {
	while (head != nullptr) remove();
}

template<class T>
void LinkedList<T>::doForEach(void (*func)(Node* nodePtr))
{
	for (Node* nodePtr = head;
		nodePtr != nullptr;
		nodePtr = nodePtr->next)
	{
		func(nodePtr);
	}
}


