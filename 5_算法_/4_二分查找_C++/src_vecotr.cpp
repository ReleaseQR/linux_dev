/*************************************************************************
	> File Name: src_vecotr.cpp
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年11月13日 星期二 21时13分58秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int Serach(int key, vector<int> num)
{
    int lo = 0;
    int hi = num.size() - 1;
    int mid;

    while(lo <= hi)
    {
        mid = lo + ((hi - lo) / 2);
        if (key < num[mid]) hi = mid - 1;
        else if (key > num[mid]) lo = mid + 1;
        else 
            return mid;
    }

    return -1;
}

int main(int argc, char** argv)
{
    vector<int> data = {23, 5, 7, 8, 90, 33, 56, 34, 78, 23, 39, 46};   

    sort(data.begin(), data.end());

    for (vector<int>::iterator it = data.begin(); it != data.end(); it++)
        cout << *it << ", ";
    cout << endl;

    int ret = Serach(33, data);

    cout << ret << endl;

    return 0;
}
