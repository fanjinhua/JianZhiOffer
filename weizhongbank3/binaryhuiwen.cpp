// weizhongbank3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
using namespace std;

string turn(string s) {
	string res = "";
	for (int i = s.length() - 1; i >= 0; i--) {
		res += s[i];
	}
	return res;
}

string longtobinarystring(long num)
{
	bitset<64> bs(num);
	string str = bs.to_string();
	return str;
}

int howManyOne(long a) {
	string B = longtobinarystring(a);
	string temp = "";
	string last = "";
	string front = "";
	string odd;
	string even;
	int result = 1;
	long judge;
	long x = 1;
	int rej = 0;
	while (x < a) {
		rej = 0;
		last = "";
		temp = longtobinarystring(x);
		last = temp.substr(temp.length() - 1, 1);
		front = temp.substr(0, temp.length() - 1);
		odd = front + last + turn(front);
		even = temp + turn(temp);
		judge = stol(odd, nullptr, 2);
		if (judge <= a) {
			result += 1;
			cout << judge << endl;
		}
		else {
			rej += 1;
		}
		judge = stol(even, nullptr, 2);
		if (judge <= a) {
			result += 1;
			cout << judge << endl;
		}
		else {
			rej += 1;
		}
		if (rej == 2) return result;
		x += 1;
	}
	return result;
}

// 6 -> 4
int main()
{
	std::cout << howManyOne(6) << endl;
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
