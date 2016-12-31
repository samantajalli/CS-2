#include <fstream>
#include <iostream>
#include <cctype>
#include <string>
#include "wordtree.h"
using namespace std;

int main() 
{
	int wordcount = 0;
	char cha;
	string word;
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
	fin.get(cha);
	// Place code to process file here
	while (!fin.eof()) // use tolower cctype to make capital letters lowercase
	{
		if (isalpha(cha) || cha == '\'')
		{
		  word += char(tolower(cha));
		}

		else if (word.length() > 0)
		{
			myTree.Add(word);
			word = "";
			wordcount++;
		}
		fin.get(cha);
		
		/*
		if(cha == ' ' || cha=='\n'){
		
			

			wordcount++;
			//word = "";
			
		}*/
	}
	
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
	cout << "Number of leaves: " << myTree.LeafCount();    
	fout << "Number of leaves: " << myTree.LeafCount();	 
	cout << "\nNumber of nodes with 1 link: " << myTree.OneChildCount();
	fout << "\nNumber of nodes with 1 link: " << myTree.OneChildCount();
	cout << "\nNumber of nodes with 2 links: " << myTree.TwoChildCount();
	fout << "\nNumber of nodes with 2 links: " << myTree.TwoChildCount();
 
	// insert loop here to allow user to enter a word, then display the number of times that word occurs in the text.  This loop will continue until 
	// user enters some kind of quit condition to indicate no more word searches. This is Find function
	string input;
	cout << "\n" << "Enter a word, then i will display number of times word occurs in text\n";
	cout << "Enter q to quit\n";
	
	//cin >> input;
	//	cout << " " << myTree.Find(input);
	//	cout << "\n"<< "Another input? ";
	//	cin >> input;
	
	cin >> input;
	do
	{
		
		cout << "\n" << input<< " " << "occurs " << myTree.Find(input) <<" times\n";
		cout <<"Another input: ";
		cin >> input;
	}while(input != "Q" && input != "q");

	

	fout.close();
	return 0;
}
