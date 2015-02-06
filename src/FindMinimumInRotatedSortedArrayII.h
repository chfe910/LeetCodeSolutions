
#include "../MyLeetCode/stdafx.h"

class Solution {
public:
	int findMin(vector<int> &num) {
		int start = 0, end = num.size() - 1;

		while (start < end) {
			if (num[start] <= num[end]) return num[start];
			int mid = (start + end) >> 1;
			if (num[mid] > num[start]) start = mid + 1;
			else /*if (num[mid] < num[end])*/ end = mid;
		}

		return num[start];
    }
};

class Solution1 {
public:
	int findMin(vector<int> &num) {
		for (int i = 0; i < num.size() - 1; ++i)
			if (num[i] > num[i + 1]) return num[i + 1];

		return num[0];
	}
};

class Tester{
public:
	int test() {
		Solution sol;
		vector<int> test;
		test.push_back(3);
		test.push_back(1);
		sol.findMin(test);
		return 0;
	}
};