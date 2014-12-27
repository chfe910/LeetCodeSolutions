
#include "../MyLeetCode/stdafx.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        
        vector<TreeNode *> iter;
        if (root) iter.push_back(root);
        
        int isForward = 1;
        while (!iter.empty()) {
            int size = iter.size();
            vector<int> level;
            
            for (int i = 0; i < size; ++i) {
                level.push_back(iter[i]->val);
                if (iter[i]->left) iter.push_back(iter[i]->left);
                if (iter[i]->right) iter.push_back(iter[i]->right);
            }
            
            if (!isForward) reverse(level.begin(), level.end());
            res.push_back(level);
            iter.erase(iter.begin(), iter.begin() + size);
            isForward ^= 0x01;
        }
        
        return res;
    }
};

class Solution1 {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		res.clear();
		if (!root) return res;
        zigzagLevelOrder(root, 1);
        return res;
    }

private:
    vector<vector<int> > res;

	void zigzagLevelOrder(TreeNode *root, int level) {
		if (res.size() < level) res.resize(level);
		if (level % 2) res[level - 1].push_back(root->val);
		else res[level - 1].insert(res[level - 1].begin(), root->val);

		if (root->left) zigzagLevelOrder(root->left, level + 1);
		if (root->right) zigzagLevelOrder(root->right, level + 1);
	}
};
