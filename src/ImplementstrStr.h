
#include "../MyLeetCode/stdafx.h"

// KMP
class Solution {
public:
	int strStr(char *haystack, char *needle) {
		int haystackLen = strlen(haystack);
		int needleLen = strlen(needle);
		int *next = new int[needleLen];
		getNext(needle, needleLen, next);

		int i = 0, j = 0;
		while (i < haystackLen && j < needleLen) {
			if (j == -1 || haystack[i] == needle[j]) {
				++i;
				++j;
			}
			else {
				j = next[j];
			}
		}

		return j >= needleLen ? i - needleLen : -1;
    }

private:
	void getNext(char *needle, int len, int *next) {
		int i = 0, j = -1;
		next[0] = -1;
		while (i < len - 1) {
			if (j == -1 || needle[i] == needle[j]) next[++i] = ++j;
			else j = next[j];
		}
	}

	void getNextImp(char *needle, int len, int *next) {
		int i = 0, j = -1;
		next[0] = -1;
		while (i < len - 1) {
			if (j == -1 || needle[i] == needle[j]) {
				++i;
				++j;
				next[i] = (needle[i] == needle[j] ? next[j] : j);
			}
			else
				j = next[j];
		}
	}
};


// Brute-force solution
class Solution1 {
public:
	int strStr(char *haystack, char *needle) {
		for (int i = 0; ; ++i)
		{
			for (int j = 0; ; ++j)
			{
				if (!needle[j]) return i;
				if (!haystack[i + j]) return -1;
				if (needle[j] != haystack[i + j]) break;
			}
		}
	}
};


class Tester{
public:
	int test() {
		Solution sol;

		cout << sol.strStr("a", "a");

		return 0;
	}
};
