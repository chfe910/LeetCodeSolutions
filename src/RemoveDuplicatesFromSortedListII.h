#include "../MyLeetCode/stdafx.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
		if (!head) return NULL;

        ListNode *dummyHead = new ListNode(0);
		dummyHead->next = head;

		ListNode *prev = dummyHead, *curr = head->next;
		int curVal = head->val;
		while (curr) {
			if (curr->val == curVal) {
				for (curr = curr->next; curr != NULL && curr->val == curVal; curr = curr->next) ;
				prev->next = curr;
				if (curr) {
					curVal = curr->val;
					curr = curr->next;
				}
			}
			else {
				prev = prev->next;
				curVal = curr->val;
				curr = curr->next;
			}
		}

		return dummyHead->next;
    }
};