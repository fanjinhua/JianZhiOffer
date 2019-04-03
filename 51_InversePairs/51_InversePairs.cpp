// 51_InversePairs.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

long long merge(vector<int>& data, int begin, int end)
{
	if (begin >= end)
		return 0;
	vector<int> temp(end - begin + 1);
	int temp_index = end - begin;

	int l_beg = begin,	l_end = begin + (end - begin) / 2;
	int r_beg = begin + (end - begin) / 2 + 1, r_end = end;
	
	long long p_left = merge(data, l_beg, l_end);
	long long p_right = merge(data, r_beg, r_end);
	long long p = p_left + p_right;
	int p1 = l_end, p2 = r_end;
	while ( (p1 >= l_beg) && (p2 >= r_beg))
	{
		if (data[p1] > data[p2])
		{
			p += p2 - r_beg + 1;
			temp[temp_index--] = data[p1--];
		}
		else
		{
			temp[temp_index--] = data[p2--];
		}
	}
	while (p1 >= l_beg)
		temp[temp_index--] = data[p1--];
	while (p2 >= r_beg)
		temp[temp_index--] = data[p2--];
	for (int i = begin; i <= end; ++i)
		data[i] = temp[i- begin];
	return p;
}
int InversePairs(vector<int> data) {
	if (data.empty())
		return 0;
	return merge(data, 0, data.size() - 1) % 1000000007;
}
int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(0);

	cout << InversePairs(v);
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
