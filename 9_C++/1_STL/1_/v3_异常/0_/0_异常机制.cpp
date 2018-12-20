/*************************************************************************
	> File Name: 0_异常机制.cpp
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月07日 星期日 19时19分02秒
 ************************************************************************/

#include<iostream>
using namespace std;

int divide(int x, int y)
{
    if (y == 0)
    {
        throw y; //抛异常
    }
    return x / y;
}

void CallDivide(int x, int y)
{
    divide(x, y);
}

void test()
{
    try{
        CallDivide(10, 0);
    }catch(int e)
    {
        cout << "除数为0" << ",e = " << e <<endl;
    }
}

int main(int argc, char** argv)
{
/*
    try {
        divide(10, 0);
    }catch(int e){ //异常根据类型进行匹配
        cout << "除数为0" << ", e = " << e << endl;
    }
*/
    test();
    return 0;
}
