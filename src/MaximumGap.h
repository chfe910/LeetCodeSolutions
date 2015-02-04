

#include "../MyLeetCode/stdafx.h"


class Solution {
public:
	int maximumGap(vector<int> &num) {
		if (num.empty() || num.size() == 1) return 0;

		int min = num[0], max = num[0];
		for (auto n : num) {
			if (n < min) min = n;
			if (n > max) max = n;
		}

		int gap = (max - min - 1) / (num.size() - 1) + 1;
		vector<int> bucketMins(num.size() - 1, INT_MAX);
		vector<int> bucketMaxs(num.size() - 1, INT_MIN);

		for (auto n : num) {
			if (n != min && n != max) {
				int bucketIdx = (n - min) / gap;
				if (n < bucketMins[bucketIdx]) bucketMins[bucketIdx] = n;
				if (n > bucketMaxs[bucketIdx]) bucketMaxs[bucketIdx] = n;
			}
		}

		int maxGap = INT_MIN, prev = min;
		for (int i = 0; i < num.size() - 1; ++i) {
			if (bucketMins[i] == INT_MAX && bucketMaxs[i] == INT_MIN) continue;
			if (bucketMins[i] - prev > maxGap) maxGap = bucketMins[i] - prev;
			prev = bucketMaxs[i];
		}

		return std::max(max - prev, maxGap);
	}
};
