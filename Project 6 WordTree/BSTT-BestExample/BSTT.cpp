#include <iostream>
#include "BSTT.h"

using namespace std;

BSTT::~BSTT() {
	DeleteTree(root);
}

// Returns true if a node in the tree contains the integer n, false otherwise.  Nonrecursive version.
bool BSTT::IsPresent(int n) const {
	TreeNode* p = root;
	while ( p !=NULL ) {
		if (p->num == n)
			return true;
	    p = ( (n < p->num) ? (p->left) : (p->right) );
	}
	// if p is ever NULL, we know the item was not in the tree
	return false;
}

void BSTT::Insert(int n) {
	Insert(n, root);
}

void BSTT::Delete(int n) {
	Delete(n, root);
}

ostream& operator<<(ostream& out, const BSTT& b) {
	b.PrintTree(out, b.root);
	return out;
}

void BSTT::PrintTree(ostream& out, TreeNode* p) const {
	// inorder traversal so elements are printed in ascending order
	if (p != NULL) {
		PrintTree(out, p->left);  // prints nodes in left subtree
		out << p->num << "\n";   // prints data in current node
		PrintTree(out, p->right);  // prints nodes in right subtree
	}
}

void BSTT::DeleteTree(TreeNode* p) {
	// deletes the entire tree that p points to
	if ( p != NULL ) {
		// Do recursive call to delete the left and right subtrees of p, then delete the node that p points to
		DeleteTree(p->left);  
		DeleteTree(p->right);
		delete p;
	}
}

void BSTT::Insert(int n, TreeNode*& p)  {
	if ( p == NULL) {
		p = new TreeNode(n);
	} else if (n < p->num) {
		Insert(n, p->left);
	} else {
		Insert(n, p->right);
	}
}

void BSTT::Delete(int n, TreeNode*& p) {
	// Note that p can never be NULL, by precondition on the public Delete
	if (n < p->num) {
		Delete(n, p->left);
	} else if (n > p->num) {
		Delete(n, p->right);
	} else if (p->left == NULL  &&  p->right == NULL) {
		// Leaf - although this case can be ommitted, since next case covers it
		delete p;
		p = NULL;
	} else if (p->left == NULL) {
		// p has a right child but no left child
		TreeNode* q = p;  // create temp pointer
		p = p->right;
		delete q;
	} else if (p->right == NULL) {
		// p has a left child but no right child
		TreeNode* q = p;
		p = p->left;
		delete q;
	} else {
		// p has both a left and a right child.
		// replace p->num with the successor of num in the tree, and then 
		// delete the node that held this number.
		p->num = DeleteSmallest(p->right);
	}
}

// Delete the smallest element in the tree pointed to by p, and return the value it stored
int BSTT::DeleteSmallest(TreeNode*& p) {
	if (p->left != NULL) {
		// There is a smaller element in the tree.  Make a recursive call.
		return DeleteSmallest(p->left);
	} else {
		// no left child, so there is no smaller element in the tree
		int n = p->num;  // save the number stored in p
		TreeNode* q = p;  // save address of node so we can delete it
		p = p->right;  
		delete q;
		return n;
	}
}
