#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：输入两个链表，找出它们的第一个公共结点。
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if ((NULL == pHead1) || (NULL == pHead2))
            return NULL;

        int len_1 = 0;
        ListNode * p_tmp_1 = pHead1;
        while (NULL != p_tmp_1)
        {
            len_1++;
            p_tmp_1 = p_tmp_1->next;
        }

        int len_2 = 0;
        ListNode * p_tmp_2 = pHead2;
        while (NULL != p_tmp_2)
        {
            len_2++;
            p_tmp_2 = p_tmp_2->next;
        }

        int diff = 0;
        if (len_1 > len_2)
        {
            diff = len_1 - len_2;
            p_tmp_1 = pHead1;
            p_tmp_2 = pHead2;
        }
        else
        {
            diff = len_2 - len_1;
            p_tmp_1 = pHead2;
            p_tmp_2 = pHead1;
        }
        while (diff > 0)
        {
            p_tmp_1 = p_tmp_1->next;
            diff--;
        }

        while ((NULL != p_tmp_1) && (NULL != p_tmp_2))
        {
            if (p_tmp_1 == p_tmp_2)
                return p_tmp_1;
            p_tmp_1 = p_tmp_1->next;
            p_tmp_2 = p_tmp_2->next;
        }

        return NULL;
    }
};

int main()
{
    Solution solution;
    return 0;
}