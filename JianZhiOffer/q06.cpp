#include "pch.h"
#if 0
#include <iostream>
using namespace std;

struct ListNode
{
	ListNode(int value, ListNode *next = nullptr) : v(value), next(next) {}
	int v;
	ListNode *next;
};

void print_list_rev(ListNode *head)
{
	if (head == nullptr)
		return;
	print_list_rev(head->next);
	std::cout << head->v << std::endl;
}

int main()
{
	ListNode *root = new ListNode(1);
	ListNode *node1 = new ListNode(2);
	ListNode *node2 = new ListNode(3);
	root->next = node1;
	node1->next = node2;
	print_list_rev(root);
	return 0;
}
#endif