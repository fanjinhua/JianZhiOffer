// huawei2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

void solu(int max, int k, vector<int> set)
{
	 vector<int> s(5, 0);
	 for (int i = 0; i < 5; ++i)
	 {
		 if (set[i])
		 {
			 ;
		 }
	 }
	 int path = 0;
}

int main()
{
	int x[5], y[5];
	for (int i = 0; i < 5; ++i)
		cin >> x[i] >> y[i];
	double g[5][5] = { 0 };
	for (int i = 0; i < 5; ++i)
	{
		for (int j = i + 1; j < 5; ++j)
		{
			g[i][j] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
		}
	}
	double max[4] = { 0 };
	for (int i = 1; i < 5; ++i)
		max[i-1] = g[0][i];
	for (int i = 1; i < 5; ++i)
	{
		for (int j = i + 1; j < 5; ++j)
		{
			for (int k = 0; k < 4; ++k)
				max[k] += g[i][j];
 		}
	}
	int j = 0;
	for (int i = 4; i > 0; --i)
		max[j++] += g[0][i];
	double min = max[0] +1;
	for (int i = 0; i < 4; ++i)
		if (max[i] < min)
			min = max[i];
	int ret = min;
	cout << ret;
	//printf("%d", min);
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
