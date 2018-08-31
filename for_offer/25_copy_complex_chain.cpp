#include <iostream>

#include <vector>
#include <string>
#include <map>

using namespace std;

/*
题目：输入一个复杂链表
（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
题解：
    通过map，建立内存地址和链表节点的序号之间的关系，然后，通过这个关系处理特殊指针。
注：
    牛客讨论区中有一种看起来更加高效的解法。
*/

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (NULL == pHead)
        {
            return NULL;
        }

        // 根据原始链表，创建新的链表
        // 新创建的链表先只处理主干部分，不处理特殊指针
        // 但是，在创建新链表的时候，使用map，为原始链表和新链表建立指针地址和链表节点的序号之间的关系
        RandomListNode * p_tmp = pHead;
        RandomListNode * p_ret = NULL;
        RandomListNode * p_rear = NULL;
        int index = 0;
        while (NULL != p_tmp)
        {
            RandomListNode * p_new = new RandomListNode(p_tmp->label);
            if (NULL == p_ret)
            {
                p_ret = p_new;
                p_rear = p_new;
            }
            else
            {
                p_rear->next = p_new;
                p_rear = p_new;
            }
            r2i.insert(pair<RandomListNode *, int>(p_tmp, index));
            i2r.insert(pair<int, RandomListNode *>(index, p_new));
            index++;
            p_tmp = p_tmp->next;
        }

        // 根据原始链表特殊指针指向的内存地址，通过map找到节点在链表中的序号
        // 然后使用找到的序号，通过map找到新链表对应的内存地址
        // 最后，使用找到的内存地址，为新链表中的特殊指针赋值
        p_tmp = pHead;
        p_rear = p_ret;
        while (NULL != p_tmp)
        {
            if (NULL != p_tmp->random)
            {
                int index_tmp = r2i[p_tmp->random];
                p_rear->random = i2r[index_tmp];
            }
            p_tmp = p_tmp->next;
            p_rear = p_rear->next;
        }
        return p_ret;
    }

private:
    map<RandomListNode *, int> r2i;
    map<int, RandomListNode *> i2r;
};

int main()
{
    Solution solution;
    return 0;
}