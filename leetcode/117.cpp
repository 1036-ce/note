// url: https://leetcode-cn.com/problems/subtree-of-another-tree/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) :
		val(x), left(left), right(right) {}
};

class Solution {
public:
    static constexpr int MAX_N = 1000 + 5;
    static constexpr int MOD = int(1E9) + 7;

    bool vis[MAX_N];
    int p[MAX_N], tot;
    void getPrime() {
        vis[0] = vis[1] = 1; tot = 0;
        for (int i = 2; i < MAX_N; ++i) {
            if (!vis[i]) p[++tot] = i;
            for (int j = 1; j <= tot && i * p[j] < MAX_N; ++j) {
                vis[i * p[j]] = 1;
                if (i % p[j] == 0) break;
            }
        }
    }

    struct Status {
        int f, s; // f 为哈希值 | s 为子树大小
        Status(int f_ = 0, int s_ = 0) 
            : f(f_), s(s_) {}
    };

    unordered_map <TreeNode *, Status> hS, hT;

    void dfs(TreeNode *o, unordered_map <TreeNode *, Status> &h) {
        h[o] = Status(o->val, 1);
        if (!o->left && !o->right) return;
        if (o->left) {
            dfs(o->left, h);
            h[o].s += h[o->left].s;
            h[o].f = (h[o].f + (31LL * h[o->left].f * p[h[o->left].s]) % MOD) % MOD;
        }
        if (o->right) {
            dfs(o->right, h);
            h[o].s += h[o->right].s;
            h[o].f = (h[o].f + (179LL * h[o->right].f * p[h[o->right].s]) % MOD) % MOD;
        }
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        getPrime();
        dfs(s, hS);
        dfs(t, hT);

        int tHash = hT[t].f;
        for (const auto &[k, v]: hS) {
            if (v.f == tHash) {
                return true;
            }
        } 
        return false;
    }
};

// kmp解法
/* class Solution {
 * public:
 *     int lNull = 200000, rNull = 300000; 
 * 
 *     void getDfsOrder(TreeNode *root, vector<int>& ans) {
 *         if (!root)
 *             return;
 *         ans.push_back(root->val);
 *         if (root->left)
 *             getDfsOrder(root->left, ans);
 *         else
 *             ans.push_back(lNull);
 *         if (root->right)
 *             getDfsOrder(root->right, ans);
 *         else
 *             ans.push_back(rNull);
 *     }
 * 
 *     bool kmp(vector<int> r1, vector<int> r2) {
 *         int m = r1.size(), n = r2.size();
 *         vector<int> fail(n, 0);
 *         for (int i = 1; i != n; ++i) {
 *             int j = fail[i - 1];
 *             while (j > 0 && r2[i] != r2[j])
 *                 j = fail[j - 1];
 *             if (r2[i] == r2[j])
 *                 ++j;
 *             fail[i] = j;
 *         }
 *         for (int i = 0, j = 0; i != m; ++i) {
 *             while (j > 0 && r1[i] != r2[j])
 *                 j = fail[j - 1];
 *             if (r1[i] == r2[j])
 *                 ++j;
 *             if (j == n)
 *                 return true;
 *         }
 *         return false;
 *     }
 *     bool isSubtree(TreeNode *root, TreeNode *subRoot) {
 *         vector<int> r1, r2;
 *         getDfsOrder(root, r1);
 *         getDfsOrder(subRoot, r2);
 * 
 *         return kmp(r1, r2);
 *     }
 * };
 *  */

// 深度优先搜索，暴力匹配
/* class Solution {
 * public:
 *     bool isSubtree(TreeNode *root, TreeNode *subRoot) {
 *         if (!root)
 *             return false;
 *         bool ans;
 *         if (root->val == subRoot->val)
 *             ans = same(root, subRoot);
 *         return ans || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
 *     }
 *     
 *     bool same(TreeNode *root, TreeNode *subRoot) {
 *         if (!root && !subRoot)
 *             return true;
 *         if (!root || !subRoot)
 *             return false;
 *         if (root->val != subRoot->val)
 *             return false;
 *         return same(root->left, subRoot->left) && same(root->right, subRoot->right);
 *     }
 * };
 *  */
int main(void)
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(1);
	TreeNode *sub = new TreeNode(1);
	Solution s;
	cout << s.isSubtree(root, sub) << endl;
	return 0;
}
