#include <fstream>
#include <iostream>
#include <cctype>
#include <string>
#include "wordtree.h"
using namespace std;

int main() {
	ifstream fin;
	ofstream fout;
	string filename;
	cout << "Enter name of file with text to analyze: ";
	cin >> filename;
	fin.open(filename.c_str());
	if (fin.fail()) {
		cout << "Error opening file.\n";
		exit(1);
	}
	cout << "\nAnalyzing " << filename << ".\n";

	WordTree myTree;

	// Place code to process file here
	
	fin.close();
    fout.open("results.txt");

	// Don't change the following - it displays the tree and word counts to the screen and to an output file.
	cout << "\nWord counts:\n\n";
	cout << myTree;
	fout << myTree;
	cout << "\nTotal number of words in text: " << wordcount << ".\n";
	fout << "\nTotal number of words in text: " << wordcount << ".\n";
	cout << "Number of distinct words appearing in text: "
		 << myTree.CountNodes() << ".\n";
	fout << "Number of distinct words appearing in text: "
		 << myTree.CountNodes() << ".\n";
	// insert code to display leaf and node info
	
 
	// insert loop here to allow user to enter a word, then display the number of times that word occurs in the text.  This loop will continue until 
	// user enters some kind of quit condition to indicate no more word searches.
	
	}

	fout.close();
	return 0;
}

