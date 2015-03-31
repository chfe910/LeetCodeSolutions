
#include "../MyLeetCode/stdafx.h"


class Solution
{
public:
	string LongestRepeatingSubstring(string str)
	{
		size_t len = str.size();
		vector<string> SuffixArray(len);
		for (size_t i = 0; i < len; ++i)
			SuffixArray[i] = str.substr(i);

		sort(SuffixArray.begin(), SuffixArray.end());

		size_t maxLen = 0, idx = 0;
		for (size_t i = 0; i < len - 1; ++i)
		{
			size_t curLen = LongestPrefix(SuffixArray[i], SuffixArray[i + 1]);
			if (curLen > maxLen)
			{
				maxLen = curLen;
				idx = i;
			}
		}

		return SuffixArray[idx].substr(0, maxLen);
	}

private:
	size_t LongestPrefix(string str1, string str2)
	{
		size_t len = min(str1.size(), str2.size());
		for (size_t i = 0; i < len; ++i)
			if (str1[i] != str2[i])
				return i;
		return len;
	}
};

class Tester
{
public:
	int test()
	{
		Solution sol;
		cout << sol.LongestRepeatingSubstring("abcdabc");
		return 0;
	}
};