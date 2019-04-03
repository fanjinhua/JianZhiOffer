// iqiyii01.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;
int *q;

int findMinIndex(int arr[], int beg, int end) //[]
{
	if (beg > end)
		return -1;
	int minv = arr[beg];
	int minIndex = beg;
	for (int i = beg + 1; i <= end; ++i)
	{
		if (arr[i] < minv)
		{
			minv = arr[i];
			minIndex = i;
		}
	}
	return minIndex;
}

int getRemain(int arr[], int size, int k)
{
	int rev = 0, revIndex = -1;
	for (int i = size - k; i < size; ++i)
	{
		revIndex = findMinIndex(arr, revIndex + 1, i);
		rev = rev * 10 + arr[revIndex];
	}
	return rev;
}

int main()
{
	int k;
	string str;
	int arr[242] = { 0 };
	int first = 1;
	while (cin >> str >> k)
	{
		if ((k <= 0) || (str.size() <=k))
		{
			cout << 0;
			return 0;
		}
		if (first != 1)
		{
			cout << endl;
		}
		for (int i = 0; i < str.size(); ++i)
			arr[i] = str[i] - '0';
		int ret = getRemain(arr, str.size(), str.size() - k);
		if (ret == 0)
			cout << 1;
		else
			cout << ret;
		first = 0;
	}
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
