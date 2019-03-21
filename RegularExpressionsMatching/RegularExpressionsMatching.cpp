// RegularExpressionsMatching.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include <vector>
using std::vector;
#include <regex>
#include <map>
using std::map;



class Solution {
public:
	bool match(char* str, char* pattern)
	{
		std::regex reg(pattern);
		return regex_match(str, reg);
	}
};

class Solution {
public:
	bool match(char* str, char* pattern)
	{
		int lens, lenp;
		lens = lenp = 0;
		char *p = str;
		while (*p++ != '\0')
			lens++;
		p = pattern;
		while (*p++ != '\0')
			lenp++;
		vector<vector<bool>> dp(lens + 1, vector<bool>(lenp + 1, false));
		// 初始化状态方程
		dp[0][0] = true;
		for (int p = 1; p < dp[0].size(); ++p)
			if (pattern[p-1] == '*')
				 // dp表的索引，从1开始
				dp[0][p] = dp[0][p - 2];

		// 自底向上填表
		for (int i = 1; i < dp.size(); ++i)
		{
			for (int j = 1; j < dp[0].size(); ++j)
			{
				if (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '.')
					dp[i][j] = dp[i - 1][j - 1];
				else if (pattern[j - 1] == '*')
				{
					if (pattern[j - 2] == str[i - 1] || pattern[j - 2] == '.')
						dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i][j - 2];
						// 分别为匹配多次，匹配一次，匹配零次
					else
						dp[i][j] = dp[i][j - 2];
				}
			}
		}
		return dp[lens][lenp];
	}
};


class Solution {
public:
	bool match(char* str, char* pattern)
	{
		if ((str == nullptr) || (pattern == nullptr))
			return false;
		return match_core(str, pattern);
	}

	bool match_core(char* s, char* p)
	{
		if (*s == '\0' && *p == '\0')
			return true;
		if (*s != '\0' && *p == '\0')
			return false;
		if (*(p + 1) == '*')
		{
			if (*s == *p || (*p == '.' && *s != '\0'))
			{
				return match_core(s+1, p) || match_core(s + 1, p + 2) || match_core(s, p + 2);
			}
			else
			{
				return match_core(s, p + 2);
			}
		}
		if (*s == *p || (*p == '.' && *s != '\0'))
			return match_core(s + 1, p + 1);
		return false;
	}
};
#include <queue>
using std::queue;
int main()
{
	using std::cout;	
	#include <map>
	map<int, int> m = { {1,2}, {2, 3} };
	m.insert(std::pair<int, int>(4, 5));
	// 查找
	if (m.count(1))
		m[1]++;
	else
		m[1] = 1;
	// 访问
	for (const auto &item : m)
		cout << item.first << item.second;
	// 访问
	map<int, int>::iterator it = m.begin();
	for (map<int, int>::iterator it = m.begin(); it != m.cend(); ++it)
		std::cout << it->first << it->second;

	queue<int> q;
	q.push(12);
	int i = q.front();
	q.pop();
    std::cout << "Hello World!\n"; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
