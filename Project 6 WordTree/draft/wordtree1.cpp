#include <iostream>
#include <string>
#include <"wordtree1.h">

WordTree::WordTree()
{
	root == NULL;
}

WordTree::~WordTree()
{
	DeleteTree(root);
}

void WordTree::DeleteTree(WordNode* tree)
{

}

void WordTree::Add(const string& insert)
{
	Add(root, insert);
}

void WordTree::Add(WordNode*& tree, const string& intree)
{
	if (tree == NULL)
	{// insertion place found
		tree = new WordNode;
		tree->right = NULL;
		tree->left = NULL;
		tree->word = intree;
		count++;	
	}
	else if (intree > tree->word) // check left subtree
		Add(tree->left, intree);
	else							//check right subtree
		Add(tree->right, intree);
	
}

int CountNodes() const
{
	return CountNodes(root);
}

int CountNodes(WordNode* tree) const
{
	if (tree == NULL)
		return 0;
	else
		return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}