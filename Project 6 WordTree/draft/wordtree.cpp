#include <iostream>
#include "wordtree.h"
#include <string>

WordTree::WordTree()
{
	root = NULL;
}

WordTree::~WordTree()
{
	DeleteTree(root);
}

void WordTree::DeleteTree(WordNode* tree)
{
	if (tree != NULL) // do recursive call to delete the left/right subtrees of tree, then deletes node that tree points to
	{
		DeleteTree(tree->left);
		DeleteTree(tree->right);
		delete tree;
	}
}

void WordTree::Add(const string& insert)
{
	Add(root, insert);
}

void WordTree::Add(WordNode*& tree, const string& intree)
{
	if (tree == NULL) 
	{// insertion place found
		
		tree = new WordNode(intree);
		tree->count++;
		tree->right = NULL;
		tree->left = NULL;
		tree->word = intree;		
	}
	else if (tree->word == intree){ // a word in the tree equals a word being read
		// so don't add it as a new node, just increment its count.
		tree->count++;
			return; 
	}
	else if (intree < tree->word) // check left subtree
		Add(tree->left, intree);
	else							//check right subtree
		Add(tree->right, intree);
	
}

int WordTree::CountNodes() const
{
	return CountNodes(root);
}

int WordTree::CountNodes(WordNode* tree) const
{
	if (tree == NULL)
		return 0;
	else
		return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}

int WordTree::LeafCount()
{
	return NumLeaves(root);
}

int WordTree::NumLeaves(WordNode *tree)
{
	int leafcount=0;
	
	if(tree!=0)
	{
		if (tree->left == NULL && tree->right == NULL)
		{
				leafcount++;
			leafcount+=NumLeaves(tree->left);
			leafcount+=NumLeaves(tree->right);
		}
		else
			leafcount+= NumLeaves(tree->left) ;
			leafcount+= NumLeaves(tree->right);
	}
	return leafcount;	
}

int WordTree::OneChildCount()
{
	return NumOneChild(root);
}

int WordTree::NumOneChild(WordNode* tree)
{
		int onecount=0;
		if (tree != NULL)
		{
	
			if (tree->left == NULL && tree->right != NULL)
			{
				onecount++;
				onecount+= NumOneChild(tree->left) ;
				onecount+= NumOneChild(tree->right);
			}
			else if (tree->left != NULL && tree->right == NULL)
			{
				onecount++;
				onecount+= NumOneChild(tree->left) ;
				onecount+= NumOneChild(tree->right);
			}
			else 
			{
				onecount+= NumOneChild(tree->left) ;
				onecount+= NumOneChild(tree->right);
			}
	}
	return onecount;
	
}


int WordTree::TwoChildCount()
{
	return NumTwoChild(root);
}

int WordTree::NumTwoChild(WordNode* tree)
{
	if (tree == NULL)
		return 0;
	if (tree->left!= NULL && tree->right != NULL){
		return 1 + NumTwoChild(tree->left) + NumTwoChild(tree->right);
	}
	return NumTwoChild(tree->left) + NumTwoChild(tree->right);
}

ostream& operator<<(ostream& out, const WordTree& t)
{
	t.Print(out, t.root);
	return out;
}

void WordTree::Print(ostream& out, WordNode* n) const
{ // inorder traversal so elements are printed in ascending order
	if (n != NULL){
		Print(out, n->left); // print nodes in left subtree
		out << n->word << " "<< n->count << "\n"; // prints data in current node
		Print(out, n->right); // print nodes in right subtree
	}
}

int WordTree::Find(string word) // find a node with a specific word
{
	return FindWord(root, word);
}

int WordTree::FindWord(WordNode* tree, string item)
{  
	if (tree != NULL)
	{	
		if (item < tree->word) // search left subtree
			return FindWord(tree->left, item);
		
		else if (item > tree->word) // search right subtree
			return FindWord(tree->right, item);
			// word was found
		if(item == tree->word)
			return   tree->count;	
		
	}
	
	 
}