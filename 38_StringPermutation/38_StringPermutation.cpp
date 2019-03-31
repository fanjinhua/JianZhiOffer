// 38_StringPermutation.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
	vector<string> Permutation(string str) {
		if (str.empty())
			return vector<string>();
		permu(str, 0, str.length());
		sort(v.begin(), v.end());
		return v;
	}
	void permu(string &s, int index, int len)
	{
		if (index == len)
		{
			if (st.count(s) == 0)
				v.push_back(s);
			st.insert(s);
			return;
		}
		for (int i = index; i < len; ++i)
		{
			swap(s[index], s[i]);
			permu(s, index + 1, len);
			swap(s[index], s[i]);
		}
	}
	vector<string> combine(string str)
	{
		if (str.empty())
			return vector<string>();

		sort(vc.begin(), vc.end());
		return vc;
	}
	void comb(string &str)
	{
		
	}
	set<string> st;
	vector<string> v; 
	vector<string> vc;
};
int main()
{
    std::cout << "Hello World!\n"; 
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
