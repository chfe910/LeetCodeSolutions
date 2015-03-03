
#include "../MyLeetCode/stdafx.h"

class Solution {
public:
	bool isNumber(string s) {
		s.erase(0, s.find_first_not_of(" "));
		s.erase(s.find_last_not_of(" ") + 1);
		s.erase(0, s.find_first_not_of("+"));
		s.erase(0, s.find_first_not_of("-"));

		if (s[0] == 'e' || s[s.size() - 1] == 'e') return false;
		if (s[0] == '.' && s[1] == 'e') return false;

		bool isFloat = false;
		bool isScientific = false;
		bool lastIsE = false;
		for (auto c : s) {
			if (lastIsE) {
				lastIsE = false;
				if (c != '+' && c != '-' && (c < '0' || c > '9')) return false;
			}
			else if (c == '.') {
				if (isFloat || isScientific) return false;
				isFloat = true;
			}
			else if (c == 'e') {
				if (isScientific) return false;
				isScientific = true;
				lastIsE = true;
			}
			else if (c < '0' || c > '9')
				return false;
		}

		if (s[s.size() - 1] == '+' || s[s.size() - 1] == '-') return false;
		if (s.size() == 1 && (isFloat || isScientific)) return false;
		return s.empty() ? false : true;
	}
};