// url: https://leetcode-cn.com/problems/01-matrix/

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

// 广度优先搜索
class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
		int n = mat.size(), m = mat[0].size();
		queue<pair<int, int>> q;
		vector<vector<int>> ans(n, vector<int>(m));
		vector<vector<int>> vis(n, vector<int>(m));
		int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
		for (int i = 0; i != n; ++i) {
			for (int j = 0; j != m; ++j) {
				if (mat[i][j] == 0) {
					vis[i][j] = 1;
					q.emplace(i, j);
				}
			}
		}

		while (!q.empty()) {
			auto [x, y] = q.front();
			q.pop();
			for (int i = 0; i != 4; ++i) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] == 0) {
					ans[nx][ny] = ans[x][y] + 1;
					q.emplace(nx, ny);
					vis[nx][ny] = 1;
				}
			}
		}
		return ans;
	}
};

// 动态规划


int main(void)
{
	vector<vector<int>> mat = {
		{0,0,0},
		{0,1,0},
		{1,1,1}
		/* {0,0,0},
		 * {0,1,0},
		 * {0,0,0} */
	};
	Solution s;
	auto ans = s.updateMatrix(mat);
	for (auto i: ans) {
		for (auto j: i)
			cout << j << " ";
		cout << endl;
	}
	return 0;
}
