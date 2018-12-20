/*************************************************************************
	> File Name: test.cpp
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月21日 星期日 20时45分10秒
 ************************************************************************/

#include<iostream>
#include<list>
using namespace std;

void test(void)
{
    list<int> mlist;
    mlist.assign(10, 20);

    list<int> mlist1;
   // mlist1 = mlist;

    mlist1.swap(mlist);
    cout << *mlist1.begin() << endl;
}

int main(int argc, char** argv)
{
    test();
    return 0;
}
