/*************************************************************************
> File Name: test.cpp
> Author: zhang dengxiang
> Mail: 995361462@qq.com
> Created Time: 2018年11月20日 星期二 10时54分18秒
************************************************************************/

#include<iostream>
using namespace std;

struct Obj{
    Obj(){
        throw 2;
    }
};

int main(int argc, char** argv)
{
    int num2 = 60;
    int num1 = 20;

    Obj obj1;

    cout << "nu2 = " << num2 << endl;
    cout << "num1 = " << num1 << endl;

    return 0;
}
