#include "stdafx.h"

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
		for (int i = 0, j = 0; j < n; ++j)
		{
			while (i < m + j && A[i] < B[j]) ++i;
			for (int k = m + j; k > i; --k) A[k] = A[k - 1];
			A[i] = B[j];
		}
    }
};

class Tester{
public:
    int test() {
		Solution sol;
		//sol.plusOne
        return 0;
    }
};