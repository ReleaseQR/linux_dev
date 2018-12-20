/*************************************************************************
	> File Name: test.cpp
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月10日 星期三 19时41分24秒
 ************************************************************************/

#include<iostream>
using namespace std;

void func(int a, int b) throw (int, char)
{
    throw 300;
}

int main(int argc, char** argv)
{
    
    try{
        func(10, 20);
    }
    catch(int e)
    {
        cout << "e = " << e <<endl;
    }
    return 0;
}
