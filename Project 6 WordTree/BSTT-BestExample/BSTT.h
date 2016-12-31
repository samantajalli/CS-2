#ifndef BSTT_H
#define BSTT_H
#include <iostream>
using namespace std;

struct TreeNode  {
	int num;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int n) : left(NULL), right(NULL)  {}
};

class BSTT {
public:
	BSTT() : root(NULL)  {}
	~BSTT();

	bool IsEmpty() const;
	bool IsPresent(int) const;

	void Insert(int);

	void Delete(int);

	friend ostream& operator<< (ostream&, const BSTT& );

private:
	void PrintTree (ostream&, TreeNode*) const;

	void DeleteTree(TreeNode*);
	void Insert(int, TreeNode*&);
	void Delete(int, TreeNode*&);
	int DeleteSmallest(TreeNode*&);

	TreeNode* root;
};
#endif
