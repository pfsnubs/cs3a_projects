// 10380722, Anthony, Chen
// Date: 9/1/2022
// Lab2, Problem2

#include <iostream>

using namespace std;

// correct answer used as constants 
// (obviously this could be bad code in actual practice, 
// but we are just using it for now)
const string USERNAME = "pcc";
const string PASSWORD = "computer";

void checkPassword(string id, string pass) {
	// use wrongInput to determine error message
	string msgOutput = "";

	// detect wrong user
	if (id != USERNAME) {
		msgOutput = "Wrong id";
	}

	// detect wrong pass
	if (pass != PASSWORD) {
		// if user AND pass wrong, write as both wrong
		if (msgOutput != "") {
			msgOutput = "Wrong id and password";
		}
		else {
			msgOutput = "Wrong password";
		}
	}

	// if there has been no incorrect info, write as correct
	if (msgOutput == "") {
		msgOutput = "Welcome!";
	}

	// print message
	cout << msgOutput;
}

int main()
{
	string idInput, passInput;

	// ask user to enter ID
	cout << "Enter ID: ";
	cin >> idInput;
	cout << "Enter password: ";
	cin >> passInput;

	// validate with function
	checkPassword(idInput, passInput);

	return 0;
}