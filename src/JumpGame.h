
#include "../MyLeetCode/stdafx.h"

class Solution {
public:
    bool canJump(int A[], int n) {
        int i = 0;
		while (1) {
			if (i == n - 1) return true;
			if (A[i] == 0) return false;
			if (i + A[i] < n) i += A[i];
			else return false;
		}
    }
};