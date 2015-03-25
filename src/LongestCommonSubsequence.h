
#include "../MyLeetCode/stdafx.h"


class Solution
{
public:
	string LCS(string str1, string str2)
	{
		int len1 = str1.size();
		int len2 = str2.size();
		vector<vector<int> > c(len1 + 1, vector<int>(len2 + 1, 0));
		vector<vector<int> > b(len1 + 1, vector<int>(len2 + 1, 0));

		for (int i = 1; i <= len1; ++i)
		{
			for (int j = 1; j <= len2; ++j)
			{
				if (str1[i - 1] == str2[j - 1])
				{
					c[i][j] = c[i - 1][j - 1] + 1;
					b[i][j] = 0;
				}
				else if (c[i - 1][j] > c[i][j - 1])
				{
					c[i][j] = c[i - 1][j];
					b[i][j] = 1;
				}
				else
				{
					c[i][j] = c[i][j - 1];
					b[i][j] = -1;
				}
			}
		}

		int len = c[len1][len2];
		string res(len, 0);
		int i = len1, j = len2;
		while (i && j)
		{
			if (!b[i][j])
			{
				res[--len] = str1[--i];
				--j;
			}
			else if (b[i][j] == 1) --i;
			else --j;
		}

		return res;
	}
};

class Solution1
{
public:
	string LCS(string str1, string str2) {
		int len1 = str1.size();
		int len2 = str2.size();
		vector<vector<int> > c(len1 + 1, vector<int>(len2 + 1, 0));

		for (int i = 1; i <= len1; ++i)
			for (int j = 1; j <= len2; ++j)
				if (str1[i - 1] == str2[j - 1]) c[i][j] = c[i - 1][j - 1] + 1;
				else c[i][j] = max(c[i - 1][j], c[i][j - 1]);

		int len = c[len1][len2];
		string res(len, 0);
		int i = len1, j = len2;
		while (i && j) {
			if (str1[i - 1] == str2[j - 1]) {
				res[--len] = str1[--i];
				--j;
			}
			else c[i - 1][j] > c[i][j- 1] ? --i : --j;
		}

		return res;
	}
};

class Tester
{
public:
	int test()
	{
		Solution1 sol;
		cout << sol.LCS("abcbdab", "bdcaba");
		return 0;
	}
};