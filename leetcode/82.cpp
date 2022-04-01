// url: https://leetcode-cn.com/problems/search-a-2d-matrix/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int n = matrix.size(), m = matrix[0].size();
		int x = 0, y = m - 1;
		while (x < n && y >= 0) {
			if (target == matrix[x][y])
				return true;
			else if (target < matrix[x][y])
				--y;
			else
				++x;
		}
		return false;
	}
};

int main(void)
{
	
	return 0;
}
