
#include "../MyLeetCode/stdafx.h"


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int> result;
		if (matrix.empty()) return result;

        result = matrix[0];
		matrix.erase(matrix.begin());
		if (matrix.empty()) return result;

		int colIdx = matrix[0].size() - 1;
		for (int i = 0; i < matrix.size(); ++i) {
			result.push_back(matrix[i][colIdx]);
			matrix[i].erase(matrix[i].begin() + colIdx);
		}
		if (matrix[0].empty()) return result;

		result.insert(result.end(), matrix.back().rbegin(), matrix.back().rend());
		matrix.erase(matrix.end() - 1);
		if (matrix.empty()) return result;
		
		for (int i = matrix.size() - 1; i >= 0; --i) {
			result.push_back(matrix[i][0]);
			matrix[i].erase(matrix[i].begin());
		}
		if (matrix[0].empty()) return result;

		vector<int> inner = spiralOrder(matrix);
		result.insert(result.end(), inner.begin(), inner.end());
		return result;
    }
};

class Tester{
public:
    int test() {
		vector<vector<int> > matrix;
		vector<int> row0;
		row0.push_back(1);
		row0.push_back(2);
		matrix.push_back(row0);
		vector<int> row1;
		row1.push_back(3);
		row1.push_back(4);
		matrix.push_back(row1);

		Solution sol;
		sol.spiralOrder(matrix);
        return 0;
    }
};