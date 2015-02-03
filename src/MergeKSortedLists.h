
#include "../MyLeetCode/stdafx.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) { // Time Limit Exceeded
        ListNode *dummyHead = new ListNode(0);
        ListNode *tail = dummyHead;

		int leftLists = lists.size();
		for (int i = 0; i < leftLists; i++)
			if (!lists[i])
				lists[i--] = lists[--leftLists];

		while (leftLists) {
			int curMinIdx = 0;
			for (int i = 1; i < leftLists; i++)
				if (lists[i]->val < lists[curMinIdx]->val)
					curMinIdx = i;

			tail->next = lists[curMinIdx];
			tail = lists[curMinIdx];
			lists[curMinIdx] = lists[curMinIdx]->next ? lists[curMinIdx]->next : lists[--leftLists];
		}

		return dummyHead->next;
    }
};

class Solution1 {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
		int leftLists = lists.size();
		while (leftLists > 1) {
			for (int i = 0; i < (leftLists >> 1); ++i)
				lists[i] = merge2Lists(lists[i], lists[leftLists - 1 - i]);
			leftLists = (leftLists + 1) >> 1;
		}

		return lists.empty() ? nullptr : lists[0];
    }

    ListNode *merge2Lists(ListNode *h1, ListNode *h2) {
		ListNode *dummyHead = new ListNode(0);
		ListNode *tail = dummyHead, *cur[2] = {h1, h2};
		while (cur[0] && cur[1]) {
			int idx = (cur[0]->val >= cur[1]->val);
			tail->next = cur[idx];
			tail = cur[idx];
			cur[idx] = cur[idx]->next;
		}

		if (cur[0]) tail->next = cur[0];
		if (cur[1]) tail->next = cur[1];

		return dummyHead->next;
    }
};

class Tester{
public:
    int test() {
		Solution1 sol;

		vector<ListNode *> lists;
		lists.push_back(new ListNode(1));
		lists.push_back(new ListNode(0));
		sol.mergeKLists(lists);

        return 0;
    }
};
