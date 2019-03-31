// 41_StreamMedian.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
	void Insert(int num)
	{
		if (size % 2 == 0)
		{
			if (!left_heap.empty() && num < left_heap.top())
			{
				left_heap.push(num);
				int temp = left_heap.top();
				left_heap.pop();
				right_heap.push(temp);
			}
			else
				right_heap.push(num);
		}
		else // insert in left part
		{
			if (!right_heap.empty() && num > right_heap.top())
			{
				right_heap.push(num);
				int temp = right_heap.top();
				right_heap.pop();
				left_heap.push(temp);
			}
			else
				left_heap.push(num);
		}
		size++;
	}

	double GetMedian()
	{
		if (size == 0)
			return 0;
		if (size % 2 == 0)
			return (left_heap.top() + right_heap.top()) / 2.0;
		else
			return left_heap.size() > right_heap.size() ? left_heap.top() : right_heap.top();
	}
	int size = 0;
	priority_queue<int, vector<int>, less<int>> left_heap;
	priority_queue<int, vector<int>, greater<int>> right_heap;
};
int main()
{
	Solution s;
	s.Insert(5);
	s.GetMedian();
	s.Insert(2);
	s.GetMedian();
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
