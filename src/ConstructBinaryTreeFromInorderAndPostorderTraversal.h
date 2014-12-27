
#include "../MyLeetCode/stdafx.h"

//Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		return buildTreeHelper(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }

    TreeNode *buildTreeHelper(vector<int> ::iterator inBegin, vector<int> ::iterator inEnd, vector<int> ::iterator postBegin, vector<int> ::iterator postEnd) {
		if (postEnd <= postBegin) return nullptr;

        TreeNode *root = new TreeNode(*(postEnd - 1));
		int leftNodes  = find(inBegin, inEnd, *(postEnd - 1)) - inBegin;
		root->left  = buildTreeHelper(inBegin, inBegin + leftNodes, postBegin, postBegin + leftNodes);
		root->right = buildTreeHelper(inBegin + leftNodes + 1, inEnd, postBegin + leftNodes, postEnd - 1);

		return root;
    }
};

class Tester{
public:
    int test() {
		vector<int> inorder(2), postorder(2);
		inorder[0] = 1;
		inorder[1] = 2;
		postorder[0] = 2;
		postorder[1] = 1;

		Solution sol;
		sol.buildTree(inorder, postorder);
        return 0;
    }
};