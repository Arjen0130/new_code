#include <iostream>

#include <vector>
#include <list>
#include <string>

using namespace std;

/*
题目：输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
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
    vector<int> printListFromTailToHead(ListNode* head) {
        list<int> list_tmp;
        while (NULL != head)
        {
            list_tmp.push_front(head->val);
            head = head->next;
        }

        vector<int> vec_ret(list_tmp.begin(), list_tmp.end());
        return vec_ret;
    }
};

int main()
{
    Solution solution;
    return 0;
}