
#include "../MyLeetCode/stdafx.h"

/**
* Definition for singly-linked list.
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/**
* Definition for binary tree
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {// NOT SLOVED!!!
public:
	TreeNode *sortedListToBST(ListNode *head) {
		if (!head) return nullptr;
		TreeNode *root = new TreeNode(head->val);
		TreeNode *rightLeaf = root;
		for (ListNode *node = head->next; node != nullptr; node = node->next)
		{
			rightLeaf->right = new TreeNode(node->val);
			rightLeaf = rightLeaf->right;
			root->right->left = root;
			root = root->right;
			root->left->right = nullptr;
		}
		return root;
	}
};

class Solution1 {
public:
	TreeNode *sortedListToBST(ListNode *head) {
		return head ? sortedListToBSTHelper(&head, 0, getLength(head) - 1) : nullptr;
	}

private:
	int getLength(ListNode *head)
	{
		int len = 0;
		for (ListNode *node = head; node != nullptr; node = node->next, ++len);
		return len;
	}

	TreeNode *sortedListToBSTHelper(ListNode **head, int start, int end)
	{
		if (*head == nullptr || end < start) return nullptr;
		int mid = (start + end) >> 1;
		TreeNode *root = new TreeNode(0);
		root->left  = sortedListToBSTHelper(head, start, mid - 1);
		root->val   = (*head)->val;
		*head = (*head)->next;
		root->right = sortedListToBSTHelper(head, mid + 1, end);

		return root;
	}
};

class Tester{
public:
	int test() {
		Solution1 sol;
		ListNode *head = new ListNode(0);
		head->next = new ListNode(1);
		head->next->next = new ListNode(2);
		head->next->next->next = new ListNode(3);
		head->next->next->next->next = new ListNode(4);
		head->next->next->next->next->next = new ListNode(5);
		head->next->next->next->next->next->next = new ListNode(6);
		head->next->next->next->next->next->next->next = new ListNode(7);
		head->next->next->next->next->next->next->next->next = new ListNode(8);
		sol.sortedListToBST(head);

		return 0;
	}
};
