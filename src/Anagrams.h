
#include "../MyLeetCode/stdafx.h"

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
		vector<string> result;

		unordered_map<string, vector<string>> dict;
		for (auto word : strs)
			dict[getLetters(word)].push_back(word);

		for (auto group : dict)
			if (group.second.size() > 1)
				result.insert(result.end(), group.second.begin(), group.second.end());

		return result;
    }

private:
	string getLetters(string word) {
		string letters;
		for	(auto letter : word) {
			int i;
			for (i = 0; i < letters.size(); ++i)
				if (letters[i] > letter)
					break;
			
			letters.insert(letters.begin() + i, letter);
		}

		return letters;
	}
};

class Solution1 {
public:
    vector<string> anagrams(vector<string> &strs) {
		vector<string> result;

		unordered_map<string, vector<string>> dict;
		for (auto word : strs){
			string tmp = word;
			sort(tmp.begin(), tmp.end());
			dict[tmp].push_back(word);
		}

		for (auto group : dict)
			if (group.second.size() > 1)
				result.insert(result.end(), group.second.begin(), group.second.end());

		return result;
    }
};

class Tester{
public:
    int test() {
		vector<string> strs;
		strs.push_back("and");
		strs.push_back("dan");
		Solution sol;
		sol.anagrams(strs);
        return 0;
    }
};