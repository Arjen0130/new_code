#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：输入一个链表，输出该链表中倒数第k个结点。
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        int len = 0;
        ListNode * p_read = pListHead;
        
        while (NULL != p_read)
        {
            p_read = p_read->next;
            len++;
        }

        if ((k < 0) || (k > len))
        {
            return NULL;
        }

        int count = 0;
        p_read = pListHead;
        while (count < len - k)
        {
            p_read = p_read->next;
            count++;
        }
        return p_read;
    }
};

int main()
{
    Solution solution;
    return 0;
}