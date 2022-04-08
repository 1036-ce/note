// url: https://leetcode-cn.com/problems/surrounded-regions/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	vector<vector<int>> vis;
	void solve(vector<vector<char>>& board) {
		int m = board.size(), n = board[0].size();
		vis.assign(m, vector<int>(n, 0));
		for (int i = 0; i != n; ++i)
			if (board[0][i] == 'O' && vis[0][i] == 0) {
				vis[0][i] = 1;
				bfs(board, 0, i);
			}
		for (int i = 0; i != n; ++i) 
			if (board[m - 1][i] == 'O' && vis[m - 1][i] == 0) {
				vis[m - 1][i] = 1;
				bfs(board, m - 1, i);
			}
		for (int i = 0; i != m; ++i) 
			if (board[i][0] == 'O' && vis[i][0] == 0) {
				vis[i][0] = 1;
				bfs(board, i, 0);
			}
		for (int i = 0; i != m; ++i) 
			if (board[i][n - 1] == 'O' && vis[i][n - 1] == 0) {
				vis[i][n - 1] = 1;
				bfs(board, i, n - 1);
			}
		for (int i = 0; i != m; ++i) {
			for (int j = 0; j != n; ++j) {
				if (board[i][j] == 'O' && vis[i][j] == 0)
					board[i][j] = 'X';
			}
		}
	}

	void bfs(vector<vector<char>>& board, int i , int j) {
		int m = board.size(), n = board[0].size();
		int dx[] = {0,0,-1,1}, dy[] = {1,-1,0,0};
		queue<pair<int, int>> q;
		q.emplace(i, j);

		while (!q.empty()) {
			auto [x, y] = q.front();
			q.pop();

			for (int i = 0; i != 4; ++i) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
						vis[nx][ny] == 0 && board[nx][ny] == 'O') {
					vis[nx][ny] = 1;
					q.emplace(nx, ny);
				}
			}
		}
	}
};

int main(void)
{
	vector<vector<char>> board
	{{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
	Solution s;

	s.solve(board);
	for (auto i: board) {
		for (auto j: i)
			cout << j << ' ';
		cout << endl;
	}
	return 0;
}
