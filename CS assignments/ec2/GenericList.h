// 10380722, Anthony, Chen
// Date: 11/30/2022
// Extra Credit

#pragma once
#ifndef GENERICLIST_H
#define GENERICLIST_H
#include <iostream>
using namespace std;
template <class T>
class GenericList
{
public:
	GenericList(int size) {
		this->size = size;
		data = new T[size];
	}
	void add(T newItem) {
		data[index] = newItem;
		index++;
	}

	friend ostream& operator << (ostream& os, const GenericList <T>& obj) {
		for (int i = 0; i < obj.size; i++) {
			cout << obj.data[i] << endl;
		}
		return os;
	}
private:
	T* data;
	int size;
	int index = 0;
};


#endif 