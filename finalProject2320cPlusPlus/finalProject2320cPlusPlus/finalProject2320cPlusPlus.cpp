// finalProject2320cPlusPlus.cpp
//


//This project encrypts data using transposition, substitution, and reversal -- substituting one letter for another using a key value, transposing letters into separate strings, and reversing strings. It then decrypts those results and checks if that decrypted string matches the original string.

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <iomanip>
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
			substitutionString += '#';
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
	//Once you have read in the original text, you need to substitute each character by adding 3 to the ASCII value of the character.
	string substitutionString = substitution(fileContents, 3);
	//Next, split the substituted string into 2 strings, one for characters in even positions in the original string, and one for characters in odd positions in the original string.
	vector<string> splitStringVector = splitString(substitutionString);
	//Then reverse each of those strings using a stack.
	string firstStringReversed = reverseString(splitStringVector[0]);
	string secondStringReversed = reverseString(splitStringVector[1]);
	cout << "file 1: " << firstStringReversed << endl;
	cout << "file 2: " << secondStringReversed << endl;
	//secondStringReversed and firstStringReversed go into two separate output files. Do not close the files for the 2 output files after writing the even and odd strings to them
	ofstream myfile1("file1.txt");
	if (myfile1.is_open()) {
		myfile1 << firstStringReversed;
		myfile1.close();
	}
	else {
		cout << "Unable to open file";
	}
	
	ofstream myfile2("file2.txt");
	if (myfile2.is_open()) {
		myfile2 << secondStringReversed;
		myfile2.close();
	}
	else {
		cout << "Unable to open file";
	}
	cout << "both files written\n\n";
	cout << "Now reverse that process to decrypt\n\n";
	cout << " original: " << fileContents << endl;
	//Begin by reading the data from the 2 files created during the encryption process -- do not use the string variables used in that encryption process, make sure you read the data from files
	string file1Contents = readFile("file1.txt");
	string file2Contents = readFile("file2.txt");
	//Next, reverse the strings in the files using a stack.
	string file1ContentsReversed = reverseString(file1Contents);
	string file2ContentsReversed = reverseString(file2Contents);
	//substitute each character by subtracting 3 from the ASCII value of the character.
	string file1ContentsSubstituted = substitution(file1ContentsReversed, -3);
	string file2ContentsSubstituted = substitution(file2ContentsReversed, -3);
	//Merge the two strings into one string interweaving the characters.
	vector<string> mergeStringVector;
	mergeStringVector.push_back(file1ContentsSubstituted);
	mergeStringVector.push_back(file2ContentsSubstituted);
	string mergedString = mergeString(mergeStringVector);
	cout << "decrypted: " << mergedString << endl;
	//Check if the decrypted string matches the original string.
	if (fileContents == mergedString) {
		cout << "The decrypted string matches the original string\n";
	}
	else {
		cout << "The decrypted string does not match the original string\n";
	}	
	system("pause");
	return 0;
} //end main function