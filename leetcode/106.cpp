// url: https://leetcode-cn.com/problems/number-of-provinces/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 并查集
/* class Solution {
 * public:
 *     int Find(vector<int>& parent, int index) {
 *         if (parent[index] != index) {
 *             parent[index] = Find(parent, parent[index]);
 *         }
 *         return parent[index];
 *     }
 * 
 *     void Union(vector<int>& parent, int index1, int index2) {
 *         int p1 = Find(parent, index1);
 *         int p2 = Find(parent, index2);
 *         parent[p1] = p2;
 *     }
 * 
 *     int findCircleNum(vector<vector<int>> isConnected) {
 *         int n = isConnected.size();
 *         vector<int> parent(n);
 *         for (int i = 0; i != n; ++i)
 *             parent[i] = i;
 *         for (int i = 0; i != n; ++i) {
 *             for (int j = i + 1; j != n; ++j) {
 *                 if (isConnected[i][j] == 1)
 *                     Union(parent, i, j);
 *             }
 *         }
 *         int ans = 0;
 *         for (int i = 0; i != n; ++i) {
 *             if (parent[i] == i)
 *                 ++ans;
 *         }
 *         return ans;
 *     }
 * };
 *  */
// 广度优先搜索
/* class Solution {
 * public:
 *     int findCircleNum(vector<vector<int>>& isConnected) {
 *         int n = isConnected.size();
 *         int ans = 0;
 *         vector<int> vis(n);
 *         for (int i = 0; i != n; ++i) {
 *             if (vis[i] == 0) {
 *                 vis[i] = 1;
 *                 ++ans;
 *                 bfs(isConnected, vis, i, n);
 *             }
 *         }
 *         return ans;
 *     }
 * 
 *     void bfs(vector<vector<int>>& isConnected, vector<int>& vis, int i, int n) {
 *         queue<int> q;
 *         q.push(i);
 * 
 *         while (!q.empty()) {
 *             int cur = q.front();
 *             q.pop();
 *             for (int j = 0; j != n; ++j) {
 *                 if (isConnected[cur][j] == 1 && vis[j] == 0) {
 *                     q.push(j);
 *                     vis[j] = 1;
 *                 }
 *             }
 *         }
 *     }
 * };
 *  */
// 深度优先搜索
/* class Solution {
 * public:
 *     int findCircleNum(vector<vector<int>>& isConnected) {
 *         int n = isConnected.size();
 *         int ans = 0;
 *         vector<int> vis(n);
 *         for (int i = 0; i != n; ++i) {
 *             if (vis[i] == 0) {
 *                 vis[i] = 1;
 *                 ++ans;
 *                 dfs(isConnected, vis, i, n);
 *             }
 *         }
 *         return ans;
 *     }
 * 
 *     void dfs(vector<vector<int>>& isConnected, vector<int>& vis, int i, int n) {
 *         for (int j = 0; j != n; ++j) {
 *             if (isConnected[i][j] == 1 && vis[j] == 0) {
 *                 vis[j] = 1;
 *                 dfs(isConnected, vis, j, n);
 *             }
 *         }
 *     }
 * };
 *  */
int main(void)
{
	vector<vector<int>> grid{
		{1,1,0},
		{1,1,0},
		{0,0,1}
	};
	Solution s;
	cout << s.findCircleNum(grid) << endl;
	return 0;
}
