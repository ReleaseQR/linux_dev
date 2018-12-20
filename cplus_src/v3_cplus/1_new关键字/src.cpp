/*************************************************************************
	> File Name: src.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月07日 星期一 21时11分55秒
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;

int main(int argc, char** argv)
{
    string *pstr = new string;
    *pstr = "my love";

    cout << pstr << endl;     // 打印的并不是“my love”的地址，而是pstr指向的对象的地址
    cout << *pstr << endl;

    delete pstr;
    return 0;

}
