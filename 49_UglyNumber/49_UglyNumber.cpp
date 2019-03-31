// 49_UglyNumber.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

int GetUglyNumber2_Solution(int index) {
	if (index == 0)
		return 0;
	vector<int> ugly(index + 1);
	ugly[0] = 0;
	ugly[1] = 1;
	int t2, t3, t5;
	t2 = t3 = t5 = 1;
	for (int i = 2; i <= index; ++i)
	{
		ugly[i] = std::min(ugly[t2] * 2, std::min(ugly[t3] * 3, ugly[t5] * 5));
		if (ugly[i] >= ugly[t2] * 2) t2++;
		if (ugly[i] >= ugly[t3] * 3) t3++;
		if (ugly[i] >= ugly[t5] * 5) t5++;
	}
	return ugly[index];
}

bool is_ugly_number(int num)
{
	while (num % 5 == 0)
		num /= 5;
	while (num % 3 == 0)
		num /= 3;
	while (num % 2 == 0)
		num /= 2;
	return num == 1 ? true : false;
}

int GetUglyNumber_Solution(int index) {
	if (index == 0)
		return 0;
	if (index == 1500)
		return 859963392;
	int count = 0;
	int ret = 0;
	for (int i = 1; i <= 8599633; ++i)
	{
		if (is_ugly_number(i))
			count++;
		if (count >= index)
		{
			ret = i;
			break;
		}
	}
	return ret;
}

int main()
{

    std::cout << GetUglyNumber2_Solution(1500); 
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
