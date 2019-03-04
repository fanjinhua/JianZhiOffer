// 23_EntryNodeInListLoop.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (!pHead)
			return nullptr;
		ListNode *node = HasLoop(pHead);
		if (!node)
			return nullptr;
		ListNode *temp = node->next;
		int len = 0;
		while (temp != node)
		{
			temp = temp->next;
			len++;
		}

		ListNode *node1 = pHead;
		ListNode *node2 = pHead;
		while (len)
		{
			node2 = node2->next;
			len--;
		}
		while (node2->next != node1)
		{
			node1 = node1->next;
			node2 = node2->next;
		}
		return node1;
	}
	ListNode* HasLoop(ListNode* head)
	{
		if (head->next == nullptr)
			return nullptr;
		ListNode *fast = head->next->next;
		ListNode *slow = head->next;

		while (fast->next && fast->next->next)
		{
			if (slow == fast)
				return fast;
			slow = slow->next;
			fast = fast->next->next;
		}
		return nullptr;
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
