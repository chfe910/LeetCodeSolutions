#include "../MyLeetCode/stdafx.h"

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
		if (!head) return head;

        map<RandomListNode *, int> positions;
		vector<RandomListNode *> cpyList;

		int pos = 0;
		for (RandomListNode *curr = head; curr != NULL; curr = curr->next, ++pos) {
			positions.insert(pair<RandomListNode *, int> (curr, pos));
			RandomListNode *newNode = new RandomListNode(curr->label);
			cpyList.push_back(newNode);
		}
		cpyList.push_back(NULL);

		pos = 0;
		for (RandomListNode *curr = head; curr != NULL; curr = curr->next, ++pos) {
			cpyList[pos]->next   = cpyList[pos + 1];
			cpyList[pos]->random = curr->random ? cpyList[positions[curr->random]] : NULL;
		}

		return cpyList[0];
    }
};

class Tester{
public:
    int test() {
		Solution sol;

		RandomListNode *head = new RandomListNode(-1);
		sol.copyRandomList(head);

        return 0;
    }
};
