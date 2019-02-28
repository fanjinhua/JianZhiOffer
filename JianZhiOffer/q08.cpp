#include "pch.h"
/** /
#include <iostream>
using namespace std;

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(nullptr), right(nullptr), next(nullptr) {

	}
};

ABCEHJIG
SFCSLOPQ
ADEEMNOE
ADIDEJFM
VCEIFGGS

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == nullptr)
			return nullptr;
		TreeLinkNode *pNext = nullptr;
		if (pNode->right != nullptr)
		{
			// ÕÒºó¼Ì
			TreeLinkNode *c = pNode->right;
			while (c->left != nullptr)
			{
				c = c->left;
			}
			pNext = c;
		}
		else if(pNode->next != nullptr)
		{
			if (pNode == pNode->next->left)
			{
				pNext = pNode->next;
			}
			else 
			{
				TreeLinkNode *current = pNode;
				TreeLinkNode *parent = pNode->next;
				while (parent != nullptr && current != parent->left)
				{
					current = parent;
					parent = parent->next;
				}
				pNext = parent;
			}
		}
		return pNext;
	}
};

/**/