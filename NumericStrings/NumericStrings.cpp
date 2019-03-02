// NumericStrings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

class Solution {
public:
	bool isNumeric(char* string)
	{
		if (string == nullptr || *string == '\0')
			return false;
		char *p = string;
		int doted = 0;
		int exp = 0;
		while (*p != '\0')
		{
			if (*p == '.' && !isUnsigned(&p))
				return false;
			if (*p != '.' && !isInteger(&p))
				return false;
			// ¥¶¿Ì 1.2.3
			if (*p == '.')
			{
				if (doted || exp)
					return false;
				doted = 1;
				p++;
				continue;
			}

			if (*p == 'e' || *p == 'E')
			{
				exp = 1;
				p++;
				if (*p == '\0')
					return false;
			}
			if (!isInteger(&p))
				return false;
		}
		return true;
	}
	
	bool isUnsigned(char **s)
	{
		for (; **s != '\0'; (*s)++)
		{
			if (**s == '.' || **s == 'e' || **s == 'E')
				return true;
			if (!isdigit(**s))
				return false;
		}
		return true;
	}
	bool isInteger(char** s)
	{
		if (**s == '+' || **s == '-')
			(*s)++;
		return isUnsigned(s);
	}
};


int main()
{
	Solution s;
	char str[] = { '1', '.', '2', '.' ,'3','\0' };

    std::cout << s.isNumeric(str);
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
