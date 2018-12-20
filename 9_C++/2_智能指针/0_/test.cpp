/*************************************************************************
	> File Name: test.cpp
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月30日 星期二 15时03分39秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<memory>
using namespace std;

void test(int &num)
{
    auto_ptr<int> ptr(new int(num));
    //*ptr = 20;
    cout << num << endl;
    cout << *ptr << endl;
    return;
}

int main(int argc, char** argv)
{
    
    int n = 5;
    test(n);

    cout << n << endl;
    return 0;
}
