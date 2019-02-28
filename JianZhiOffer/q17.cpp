#include "pch.h"
#include <iostream>

void PrintNumber(char* number)
{
	bool isBeginning0 = true;
	int nLength = strlen(number);

	for (int i = 0; i < nLength; ++i)
	{
		if (isBeginning0 && number[i] != '0')
			isBeginning0 = false;

		if (!isBeginning0)
		{
			printf("%c", number[i]);
		}
	}

	printf("\t");
}

void print_recursive(char* num, int len, int index)
{
	if (index == len - 1)
	{
		PrintNumber(num);
		return;
	}
	for (int i = 0; i < 10; ++i)
	{
		num[index + 1] = '0' + i;
		print_recursive(num, len, index+1);
	}
}

void print(int n)
{
	if (n <= 0)
		return;
	char *num = new char[n + 1];
	num[n] = '\0';

	for (int i = 0; i < 10; ++i)
	{
		num[0] = '0' + i;
		print_recursive(num, n, 0);
	}
	delete[] num;
}
int main()
{
	print(2);
	return 0;
}
