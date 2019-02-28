#include "pch.h"
/** /
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (matrix == nullptr || str == nullptr)
			return false;
		stack<int> s;
		int pos = 0;
		while (str[pos] != '\0')
			pos++;
		int len = pos;
		pos = 0;
		bool *visited = new bool[rows*cols];
		memset(visited, 0, rows*cols);

		for (int i = 0; i < rows*cols; ++i)
		{
			if (matrix[i] == str[pos])
			{
				s.push(i);		
			}
		}

		while (!s.empty())
		{
			int index = s.top();
			s.pop();
			visited[index] = true;
			int flag = 0;
			// up
			if ((index - cols >= 0) && !visited[index - cols] && (matrix[index - cols] == str[pos + 1]))
			{
				s.push(index - cols);
				flag = 1;
				//visited[index - cols] = true;
			}
			// down
			if ((index + cols < rows*cols) && (!visited[index + cols]) && (matrix[index + cols] == str[pos + 1]))
			{
				s.push(index + cols);
				flag = 1;
				//visited[index + cols] = true;
			}
			// left
			if ((index %cols != 0) && !visited[index - 1] && (matrix[index - 1] == str[pos + 1]))
			{
				s.push(index - 1);
				flag = 1;
				//visited[index - 1] = true;
			}
			if (index + 1 < rows*cols)
			{
				if ((index %cols != cols-1) && !visited[index + 1] && (matrix[index + 1] == str[pos + 1]))
				{
					s.push(index + 1);
					flag = 1;
					//visited[index + 1] = true;
				}
			}
			if (flag)
				pos++;
			if (pos == len-1)
				return true;
		}
		delete[]visited;
		return false;
	}
};

int main()
{
	char matrix[] = {'a', 'b', 't', 'g',
					'c', 'f', 'c', 's',
					'j', 'd', 'e', 'h' };
	char str[] = "bfce";
	char m[] = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
	char s[] = "SGGFIECVAASABCEHJIGQEM"; //从右下角绕矩阵一圈
	Solution solu = Solution();

	if (solu.hasPath(m, 5, 8, s))
		cout << "有" << endl;
	else
		cout << "无" << endl;
	return 0;
}
/**/