
#include "../MyLeetCode/stdafx.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return num.empty() ? nullptr : sortedArrayToBST(num, 0, num.size() - 1);
    }

private:
    TreeNode *sortedArrayToBST(vector<int> &num, int start, int end) {
		int mid = (start + end) >> 1;
        TreeNode *root = new TreeNode(num[mid]);
		
		if (start < mid) root->left  = sortedArrayToBST(num, start, mid - 1);
		if (mid   < end) root->right = sortedArrayToBST(num, mid + 1, end);

		return root;
    }
};