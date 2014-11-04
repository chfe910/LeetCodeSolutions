#include "../MyLeetCode/stdafx.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
		ListNode *dummyHead = new ListNode(0);
		dummyHead->next = head;

		ListNode *fast = head;
		for (int i = 0; i < n - 1; ++i)
			fast = fast->next;
		
		ListNode *low  = dummyHead;
		for (int i = 0; i < m - 1; ++i)
			low  = low ->next;

		for (int i = 0; i < n - m; ++i) {
			ListNode *curr = low->next;
			low ->next = low ->next->next;
			curr->next = fast->next;
			fast->next = curr;
		}

		head = dummyHead->next;
		delete dummyHead;
		return head;
    }
};