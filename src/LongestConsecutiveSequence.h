

#include "../MyLeetCode/stdafx.h"


class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		unordered_map<int, int> myMap;
		int res = 0;
		for (auto n : num) {
			if (myMap.find(n) == myMap.end()) {
				int left  = myMap.find(n - 1) == myMap.end() ? 0 : myMap[n - 1];
				int right = myMap.find(n + 1) == myMap.end() ? 0 : myMap[n + 1];

				int sum = left + 1 + right;
				if (sum > res) res = sum;
				myMap[n] = myMap[n - left ] = myMap[n + right] = sum;
			}
		}

		return res;
	}
};
