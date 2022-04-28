// url: https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof/

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
	string ans;
	string serialize(TreeNode* root) {
		if (!root)
			return "";
		ans += to_string(root->val);
		ans += ' ';
		if (root->left) {
			serialize(root->left);
		}
		else {
			ans += LNull;
			ans += ' ';
		}

		if (root->right) {
			serialize(root->right);
		}
		else {
			ans += RNull;
			ans += ' ';
		}
		return ans;
	}

	TreeNode* deserialize(string data) {
        if (data.empty())
            return nullptr;
		list<string> sl;
		istringstream is(data);
		string word;
		while (is >> word) {
			sl.push_back(word);
		}
		TreeNode *ans = dfs(sl);
		return ans;
	}
	TreeNode* dfs(list<string>& sl) {
		// auto pos = data.find_first_of(" ");
		// string cur = data.substr(0, pos);
		// data = data.substr(pos + 1, string::npos);
		string cur = sl.front();
		sl.pop_front();
		if (cur == LNull || cur == RNull)
			return nullptr;
		TreeNode *root = new TreeNode(stoi(cur));
		root->left = dfs(sl);
		root->right = dfs(sl);
		return root;
	}
private:
	const string LNull = "LNull";
	const string RNull = "RNull";
};


int main(void)
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(5);
	Codec s;
	TreeNode *ans = s.deserialize(s.serialize(root));
	return 0;
}
