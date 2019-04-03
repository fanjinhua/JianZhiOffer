// jf3601.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <climits>
int max = 0x7fffffff;
int max2 = INT_MAX;
int min2 = INT_MIN;

using namespace std;

int judge(vector<int> array) {
	int count = array[3];
	count += array[1] / 2;
	int num2 = array[1] % 2;
	int num1;
	int num3;
	if (array[0] > array[2]) {
		count += array[2];
		num1 = array[0] - array[2];
		num3 = 0;
	}
	else {
		count += array[0];
		num1 = 0;
		num3 = array[2] - array[0];
	}

	if (num1 >= 2 && num2 == 1) {
		count++;
		num1 = num1 - 2;
	}

	count += num1 / 4;
	return count;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		vector<int> arr(4);
		for (int i = 0; i < 4; ++i)
			cin >> arr[i];
		cout << judge(arr) << endl;
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
