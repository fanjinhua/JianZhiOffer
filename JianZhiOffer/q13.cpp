#include "pch.h"
#if 0
#include <stack>
#include <iostream>
class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		if (threshold < 0)
			return 0;
		int r = 0, c = 0;
		int steps = 0;
		std::stack<std::pair<int, int>> s;
		s.push(std::make_pair(0, 0));
		bool *v = new bool[rows*cols];
		memset(v, 0, rows*cols);
		//r*cols+c
		while (!s.empty())
		{
			std::pair<int, int> p = s.top();
			s.pop();
			if (v[p.first*cols + p.second] == true)
				continue;
			v[p.first*cols + p.second] = true;
			steps++;
			//up
			if ((p.first > 0) && !v[(p.first-1)*cols + p.second] && binding(threshold, p.first - 1, p.second))
			{
				s.push(std::make_pair(p.first - 1, p.second));
			}
			// down
			if ((p.first<rows-1) && !v[(p.first + 1)*cols + p.second] && binding(threshold, p.first+1, p.second))
			{
				s.push(std::make_pair(p.first + 1, p.second));
			}
			// left
			if ((p.second > 0) && !v[p.first*cols + (p.second-1)] && binding(threshold, p.first, p.second - 1))
			{
				s.push(std::make_pair(p.first, p.second-1));
			}
			if ((p.second < cols-1) && !v[p.first*cols + (p.second + 1)] && binding(threshold, p.first, p.second + 1))
			{
				s.push(std::make_pair(p.first, p.second + 1));
			}
		}
		delete[]v;
		return steps;
	}
private:
	int binding(int t, int r, int c)
	{
		int sum = 0;
		if (r < 10)
			sum += r;
		else
			sum += (r % 10 + r / 10);
		if (c < 10)
			sum += c;
		else
			sum += (c % 10 + c/ 10);
		
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
#endif