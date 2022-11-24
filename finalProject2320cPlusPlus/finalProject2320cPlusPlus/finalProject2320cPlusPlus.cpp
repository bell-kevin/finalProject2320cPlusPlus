// finalProject2320cPlusPlus.cpp
//


//This project encrypts data using transposition, substitution, and reversal -- substituting one letter for another using a key value, transposing letters into separate strings, and reversing strings. It then decrypts those results and checks if that decrypted string matches the original string.

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
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
			substitutionString += '#';
		}
		else {
			substitutionString += (fileContents[i] + key);
		}
	}
	return substitutionString;
}

//function to split one string into two strings. one string for characters in even positions in the original string, and one string for characters in odd positions in the original string
void splitString(string fileContents, string& evenString, string& oddString) {
	for (int i = 0; i < fileContents.length(); i++) {
		if (i % 2 == 0) {
			evenString += fileContents[i];
		}
		else {
			oddString += fileContents[i];
		}
	}
}

//function to merge two string into one string, interweaving them together
string mergeString(string evenString, string oddString) {
	string mergedString;
	for (int i = 0; i < evenString.length(); i++) {
		mergedString += evenString[i];
		mergedString += oddString[i];
	}
	return mergedString;
}

//function to reverse a string using a stack
string reverseString(string fileContents) {
	string reversedString;
	stack<char> myStack;
	for (int i = 0; i < fileContents.length(); i++) {
		myStack.push(fileContents[i]);
	}
	while (!myStack.empty()) {
		reversedString += myStack.top();
		myStack.pop();
	}
	return reversedString;
}

//function to write a file
void writeFile(string fileName, string fileContents) {
	ofstream myfile(fileName);
	if (myfile.is_open()) {
		myfile << fileContents;
		myfile.close();
	}
	else {
		cout << "Unable to open file";
	}
}


int main() {
	cout << "Final Project by Kevin Bell\n\n";
	//read a file
	string fileContents = readFile("text.txt");
	cout << "Original: " << fileContents << endl;
	//Once you have read in the original text, you need to substitute each character by adding 3 to the ASCII value of the character.
	string substitutionString = substitution(fileContents, 3);
	//Next, split the substituted string into 2 strings, one for characters in even positions in the original string, and one for characters in odd positions in the original string.
	string evenString;
	string oddString;
	splitString(substitutionString, evenString, oddString);
	//Then reverse each of those strings using a stack.
	string reversedEvenString = reverseString(evenString);
	string reversedOddString = reverseString(oddString);
	cout << "file 1: " << reversedEvenString << endl;
	cout << "file 2: " << reversedOddString << endl;
	//secondStringReversed and firstStringReversed go into two separate output files. Do not close the files for the 2 output files after writing the even and odd strings to them
	writeFile("file1.txt", reversedEvenString);
	writeFile("file2.txt", reversedOddString);
	cout << "both files written\n\n";
	cout << "Now reverse that process to decrypt\n\n";
	cout << " original: " << fileContents << endl;
	//Begin by reading the data from the 2 files created during the encryption process -- do not use the string variables used in that encryption process, make sure you read the data from files
	string file1Contents = readFile("file1.txt");
	string file2Contents = readFile("file2.txt");
	//Next, reverse the strings in the 2 files using a stack.
	string reversedFile1Contents = reverseString(file1Contents);
	string reversedFile2Contents = reverseString(file2Contents);
	//substitute each character by subtracting 3 from the ASCII value of the character.
	string decryptedSubstitutionStringFile1 = substitution(reversedFile1Contents, -3);
	string decryptedSubstitutionStringFile2 = substitution(reversedFile2Contents, -3);
	//merge the 2 strings into one string, interweaving them together
	string decryptedMergedString = mergeString(decryptedSubstitutionStringFile1, decryptedSubstitutionStringFile2);
	//remove the \0 characters from the string
	string decryptedString;
	for (int i = 0; i < decryptedMergedString.length(); i++) {
		if (decryptedMergedString[i] != '\0') {
			decryptedString += decryptedMergedString[i];
		}
	} // end for loop
	//output the decrypted string to the screen
	cout << "decrypted: " << decryptedString << endl;
	//check if that decrypted string matches the original string.
	if (decryptedString == fileContents) {
		cout << "decrypted string matches original string\n";
	}
	else {
		cout << "decrypted string does not match original string\n";
	}
	system("pause");
	return 0;
} //end main function
