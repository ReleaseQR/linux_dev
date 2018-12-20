/*************************************************************************
	> File Name: src.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月08日 星期二 20时54分04秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct Date
{
    int year;
    int month;
    int day;
};

void init(Date& d)
{
    d.year = 2018;
    d.month = 5;
    d.day = 8;
}

int main(int argc, char** argv)
{
    Date day = {2012, 5, 8};
    cout << day.year << ":" << day.month << ":" << day.day << endl;

    init(day);
    cout << day.year << ":" << day.month << ":" << day.day << endl;
    return 0;
}
