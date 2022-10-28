// 10380722, Anthony, Chen
// Date: 10/30/2022
// Lab14, Problem1
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
typedef struct node* NodePtr;

class student
{
private:
	int id;
	string name;
	int score;
public:
	// constructors
	student() {};
	student(int newId, string newName, int newScore) {
		id = newId;
		name = newName;
		score = newScore;
	}

	// fxns

	// getter methods
	int getId() {
		return id;
	}
	string getName() {
		return name;
	}
	int getScore() {
		return score;
	}

	// setter methods
	void setId(int newId) {
		id = newId;
	}
	void getName(string newName) {
		name = newName;
	}
	void getScore(int newScore) {
		score = newScore;
	}
};


struct node
{
public:
	student data;
	NodePtr link;
};


void print(NodePtr head)
{
	for (NodePtr ptr = head; ptr != NULL; ptr = ptr->link ) {
		cout << setw(5) << ptr->data.getId() << setw(10) << ptr->data.getName() 
			<< setw(10) << ptr->data.getScore() << " ";
		cout << endl;
	}
		
}

int main()
{
	// menu input for filename
	string fileName;
	cout << "Enter filename : ";
	cin >> fileName;
	ifstream infile;
	infile.open(fileName);
	if (infile.fail()) {
		cout << "Input file opening failed." << endl;
		exit(1);
	}

	// read file to create student linked list
	NodePtr head = NULL, body = NULL;
	while (!infile.eof()) {
		// skip line
		int newId, newScore;
		string newName;
		infile >> newId >> newName >> newScore;

		// create newStudent and put into body node
		student newStudent = student(newId, newName, newScore);
		body = new node{newStudent, NULL};

		// insert ptr into linked list
		if (head == NULL) {
			head = body;
		}
		else if (head->data.getId() < body->data.getId()) {
			NodePtr prev = NULL;

			// traverse list from back
			for (NodePtr temp = head; temp != NULL; temp = temp->link) {
				if (temp->data.getId() < body->data.getId()) {
					body->link = temp->link;
					temp->link = body;

					if (prev != NULL) {
						prev->link = temp;
					}
					prev = temp;
				}
			}
		}
		else {
			body->link = head;
			head = body;
		}
	}

	// print after every sort for ladder output
	print(head);

	return 0;
}