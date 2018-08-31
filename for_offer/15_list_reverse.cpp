#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：输入一个链表，反转链表后，输出新链表的表头。
*/

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (NULL == pHead)
        {
            return NULL;
        }

        ListNode * pRet = NULL;
        while (NULL != pHead)
        {
            ListNode * pTmp = pHead;
            pHead = pHead->next;
            if (NULL == pRet)
            {
                pTmp->next = NULL;
                pRet = pTmp;
            }
            else
            {
                pTmp->next = pRet;
                pRet = pTmp;
            }
            
        }
        return pRet;
    }
};

int main()
{
    Solution solution;
    return 0;
}