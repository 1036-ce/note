// url: https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int n, m;
	vector<vector<int>> vis;
	bool exist(vector<vector<char>>& board, string word) {
		n = board.size(), m = board[0].size();
		vis.assign(n, vector<int>(m, 0));
		bool ans = false;
		for (int i = 0; i != n; ++i) {
			for (int j = 0; j != m; ++j) {
				if (board[i][j] == word[0]) {
					vis[i][j] = 1;
					ans = ans || dfs(board, word, i, j, 0);
					vis[i][j] = 0;
				}
			}
		}
		return ans;
	}

	bool dfs(vector<vector<char>>& board, string& word, int x, int y, int pos) {
		if (pos == word.size() - 1)
			return true;
		int dx[] = {0,0,-1,1}, dy[] = {1, -1, 0, 0};
		bool ans = false;
		for (int i = 0; i != 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
					vis[nx][ny] == 0 && board[nx][ny] == word[pos + 1]) {
				vis[nx][ny] = 1;
				ans = ans || dfs(board, word, nx, ny, pos + 1);
				vis[nx][ny] = 0;
			}
		}
		return ans;
	}
};

int main(void)
{
	vector<vector<char>> board{
		/* {'a','b'},
		 * {'c','d'} */
		{'A','B','C','E'},
			{'S','F','E','S'},
			{'A','D','E','E'}	 
	};
	string word("ABCESEEEFS");
	Solution s;
	cout << s.exist(board, word) << endl;
	return 0;
}
