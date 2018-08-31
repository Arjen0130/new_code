#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void replaceSpace(char *str,int length) {
        string tmp(str);
        string::size_type pos = 0;
        int count = 0;
        while ((pos = tmp.find(" ", pos)) != string::npos)
        {
            tmp.replace(pos, 1, "%20");
        }
        tmp.copy(str, tmp.size(), 0);
	}
};

int main()
{
    Solution solution;

    // char str[100] = " helloworld";
    char str[100] = {' ', 'h','e','l','l','o'};
    solution.replaceSpace(str, 100);
    cout  << "The result is " << str << endl;

    return 0;
}