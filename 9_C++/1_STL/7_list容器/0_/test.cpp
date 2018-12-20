/*************************************************************************
	> File Name: test.cpp
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月21日 星期日 20时22分47秒
 ************************************************************************/

#include<iostream>
#include<list>
using namespace std;

void test(void)
{
    list<int> mlist;
    list<int> mlist2(10, 88);
    list<int> mlist3(mlist2);
    list<int> mlist4(mlist2.begin(), mlist2.end());

    for (list<int>::iterator it = mlist4.begin(); it != mlist4.end(); it++)
        cout << *it << " ";
    cout << endl;
}

void test1(void)
{
    list<int> mlist;

    mlist.push_back(100);
    mlist.push_back(200);
    mlist.push_front(300);

    mlist.insert(mlist.begin(), 400);

    list<int>::iterator it = mlist.begin();
    it++;

    mlist.insert(it, 500);

    for (list<int>::iterator mit = mlist.begin(); mit != mlist.end(); mit++)
        cout << *mit << " ";
    cout << endl;
}

int main(int argc, char** argv)
{
    
   // test();
    test1();
    return 0;
}
