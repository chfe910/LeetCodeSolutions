
#include "../MyLeetCode/stdafx.h"
/**
* Definition for an interval.
*/
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> merge(vector<Interval> &intervals) {
		vector<Interval> mergeIntervals;
		for (auto interval : intervals) {
			int i;
			for (i = 0; i < mergeIntervals.size(); ++i) {
				if (interval.end < mergeIntervals[i].start) {
					mergeIntervals.insert(mergeIntervals.begin() + i, interval);
					break;
				}
				else if (interval.start <= mergeIntervals[i].end) {
					mergeIntervals[i].start = min(interval.start, mergeIntervals[i].start);
					if (interval.end > mergeIntervals[i].end) {
						while (i + 1 < mergeIntervals.size() && interval.end >= mergeIntervals[i + 1].start) {
							mergeIntervals[i].end = mergeIntervals[i + 1].end;
							mergeIntervals.erase(mergeIntervals.begin() + i + 1);
						}
						mergeIntervals[i].end = max(interval.end, mergeIntervals[i].end);
					}
					break;
				}
			}

			if (i == mergeIntervals.size())
				mergeIntervals.push_back(interval);
		}

		return mergeIntervals;
	}
};


class Tester{
public:
	int test() {
		Solution sol;
		vector<Interval> test;
		test.push_back(Interval(2, 3));
		test.push_back(Interval(4, 6));
		test.push_back(Interval(5, 7));
		test.push_back(Interval(3, 4));
		sol.merge(test);
		return 0;
	}
};