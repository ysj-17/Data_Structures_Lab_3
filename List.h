#ifndef DOUBLY_LIST
#define DOUBLY_LIST
using std::cout;
using std::endl;

template <class T>
class Node
{
public:
	T  item;
	Node *prev;
	Node *next;
	Node *head;
	Node *tail;
};

int itemCountList = 0;

template <class T> class ListInterface : public Node<T>
{
public:

	virtual bool isEmpty() { return true; }
	virtual bool add(T newEntry) { return true; }
	virtual bool remove(T anEntry) { return true; }
	virtual void clear() { cout << "Error in ListInterface Class"; }
	virtual bool search(T anEntry) { return true; }
	virtual bool displayList() { return true; }
	virtual void sortingList() {}
};



template <class T> class List : public ListInterface<T>
{

public:
	using Node<T>::head;
	using Node<T>::tail;
	List() { head = nullptr; tail = nullptr; }
	int sizeOfList();
	T returnValue(int size);
	void radixSort(List<int> objectInt);
	int radixGetMaxLength(int *unsorted, int arraySize);
	int radixGetLength(int dataInput);

	bool isEmpty() {
		if (head == NULL) {
			return true;
		}
		else { return false; }
	}


	bool add(T newEntry) {
		Node<T> *newNode = new Node<T>;
		newNode->item = newEntry;
		newNode->head = NULL;
		newNode->tail = NULL;

		if (isEmpty() == true) {
			head = newNode;
			tail = newNode;
			itemCountList++;
		}
		else {
			newNode->next = tail;
			tail->prev = newNode;
			tail = newNode;
			tail->prev = NULL;
			itemCountList++;
		}

		return true;
	}

	bool remove(T anEntry) {
		if (isEmpty() == true) {
			cout << "The list is empty!" << endl;
			return false;
		}
		else {
			if (isEmpty() == false) {
				Node<T> *rover = head;
				Node<T> *nodePtr = rover->prev;
				while (nodePtr != tail) { // Rover goes until it hits the end of the list
					if (nodePtr->item == anEntry) {
						rover->prev = nodePtr->prev;
						delete nodePtr;
						itemCountList--;
						return true;
					}
					else nodePtr = nodePtr->prev; // Setting rover to the previous
				}
				return false;
			}
		}
		cout << "Error #1 has Occured: Remove function" << endl;
		return false;
	}

	void clear() {
		Node<T> *nodePtr = head;
		Node<T> *n;
		while (nodePtr != NULL) {
			n = nodePtr->prev;
			delete nodePtr; // delete Dynamic memory
			nodePtr = n;
			itemCountList--;
		}
		head = nullptr; // point head to null 

	}



	bool search(T anEntry) {
		// Rover will go through the list one by one
		Node<T> *rover = head;
		while (rover != tail) { // Rover goes until it hits the end of the list
			if (rover->item == anEntry)
				return true;
			// Setting rover to the previous
			else rover = rover->prev;
		}

		return false;
	}


	bool displayList()
	{
		//// Rover will go through the list one by one
		Node<T> *rover = head;
		if (isEmpty() == true) {
			cout << "Nothing to display";
			return false;
		}
		else {
			while (rover != NULL) // Rover goes until it hits the end of the list
			{
				cout << rover->item;
				cout << endl;
				// Setting rover to the previous
				rover = rover->prev;
			}
			return true;
		}
	}


	
};


template<class T>
T List<T>::returnValue(int size) {
	Node<T> *rover = head;
	int counter = 0;
	T container;

	if (rover != NULL) {
		while (counter != size) {
			rover = rover->prev;
			counter++;
		}
		container = rover->item;
		return container;
	}
	
	else return -1;
}

template<class T>
int List<T>::sizeOfList() {
	int counter = 0;

	Node<T> *rover = head;
	if (isEmpty() == true) {
		return 0;
	}
	else {
		while (rover != NULL) 
		{
			rover = rover->prev;
			counter++;
		}

		return counter;
	}
}


#endif