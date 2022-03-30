// url: https://leetcode-cn.com/problems/rotting-oranges/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solutino {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		int ans = 0;
		int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
		int num = 0; 	// origin's numbers
		queue<pair<int, int>> q;
		for (int i = 0; i != n; ++i) {
			for (int j = 0; j != m; ++j) {
				if (grid[i][j] == 2) {
					q.emplace(i, j);
					grid[i][j] = 3;
				}
				if (grid[i][j] == 1)
					++num;
			}
		}

		int size = q.size();
		while (!q.empty()) {
			if (size == 0) {
				++ans;
				size = q.size();
			}
			auto [x, y] = q.front();
			q.pop(), --size;
			for (int i = 0; i != 4; ++i) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
					q.emplace(nx, ny);
					grid[nx][ny] = 3;
					--num;
				}
			}
		}

		return num == 0 ? ans : -1;
	}
};

int main(void)
{
	vector<vector<int>> grid{
		{2,1,1},
		{0,1,1},
		{1,0,1}
	};
	Solutino s;
	cout << s.orangesRotting(grid) << endl;
	return 0;
}
