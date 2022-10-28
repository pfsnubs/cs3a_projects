// 10380722, Anthony, Chen
// Date: 10/30/2022
// Lab15, Problem1
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

void reverseOrder(NodePtr& head) {
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

NodePtr mergeLists(NodePtr& link1, NodePtr& link2, int maxNo) {
	NodePtr newHead = NULL, prev = NULL;
	for (int i = 0; i < maxNo; i++) {
		// access both notes and start from highest to lowest
		// greater gets to start the list first
		if (link1->data > link2->data) {
			if (newHead == NULL) {
				newHead = link1;
				prev = newHead;
			}
			else {
				// link node up to the back of the list
				link1->link = prev;

				// set prev to the current one to use for later
				prev = link1;

				// advance link1 to the next to look at 
				link1 = link1->link;
			}
		}
		else { // if link2 is greater, put it instead
			if (newHead == NULL) {
				newHead = link2;
				prev = newHead;
			}
			else {
				// link node up to the back of the list
				link2->link = prev;

				// set prev to the current one to use for later
				prev = link2;

				// advance link1 to the next to look at 
				link2 = link2->link;
			}
		}		
	}
	return newHead;
}

int main()
{

	// menu input for filename
	// make first linked list
	int totalNums1;
	cout << "Enter number of elements in first linkedlist : ";
	cin >> totalNums1;
	ifstream infile;
	NodePtr head1 = NULL, body1 = NULL;
	for (int i = 0; i < totalNums1; i++) {
		body1 = new node;
		cout << "Enter the " << (i + 1) << " element of first linkedlist: ";
		cin >> body1->data;
		body1->link = NULL;

		// insert ptr into linked list
		if (head1 == NULL) {
			head1 = body1;
		}
		else {
			body1->link = head1;
			head1 = body1;
		}
	}
	reverseOrder(head1);

	// make second linked list
	int totalNums2;
	cout << "Enter number of elements in second linkedlist : ";
	cin >> totalNums2;
	NodePtr head2 = NULL, body2 = NULL;
	for (int i = 0; i < totalNums2; i++) {
		body2 = new node;
		cout << "Enter the " << (i + 1) << " element of second linkedlist: ";
		cin >> body2->data;
		body2->link = NULL;

		// insert ptr into linked list
		if (head2 == NULL) {
			head2 = body2;
		}
		else {
			body2->link = head2;
			head2 = body2;
		}
	}
	reverseOrder(head2);

	cout << endl;
	cout << "The first linked list is shown as:" << endl;
	print(head1);

	cout << endl;
	cout << "The second linked list is shown as:" << endl;
	print(head2);

	cout << endl;
	cout << "Merged Linked List is:" << endl;
	NodePtr merged = mergeLists(head1, head2, totalNums1 + totalNums2);
	//print(merged);

	return 0;
}