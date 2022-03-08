#include <cstddef>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class TreeNode {
public:
	TreeNode(const string &s, int n = 0, TreeNode *lchild = nullptr, TreeNode *rchild = nullptr):
		value(s), count(n), left(lchild), right(rchild), use(new std::size_t(1)) {}
	//拷贝构造函数
	TreeNode(const TreeNode &node): 
		value(node.value), count(node.count), left(node.left), right(node.right), use(node.use) { ++*use; }

	//拷贝赋值运算符
	TreeNode &operator=(const TreeNode &node)
	{
		++*node.use;
		if (--*use == 0)
		{
			delete left;
			delete right;
			delete use;
		}
		value = node.value;
		count = node.count;
		left = node.left;
		right = node.right;
		return *this;
	}
	//析构函数
	~TreeNode()
	{
		if (--*use == 0)
		{
			delete left;
			delete right;
			delete use;
		}
	} 
private:
	std::string value;
	int count;
	TreeNode *left;
	TreeNode *right;
	std::size_t *use;
};

class BinStrTree {
public:
	BinStrTree(const TreeNode &r): root(new TreeNode(r)), use(new std::size_t(1)) {}
	//拷贝构造函数
	BinStrTree(const BinStrTree &bst): root(bst.root) { ++*use; }
	//拷贝赋值运算符
	BinStrTree &operator=(const BinStrTree &bst)
	{
		++*bst.use;
		if (--*use == 0)
		{
			delete root;
			delete use;
		}

		root = bst.root;
		use = bst.use;
		return *this;
	}
	//析构函数
	~BinStrTree()
	{
		if (--*use == 0)
		{
			delete root;
			delete use;
		}
	} 
private:
	TreeNode *root;
	std::size_t *use;
};

int main(void)
{
	TreeNode node("123");
	BinStrTree root(node);
	return 0;
}
