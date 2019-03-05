// 26_SubstructureInTree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

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
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool find = false;
		if (pRoot1 && pRoot2)
		{
			if (pRoot1->val == pRoot2->val)
				find = HasSubstruc(pRoot1, pRoot2);
			if (!find)
				find = HasSubtree(pRoot1->left, pRoot2);
			if (!find)
				find = HasSubtree(pRoot1->right, pRoot2);
		}
		return find;
	}
private:
	bool HasSubstruc(TreeNode* r1, TreeNode* r2)
	{
		if (!r2)
			return true;
		if (!r1 && r2)
			return false;
		if (r1->val == r2->val)
			return HasSubstruc(r1->left, r2->left) && HasSubstruc(r1->right, r2->right);
		return false;
	}
};

int main()
{
	TreeNode *n1 = new TreeNode(18);
	TreeNode *n2 = new TreeNode(8);
	TreeNode *n3 = new TreeNode(7);
	TreeNode *n4 = new TreeNode(9);
	TreeNode *n5 = new TreeNode(2);
	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	TreeNode *n11 = new TreeNode(8);
	TreeNode *n12 = new TreeNode(9);
	TreeNode *n13 = new TreeNode(2);
	n11->left = n12;
	n11->right = n13;

	Solution sl;
    std::cout << sl.HasSubtree(n1, n11); 
	delete n1;
	delete n2;
	delete n3;
	delete n4;
	delete n5;
	delete n11;
	delete n12;
	delete n13;
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
