// 34_PathInTree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using std::vector;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	vector<vector<int> > FindPath(TreeNode* root, int exp) {
		if (!root)
			return paths;
		Path(root, exp, vector<int>());
		return paths;
	}
	void Path(TreeNode* root, int exp, vector<int> p)
	{
		bool isleaf = !(root->left) && !(root->right);
		if (isleaf)
		{
			if ((root->val) == exp)
			{
				p.push_back(root->val);
				paths.push_back(p);
			}
			return;
		}
		if ((root->val) > exp)
			return;
		p.push_back(root->val);
		if (root->left)
			Path(root->left, exp - root->val, p);
		if (root->right)
			Path(root->right, exp - root->val, p);
		return;
	}
	vector<vector<int> > paths;
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
