#include <iostream>

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
题目：
    LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...
    他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！
    红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....
    LL不高兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。
    上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。
    LL决定去买体育彩票啦。 
    现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何， 
    如果牌能组成顺子就输出true，否则就输出false。
    为了方便起见,你可以认为大小王是0。
  方法1：
    使用 STL 算法，将0和非0牌分开存放；
    然后，将非0牌排序，找到其中最大的和最小的；
    确认非0牌中没有重复牌；
    计算最大牌和最小牌的范围不能超过4。
  方法2：
    使用遍历算法，直接找最大牌和最小牌；
    使用数值的位来计算是否有重复牌。
*/

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        
    }
private:
    bool method_1(vector<int> numbers)
    {
        int size = numbers.size();
        if (5 != size)
        {
            return false;
        }

        vector<int> vec_1;
        vector<int> vec_2;
        for (int i = 0; i < size; i++)
        {
            if (0 == numbers[i])
            {
                vec_1.push_back(numbers[i]);
            }
            else
            {
                vec_2.push_back(numbers[i]);
            }
        }

        sort(vec_2.begin(), vec_2.end());

        int size_1 = vec_1.size();
        int size_2 = vec_2.size();
        vec_2.erase(unique(vec_2.begin(), vec_2.end()), vec_2.end());
        int size_3 = vec_2.size();
        if (size_2 != size_3)
        {
            return false;
        }
        if (0 == size_2)
        {
            return true;
        }
        int min = vec_2[0];
        int max = vec_2[size_2 - 1];
        return (max - min + 1 - size_1 - size_2) <= 0;
    }

    bool method_2(vector<int> numbers)
    {
        if(numbers.size() != 5) 
            return false;
        int min = 14;
        int max = -1;
        int flag = 0;
        for(int i = 0; i < numbers.size(); i++) 
        {
            int number = numbers[i];
            if(number < 0 || number > 13) 
                return false;
            if(number == 0) 
                continue;
            if(((flag >> number) & 1) == 1) 
                return false;
            flag |= (1 << number);
            if(number > max) 
                max = number;
            if(number < min) 
                min = number;
            if(max - min >= 5) 
                return false;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    return 0;
}