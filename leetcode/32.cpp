// url: https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		if (matrix.empty()) return false;
		if (matrix[0].empty()) return false;

		int row = matrix.size(), col = matrix[0].size();	// 从右上角开始
		int n = 0, m = col - 1;
		while (n < row && m >= 0) {
			if (matrix[n][m] == target)
				return true;
			else if (matrix[n][m] > target) 
				--m;
			else
				++n;
		}
		return false;
	}
};

int main(void)
{
	vector<vector<int>> matrix{
		{1,4,7,11,15},
		{2,5,8,12,19},
		{3,6,9,16,22},
		{10,13,14,17,24},
		{18,21,23,26,30}
	}; 
	/* vector<vector<int>> matrix{
	 *     {-1, 3}
	 * }; */
	Solution s;
	cout << s.findNumberIn2DArray(matrix, 20) << endl;
	return 0;
}
