
#include "../MyLeetCode/stdafx.h"

class Solution
{
public:
	string LongestCommonSubstring(string str1, string str2) {
		int len1 = str1.size();
		int len2 = str2.size();
		int len = 0, idx = 0;
		vector<vector<int> > c(len1 + 1, vector<int>(len2 + 1, 0));

		for (int i = 1; i <= len1; ++i)
			for (int j = 1; j <= len2; ++j) {
				c[i][j] = (str1[i - 1] == str2[j - 1] ? c[i - 1][j - 1] + 1 : 0);
				if (c[i][j] > len) {
					len = c[i][j];
					idx = i;
				}
			}

		return str1.substr(idx - len, len);
	}
};

class Tester
{
public:
	int test()
	{
		Solution sol;
		cout << sol.LongestCommonSubstring("abcationdef", "defation");
		cout << endl << sol.LongestCommonSubstring("", "def");
		return 0;
	}
};