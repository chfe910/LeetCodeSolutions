
#include "../MyLeetCode/stdafx.h"

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> answer;
		for (int i = 0; i < numbers.size() - 1; i++)
			for (int j = i + 1; j < numbers.size(); j++)
				if (numbers[i] + numbers[j] == target) {
					answer.push_back(i + 1);
					answer.push_back(j + 1);
					return answer;
				}
		
		return answer;
    }
};

class Solution1 {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> answer;
		map<int, int> numMap;
		for (int i = 0; i < numbers.size(); i++)
			if (numMap.find(target - numbers[i]) != numMap.end()) {
			    answer.push_back(numMap[target - numbers[i]] + 1);
			    answer.push_back(i + 1);
			    return answer;
			}
			else numMap[numbers[i]] = i;
		
		return answer;
    }
};
