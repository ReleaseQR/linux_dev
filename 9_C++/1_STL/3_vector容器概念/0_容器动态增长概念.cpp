/*************************************************************************
	> File Name: 0_容
    器动态增长概念.cpp
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月17日 星期三 09时43分18秒
 ************************************************************************/
#include<iostream>
#include<vector>
using namespace std;


void test(void)
{
    vector<int> v;
    for (int i = 0; i < 10000; i++)
        v.push_back(i);
    
    cout << "size = " << v.size() << endl;
    cout << "capacity = "<< v.capacity() << endl;

    v.resize(10);
    cout << "---------------------" << endl;
    cout << "size = " << v.size() << endl;
    cout << "capacity = "<< v.capacity() << endl;

    //收缩内存空间
    vector<int>(v).swap(v);
    cout << "---------------------" << endl;
    cout << "size = " << v.size() << endl;
    cout << "capacity = "<< v.capacity() << endl;
}


void test01(void)
{
    //reserve 预留空间
    int num = 0;
    int* address = NULL;

    vector<int> v;
    v.reserve(100000); //预先申请足够的内存，以避免多次申请内存
    for(int i = 0; i < 100000; i++)
    {
        v.push_back(i);
        if (address != &(v[0]))
        {
            address = &(v[0]);
            num++;
        }
    }

    cout << "num = " << num << endl;

}

int main(int argc, char** argv)
{
    //test();
    test01();
    return 0;
}
