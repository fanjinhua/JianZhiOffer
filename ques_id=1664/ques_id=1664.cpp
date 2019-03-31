// ques_id=1664.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

union un
{
	unsigned char b[4];
	unsigned a;
};

int main()
{
	un u;
	u.b[0] = 100;
	u.b[1] = 0;
	u.b[2] = 0;
	u.b[3] = 0;
	cout << u.a << endl;  // a == 100
	u.b[0] = 0;
	u.b[1] = 0;
	u.b[2] = 0;
	u.b[3] = 100;
	cout << u.a << endl;  // a == 1677721600
	return 0;
}

#if 0
int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 1)
		{
			cout << 1 << endl;
			continue;
		}
		int price = 1;
		n--;
		int upday = 1;
		bool down = false;
		while (n)
		{			
			if (!down)
			{
				for (int i = 0; (n > 0) && (i < upday); ++i)
				{
					price++;
					n--;
				}
				upday = upday + 1;
				down = true;
			}
			else
			{
				price--;
				n--;
				down = false;
			}
		}
		std::cout << price << endl;
	}
	return 0;
}
#endif
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
