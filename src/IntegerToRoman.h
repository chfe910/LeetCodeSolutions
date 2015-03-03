
#include "../MyLeetCode/stdafx.h"

class Solution {
public:
	string intToRoman(int num) {
		static const int ints[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		static const string romans[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

		for (int i = 0; i < 13; ++i) {
			if (num >= ints[i])
				return string(romans[i]) + intToRoman(num - ints[i]);
		}

		return "";
	}
};

class Tester{
public:
	int test() {
		Solution sol;

		cout << sol.intToRoman(190);

		return 0;
	}
};
