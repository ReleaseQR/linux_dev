/*************************************************************************
	> File Name: test.cpp
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月08日 星期一 08时46分48秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Person{
public:
    Person()
    {
        cout << "构造函数" << endl;
    }

    ~Person()
    {
        cout << "对象析构" << endl;
    }
};

int divide(int x, int y)
{
    Person p1, p2;
    if (y == 0)
    {
        throw y;
    }
    return x / y;
}
void test01()
{
    try{
        divide(10, 0);
    }catch(int e)
    {
        cout << "发生异常 e = " << e << endl;
    }
    return;
}

int main(int argc, char** argv)
{
    test01();
    return 0;
}
