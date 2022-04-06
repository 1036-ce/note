// url: https://leetcode-cn.com/problems/number-of-islands/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int m, n;
	int numIslands(vector<vector<char>>& grid) {
		m = grid.size(), n = grid[0].size();
		int ans = 0;
		vector<vector<int>> vis(m, vector<int>(n, 0));
		for (int i = 0; i != m; ++i) {
			for (int j = 0; j != n; ++j) {
				if (grid[i][j] == '1' && vis[i][j] == 0) {
					vis[i][j] = 1;
					bfs(grid, vis, i, j);
					++ans;
				}
			}
		}
		return ans;
	}

	void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j) {
		int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
		queue<pair<int, int>> q;
		q.emplace(i, j);

		while (!q.empty()) {
			auto [x, y] = q.front();
			q.pop();
			for (int i = 0; i != 4; ++i) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
						grid[nx][ny] == '1' && vis[nx][ny] == 0) {
					q.emplace(nx, ny);
					vis[nx][ny] = 1;
				}
			}
		}
	}
};

int main(void)
{
	vector<vector<char>> grid {
		{'1','1','1','1','0'},
		{'1','1','0','1','0'},
		{'1','1','0','0','0'},
		{'0','0','0','0','0'}
	};
	Solution s;
	cout << s.numIslands(grid) << endl;
	return 0;
}
