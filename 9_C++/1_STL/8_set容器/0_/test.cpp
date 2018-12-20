/*************************************************************************
	> File Name: test.cpp
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月30日 星期二 13时24分17秒
 ************************************************************************/

#include<iostream>
#include<set>
using namespace std;



void test(void)
{
    set<int> s;
    s.insert(40);
    s.insert(3);
    s.insert(5);
    s.insert(800);
    s.insert(23);

    //默认从大大小排序
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
        cout << *it << endl;
}

int main(int argc, char** argv)
{
    
    test();
    return 0;
}
