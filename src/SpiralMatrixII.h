
#include "../MyLeetCode/stdafx.h"


class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int> (n, 0));
        
        int beginRow = 0, endRow = n - 1, beginCol = 0, endCol = n - 1;
        int element = 1;
        while (beginRow <= endRow && beginCol <= endCol) {
            for (int j = beginCol; j <= endCol; ++j)
                matrix[beginRow][j] = (element++);
            if (++beginRow > endRow) break;
            
            for (int i = beginRow; i <= endRow; ++i)
                matrix[i][endCol] = (element++);
            if (--endCol < beginCol) break;
            
            for (int j = endCol; j >= beginCol; --j)
                matrix[endRow][j] = (element++);
            if (--endRow < beginRow) break;
            
            for (int i = endRow; i >= beginRow; --i)
                matrix[i][beginCol] = (element++);
            if (++beginCol > endCol) break;
        }
        
        return matrix;
    }
};