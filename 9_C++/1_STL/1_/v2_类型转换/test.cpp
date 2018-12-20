/*************************************************************************
	> File Name: test.cpp
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月07日 星期日 16时03分26秒
 ************************************************************************/

#include<iostream>
using namespace std;

typedef void (*FUN1)(int, int);
typedef int (*FUN2)(char, int);

int main(int argc, char** argv)
{
    int a = 10;
    const int &b = a;

    int &c = const_cast<int &>(b);
    c = 20;
    cout << b << endl;

    const int* p = NULL;
    int* p1 = const_cast<int*>(p);

    int *p2 = NULL;
    const int* p3 = const_cast<const int*>(p2);

    //reinterpret_cast强制类型

    FUN1 fun1;
    FUN2 fun2 = reinterpret_cast<FUN2>(fun1);
    return 0;
}
