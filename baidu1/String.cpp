// baidu1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

class String
{
public:
	String(const char * str = NULL)
	{
		if (m_data == NULL)
		{
			m_data = new char[1];
			m_data[0] = '\0';
		}
		else
		{
			m_data = new char[strlen(str) + 1];
			strcpy(m_data, str);
		}
	}
	String(const String &other)
	{
		m_data = new char[strlen(other.m_data)+1];
		strcpy(m_data, other.m_data);
	}
	String &operator =(const String &other)
	{
		if (this == &other)
			return *this;
		delete[] m_data; // 构造函数和拷贝构造函数是初始化，不存在 delete
		m_data = new char[strlen(other.m_data) + 1];
		strcpy(m_data, other.m_data);
		return *this;
	}
	~String(void)
	{
		delete[] m_data; // 或 delete m_data;
	}
private:
	char *m_data; // 用于保存字符串
};

int main()
{

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
