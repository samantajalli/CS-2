#ifndef WORDTREE_H
#define WORDTREE_H
#include <string>
using namespace std;

struct WordNode {
	string word;
	int count; // number of nodes in tree
	WordNode* left;
	WordNode* right;
	WordNode(const string& s)// default constructor for WordNode
		{
			count = 0;
			word = s; 
			left = NULL;
			right = NULL;
		}// insert initializer list here
};

class WordTree  {
public:
	WordTree();   // insert initializer list here
	~WordTree(); // use postorder traversal
	void Add(const string&);
	int CountNodes() const; // count frequencies of words in wordtree
	friend ostream& operator<<(ostream&, const WordTree&);//use inorder traversal
	 int LeafCount();
    int OneChildCount();
	int TwoChildCount();
	int Find(string word);

private:
	void Add(WordNode*&, const string&);
	int CountNodes(WordNode*) const;
	void DeleteTree(WordNode*);
	void Print(ostream&, WordNode*) const;
	WordNode* root;
	 int NumLeaves(WordNode* tree);
     int NumOneChild(WordNode* tree);
     int NumTwoChild(WordNode* tree);
     int FindWord(WordNode* tree, string word);
};

#endif