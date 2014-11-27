
#include "../MyLeetCode/stdafx.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
		vector<int> level;

		queue<TreeNode *> levelQ;
		if (root) levelQ.push(root);		
		while (!levelQ.empty()) {
			level.clear();
			int size = levelQ.size();
			for (int i = 0; i < size; ++i) {
				TreeNode *node = levelQ.front();
				levelQ.pop();

				level.push_back(node->val);

				if (node->left ) levelQ.push(node->left );
				if (node->right) levelQ.push(node->right);
			}

			result.push_back(level);
		}

		return result;
    }
};