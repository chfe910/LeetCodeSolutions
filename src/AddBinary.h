
#include "../MyLeetCode/stdafx.h"

class Solution {
public:
    string addBinary(string a, string b) {
		string sum;
		int carry = 0;
		for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; --i, --j) {
			string bitAdd("0");
			int src1 = (i >= 0 ? a[i] - '0' : 0);
			int src2 = (j >= 0 ? b[j] - '0' : 0);
			bitAdd[0] +=  (src1 + src2 + carry) & 1;
			carry = ((src1 + src2 + carry) & 2) ? 1 : 0;
			sum = bitAdd + sum;
		}

		if (carry) {
			string s("1");
			sum = s + sum;
		}

		return sum;
    }
};

class Tester{
public:
    int test() {
		Solution sol;
		sol.addBinary("1", "1");
        return 0;
    }
};