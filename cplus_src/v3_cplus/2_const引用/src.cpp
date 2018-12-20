/*************************************************************************
	> File Name: src.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月07日 星期一 21时43分59秒
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;

void func(const int &ref)
{
    //ref += 20;  //const is not allow write
    cout << ref << endl;
}

void foo(int &ref)
{
    cout << ref << endl;
}

int main(int argc, char** argv)
{
    int x = 10;
    const int a  = 20;
    string str = "   m y love ";
    func(x + 20); 
    
    foo(const_cast<int&>(a));

    str.erase(0, str.find_first_not_of(' '));
    cout << str << endl;
    return 0;
}

