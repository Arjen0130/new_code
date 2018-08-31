#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：
*/

class Solution 
{
public:
    //Insert one char from stringstream
    void Insert(char ch)
    {
         str += ch;
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int size = str.size();
        if (0 == size)
            return '#';
        if (1 == size)
            return str[0];

        vector<int> count(256, 0);
        vector<int> pos(256, -1);
        for (int i = 0; i < size; i++)
        {
            count[str[i]] += 1;
            pos[str[i]] = i;
        }

        char ret = '#';
        int min = str.size();
        for (int i = 0; i < 256; i++)
        {
            if ((1 == count[i]) && (min > pos[i]))
            {
                min = pos[i];
                ret = (char)i;
            }
        }

        return ret;
    }
private:
    string str;
};

int main()
{
    Solution solution;
    return 0;
}