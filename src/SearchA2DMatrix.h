
#include "../MyLeetCode/stdafx.h"


class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();

		int low = 0, high = row * col - 1;
		while (low <= high) {
			int middle = (low + high) >> 1;
			int midVal = matrix[middle / col][middle % col];
			if (midVal == target) return true;
			else if (midVal > target) high = middle - 1;
			else low = middle + 1;
		}

		return false;
    }
};