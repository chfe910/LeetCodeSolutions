
#include "../MyLeetCode/stdafx.h"

class Solution {
public:
	int romanToInt(string s) {
		unordered_map<char, int> basics;
		basics['I'] = 1;
		basics['V'] = 5;
		basics['X'] = 10;
		basics['L'] = 50;
		basics['C'] = 100;
		basics['D'] = 500;
		basics['M'] = 1000;

		int result = 0;
		int last = 0;
		for (int i = s.size() - 1; i >= 0; --i) {
			auto c = s[i];
			if (basics[c] >= last) result += basics[c];
			else result -= basics[c];

			last = basics[c];
		}

		return result;
	}
};