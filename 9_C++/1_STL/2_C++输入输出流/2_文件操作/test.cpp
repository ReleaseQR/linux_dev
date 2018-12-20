/*************************************************************************
	> File Name: test.cpp
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月13日 星期六 10时55分06秒
 ************************************************************************/

#include<iostream>
#include<fstream>
using namespace std;

void test()
{
    const char* filepatch = "./source.txt";
    const char* filetarget = "./target.txt";
 //   ifstream ism(filepatch, ios::in); //只读方式打开
    
    ifstream ism;
    ism.open(filepatch, ios::in);
    ofstream osm(filetarget, ios::out | ios::app);
    if (!ism)
    {
        cout << "open failed " << endl;
        return;
    }

    char ch;
    while(ism.get(ch))
    {
       // cout << ch;
        osm.put(ch);
    }
    ism.close();
    osm.close();
}

int main(int argc, char** argv)
{
    
    test();
    return 0;
}
