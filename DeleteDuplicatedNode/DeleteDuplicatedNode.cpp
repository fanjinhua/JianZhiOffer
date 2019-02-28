// DeleteDuplicatedNode.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (!pHead)
			return nullptr;
		// 设置一个哨兵
		ListNode *node = new ListNode(0);
		node->next = pHead;
		ListNode *pre = node;
		ListNode *p = pHead;
		while (p)
		{
			if (p->next && (p->val == p->next->val))
			{//双层检测重复
				int v = p->val;
				// while (p->next && (v == p->next->val)) 用p更新
				while (p && (v == p->val))
					p = p->next;
				pre->next = p;
			}
			else
			{
				pre = p;
				p = p->next;
			}
		}
		return node->next;
	}
};

int main()
{
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(3);
	ListNode *n4 = new ListNode(3);
	ListNode *n5 = new ListNode(4);
	ListNode *n6 = new ListNode(4);
	ListNode *n7 = new ListNode(5);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;

	Solution s;
	s.deleteDuplication(n1);

    std::cout << n1->next->next->val; 
	
	return 0;
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
