/*************************************************************************
	> File Name: test.cpp
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月20日 星期六 17时19分44秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;


void test(void)
{
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    while(q.size() > 0)
    {
        cout << q.front() << " ";
        q.pop(); //删除对头的元素
    }
    cout << endl;
}
int main(int argc, char** argv)
{
   test();
    return 0;
}
