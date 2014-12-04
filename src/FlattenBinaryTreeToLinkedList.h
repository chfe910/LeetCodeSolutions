
#include "../MyLeetCode/stdafx.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode *root) {
        if (!root) return;

		if (root->left) {
			TreeNode *pCurNode = root->left;
			if (root->right) {
				while (pCurNode->right) pCurNode = pCurNode->right;
				pCurNode->right = root->right;
			}
			root->right = root->left;
			root->left = nullptr;
		}

		flatten(root->right);
    }
};


class Solution1 {
public:
    void flatten(TreeNode *root) {
		for (TreeNode *pCurChildRoot = root; pCurChildRoot != nullptr; pCurChildRoot = pCurChildRoot->right)
			if (pCurChildRoot->left) {
				TreeNode *pCurNode = pCurChildRoot->left;
				if (pCurChildRoot->right) {
					while (pCurNode->right) pCurNode = pCurNode->right;
					pCurNode->right = pCurChildRoot->right;
				}
				pCurChildRoot->right = pCurChildRoot->left;
				pCurChildRoot->left = nullptr;
			}
    }
};


class Tester{
public:
    int test() {
		Solution sol;

		TreeNode *root = new TreeNode(1);
		root->right = new TreeNode(2);
		sol.flatten(root);

        return 0;
    }
};
