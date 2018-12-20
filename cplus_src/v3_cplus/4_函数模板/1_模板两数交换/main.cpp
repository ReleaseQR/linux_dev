/*************************************************************************
	> File Name: main.cpp
	> Author: DengXiang Zhang
	> Mail:1097684676@qq.com 
	> Created Time: 2018年05月13日 星期日 14时54分52秒
 ************************************************************************/

#include<iostream>
using namespace std;

template <class T>   //template<typename T>
void Tswap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main(int argc, char **argv)
{

    int a = 10;
    int b = 20;

    double da = 1.1;
    double db = 2.3;
    cout << "a = " << a << "b = "<< b << endl;
    Tswap(a,b);
    cout << "a = " << a << "b = "<< b << endl;
    
    cout << "da = " << da <<" db = "<< db << endl;
    Tswap(da,db);
    cout << "da = " << da << " db = "<< db << endl;
    return 0;
}
