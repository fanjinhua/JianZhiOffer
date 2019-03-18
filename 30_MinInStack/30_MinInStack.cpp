// 30_MinInStack.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <stack>

using std::stack;

class Solution {
public:
	void push(int value) {
		A.push(value);
		if (!B.empty())
		{
			if (value < B.top())
				B.push(value);
			else
			{
				B.push(B.top());
			}
		}
		else
			B.push(value);
	}
	void pop() {
		if (!A.empty())
			A.pop();
		if (!B.empty())
			B.pop();
	}
	int top() {
		if (!A.empty())
			return A.top();
		return 0;
	}
	int min() {
		if (!B.empty())
		{
			return B.top();
		}
		return 0;
	}
private:
	stack<int> A;
	stack<int> B;
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
