/*************************************************************************
	> File Name: test.cpp
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月13日 星期六 10时29分34秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
using namespace std;

int main(int argc, char** argv)
{


    int num = 10;
    cout.unsetf(ios::dec);
    cout.setf(ios::oct);//八进制输出
    cout.setf(ios::showbase);
    cout << num << endl;
        
    cout << hex
    << setiosflags(ios::showbase)
    << setw(10)
    << setfill('-')
    << num 
    << endl;

    return 0;
}
