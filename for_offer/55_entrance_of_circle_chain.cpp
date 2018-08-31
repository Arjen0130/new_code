#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：
    给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if (NULL == pHead)
            return NULL;
        
        int c_len = circle_length(circle_node(pHead));
        if (0 != c_len)
        {
            ListNode * p_first = pHead;
            ListNode * p_second = pHead;
            while (0 < c_len)
            {
                p_first = p_first->next;
                c_len--;
            }
            while (p_first != p_second)
            {
                p_first = p_first->next;
                p_second = p_second->next;
            }
            return p_first;
        }
        return NULL;
    }

private:
    ListNode * circle_node (ListNode * p_head)
    {
        if (NULL == p_head)
            return NULL;
        ListNode * p_fast = p_head->next;
        ListNode * p_slow = p_head;

        while ((NULL != p_fast) && (NULL != p_fast->next) && (p_fast != p_slow))
        {
            p_fast = p_fast->next->next;
            p_slow = p_slow->next;
        }

        return p_fast == p_slow ? p_fast : NULL;
    }

    int circle_length(ListNode * p_node)
    {
        if (NULL == p_node)
            return 0;

        ListNode * p_tmp = p_node->next;
        int len = 1;
        while (p_tmp != p_node)
        {
            p_tmp = p_tmp->next;
            len++;
        }
        return len;
    }
};

int main()
{

    ListNode * p_head = new ListNode(0);
    ListNode * p_tmp = p_head;
    ListNode * p_tmp_2 = NULL;
    for (int i = 1; i < 7; i++)
    {
        p_tmp->next = new ListNode(i);
        p_tmp = p_tmp->next;
        //if (3 == i)
        //    p_tmp_2 = p_tmp;
    }
    //p_tmp->next = p_tmp_2;
    Solution solution;
    cout << solution.EntryNodeOfLoop(p_head)->val << endl;
    return 0;
}