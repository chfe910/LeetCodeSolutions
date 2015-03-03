
#include "../MyLeetCode/stdafx.h"

/* Definition for binary tree */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
	stack<TreeNode *> nodeStack;

	void pushAll(TreeNode *root) {
		for (TreeNode *node = root; node != nullptr; node = node->left) {
			nodeStack.push(node);
		}
	}

public:
    BSTIterator(TreeNode *root) {
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !nodeStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *node = nodeStack.top();
		nodeStack.pop();
		pushAll(node->right);
		return node->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */



/**********************************************C solution********************************************/

struct BSTIterator {
    
};

struct BSTIterator *bstIteratorCreate(struct TreeNode *root) {
    struct BSTIterator *newIter = (struct BSTIterator *)malloc(sizeof(struct BSTIterator));
}

/** @return whether we have a next smallest number */
bool bstIteratorHasNext(struct BSTIterator *iter) {
    
}

/** @return the next smallest number */
int bstIteratorNext(struct BSTIterator *iter) {
    
}

/** Deallocates memory previously allocated for the iterator */
void bstIteratorFree(struct BSTIterator *iter) {
    
}

/**
 * Your BSTIterator will be called like this:
 * struct BSTIterator *i = bstIteratorCreate(root);
 * while (bstIteratorHasNext(i)) printf("%d\n", bstIteratorNext(i));
 * bstIteratorFree(i);
 */