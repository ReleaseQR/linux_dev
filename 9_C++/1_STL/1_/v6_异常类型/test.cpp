/*************************************************************************
	> File Name: test.cpp
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月10日 星期三 19时57分02秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;


class Exception{
public:
    Exception(char *str)
    {
        this->str = new char[strlen(str)];
        strcpy(this->str, str);
    }
    void show()
    {
        cout << str << endl;
    }
    ~ Exception()
    {
        if (str != NULL)
        {
            delete[] str;
        }
    }
private:
    char *str = NULL;
};

//char *chr = const_cast<char*>("this is err \n");
void func() 
{
    throw Exception("this is new err\n");
}

int main(int argc, char** argv)
{
    try{
        func();
    }
    catch(Exception e)
    {
        e.show();
    }

    return 0;
}
