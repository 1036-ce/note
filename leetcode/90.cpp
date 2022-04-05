// url: https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/

#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// 快速选择算法
class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		int n = arr.size();
		int s = 0, e = n - 1;
		int m = n;

		while (1) {
			if (m < k)	s = m;
			else if (m > k)	e = m - 1;
			else	 break;
			int rnum = randnum(s, e);
			std::swap(arr[rnum], arr[e]);
			int pivot = arr[e];
			int i = s;
			for (int j = s; j < e; ++j) {
				if (arr[j] <= pivot) {
					std::swap(arr[i], arr[j]);
					++i;
				}
			}
			std::swap(arr[i], arr[e]);
			m = i;
		}
		return vector<int>(arr.begin(), arr.begin() + k);
	}

	int randnum(int s, int e) {
		return rand() % (e - s + 1) + s;
	}
};

int main(void)
{
	vector<int> arr{3,2,1};
	Solution s;
	vector<int> ans = s.getLeastNumbers(arr, 2);
	for (auto i: ans)
		cout << i << ' ';
	cout << endl;
	return 0;
}
