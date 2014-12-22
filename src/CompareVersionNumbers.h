
#include "../MyLeetCode/stdafx.h"

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int level1 = 0, level2 = 0;

		int idx1 = 0, idx2 = 0;
		while (idx1 != version1.length() || idx2 != version2.length()) {
			level1 = 0;
			for ( ; idx1 < version1.length(); ++idx1) {
				if (version1[idx1] == '.') {
					++idx1;
					break;
				}
				else level1 = level1 * 10 + (version1[idx1] - '0');
			}
			
			level2 = 0;
			for ( ; idx2 < version2.length(); ++idx2) {
				if (version2[idx2] == '.') {
					++idx2;
					break;
				}
				else level2 = level2 * 10 + (version2[idx2] - '0');
			}

			if (level1 > level2) return 1;
			else if (level1 < level2) return -1;
		}

		return 0;
    }
};

class Solution1 {
public:
    int compareVersion(string version1, string version2) {
		const char *str1 = version1.c_str();
		const char *str2 = version2.c_str();
		while (*str1 != '\0' || *str2 != '\0') {
			int level1 = (*str1 == '\0' ? 0 : strtol(str1, (char **)&str1, 10));
			int level2 = (*str2 == '\0' ? 0 : strtol(str2, (char **)&str2, 10));

			if (level1 > level2) return 1;
			else if (level1 < level2) return -1;

			if (*str1 != '\0') ++str1;
			if (*str2 != '\0') ++str2;
		}

		return 0;
    }
};
