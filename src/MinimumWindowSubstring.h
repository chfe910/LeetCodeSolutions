
#include "../MyLeetCode/stdafx.h"

class Solution {
public:
	string minWindow(string S, string T) {
		int count = T.size();

		int  require[128] = { 0 };
		bool charSet[128] = { false };
		for (int n = 0; n < count; ++n) {
			require[T[n]]++;
			charSet[T[n]] = true;
		}

		int i = -1, j = 0;
		int minLen = INT_MAX, minIdx = 0;
		while (i < (int)S.size() && j < (int)S.size()) {
			if (count) {
				i++;
				require[S[i]]--;
				if (charSet[S[i]] && require[S[i]] >= 0) count--;
			}
			else {
				if (minLen > i - j + 1) {
					minLen = i - j + 1;
					minIdx = j;
				}
				require[S[j]]++;
				if (charSet[S[j]] && require[S[j]] > 0) count++;
				j++;
			}
		}

		return (minLen == INT_MAX ? "" : S.substr(minIdx, minLen));
	}
};

class Tester{
public:
	int test() {
		Solution sol;
		cout << sol.minWindow("AAAAAAAAADADOBECODEBANC", "ABC");
		return 0;
	}
};