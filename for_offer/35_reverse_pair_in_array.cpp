#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
题目：
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。
并将P对1000000007取模的结果输出。 
即输出P%1000000007
输入描述:
题目保证输入的数组中没有的相同的数字
数据范围：
	对于%50的数据,size<=10^4
	对于%75的数据,size<=10^5
	对于%100的数据,size<=2*10^5
*/

class Solution {
public:
    int InversePairs(vector<int> data) {
        int size = data.size();
        if (1 >= size)
            return 0;
        
        // 注意这里使用的数据类型
        long long count = 0;
        vector <int> copy(data);
        merge_sort(data, copy, 0, size - 1, count);
        return count % 1000000007;
    }

private:
    void merge_sort(vector<int> & data, vector<int> & copy, int sta, int end, long long & count)
    {
        if (sta >= end)
            return;
        
        int mid = (sta + end) / 2;

        merge_sort(data, copy, sta, mid, count);
        merge_sort(data, copy, mid + 1, end, count);

        int tra_first = mid;
        int tra_second = end;
        // vector<int> copy(data);
        int tra_copy = end;

        while ((tra_first >= sta) && (tra_second > mid))
        {
            if (data[tra_first] > data[tra_second])
            {
                copy[tra_copy--] = data[tra_first--];
                count += (tra_second - mid);
            }
            else
            {
                copy[tra_copy--] = data[tra_second--];
            }
        }

        while (tra_first >= sta)
        {
            copy[tra_copy--] = data[tra_first--];
        }
        while (tra_second > mid)
        {
            copy[tra_copy--] = data[tra_second--];
        }

        for (int i = sta; i <= end; i++)
        {
            data[i] = copy[i];
        }
    }
};

int main()
{
    Solution solution;
    int array_tmp[8] = {1, 2, 3, 4, 5, 6, 7, 0};
    vector<int> vec(array_tmp, array_tmp + 8);
    cout << solution.InversePairs(vec) << endl;
    return 0;
}