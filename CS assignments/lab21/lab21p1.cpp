// 10380722, Anthony, Chen
// Date: 11/17/2022
// Lab 21, Problem 1

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void printMap(int **map, int row, int col) {
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << map[i][j] << " ";
        cout << endl;
    }
}

int gatherLit(int** map, int row, int col) {
    int maxLit = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            if (map[i][j] == 1) {
                maxLit++;
            }
    }
    return maxLit;
}

int** flipRowCol(int** map, int rowSelect, int colSelect, int row, int col) {
    // create a copy of map to look at
    int** invertedMap = new int* [row];
    for (int i = 0; i < row; i++)
        invertedMap[i] = new int[col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            invertedMap[i][j] = map[i][j];
    }

    // look at row-by-row and invert column vals
    for (int i = 0; i < row; i++)
    {
        if (invertedMap[i][colSelect] == 0) {
            invertedMap[i][colSelect] = 1;
        }
        else {
            invertedMap[i][colSelect] = 0;
        }
    }

    // look at col-by-col and invert row vals
    for (int i = 0; i < col; i++)
    {
        if (invertedMap[rowSelect][i] == 0) {
            invertedMap[rowSelect][i] = 1;
        }
        else {
            invertedMap[rowSelect][i] = 0;
        }
    }
    
    return invertedMap;
}

int main()
{
    string fileName;
    cout << "Enter the fileName : ";
    cin >> fileName;

    ifstream inStream;
    inStream.open("lab21\\" + fileName);
    if (inStream.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }

    // Create row x col matrix
    int row, col;
    inStream >> row >> col;

    int** map = new int* [row];
    for (int i = 0; i < row; i++)
        map[i] = new int[col];

    while (!inStream.eof())
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
                inStream >> map[i][j];
        }
    }

    // Print out original map
    cout << "\n  Original map" << endl;
    cout << "----------------" << endl;
    printMap(map, row, col);

    // Find which pair of row and col will give the max lit bulbs
    int maxRow = 0;
    int maxCol = 0;
    int maxLit = 0;
    int** mapMax = NULL;
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int** invertedMap = flipRowCol(map, i, j, row, col);
            int maxCompare = gatherLit(invertedMap, row, col);
            // set new max as combination of i-j inversion pairs
            if (maxLit < maxCompare) {
                maxRow = i;
                maxCol = j;
                maxLit = maxCompare;
                mapMax = invertedMap;
            }
        }
    }
    
    cout << left << setw(7) << "Row" << setw(3) << ":" << maxRow << endl;
    cout << left << setw(7) << "Column" << setw(3) << ":" << maxCol << endl;
    cout << left << setw(7) << "Max" << setw(3) << ":" << maxLit << endl;

    return 0;
}