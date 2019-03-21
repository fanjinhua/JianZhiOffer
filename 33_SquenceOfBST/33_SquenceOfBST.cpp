// 33_SquenceOfBST.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence)
	{
		if (sequence.empty())
			return false;
		return SquenceOfBST(sequence);
	}
	bool SquenceOfBST(vector<int> sequence) {
		if (sequence.empty())
			return true;
		int p = sequence.back();
		sequence.pop_back();
		auto it = sequence.begin();
		for (; it != sequence.end(); ++it)
			if (*it > p)
				break;
		for (auto it2 = it; it2 != sequence.end(); ++it2)
			if (*it2 < p)
				return false;
		return SquenceOfBST(vector<int>(sequence.begin(), it)) && \
			SquenceOfBST(vector<int>(it, sequence.end()));
	}
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
