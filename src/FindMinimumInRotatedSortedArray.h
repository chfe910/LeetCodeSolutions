
#include "../MyLeetCode/stdafx.h"

class Solution {
public:
    int findMin(vector<int> &num) {
        for (int i = 1; i < num.size(); ++i)
            if (num[i] < num[i - 1])
                return num[i];
                
        return num[0];
    }
};

class Solution1 {
public:
    int findMin(vector<int> &num) {
        int start=0,end=num.size()-1;
 
        while (start<end) {
            if (num[start]<num[end])
                return num[start];
 
            int mid = (start+end)/2;
 
            if (num[mid]>=num[start]) {
                start = mid+1;
            } else {
                end = mid;
            }
        }
 
        return num[start];
    }
};