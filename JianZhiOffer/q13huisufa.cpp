#include "pch.h"

#include <iostream>
class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		bool *v = new bool[rows*cols];
		memset(v, 0, rows*cols);
		int nums = moving(threshold, rows, cols, 0, 0, v);
		delete[]v;
		return nums;
	}
private:
	int moving(int t, int row, int cols, int r, int c, bool *v)
	{
		if ((r < 0) || (r >= row) || (c < 0) || (c >= cols) || v[r*cols + c] || !binding(t, r, c))
			return 0;
		v[r*cols + c] = true;
		return 1 + moving(t, row, cols, r - 1, c, v)
			+ moving(t, row, cols, r + 1, c, v)
			+ moving(t, row, cols, r, c - 1, v)
			+ moving(t, row, cols, r, c + 1, v);
	}

	int binding(int t, int r, int c)
	{
		int sum = 0;
		do
		{
			sum += r % 10;
			r = r / 10;
		} while (r > 0);
		do
		{
			sum += c % 10;
			c = c / 10;
		} while (c > 0);

		if (sum > t)
			return 0;
		return 1;
	}
};

int main()
{
	Solution su;
	std::cout << su.movingCount(5, 10, 10);
	return 0;
}
