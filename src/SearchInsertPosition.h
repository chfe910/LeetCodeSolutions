
#include "../MyLeetCode/stdafx.h"

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int low = 0, high = n - 1;
        while (low <=  high) {
            int middle = (low + high) >> 1;
            if (A[middle] == target) return middle;
            else if (A[middle] > target) high = middle - 1;
            else low = middle + 1;
        }
        
        return low;
    }
};