
#include "../MyLeetCode/stdafx.h"

class Solution { // NOT SOLVED!!!
public:
    string largestNumber(vector<int> &num) {
		vector<vector<string> > sortNums(10);
		for (unsigned int i = 0; i < num.size(); ++i)
		{
			char buf[100] = {0};
			sprintf_s(buf, "%d", num[i]);
			string num_s = buf;

			int idx = num_s[0] - '0';

			// find pos
			int begin = 0, end = sortNums[idx].size() - 1;
			while (begin < end)
			{
				int mid = (begin + end) >> 1;
				if (num_s > sortNums[idx][mid]) end = mid - 1;
				else if (num_s < sortNums[idx][mid]) begin = mid + 1;
				else break;
			}

			sortNums[idx].insert(sortNums[idx].begin() + begin, num_s);
		}

		string result;
		for (int i = 9; i > 0; --i)
		{
			for (unsigned int j = 0; j < sortNums[i].size(); ++j)
			{
				result += sortNums[i][j];
			}
		}

		return result;
    }
};

class Solution1 {
public:
    string largestNumber(vector<int> &num) {
		vector<string> strNum;
		for (auto i : num)
			strNum.push_back(to_string(i));

		sort(begin(strNum), end(strNum), [](string &s1, string &s2){ return s1+s2>s2+s1; });

		string result;
		for (auto s : strNum)
			result += s;

		while (result[0] == '0' && result.size() > 1)
			result.erase(0, 1);

		return result;
    }
};


class Tester{
public:
    int test() {
		vector<int> vec;
		vec.push_back(1);
		vec.push_back(1);
		vec.push_back(1);/*
		vec.push_back(5);
		vec.push_back(9);*/
		Solution1 sol;
		cout << sol.largestNumber(vec);

        return 0;
    }
};
