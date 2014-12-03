
#include "../MyLeetCode/stdafx.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		if (preorder.empty()) return nullptr;

        TreeNode *root = new TreeNode(preorder[0]);
		int leftNodes  = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
		int rightNodes = inorder.size() - 1 - leftNodes;

		if (leftNodes) {
			vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + leftNodes + 1);
			vector<int> leftInorder ( inorder.begin()	 ,  inorder.begin() + leftNodes);
			root->left = buildTree(leftPreorder, leftInorder);
		}
		
		if (rightNodes) {
			vector<int> rightPreorder(preorder.end() - rightNodes, preorder.end());
			vector<int> rightInorder ( inorder.end() - rightNodes,  inorder.end());
			root->right = buildTree(rightPreorder, rightInorder);
		}

		return root;
    }
};

class Solution1 {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		return buildTreeHelper(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }

    TreeNode *buildTreeHelper(vector<int> ::iterator preBegin, vector<int> ::iterator preEnd, vector<int> ::iterator inBegin, vector<int> ::iterator inEnd) {
		if (preEnd <= preBegin) return nullptr;

        TreeNode *root = new TreeNode(*preBegin);
		int leftNodes  = find(inBegin, inEnd, *preBegin) - inBegin;
		root->left  = buildTreeHelper(preBegin + 1, preBegin + leftNodes + 1, inBegin, inBegin + leftNodes);
		root->right = buildTreeHelper(preBegin + leftNodes + 1, preEnd, inBegin + leftNodes + 1, inEnd);

		return root;
    }
};

class Tester{
public:
    int test() {
		vector<int> row0;
		row0.push_back(1);
		row0.push_back(2);
		vector<int> row1;
		row1.push_back(2);
		row1.push_back(1);

		Solution sol;
		sol.buildTree(row0, row1);
        return 0;
    }
};