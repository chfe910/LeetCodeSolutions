
#include "../MyLeetCode/stdafx.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        for (ListNode *curA = headA; curA != nullptr; curA = curA->next) ++lenA;
        for (ListNode *curB = headB; curB != nullptr; curB = curB->next) ++lenB;
        
        ListNode *curA = headA, *curB = headB;
        while (lenA > lenB) {
            curA = curA->next;
            --lenA;
        }
        while (lenB > lenA) {
            curB = curB->next;
            --lenB;
        }
        
        while (curA != curB) {
            curA = curA->next;
            curB = curB->next;
        }
        
        return curA;
    }
};

class Solution1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA, *pB = headB;
        int flag = 2;
        while (flag) {
            if (!pA) {
                pA = headB;
                --flag;
            }
            else pA = pA->next;
            
            if (!pB) {
                pB = headA;
                --flag;
            }
            else pB = pB->next;
        }
        
        while (pA != pB) {
            pA = pA->next;
            pB = pB->next;
        }
        
        return pA;
    }
};