#include <iostream>

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        stable_partition(array.begin(), array.end(), isOdd);
        // vector<int> tmp;
        // int size = array.size();
        // int pos = -1;
        // for (int i = 0; i < size; i++)
        // {
        //     if (0 == array[i] % 2)
        //     {
        //         if (-1 == pos)
        //         {
        //             pos = i;
        //         }
        //         tmp.push_back(array[i]);
        //     }
        //     else
        //     {
        //         if (-1 != pos)
        //         {
        //             array[pos++] = array[i];
        //         }
        //     }

        // }
 
        // size = tmp.size();
        // for (int i = 0; i < size; i++)
        // {
        //     array[pos++] = tmp[i];
        // }
    }

    static bool isOdd(int num)
    {
        return num % 2 ? true : false;
    }
};

int main()
{
    vector<int> array;
    for (int i = 0; i < 10; i++)
    {
        array.push_back(i);
    }
    Solution solution;
    solution.reOrderArray(array);

    cout << "The result is";
    for (int i = 0; i < 10; i++)
    {
        cout << " " << array[i];
    }
    cout << endl;
    return 0;
}