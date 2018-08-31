#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：
    牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
    同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
    例如，“student. a am I”。
    后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
    Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
*/

class Solution {
public:
    string ReverseSentence(string str) {
        string res = "", tmp = "";
        for(unsigned int i = 0; i < str.size(); ++i)
        {
            if(str[i] == ' ') 
            {
                res = " " + tmp + res;
                tmp = "";
            }
            else 
            {
                tmp += str[i];
            }
        }
        if(tmp.size())
        {
            res = tmp + res;
        }
        return res;
    }
};

int main()
{
    Solution solution;
    string str = "student. a am I";
    cout << solution.ReverseSentence(str) << endl;
    return 0;
}