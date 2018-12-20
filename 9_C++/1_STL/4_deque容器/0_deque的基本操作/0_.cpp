/*************************************************************************
	> File Name: 0_.cpp
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月20日 星期六 14时53分12秒
 ************************************************************************/

#include<iostream>
#include<deque>

using namespace std;

void test(void)
{
    deque<int> d1;
    deque<int> d2(10, 5);
    deque<int> d3(d2.begin(), d2.end());

    deque<int> d4(d3);

    for (deque<int>::iterator it = d4.begin(); it != d4.end(); it++)
        cout << *it << endl;
}

void test01(void)
{
    deque<int> d1;
    d1.assign(10, 8);

    for (deque<int>::iterator it = d1.begin(); it != d1.end(); it++)
    cout << *it << endl;
}

void test02(void)
{
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);
    d1.push_back(40);

    d1.push_front(90);

    for (deque<int>::iterator it = d1.begin(); it != d1.end(); it++)
        cout << *it << endl;
}

int main(int argc, char** argv)
{
    
   //test();
    //test01();
    test02();
    return 0;
}
