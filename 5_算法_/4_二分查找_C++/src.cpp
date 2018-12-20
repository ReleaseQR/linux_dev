/*************************************************************************
	> File Name: src.cpp
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年11月13日 星期二 20时40分23秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int Serach(int key, int num[], int len)
{
    int lo = 0;
    int hi = len - 1;

    while(lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (key < num[mid]) 
            hi = mid - 1;
        else if (key > num[mid])
            lo = mid + 1;
        else
            return mid;
    }

    return -1;
}

int main(int argc, char** argv)
{
    int data[] = {23, 67, 88, 90, 1, 4, 56, 33, 57, 39, 66, 81};
    int len = sizeof(data) / sizeof(int);
    sort(data, data + len);
    
    for (int num : data)
        cout << num << ", ";
    cout << endl;
    
    int keyval;
    cin >> keyval;
    int ret = Serach(keyval, data, len);
    cout << "idenx = " << ret << endl;

    return 0;
}
