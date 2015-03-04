
#include "../MyLeetCode/stdafx.h"


class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		if (strs.empty()) return "";
		
		string commonPrefix = strs[0];
		for (int i = 1; i < strs.size(); ++i) {
			int j = 0;
			for ( ; j < commonPrefix.size() && j < strs[i].size(); ++j) {
				if (commonPrefix[j] != strs[i][j]) break;
			}
			commonPrefix = commonPrefix.substr(0, j);
		}

		return commonPrefix;
	}
};