/*************************************************************************
	> File Name: inherit.cpp
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年08月24日 星期五 21时01分38秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Parent{
public:
    Parent(int a){
        this->a = a;
    }
    int a;
};

class Child : public Parent{
public:
    Child(int c_a, int p_a) : Parent(p_a)
    {
        this->a = c_a;
    }

    void print()
    {
        cout << this->a << endl;
        cout << Parent::a << endl;
    }
    int a;

};

int main(int argc, char** argv)
{
    Child c(10, 20);
    c.print();

    return 0;
}
