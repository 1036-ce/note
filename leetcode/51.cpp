// url: https://leetcode-cn.com/problems/flood-fill/

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, 
			int sr, int sc, int newColor) {
		if (image[sr][sc] == newColor) return image;
		int n = image.size(), m = image[0].size();
		int cur = image[sr][sc];
		int dx[] = {0, 0, 1, -1};
		int dy[] = {1, -1, 0, 0};
		queue<pair<int, int>> q;
		q.push(pair<int, int>(sr, sc));

		while (!q.empty()) {
			pair<int, int> p = q.front();
			q.pop();
			image[p.first][p.second] = newColor;

			for (int i = 0; i != 4; ++i) {
				int nx = p.first + dx[i], ny = p.second + dy[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && image[nx][ny] == cur)
					q.emplace(nx, ny);
			}
		}
		return image;
	}
};

int main(void)
{
	vector<vector<int>> vec {
		{0,0,0},
			{0,1,1}
	};

	Solution s;
	vec = s.floodFill(vec, 1, 1, 1);
	for (auto a: vec) {
		for (auto i: a)
			cout << i << " ";
		cout << endl;
	}

	return 0;
}
