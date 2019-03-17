// 29_PrintMatrix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		if (matrix.size() == 0)
			return vector<int>();
		int rows = matrix.size();
		int cols = matrix[0].size();
		vector<int> res;

		for (int start = 0; (start*2 < rows) && (start*2 < cols); ++start)
		{
			int endCol = cols - start - 1;
			int endRow = rows - start - 1;

			// 打印一行
			for (int i = start; i <= endCol; ++i)
			{
				res.push_back(matrix[start][i]);
			}
			// 打印一列
			for (int i = start + 1; i <= endRow; ++i)
			{
				res.push_back(matrix[i][endCol]);
			}
			// 打印底部一行
			if (endRow != start)
			{
				for (int i = endCol - 1; i >= start; --i)
				{
					res.push_back(matrix[endRow][i]);
				}
			}
			// 打印一列
			if (endCol != start)
			{
				for (int i = endRow - 1; i > start; --i)
				{
					res.push_back(matrix[i][start]);
				}
			}
		}
	return res;
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
