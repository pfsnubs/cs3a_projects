// 10380722, Anthony, Chen
// Date: 11/6/2022
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

NodePtr mergeLists(NodePtr& link1, NodePtr& link2, int maxNo) {
	NodePtr newHead = NULL;
	for (int i = 0; i < maxNo; i++) {
		// least to greatest, use winningLink as reference 
		// and ASSUME link1 is winner, swap otherwise
		NodePtr* winningLink = NULL;

		// detect first if either are null nodes, 
		// if so then set to the opposing node
		if (!link1) {
			winningLink = &link2;
		}
		else
		if (!link2) {
			winningLink = &link1;
		}

		// if both are still available nodes, compare datas
		if (!winningLink) {
			if (link1->data > link2->data) {
				winningLink = &link2;
			}
			else {
				winningLink = &link1;
			}
		}

		// add winner node to chain and advance link
		if (newHead == NULL) {
			NodePtr oldLink = (*winningLink)->link;
			// initialize head as winning node and advance
			newHead = (*winningLink);

			// de-reference link of head
			newHead->link = NULL;

			// set reference to its ascending
			*winningLink = oldLink;
			//cout << "(0)L1= " << link1->data << " L2= " << link2->data << endl;
			//cout << "(0)WL= " << (*winningLink)->data << " OL= " << oldLink->data << endl;
		}
		else {
			// store old pos of link for later
			NodePtr oldLink = (*winningLink)->link;
			(*winningLink)->link = NULL;

			// traverse head's link to the end and point to node
			NodePtr ptr = newHead;
			while (ptr->link != NULL) {
				ptr = ptr->link;
			}
			ptr->link = (*winningLink);

			// advance winner link to the next to look at 
			*winningLink = oldLink;
			//cout << "(2)L1= " << link1->data << " L2= " << link2->data << endl;
			//cout << "(3)WLL= " << winningLink->link->data << endl;
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
			// traverse through head link to add to end of chain
			NodePtr ptr = head1;
			while (ptr->link != NULL) {
				ptr = ptr->link;
			}
			ptr->link = body1;
		}
	}

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
			NodePtr ptr = head2;
			while (ptr->link != NULL) {
				ptr = ptr->link;
			}
			ptr->link = body2;
		}
	}

	cout << endl;
	cout << "The first linked list is shown as:" << endl;
	print(head1);

	cout << "The second linked list is shown as:" << endl;
	print(head2);

	cout << "Merged Linked List is:" << endl;
	NodePtr merged = mergeLists(head1, head2, totalNums1 + totalNums2);
	print(merged);

	return 0;
}