// url: https://leetcode-cn.com/problems/interval-list-intersections/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	/*
        双指针:
        指针i表示A集合中区间的索引,那么A[i][0]和A[i][1]分别表示区间A[i]的左右边界
        指针j表示B集合中区间的索引,那么B[j][0]和B[j][1]分别表示区间B[j]的左右边界
        左边界start取两个区间左边界较大值,右边界end取两个区间右界较小值
        若start<=end则可以形成区间,将[start,end]加入结果
        指针移动:看谁的右边界较小,较小的右边界后面不可能有交集了,因此根据右边界大小移动i与j指针
        具体地:A[i][1]>B[j][1],j++;A[i][1]<B[j][1],i++
        循环至两个区间组都到达末尾就结束
        */
	vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
			vector<vector<int>>& secondlist) {
		vector<vector<int>> ans;
		int len1 = firstList.size(), len2 = secondlist.size();
		int left = 0, right = 0;
		while (left != len1 && right != len2) {
			int start = max(firstList[left][0], secondlist[right][0]);
			int end = min(firstList[left][1], secondlist[right][1]);
			if (start <= end)
				ans.push_back(vector<int>{start, end});
			if (firstList[left][1] < secondlist[right][1])
				++left;
			else
				++right;
		}
		return ans;
	}
};

int main(void)
{
	/* vector<vector<int>> a {
	 *     {0,2},
	 *     {5,10},
	 *     {13,23},
	 *     {24,25},
	 * };
	 * vector<vector<int>> b {
	 *     {1,5},
	 *     {8,12},
	 *     {15,24},
	 *     {25,26}
	 * }; */
	vector<vector<int>> a {
		{4,6},
		{7,8},
		{10,17}
	};
	vector<vector<int>> b {
		{5, 10}
	};
	Solution s;
	auto ans = s.intervalIntersection(a, b);
	for (auto i: ans) {
		for (auto j: i)
			cout << j << ' ';
		cout << endl;
	}
	return 0;
}
