
#include "../MyLeetCode/stdafx.h"

class Solution {
public:
    int majorityElement(vector<int> &num) {

		if (num.size() == 1) return num[0];

		int bitCount[32] = {0};

		for (int i = 0; i < num.size(); ++i)
		{
			for (int j = 0; j < 32; ++j)
			{
				if (num[i] & (1 << j))
					++bitCount[j];
			}
		}

		int result = 0;
		int count = (num.size() >> 1) + 1;
		for (int j = 0; j < 32; ++j)
		{
			if (bitCount[j] / count)
				result |= (1 << j);
		}

		return result;
    }
};

class Solution1 {
public:
    int majorityElement(vector<int> &num) {
		int curIdx = 0, count = 0;
		for (int i = 1; i < num.size(); ++i)
		{
			num[i] == num[curIdx] ? ++count : --count;
			if (!count)
			{
				curIdx = i;
				count = 1;
			}
		}

		return num[curIdx];
    }
};

class Tester{
public:
    int test() {
		Solution sol;

		vector<int> num;
		num.push_back(2);
		num.push_back(2);

		cout << sol.majorityElement(num);

        return 0;
    }
};
