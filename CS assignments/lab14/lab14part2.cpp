// 10380722, Anthony, Chen
// Date: 10/30/2022
// Lab14, Problem2
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
typedef struct node* NodePtr;

struct node
{
public:
	int data;
	NodePtr link;
};

void print(NodePtr head)
{
	for (NodePtr ptr = head; ptr != NULL; ptr = ptr->link) {
		cout << ptr->data << "->";
	}

	// declare NULL at end because ends will always point to null
	cout << "NULL";
	cout << endl;
}


void reverseOrder(NodePtr &head) {
	// set variables before head's link becomes NULL
	NodePtr prev = head, ptr = head->link;

	// error cases
	if (head->link == NULL || head == NULL) {
		// 0 or 1 nodes, return nothing
		return;
	}
	else if (ptr->link == NULL) { 
		// CASE: 2-count node lists, return a small swap
		prev->link = NULL;
		ptr->link = prev;
		head = ptr;
		return;
	}

	// reversing order, so make the first link set to NULL
	head->link = NULL;

	// reverse pointing order of the links
	for (NodePtr next = ptr->link; next != NULL; next = next->link) {
		// reverse linkage of ptrs to descendant members
		ptr->link = prev;

		// set head to the newest ascendant
		head = next;

		// increment step for ptr and prev to ascendant members
		prev = ptr;
		ptr = next;
	}

	// set head to the previous node 
	// to fully link in reverse order
	head->link = prev;
}

int main()
{
	// menu input for filename
	int totalNums;
	cout << "Enter number of elements in linkedlist : ";
	cin >> totalNums;
	ifstream infile;

	// make node of ints if user's choosing
	NodePtr head = NULL, body = NULL;
	for (int i = 0; i < totalNums; i++) {
		body = new node;
		cout << "Enter the " << (i + 1) << " element of the linkedlist: ";
		cin >> body->data;
		body->link = NULL;

		// insert ptr into linked list
		if (head == NULL) {
			head = body;
		}
		else {
			body->link = head;
			head = body;
		}		
	}
	reverseOrder(head);

	cout << endl;
	cout << "*** Given linked list" << endl;
	print(head);

	cout << endl;
	cout << "*** Reversed linked list" << endl;
	reverseOrder(head);
	print(head);

	return 0;
}