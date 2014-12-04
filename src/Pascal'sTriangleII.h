
#include "../MyLeetCode/stdafx.h"

class Solution {
public:
    vector<int> getRow(int rowIndex) {
		vector<int> row, prev_row;

		row.push_back(1);

		for (int i = 1; i <= rowIndex; ++i) {
			prev_row = row;
			
			row.clear();
			row.push_back(1);
			for (int j = 1; j < prev_row.size(); j++)
				row.push_back(prev_row[j - 1] + prev_row[j]);
			row.push_back(1);
		}

		return row;
    }
};

class Solution1 {
public:
    vector<int> getRow(int rowIndex) {
		vector<int> row(rowIndex + 1, 0);

		row[0] = 1;
		for (int i = 1; i <= rowIndex; ++i) {
			for (int j = i + 1; j > 0; --j) {
				row[j] += row[j - 1];
			}
		}

		return row;
    }
};
