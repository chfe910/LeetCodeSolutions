
#include "../MyLeetCode/stdafx.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        
        ListNode *slow = head, *fast = head;
        while (slow->next && fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
				for (slow = head; slow != fast; slow = slow->next, fast = fast->next) ;
				return slow;
			}
        }
        
        return NULL;
    }
};