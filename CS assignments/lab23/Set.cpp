#include "Set.h"
using namespace std;
const int SET_DEFAULT = 10;

template <class T>
Set<T>::Set() {
	// create a default set with capacity 10
	size = 0;
	capacity = SET_DEFAULT;
	items = new T[SET_DEFAULT];
	for (int i = 0; i < capacity; i++) {
		items[i] = 0;
	}
};

template <class T>
Set<T>::Set(int capacity) {
	// create a set with capacity
	size = 0;
	this->capacity = capacity;
	items = new T[capacity];
	for (int i = 0; i < capacity; i++) {
		items[i] = 0;
	}
}; 

template <class T>
Set<T>::Set(const Set<T>& source) {
	// copy constructor
	this->size = source.getSize();
	this->capacity = source.getCapacity();
	this->items = new T[source.getCapacity()];
	for (int i = 0; i < source.getCapacity(); i++) {
		this->items[i] = source.items[i];
	};
}; 

template <class T>
Set<T>::~Set() {
	// destructor
	delete[] items; // DO NOT FORGET THE BRACKET!!! IT IS AN ARRAY!!!
};  

template <class T>
void Set<T>::insert(T item) {
	// insert item into the set
	bool entryExisted = false;
	for (int i = 0; i < capacity; i++) {
		if (items[i] == item) {
			entryExisted = true;
		}
	}

	// CASE: do not insert if either:
	//			1: entry already exists
	//			2: item is a negative number
	//			3: insertion size exceeds capacity if inserted
	if (entryExisted || item < 0 || size + 1 > capacity) {
		return;
	}

	// insert entry at the very end and increment capacity
	items[size] = item;
	size++;
};  

template <class T>
void Set<T>::remove(T item) {
	// remove item from the set by finding it and recreating array
	bool foundRemoval = false;
	for (int i = 0; i < size; i++) {
		if (items[i] == item) {
			items[i] = -1; // mark to remove as -1
			foundRemoval = true;
		};
	};

	// if a index for removal found, start remaking array
	if (foundRemoval) {
		// save old items heap
		T* memDelete = items;

		// create a new items list heap
		int newCapacity = capacity - 1;
		int newSize = size - 1;
		items = new T[newCapacity];

		// use iter to traverse items list, and i as # of loops thru
		int iter = 0;
		for (int i = 0; i < size; i++) {
			// skip over removed
			if (memDelete[i] == -1) {
				continue;
			}

			// set new iter index to old i (which will skip removed index automatically)
			items[iter] = memDelete[i];
			iter++;
		}

		// past list of items, set rest to zero
		for (int i = newSize; i < newCapacity; i++) {
			items[i] = 0;
		}

		// clean up old heap and set other vals
		delete[] memDelete;
		this->size = newSize;
		this->capacity = newCapacity;
	}
}; 

template <class T>
bool Set<T>::full() {
	// return true, if set is full
	return size == capacity;
};

template <class T>
bool Set<T>::exist(T item) const {
	bool exists = false;
	for (int i = 0; i < capacity; i++) {
		if (items[i] == item) {
			exists = true;
			break;
		}
	}
	return exists;
};

template <class T>
void Set<T>::print() {
	// print all elements in the set
	for (int i = 0; i < capacity; i++) {
		cout << items[i] << " ";
	};
	cout << endl;
}; 

// operator overloads
template <class T>
void Set<T>::operator +=(const Set<T>& source) {
	// add items from source to the backlog of current
	for (int i = 0; i < source.getSize(); i++) {
		this->insert(source.items[i]);
	}
};

template <class T>
void Set<T>::operator =(const Set<T>& source){
	this->size = source.getSize();
	this->capacity = source.getCapacity();
	this->items = new T[source.getCapacity()];
	for (int i = 0; i < source.getCapacity(); i++) {
		this->items[i] = source.items[i];
	};
};

// accessors
template <class T>
int Set<T>::getSize() const {
	return size;
}; 

template <class T>
int Set<T>::getCapacity() const {
	return capacity;
}; 