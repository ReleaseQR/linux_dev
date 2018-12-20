/*************************************************************************
	> File Name: v2_类的仿函数.cpp
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年11月20日 星期二 18时12分57秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

class Student{
public:
    Student(int num) : mdata(num){
        cout << "this is constrc the mdata =  " << mdata << endl;
    }

    int operator()(int d){
        cout << "this is simle fuctions" << endl;
        mdata = d;
        return mdata;
    }
public:
    int mdata;
};

int main(int argc, char** argv)
{
    
    Student s1(30);
    int data = s1(40);
    cout << "data = " << s1.mdata << endl;
    return 0;
}
