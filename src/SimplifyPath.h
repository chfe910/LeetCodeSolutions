
#include "../MyLeetCode/stdafx.h"


class Solution {
public:
    string simplifyPath(string path) {
        string dir;
		stack<string> dirs;

		for (auto ch : path) {
			if (ch != '/') dir += ch;
			else if (!dir.empty()) {
				dirs.push(dir);
				dir.clear();
			}
		}

		if (!dir.empty()) {
			dirs.push(dir);
			dir.clear();
		}

		int popCount = 0;
		while (!dirs.empty()) {
			auto topDir = dirs.top();
			dirs.pop();

			if (!topDir.compare(".")) continue;
			else if (!topDir.compare("..")) ++popCount;
			else if (popCount) --popCount;
			else dir.insert(0, "/" + topDir);
		}

		return dir.empty() ? "/" : dir;
    }
};

class Tester{
public:
	int test() {
		Solution sol;
		sol.simplifyPath("/a/./b/../../c/");
		return 0;
	}
};