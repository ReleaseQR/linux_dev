/*************************************************************************
	> File Name: test.cpp
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月30日 星期二 13时52分17秒
 ************************************************************************/

#include<iostream>
using namespace std;


class Compare{
public:
    bool operator()()
    {
        cout << "this is simler functios" << endl;
    }
};
int main(int argc, char** argv)
{
    
    Compare c;
    c();
    return 0;
}
