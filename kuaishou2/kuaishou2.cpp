// kuaishou2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

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

int movingCount(int threshold, int rows, int cols)
{
	bool *v = new bool[rows*cols];
	memset(v, 0, rows*cols);
	int nums = moving(threshold, rows, cols, 0, 0, v);
	delete[]v;
	return nums;
}


int main()
{
	int m, n, k;
	cin >> m >> n >> k;
	cout << movingCount(k, m, n);
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
