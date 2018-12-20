/*************************************************************************
	> File Name: src.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月08日 星期二 20时54分04秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Date
{
private:
    int year;
    int month;
    int day;
public:
    Date(int year = 2012, int month = 9, int day = 1)
    {
        this->year = year;
        this->month = month;
        this->day = day;

    }


    void print()
    {
        cout << "year = "<< year << endl;
        cout << "month = " << month << endl;
        cout << "day = "<< day << endl;
    }
};


int main(int argc, char** argv)
{
    Date day(2018, 5, 8);
    Date day2;

    day.print();
    day2.print();
    return 0;
}
