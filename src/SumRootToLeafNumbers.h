
#include "../MyLeetCode/stdafx.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        sum = 0;
		sumNumbers(root, 0);
		return sum;
    }

private:
	int sum;

	void sumNumbers(TreeNode *root, int num) {
		if (!root) return;

		num = num*10 + root->val;
		if (root->left == nullptr && root->right == nullptr) sum += num;
		if (root->left) sumNumbers(root->left, num);
		if (root->right) sumNumbers(root->right, num);
	}
};