#include "../MyLeetCode/stdafx.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
		if (1 == k) return head;

		ListNode *curr = head;
		vector<ListNode *> group;
		for (int i = 0; i < k; ++i, curr = curr->next)
		{
			if (!curr) return head;
			group.push_back(curr);
		}
		
		group[0]->next = reverseKGroup(group[k - 1]->next, k);

		for (int i = 1; i < k; ++i)
			group[i]->next = group[i - 1];

		return group[k - 1];
    }
};

class Solution1 {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
		if (1 == k) return head;

		ListNode *curr = head;
		vector<ListNode *> group;
		for (int i = 0; i < k; ++i, curr = curr->next) {
			if (!curr) return head;
			group.push_back(curr);
		}
		
		for (int i = 0; i < (k >> 1); ++i) { // k >> 1 µÈ¼ÛÓÚ k / 2
			int tmp = group[i]->val;
			group[i]->val = group[k - i - 1]->val;
			group[k - i - 1]->val = tmp;
		}

		group[k - 1]->next = reverseKGroup(group[k - 1]->next, k);
		return head;
    }
};

class Solution2 {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
		if (!head || 1 == k) return head;

		ListNode *curr = head;
		for (int i = 0; i < k - 1; ++i, curr = curr->next)
			if (!curr->next) return head;
		
		curr->next = reverseKGroup(curr->next, k);

		ListNode *newHead = new ListNode(0);
		newHead->next = head;
		for (int i = 0; i < k - 1; ++i) {
			curr = newHead;
			for (int j = 0; j < k - i - 1; ++j, curr = curr->next) {
				ListNode *curr1 = curr->next, *curr2 = curr->next->next;
				curr1->next = curr2->next;
				curr2->next = curr1;
				curr->next = curr2;
			}
		}

		return newHead->next;
    }
};

class Solution3 {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
		if (!head || 1 == k) return head;

		ListNode *curr = head;
		for (int i = 0; i < k - 1; ++i, curr = curr->next)
			if (!curr->next) return head;
		
		curr->next = reverseKGroup(curr->next, k);

		ListNode *curr1 = head;
		for (int i = 0; i < k - 1; ++i) {
			ListNode *curr2 = curr1->next;
			curr1->next = curr->next;
			curr->next = curr1;
			curr1 = curr2;
		}

		return curr;
    }
};