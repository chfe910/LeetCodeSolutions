
#include "../MyLeetCode/stdafx.h"

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
		queue<TreeLinkNode *> levelQ;
		
		if (root) levelQ.push(root);
		while (!levelQ.empty()) {
			int size = levelQ.size();
			for (int i = 0; i < size; ++i) {
				TreeLinkNode *node = levelQ.front();
				levelQ.pop();

				node->next = (i == size - 1) ? NULL : levelQ.front();

				if (node->left ) levelQ.push(node->left );
				if (node->right) levelQ.push(node->right);
			}
		}
    }
};

class Solution1 {
public:
    void connect(TreeLinkNode *root) {
		if (!root) return;
		for (TreeLinkNode *pLevelFirstNode = root; pLevelFirstNode->left != nullptr; pLevelFirstNode = pLevelFirstNode->left) {
			for (TreeLinkNode *pCurNode = pLevelFirstNode; pCurNode != nullptr; pCurNode = pCurNode->next) {
				pCurNode->left->next = pCurNode->right;
				if (pCurNode->next) pCurNode->right->next = pCurNode->next->left;
			}
		}
    }
};