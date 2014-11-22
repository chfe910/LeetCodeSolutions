
#include "../MyLeetCode/stdafx.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
		ListNode *dummyHead = new ListNode(0);
		dummyHead->next = head;
        ListNode *part1Tail = dummyHead, *part2Tail = dummyHead;

		while (part1Tail->next && part1Tail->next->val < x) {
			part1Tail = part1Tail->next;
			part2Tail = part2Tail->next;
		}

		while (part1Tail->next && part2Tail->next) {
			if (part2Tail->next->val >= x)
				part2Tail = part2Tail->next;
			else {
				ListNode *moveNode = part2Tail->next;
				part2Tail->next = part2Tail->next->next;
				moveNode->next  = part1Tail->next;
				part1Tail->next = moveNode;
				part1Tail = moveNode;
			}
		}

		return dummyHead->next;
    }
};

class Solution1 {
public:
    ListNode *partition(ListNode *head, int x) {
		ListNode *part1DummyHead = new ListNode(0), *part2DummyHead = new ListNode(0);
        ListNode *part1Tail = part1DummyHead,		*part2Tail = part2DummyHead;

		for (ListNode *cur = head; cur != NULL; cur = cur->next) {
			if (cur->val < x) {
				part1Tail->next = cur;
				part1Tail = cur; // No need to set cur->next as NULL
			}
			else {
				part2Tail->next = cur;
				part2Tail = cur; // No need to set cur->next as NULL
			}
		}

		part1Tail->next = part2DummyHead->next;
		part2Tail->next = NULL;

		return part1DummyHead->next;
    }
};


class Solution2 {
public:
    ListNode *partition(ListNode *head, int x) {
		ListNode *part1DummyHead = new ListNode(0), *part2DummyHead = new ListNode(0);
        ListNode *part1Tail = part1DummyHead,		*part2Tail = part2DummyHead;

		for (ListNode *cur = head; cur != NULL; cur = cur->next) {
			ListNode **optTail = cur->val < x ? &part1Tail : &part2Tail;
			(*optTail)->next = cur;
			(*optTail) = cur;  // No need to set cur->next as NULL
		}

		part1Tail->next = part2DummyHead->next;
		part2Tail->next = NULL;

		return part1DummyHead->next;
    }
};

class Solution3 {
public:
    ListNode *partition(ListNode *head, int x) {
		ListNode *part1DummyHead = new ListNode(0), *part2DummyHead = new ListNode(0);
		ListNode *partTails[2] = {part1DummyHead, part2DummyHead};

		for (ListNode *cur = head; cur != NULL; cur = cur->next) {
			partTails[cur->val >= x]->next = cur;
			partTails[cur->val >= x] = cur;  // No need to set cur->next as NULL
		}

		partTails[0]->next = part2DummyHead->next;
		partTails[1]->next = NULL;

		return part1DummyHead->next;
    }
};

class Tester{
public:
    int test() {
		Solution sol;

		ListNode *head = new ListNode(1);
		head->next = new ListNode(2);
		sol.partition(head, 2);

        return 0;
    }
};
