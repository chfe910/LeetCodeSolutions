#include "../MyLeetCode/stdafx.h"

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
		vector<int> result;
		int carry = 1;
        for (int i = digits.size() - 1; i >= 0; --i){
			result.insert(result.begin(), (digits[i] + carry) % 10);
			carry = (digits[i] + carry == 10);
		}

		if (carry)
			result.insert(result.begin(), 1);

		return result;
    }
};

class Solution1 {
public:
    vector<int> plusOne(vector<int> &digits) {
		int carry = 1;
        for (int i = digits.size() - 1; i >= 0; --i){
			if (carry)
			{
				digits[i] += carry;
				carry = (digits[i] == 10);
				digits[i] %= 10;
			}
			else
				break;
		}

		if (carry)
		{
			digits[0] = 1;
			digits.push_back(0);
		}

		return digits;
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