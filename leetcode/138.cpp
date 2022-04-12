// url: https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m == 0) return {};
		int n = matrix[0].size();
		if (n == 0) return {};
		int x = 0, y = -1;
		vector<vector<int>> dir{
				{0, 1, 0, n - 1},
				{1, 0, m - 1, n - 1},
				{0,-1, m - 1, 0},
				{-1,0, 1, 0}
				};
		vector<int> ans;
		
		int i = 0;
		int cnt = 0;
		while (cnt != m * n) {
			vector<int>& tmp = dir[i];
			x += tmp[0], y += tmp[1];
			while (x != tmp[2] || y != tmp[3]) {
				ans.push_back(matrix[x][y]);
				++cnt;
				x += tmp[0], y += tmp[1];
			}
			if (x == tmp[2] && y == tmp[3]) {
				++cnt;
				ans.push_back(matrix[x][y]);
			}
			// int offset = tmp[0] + tmp[1];
			tmp[2] += (tmp[1] - tmp[0]);
			tmp[3] += -(tmp[1] + tmp[0]);
			i = (i + 1) % 4;
		}
		return ans;
	}
};

int main(void)
{
	vector<vector<int>> matrix{
		{1,2,3},
		{4,5,6},
		{7,8,9} 
		/* {1,2,3,4},
		 * {5,6,7,8},
		 * {9,10,11,12},
		 * {13,14,15,16}   */
	};
	Solution s;
	auto ans = s.spiralOrder(matrix);
	for (auto i: ans) 
		cout << i << ' ';
	cout << endl;
	return 0;
}
