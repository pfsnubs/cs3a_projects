// 10380722, Anthony, Chen
// Date: 10/23/2022
// Lab13, Problem1
#include <iostream>

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
	for (NodePtr ptr = head; ptr != NULL; ptr = ptr->link)
		cout << ptr->data << " ";
	cout << endl;
}

int main()
{
	int A[10] = { 4, 3, 6, 1, 10, 9, 5, 8, 7, 2 };

	NodePtr head = NULL, body = NULL;
	for (int i = 0; i < 10; i++) {
		body = new node;
		body->data = A[i];
		body->link = NULL;

		// insert ptr into linked list
		if (head == NULL) {
			head = body;
		}
		else if (head->data > body->data) {	
			cout << head->data << " OVER DATA " << body->data << endl;
			NodePtr prev = head->link;
			for (NodePtr temp = head; (temp->data < body->data); temp = temp->link) {
				cout << temp->data << "COMPARING FOR VAL" << body->data << endl;
				prev = temp;
			}

			body->link = prev->link;
			prev->link = body;
		}
		else {
			body->link = head;
			head = body;
		}
	}

	print(head);
	return 0;
}