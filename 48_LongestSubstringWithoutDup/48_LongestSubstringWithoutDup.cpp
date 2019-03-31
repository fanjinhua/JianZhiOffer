// 48_LongestSubstringWithoutDup.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

string LongestSubstrWithoutDuplicate(string& str)
{
	if (str.empty())
		return string();
	int *T = new int[str.size()];
	for (int i = 0; i < str.size(); ++i)
		T[i] = 1;
	for (int i = 1; i < str.size(); ++i)
	{
		int bind = 1;
		int k = i - 1;
		for (int j = 0; j < T[i - 1]; ++j)
			if (str[i] == str[k--])
			{
				bind = 0;
				break;
			}
		T[i] = bind * T[i - 1] + 1;
	}
	//for (int i = 0; i < str.size(); ++i)
		//cout << "T" << i << " = " << T[i] << endl;
	int max_len = 0;
	int max_index = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		if (T[i] > max_len)
		{
			max_len = T[i];
			max_index = i;
		}
	}

	string ret = str.substr((max_index-max_len+1), max_len);
	delete[] T;
	return ret;
}

int main()
{
	string str = "arabcacfr";
	cout << LongestSubstrWithoutDuplicate(str) << endl;
	str = "a";
	cout << LongestSubstrWithoutDuplicate(str) << endl;
	str = "bbbbbbb";
	cout << LongestSubstrWithoutDuplicate(str) << endl;
	str = "abcdefg";
	cout << LongestSubstrWithoutDuplicate(str) << endl;
	str = "";
	cout << LongestSubstrWithoutDuplicate(str) << endl;

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
