// url: https://leetcode-cn.com/problems/max-area-of-island/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int vis[55][55];
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		int ans = 0;
		for (int i = 0; i != n; ++i) {
			for (int j = 0; j != m; ++j) {
				if (vis[i][j] == 0 && grid[i][j] == 1) {
					vis[i][j] = 1;
					ans = max(ans, bfs(grid, i, j));
					// cout << ans << endl;
				}
			}
		}
		return ans;
	}

	int bfs(vector<vector<int>>& grid, int i, int j) {
		int n = grid.size(), m = grid[0].size();
		int dx[] = {0, 0, 1, -1};
		int dy[] = {1, -1, 0, 0};
		queue<pair<int, int>> q;
		q.emplace(i, j);
		int ans = 0;

		while (!q.empty()) {
			pair<int, int> p = q.front();
			q.pop();
			++ans;

			for (int i = 0; i != 4; ++i) {
				int nx = p.first + dx[i], ny = p.second + dy[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
						grid[nx][ny] == 1 && vis[nx][ny] == 0) {
					q.emplace(nx, ny);
					vis[nx][ny] = 1;
				}
			}
		}
		return ans;
	}
};

int main(void)
{
	vector<vector<int>> grid = {
		{0,0,1,0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,1,0,0,0},
		{0,1,1,0,1,0,0,0,0,0,0,0,0},
		{0,1,0,0,1,1,0,0,1,0,1,0,0},
		{0,1,0,0,1,1,0,0,1,1,1,0,0},
		{0,0,0,0,0,0,0,0,0,0,1,0,0},
		{0,0,0,0,0,0,0,1,1,1,0,0,0},
		{0,0,0,0,0,0,0,1,1,0,0,0,0}
	};

	Solution s;
	cout << s.maxAreaOfIsland(grid) << endl;
	return 0;
}
