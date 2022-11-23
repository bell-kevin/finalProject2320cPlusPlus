// finalProject2320cPlusPlus.cpp
//


//This project encrypts data using transposition, substitution, and reversal -- substituting one letter for another using a key value, transposing letters into separate strings, and reversing strings. It then decrypts those results and checks if that decrypted string matches the original string.

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
using namespace std;

//Create a project that reads a text file that contains a string.

//function to read a file
string readFile(string fileName) {
	string line;
	string fileContents;
	ifstream myfile(fileName);
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			fileContents += line;
		}
		myfile.close();
	}
	else {
		cout << "Unable to open file";
	}
	return fileContents;
}

//function to substitute characters using a key value
string substitution(string fileContents, int key) {
	string substitutionString;
	for (int i = 0; i < fileContents.length(); i++) {
		if (fileContents[i] == ' ') {
			substitutionString += ' ';
		}
		else {
			substitutionString += (fileContents[i] + key);
		}
	}
	return substitutionString;
}

//function to split one string into two strings
vector<string> splitString(string fileContents) {
	vector<string> splitString;
	string firstString;
	string secondString;
	for (int i = 0; i < fileContents.length(); i++) {
		if (i % 2 == 0) {
			firstString += fileContents[i];
		}
		else {
			secondString += fileContents[i];
		}
	}
	splitString.push_back(firstString);
	splitString.push_back(secondString);
	return splitString;
}

//function to merge two strings into one string interweaving the characters
string mergeString(vector<string> splitString) {
	string mergedString;
	for (int i = 0; i < splitString[0].length(); i++) {
		mergedString += splitString[0][i];
		mergedString += splitString[1][i];
	}
	return mergedString;
}

//function to reverse a string using a stack
string reverseString(string fileContents) {
	string reversedString;
	stack<char> reverseStack;
	for (int i = 0; i < fileContents.length(); i++) {
		reverseStack.push(fileContents[i]);
	}
	while (!reverseStack.empty()) {
		reversedString += reverseStack.top();
		reverseStack.pop();
	}
	return reversedString;
}

int main()
{
    cout << "Final Project by Kevin Bell\n\n";
	string fileContents = readFile("text.txt");
	cout << "Original: " << fileContents << endl;
}