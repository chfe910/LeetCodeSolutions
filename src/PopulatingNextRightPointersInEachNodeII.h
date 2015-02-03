
#include "../MyLeetCode/stdafx.h"


struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
		for (TreeLinkNode *levelFirstNode = root; levelFirstNode != nullptr; levelFirstNode = getNext(levelFirstNode)) {
			for (TreeLinkNode *curNode = levelFirstNode; curNode != nullptr; curNode = curNode->next) {
				if (curNode->left ) curNode->left ->next = curNode->right ? curNode->right : getNext(curNode->next);
				if (curNode->right) curNode->right->next = getNext(curNode->next);
			}
		}
    }

private:
	TreeLinkNode *getNext(TreeLinkNode *node) {
		while (node) {
			if (node->left) return node->left;
			if (node->right) return node->right;
			node = node->next;
		}

		return nullptr;
	}
};

//annother solution

class Tester{
public:
    int test() {
		Solution sol;
		sol.connect(new TreeLinkNode(0));

        return 0;
    }
};
