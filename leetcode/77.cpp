// url: https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> vis;
	int movingCount(int m, int n, int k) {
		vis.assign(m, vector<int>(n, 0));
		vis[0][0] = 1;
		int ans = dfs(0, 0, m, n, k);
		return ans;
	}

	int dfs(int x, int y, int m, int n, int k) {
		int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
		int ans = 1;
		for (int i = 0; i != 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n
					&& vis[nx][ny] == 0 && can_move(nx, ny, k)) {
				vis[nx][ny] = 1;
				ans += dfs(nx, ny, m, n, k);
			}
		}
		return ans;
	}
	bool can_move(int x, int y, int k) {
		int num = 0;
		while (x) {
			num += x % 10;
			x /= 10;
		}
		while (y) {
			num += y % 10;
			y /= 10;
		}
		return num <= k ? true : false;
	}
};

int main(void)
{
	int m = 3, n = 2, k = 17;
	Solution s;
	cout << s.movingCount(m, n, k) << endl;
	return 0;
}
