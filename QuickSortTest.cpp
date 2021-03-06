#include "DataGenerator.h" 
#include "FileIO.h"
#include "Quicksort.h"
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	// used for user control flow
	char select = ' ';
	// size of the Array to be sorted/generated
	int size = 0;
	// the Array that is getting sorted
	int* toBeSorted;

	// I/O
	cout << "(a) 100000 elements" << endl;
	cout << "(b) 1000000 elements" << endl;
	cout << "(c) 5000000 elements" << endl;
	cout << "(d) quit" << endl;
	do {
		cout << "Please choose an option: " << flush;
		cin >> select;
	} while (select > 'd' || select < 'a');
	switch (select)
	{
	case 'a': size = 100000;
		break;
	case 'b': size = 1000000;
		break;
	case 'c': size = 5000000;
		break;
	case 'd': return 0;
		break;
	default:
		break;
	}
	do {
		cout << "Do you wanna sort an already sorted sorted Array? (y/n): " << flush;
		cin >> select;
	} while (select != 'y' && select != 'n');

	// create the Array
	toBeSorted = new int[size];

	if (select == 'n') {
		// if the input file allready exists
		if (fileExists(to_string(size) + "_input.txt")) {
			cout << "Input already exists!" << endl;
			do {
				cout << "Should a new input be generated? (y/n): " << flush;
				cin >> select;
			} while (select != 'n' && select != 'y');
		}
		// create a new one
		if (!fileExists(to_string(size) + "_input.txt") || select == 'y') {
			cout << "Input is getting generated..." << endl;
			int* input = new int[size];
			generateData(input, size);
			writeToFile(to_string(size) + "_input.txt", input, size);
			delete[] input;
		}
		cout << "Reading input from file..." << endl;
		// read from the File
		readFromFile(to_string(size) + "_input.txt", toBeSorted, size);
	}
	else {
		if (!fileExists(to_string(size) + "_output.txt")) {
			cout << "There is no sorted array of this size" << endl;
			cout << "Please sort one of this size first" << endl;
			return 0;
		}
		cout << "Reading input from file..." << endl;
		readFromFile(to_string(size) + "_output.txt", toBeSorted, size);
	}
	do {
		cout << "(i)terative or (r)ecursive Quicksort?" << flush;
		cin >> select;
	} while (select != 'i' && select != 'r');
	clock_t start, end;
	if (select == 'r') {
		do {
			cout << "a. Lombuto Partition \nb. Median of Three\nSelection: " << flush;
			cin >> select;
		} while (select != 'a' && select != 'b');
		cout << "Sorting... " << endl;
		if (select == 'a') {
			start = clock();
			quickSort(toBeSorted, 0, size - 1);
			end = clock();
		}
		else {
			start = clock();
			quickSortMedian(toBeSorted, 0, size - 1);
			end = clock();
		}

	}
	else {
		do {
			cout << "a. Lombuto Partition\nb. Median of Three\nSelection: " << flush;
			cin >> select;
		} while (select != 'a' && select != 'b');
		cout << "Sorting..." << endl;
		if (select == 'a') {
			start = clock();
			quickSortIterativ(toBeSorted, size);
			end = clock();
		}
		else {
			start = clock();
			quickSortMedianIterativ(toBeSorted, size);
			end = clock();
		}
	}
	long duration = ((end - start) * 1000) / CLOCKS_PER_SEC;
	cout << "Duration: " << duration << flush << endl;
	cout << "Writing to file ..." << endl;
	writeToFile(to_string(size) + "_output.txt",toBeSorted, size);
	delete[] toBeSorted;
    return 0;
}
