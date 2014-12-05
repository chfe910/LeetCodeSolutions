
#include "../MyLeetCode/stdafx.h"

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
		int low = 0, high = num.size() - 1;
		while (low <= high) {
			int mid  = (low + high) >> 1;
			bool isUphillForward = (mid == 0 ? true : num[mid] > num[mid - 1]);
			bool isUphillAfter = (mid == num.size() - 1 ? false : num[mid + 1] > num[mid]);

			if (isUphillForward && !isUphillAfter) return mid;
			else if (isUphillForward && isUphillAfter) low = mid + 1;
			else high = mid - 1;
		}

		return low;
    }
};
