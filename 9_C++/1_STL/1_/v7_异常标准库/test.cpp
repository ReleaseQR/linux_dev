/*************************************************************************
	> File Name: test.cpp
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月13日 星期六 08时51分58秒
 ************************************************************************/

#include<iostream>
#include<exception>
#include<stdexcept>

using namespace std;

class Person{
public:
    Person()
    {
        mAge = 0;
    }

    void SetAge(int age)
    {
        if (age < 0 || age > 100)
        {
            throw out_of_range("age is not rang \n");
        }else
        mAge = age;
    }
public:
     int mAge;
};

int divide(int x, int y)
{
    if (y == 0)
    {
        throw out_of_range("rang out of num \n");
    }
}


void test01()
{
    Person p;
    try{
        p.SetAge(1000);
    }
    catch(exception& e)
    {
       cout << e.what() << endl;
    }
}
int main(int argc, char** argv)
{
    test01();
    return 0;
}
