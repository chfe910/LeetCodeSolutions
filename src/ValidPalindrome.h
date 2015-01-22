
#include "../MyLeetCode/stdafx.h"

class Solution {
public:
	bool isPalindrome(string s) {
		for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
		{
			while (i < s.size())
			{
				if		(s[i] >= '0' && s[i] <= '9') break;
				else if (s[i] >= 'a' && s[i] <= 'z') break;
				else if (s[i] >= 'A' && s[i] <= 'Z') { s[i] += ('a' - 'A'); break; }
				++i;
			}

			while (j >= 0)
			{
				if		(s[j] >= '0' && s[j] <= '9') break;
				else if (s[j] >= 'a' && s[j] <= 'z') break;
				else if (s[j] >= 'A' && s[j] <= 'Z') { s[j] += ('a' - 'A'); break; }
				--j;
			}

			if (s[i] != s[j]) return false;
		}

		return true;
	}
};

class Solution1 {
public:
	bool isPalindrome(string s) {
		for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
		{
			while (i < s.size() && !isalnum(s[i])) ++i;
			while (j >= 0       && !isalnum(s[j])) --j;
			if (tolower(s[i]) != tolower(s[j])) return false;
		}

		return true;
	}
};

class Tester{
public:
	int test() {
		Solution sol;

		sol.isPalindrome("ab2a");

		return 0;
	}
};
