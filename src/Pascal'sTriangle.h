#include "../MyLeetCode/stdafx.h"

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > triangle;

		if (numRows == 0) return triangle;

		vector<int> row;
		row.push_back(1);
		triangle.push_back(row);

		for (int i = 1; i < numRows; ++i)
		{
			row.clear();
			row.push_back(1);
			for (int j = 1; j < triangle[i - 1].size(); j++)
				row.push_back(triangle[i - 1][j - 1] + triangle[i - 1][j]);
			row.push_back(1);
			triangle.push_back(row);
		}

		return triangle;
    }
};

class Tester{
public:
    int test() {
		Solution sol;
		//sol.plusOne
        return 0;
    }
};