// url: https://leetcode-cn.com/problems/all-paths-from-source-to-target/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> vis;
	vector<vector<int>> ans;
	vector<int> tmp;
	int n;
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		n = graph.size();
		vis.assign(n, 0);
		tmp.push_back(0);
		vis[0] = 1;
		dfs(graph, 0);
		return ans;
	}

	void dfs(vector<vector<int>>& graph, int s) {
		if (s == n - 1) {
			ans.push_back(tmp);
			return;
		}
		int m = graph[s].size();
		for (int i = 0; i != m; ++i) {
			int num = graph[s][i];
			if (vis[num] == 0) {
				vis[num] = 1;
				tmp.push_back(num);
				dfs(graph, num);
				vis[num] = 0;
				tmp.pop_back();
			}
		}
	}
};

int main(void)
{
	vector<vector<int>> graph{
		{1,2},
		{3},
		{3},
		{}
	};
	Solution s;
	auto ans = s.allPathsSourceTarget(graph);
	for (auto i: ans) {
		for (auto j: i)
			cout << j << ' ';
		cout << endl;
	}
	return 0;
}
