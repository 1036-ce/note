// url: https://leetcode-cn.com/problems/word-search/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int m, n;
	vector<int> dx, dy;
	vector<vector<int>> vis;
	bool exist(vector<vector<char>>& board, string word) {
		bool ans = false;
		m = board.size(), n = board[0].size();
		dx.assign({0,0,1,-1});
		dy.assign({1,-1,0,0});
		for (int i = 0; i != m; ++i)
			for (int j = 0; j != n; ++j) {
				if (board[i][j] == word[0]) {
					vis.assign(m, vector<int>(n, 0));
					vis[i][j] = 1;
					ans = ans || dfs(board, word, 1, i, j);
				}
			}
		return ans;
	}

	bool dfs(vector<vector<char>>& board, string& word, int s, int x, int y) {
		if (s == word.size())
			return true;
		bool ans = false;
		for (int i = 0; i != 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
					vis[nx][ny] == 0 && board[nx][ny] == word[s]) {
				// cout << board[nx][ny] << endl;
				vis[nx][ny] = 1;
				ans = ans || dfs(board, word, s + 1, nx, ny);
				vis[nx][ny] = 0;
			}
		}
		return ans;
	}
};

int main(void)
{
	vector<vector<char>> board{
		{'C','A','A'},
		{'A','A','A'},
		{'B','C','D'}
	};
	Solution s;
	cout << s.exist(board, "AAB") << endl;
	return 0;
}
