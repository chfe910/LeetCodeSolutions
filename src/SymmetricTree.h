
#include "../MyLeetCode/stdafx.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        return root ? isSymmetric(root->left, root->right) : true;
    }
    
private:
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        if (left->val != right->val) return false;
        
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};

class Solution1 {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        
        stack<TreeNode *> leftStack, rightStack;
        leftStack.push(root->left);
        rightStack.push(root->right);
        
        while (!leftStack.empty()) {
            TreeNode *left = leftStack.top(),   *right = rightStack.top();
            leftStack.pop();                    rightStack.pop();
            
            if (!left && !right) continue;
            if (!left &&  right) return false;
            if ( left && !right) return false;
            if (left->val != right->val) return false;
            
            leftStack.push(left->left );        rightStack.push(right->right);
            leftStack.push(left->right);        rightStack.push(right->left);
        }
        
        
        return true;
    }
};

class Solution2 {//failed
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        
        inorderTraversal(root);

		int i = 0, j = valVec.size() - 1;
		while (i < j) {
			if (valVec[i++] != valVec[j--])
				return false;
		}
        
        return true;
    }

private:
	void inorderTraversal(TreeNode *root) {
		if (!root) {
			valVec.push_back("#");
			return;
		}

		if (root->left == nullptr && root->right == nullptr) {
			valVec.push_back("0" + root->val);
		}
		else {
			inorderTraversal(root->left);
			valVec.push_back("0" + root->val);
			inorderTraversal(root->right);
		}
	}

	vector<string> valVec;
};