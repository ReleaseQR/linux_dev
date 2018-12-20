/*************************************************************************
	> File Name: test.cpp
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月20日 星期六 17时01分17秒
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

void test(void)
{
    stack<int> s1;
    stack<int> s2(s1);

    //stack操作
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(100);

    cout << s1.top() << endl;

    s1.pop();
    cout << s1.top() << endl;

    while(!s1.empty())
    {
        cout << s1.top() << endl;
        s1.pop();
    }
}

int main(int argc, char** argv)
{
    test();
    return 0;
}
