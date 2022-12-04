// 10380722, Anthony, Chen
// Date: 11/22/2022
// Lab22, Problem1

#include <string>
#include <iostream>

using namespace std;

// classes for exception handling
class ZeroInFront {};
class CharFound {
public:
	CharFound() {};
	CharFound(char c){
		this->c = c;
	}
	char getChar() {
		return c;
	}
private:
	char c;
};


int main()
{
	string int1, int2;
	bool passedProgram = false;
	do {
		try {
			cout << "Enter two integers:\n";
			cin >> int1 >> int2;

			// condt 1: check if zero is in front of number
			if (int1[0] == '0' && int1.length() > 1
				|| int2[0] == '0' && int2.length() > 1) {
				throw ZeroInFront();
			}

			// condt 2: check if there are any chars
			char charFind;
			for (int i = 0; i < int1.length(); i++) {
				if (!isdigit(int1[i])) {
					charFind = int1[i];
					throw CharFound(charFind);
					break;
				}
			}
			for (int i = 0; i < int2.length(); i++) {
				if (!isdigit(int2[i])) {
					charFind = int2[i];
					throw CharFound(charFind);
					break;
				}
			}
			int sum = stoi(int1) + stoi(int2);
			cout << int1 << " + " << int2 << " = " << sum << endl;
			passedProgram = true;
		}
		catch (ZeroInFront) {
			cout << "Numbers starting with 0 cannot be entered." << endl;
			cout << "Please enter again.\n" << endl;
		}
		catch (CharFound cFound) {
			cout << "You entered a character " << cFound.getChar() << "." << endl;
			cout << "Please enter again.\n" << endl;
		}
	} while (!passedProgram);
	cout << "Exiting the program...." << endl;
	return 0;
}