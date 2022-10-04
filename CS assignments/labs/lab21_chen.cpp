// 10380722, Anthony, Chen
// Date: 9/1/2022
// Lab2, Problem1

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_SLOTS = 3;

void rollSlots() {
	// use a simple array to check slots
	int rolls[MAX_SLOTS];

	// by default, assume match total is one number
	int matchedTotal = 1;

	// roll slots three times
	for (int i = 0; i < MAX_SLOTS; i++) {
		int slotRoll = (rand() % 9) + 1;
		rolls[i] = slotRoll;
		cout << " " << slotRoll << " ";

		// go through each slot to see if 
		// there are any matching the current slot
		for (int x = 0; x < i; x++) {
			if (rolls[x] == rolls[i]) {
				matchedTotal++;
			}
		}
	}
	
	// add spacing
	cout << endl;

	// switch message to determine slot result
	switch (matchedTotal) {
		case 1:
			cout << "No match" << endl;
			break;
		case 2:
			cout << "Matched 2!!" << endl;
			break;
		case 3:
			cout << "Jackpot!!" << endl;
			break;
	}

	// make bar prints
	cout << "-----------------------------" << endl;
	cout << endl;
}

int main()
{
	srand(time(0));
	char endLoop = 'y';

	while (endLoop == 'y') {
		rollSlots();
		cout << "Play again (y/n)?: ";
		cin >> endLoop;

	}
	
	return 0;
}