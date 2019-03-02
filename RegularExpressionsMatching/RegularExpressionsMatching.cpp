// RegularExpressionsMatching.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>

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
int main()
{
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
