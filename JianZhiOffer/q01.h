#if 0
#pragma once
#include <vector>
using std::vector;

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int r = 0;
		int lenr = array.size();
		int c = array[0].size() - 1;

		while (r < lenr && c >= 0)
		{
			if (target > array[r][c])
				++r;
			else if (target < array[r][c])
				--c;
			else
				return true;
		}
		return false;
	}
};
#endif