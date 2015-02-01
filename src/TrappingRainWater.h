
#include "../MyLeetCode/stdafx.h"

class Solution {
public:
	int trap(int A[], int n) {
		int water = 0;
		for (int left = 0, right = n - 1; left < right; )
		{
			int leftHeight  = A[left ];
			int rightHeight = A[right];

			if (leftHeight < rightHeight)
				while (left < right && A[++left ] <= leftHeight ) water += (leftHeight  - A[left ]);
			else
				while (left < right && A[--right] <= rightHeight) water += (rightHeight - A[right]);
		}
		return water;
	}
};

class Solution1 {
public:
	int trap(int A[], int n) {
		int water = 0;
		int leftStdHeight = 0, rightStdHeight = 0;
		for (int left = 0, right = n - 1; left < right; ) {
			if (A[left] <= A[right]) { A[left ] < leftStdHeight  ? (water += leftStdHeight  - A[left ]) : (leftStdHeight  = A[left ]); ++left ; }
			else					 { A[right] < rightStdHeight ? (water += rightStdHeight - A[right]) : (rightStdHeight = A[right]); --right; }
		}
		return water;
	}
};