#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution 
{
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (NULL == pHead)
            return NULL;

        ListNode * p_pre = NULL;
        ListNode * p_sta = pHead;
        ListNode * p_end = pHead->next;
        while (NULL != p_end)
        {
            if (p_sta->val != p_end->val)
            {
                p_pre = p_sta;
                p_sta = p_sta->next;
                p_end = p_end ->next;
                continue;
            }
            
            do
            {
                ListNode * p_tmp = p_end;
                p_end = p_end->next;
                delete p_tmp;
            } while ((NULL != p_end) && (p_sta->val == p_end->val));

            delete p_sta;

            if (p_sta == pHead)
            {
                return deleteDuplication(p_end);
            }      
            else
            {
                p_pre->next = p_end;
                p_sta = p_end;
                if (NULL != p_end)
                    p_end = p_end->next;
            } 
        }
        return pHead;
    }
};

int main()
{
    Solution solution;
    return 0;
}