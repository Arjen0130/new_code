#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode * p_ret = NULL;
        ListNode * p_tmp = NULL;
        ListNode * p_rear = NULL;

        if (NULL == pHead1)
        {
            return pHead2;
        }
        if (NULL == pHead2)
        {
            return pHead1;
        }

        while ((NULL != pHead1) && (NULL != pHead2))
        {
            if (pHead1->val <= pHead2->val)
            {
                p_tmp = pHead1;
                pHead1 = pHead1->next;
            }
            else
            {
                p_tmp = pHead2;
                pHead2 = pHead2->next;
            }

            if (NULL == p_ret)
            {
                p_ret = p_tmp;
                p_rear = p_ret;
            }
            else
            {
                p_rear->next = p_tmp;
                p_rear = p_tmp;
            }
        }

        if (NULL != pHead1)
        {
            p_rear->next = pHead1;
        }
        if (NULL != pHead2)
        {
            p_rear->next = pHead2;
        }

        return p_ret;
    }
};

int main()
{
    Solution solution;

    ListNode * p_head_1 = NULL;
    ListNode * p_head_2 = NULL;

    for (int i = 2; i >= 0; i--)
    {
        ListNode * p_new_odd_node = new ListNode(2*i+1);
        ListNode * p_new_even_node = new ListNode(2*i);

        if (NULL == p_head_1)
        {
            p_head_1 = p_new_odd_node;
            p_head_2 = p_new_even_node;
        }
        else
        {
            p_new_odd_node->next = p_head_1;
            p_head_1 = p_new_odd_node;
            p_new_even_node->next = p_head_2;
            p_head_2 = p_new_even_node;
        }
    }

    ListNode * p_ret = solution.Merge(p_head_1, p_head_2);

    return 0;
}