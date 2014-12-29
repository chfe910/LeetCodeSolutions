
#include "../MyLeetCode/stdafx.h"

class Solution {
public:
    string convertToTitle(int n) {
		string res;
		while (n--) {
			char element = ('A' + n % 26);
			res = element + res;
			n /= 26;
		}

		return res;
    }
};

class Tester{
public:
    int test() {
		Solution sol;

		sol.convertToTitle(703);

        return 0;
    }
};
