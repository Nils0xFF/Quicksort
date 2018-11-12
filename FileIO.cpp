#include "FileIO.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void writeToFile(string fileName, int* outPut, int length) {
	ofstream myFile;
	myFile.open(fileName);
	if (myFile.is_open()) {
		for (int i = 0; i < length - 1; i++) {
			myFile << outPut[i] << ",";
		}
		myFile << outPut[length - 1]  << "/n";
		myFile.close();
	}
	else cout << "Cant open Outputfile";
	return;
}

void readFromFile(string fileName, int* input, int length) {
	ifstream myFile;
	string line;
	myFile.open(fileName);
	if (myFile.is_open()) {
		int i = 0;
		while (getline(myFile, line, ',') && i < length) {
			if (line == "/n") break;
			input[i] = stoi(line);
			i++;
		}
		myFile.close();
	}
	else cout << "Cant open InputFile";
	return;
}

bool fileExists(string fileName) {
	ifstream file(fileName);
	return file.good();
}