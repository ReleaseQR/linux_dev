/*************************************************************************
	> File Name: v1.cpp
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月02日 星期二 08时20分49秒
 ************************************************************************/

#include<iostream>
using namespace std;

template<class T>
class Person{
public:
    Person(T age, T id);
    void show();
public:
    T mAge;
    T mID;

};

template<class T>
Person<T>::Person(T age, T id)
{
    this->mAge = age;
    this->mID   = id;
}

template<class T>
void Person<T>::show()
{
    cout << mAge << ", " << mID << endl;    
}


int main(int argc, char** argv)
{
    Person<int> p1(10, 20); 
    p1.show();
    return 0;
}
