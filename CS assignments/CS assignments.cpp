// 10380722, Anthony, Chen
// Date: 10/23/2022
// Homework Project 1

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stack>
using namespace std;

bool palinCheck(string palinString) {
    bool truePalindrome = false;
    stack<char> palin;
    stack<char> palin2;
    
    // push chars into char stack
    for (int i = 0; i < palinString.length(); i++) {
        palin.push(palinString[i]);
        if (palin == palin2) {
            truePalindrome = true;
        }
    }

    for (int i = 0; i < palinString.length(); i++) {
        palin.push(palinString[i]);
        if (palin == palin2) {
            truePalindrome = true;
        }
    }

    return truePalindrome;
}

int main()
{
    string palin;
    cout << "Enter string: ";
    // read data into ps
    cin >> palin;
    
    bool palindromed = palinCheck();
    if (palindromed) {
        cout << palin << " is a palindrome" << endl;
    }
    else {
        cout << palin << " is not a palindrome" << endl;
    }

    return 0;
}
