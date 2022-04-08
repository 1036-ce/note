// url: https://leetcode-cn.com/problems/shortest-path-in-binary-matrix/

#include <ctime>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		int n = grid.size();
		if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
			return -1;
		if (n == 1 && grid[0][0] == 0)
			return 1;
		return bfs(grid);
	}

	int bfs(vector<vector<int>>& grid) {
		int n = grid.size();
		queue<pair<int, int>> q;
		int dx[] = {1, 0, -1, -1, -1, 0, 1, 1};
		int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
		vector<vector<int>> vis(n, vector<int>(n, 0));
		vis[0][0] = 1;
		q.emplace(0, 0);

		int f = 1;
		while (!q.empty()) {
			auto [x, y] = q.front();
			q.pop();
			for (int i = 0; i != 8; ++i) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n
						&& vis[nx][ny] == 0 && grid[nx][ny] == 0) {
					vis[nx][ny] = vis[x][y] + 1;
					if (nx == n - 1 && ny == n - 1)
						return vis[nx][ny];
					q.emplace(nx, ny);
				}
			}
		}
		return -1;
	}
};

int main(void)
{
	vector<vector<int>> grid{
		// {0,1},
		// {1,0}
		{0,0,0},
		{1,1,0},
		{1,1,0} 
	};
	Solution s;
	cout << s.shortestPathBinaryMatrix(grid) << endl;
	return 0;
}
