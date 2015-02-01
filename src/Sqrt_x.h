
#include "../MyLeetCode/stdafx.h"

class Solution {
public:
    int sqrt(int x) {
		int i, j, res = 0;
		for (i = 0; i < 32; i++) {
			if ((long)(1<<i) * (1<<i) > x) break;
		}

		for (j = i - 1; j >= 0; --j) {
			long tmp = res | (1 << j);
			res |= (tmp * tmp <= x) << j;
		}
        
        return res;
    }
};

class Tester{
public:
    int test() {
		Solution sol;

		cout << sol.sqrt(2147395599);

        return 0;
    }
};
