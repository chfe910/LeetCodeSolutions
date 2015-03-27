
#include "../MyLeetCode/stdafx.h"

class Solution {
public:
	int maxProduct(int A[], int n) {
		if (0 == n) return 0;

		int maxRes = A[0];
		int maxEnd = A[0];
		int minEnd = A[0];
		for (int i = 1; i < n; ++i) {
			int end1 = maxEnd * A[i], end2 = minEnd * A[i];
			maxEnd = max(A[i], max(end1, end2));
			minEnd = min(A[i], min(end1, end2));
			if (maxEnd > maxRes) maxRes = maxEnd;
		}

		return maxRes;
	}
};