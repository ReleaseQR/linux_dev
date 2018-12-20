/*************************************************************************
	> File Name: 0_基本操作.cpp
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年11月20日 星期二 14时15分21秒
 ************************************************************************/

#include<iostream>
using namespace std;

template <typename FUNC>
void PrintUser(FUNC func, int a, int b, int c)
{
    func(a, b, c);
}

int main(int argc, char** argv)
{
    
    PrintUser([](int a, int b, int c){
        cout << a << ", " << b << ", " << c << ", " << endl;
    }, 1, 3, 5);
    return 0;
}
