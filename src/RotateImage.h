
#include "../MyLeetCode/stdafx.h"

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int beginRow = 0, endRow = matrix.size() - 1, beginCol = 0, endCol = matrix[0].size() - 1;
        while (beginRow <= endRow && beginCol <= endCol) {
            for (int i = 0; i < endCol - beginCol; ++i) {
				int tmp							   = matrix[beginRow    ][beginCol + i];
				matrix[beginRow    ][beginCol + i] = matrix[  endRow - i][beginCol	  ];
				matrix[  endRow - i][beginCol    ] = matrix[  endRow    ][  endCol - i];
				matrix[  endRow    ][  endCol - i] = matrix[beginRow + i][  endCol    ];
				matrix[beginRow + i][  endCol    ] = tmp;
			}

			++beginRow; --endRow;
			++beginCol; --endCol;
        }
    }
};