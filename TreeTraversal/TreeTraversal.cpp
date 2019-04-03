// TreeTraversal.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <stack>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x, TreeNode*l=nullptr, TreeNode*r=nullptr) : val(x), left(l), right(r) {}
};

void preorder(TreeNode *root)
{
	stack<TreeNode*> s;
	s.push(root);
	while (!s.empty())
	{
		TreeNode * node = s.top();
		s.pop();
		if (node)
		{
			cout << node->val << "\n";
			s.push(node->right);
			s.push(node->left);
		}
	}
}
// 中序：考察到一个节点后，将其暂存，遍历完左子树后，再输出该节点的值，然后遍历右子树。(左根右)
void inorder(TreeNode *root)
{
	stack<TreeNode*> s;
	TreeNode * node = root;
	while (node || !s.empty())
	{
		while (node)
		{
			s.push(node);
			node = node->left;
		}
		if (!s.empty())
		{
			node = s.top();
			s.pop();
			cout << node->val << "\n";
			node = node->right;
		}
	}
}

void postorder(TreeNode *root)
{
	stack<TreeNode*> s;
	TreeNode *node = root;
	TreeNode *last_visit = root;
	while (node || !s.empty())
	{
		while (node)
		{
			s.push(node);
			node = node->left;
		}
		node = s.top();
		// 查看当前栈顶元素
		// 如果其右子树也为空，或者右子树已经访问
		// 则可以直接输出当前节点的值
		if (!node->right || (node->right == last_visit))
		{
			s.pop();
			cout << node->val << "\n";
			last_visit = node;
			node = nullptr;
		}
		else	// 否则，继续遍历右子树
			node = node->right;
	}
}
/*
			1
		2		3
	 4	  5   6    7
*/


int main()
{
	TreeNode *node7 = new TreeNode(7);
	TreeNode *node6 = new TreeNode(6);
	TreeNode *node5 = new TreeNode(5);
	TreeNode *node4 = new TreeNode(4);
	TreeNode *node3 = new TreeNode(3, node6, node7);
	TreeNode *node2 = new TreeNode(2, node4, node5);
	TreeNode *node1 = new TreeNode(1, node2, node3);
	//preorder(node1);
	//inorder(node1);
	postorder(node1);
	delete node1;
	delete node2;
	delete node3;
	delete node4;
	delete node5;
	delete node6;
	delete node7;

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
