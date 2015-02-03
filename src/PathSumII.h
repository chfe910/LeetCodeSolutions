
#include "../MyLeetCode/stdafx.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<vector<int> > paths;
		vector<int> curr_path;
        if (!root) return paths;

		find(root, sum, paths, curr_path);

		return paths;
    }

private:
	void find(TreeNode *root, int sum, vector<vector<int> > &paths, vector<int> &curr_path) {
		curr_path.push_back(root->val);
		if (root->left == nullptr && root->right == nullptr)
			if (root->val == sum) paths.push_back(curr_path);
		if (root->left) {
			find(root->left, sum - root->val, paths, curr_path);
			curr_path.pop_back();
		}
		if (root->right) {
			find(root->right, sum - root->val, paths, curr_path);
			curr_path.pop_back();
		}
	}
};
