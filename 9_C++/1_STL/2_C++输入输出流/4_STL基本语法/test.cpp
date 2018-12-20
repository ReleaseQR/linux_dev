/*************************************************************************
	> File Name: test.cpp
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月13日 星期六 13时19分22秒
 ************************************************************************/

#include<iostream>
#include<vector>

#include<algorithm>

using namespace std;

void show(int v)
{
    cout << v << endl;
}

void test()
{
    vector<int> v;  //定义了一个容器，并且指定存放的元素
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    vector<int>::iterator pBegin = v.begin();
    vector<int>::iterator pEnd   = v.end();
    //通过算法便利
    for_each(pBegin, pEnd, show); //回调函数
}

class Person{
public:
    Person(int age, int id):age(age), id(id)
    {

    }
    void show()
    {
        cout << "age = " << age << ",id = " << id << endl;
    }
private:
    int age;
    int id;
};

void test01()
{
    vector<Person> v;
    Person p1(10, 20), p2(30, 40), p3(50, 60);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(Person(100, 200));

    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        it->show();
        (*it).show();
    }
}

int main(int argc, char** argv)
{
    //test();
    test01();
    return 0;
}
