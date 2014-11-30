
#include "../MyLeetCode/stdafx.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
		inorderTraversal(root, result);
		return result;
    }
	
private:
    void inorderTraversal(TreeNode *root, vector<int> &result) {
		if (!root) return;
        if (root->left ) inorderTraversal(root->left,  result);
		result.push_back(root->val);
        if (root->right) inorderTraversal(root->right, result);
    }
};

class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
		stack<TreeNode *> walker;
		TreeNode *pCurNode = root;
		while (!walker.empty() || pCurNode != nullptr) {
			if (pCurNode != nullptr) {
				walker.push(pCurNode);
				pCurNode = pCurNode->left;
			}
			else {
				pCurNode = walker.top();
				walker.pop();
				result.push_back(pCurNode->val);
				pCurNode = pCurNode->right;
			}
		}

		return result;
    }
};