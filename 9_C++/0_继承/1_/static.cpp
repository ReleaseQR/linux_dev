/*************************************************************************
	> File Name: static.c
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年08月24日 星期五 21时12分57秒
 ************************************************************************/

#include<iostream>

using namespace std;


class A{
public:
    static int a;
private:
    int _b;
};

int A::a = 300;

int main(int argc, char** argv)
{
    A b;
    A c;

    cout << b.a << endl;

    c.a = 2;
    cout << b.a << endl;

    return 0;
}
