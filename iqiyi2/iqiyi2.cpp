// iqiyi2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <stack>
// e3[2[abc]gh] ---> //eabcabcghabcabcghabcabcgh

using namespace std;
string decodeString2(string s) {
	int num = 0;
	stack<int> numstack;
	stack<string> strstack;
	string cur = "";
	string result = "";
	for (int i = 0; i < s.size(); ++i)
	{
		if (isdigit(s[i]))
		{
			num = 10 * num + s[i] - '0';
		}
		else if (s[i] == '[')
		{
			numstack.push(num);
			strstack.push(cur);
			num = 0;
			cur.clear();
		}
		else if (isalpha(s[i]))
			cur += s[i];
		else if (s[i] == ']')
		{
			int k = numstack.top();
			numstack.pop();
			for (int j = 0; j < k; ++j)
				strstack.top() += cur;
			cur = strstack.top();
			strstack.pop();
		}
	}
	result = result + cur;
	return result;
}
 // 遇到 ] 弹出数字，打印 n 倍 [] 中的元素
// 保存当前字母 curr，
string decodeString(string s) {
	stack<string> str_stack;
	stack<int> num_stack;
	int num = 0;
	string curr = "";
	for (int i = 0; i < s.size(); ++i)
	{
		if (isdigit(s[i]))
		{
			num = num * 10 + s[i] - '0';
		}
		else if (isalpha(s[i]))
		{
			curr += s[i];
		}
		else if (s[i] == '[')
		{
			num_stack.push(num);
			num = 0;
			str_stack.push(curr);
			curr = "";
		}
		else if (s[i] == ']')
		{
			int times = num_stack.top();
			num_stack.pop();
			string temp = str_stack.top();
			str_stack.pop();
			for (int j = 0; j < times; ++j)
				temp += curr;
			curr = temp;
		}
	}
	string res = "";
	return curr;
}

//eabcabcghabcabcghabcabcgh
int main()
{
	string str = "e3[2[abc]gh]";   //exyzxyzxyzxyzxyzxyzxyzxyzxyz
	cout << decodeString2(str) << endl;
	cout << decodeString(str) << endl;
	return 0;
}
//
//int main()
//{
//	string str;
//	cin >> str;
//	string ret;
//	while (cin >> str)
//	{
//		int state = 0;
//		for (int i = 0; i < str.size(); ++i)
//		{
//			if (isdigit(str[i]) && (str[i+1] == '['))
//			{
//				state++;
//			}
//			else if (isalpha(str[i]))
//				;
//		}
//	}
//
//	return 0;
//}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
