/*************************************************************************
	> File Name: arry.cpp
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月07日 星期日 12时39分21秒
 ************************************************************************/

#include<iostream>
using namespace std;

template<class T>
class Array{
public:
    Array(int capacity);
    Array(const Array<T>& arry);//拷贝构造
    T& operator[](int index);
    Array<T> operator=(const Array<T>& arr);
    void PushBack(T& data);
    void PushBack(T&& data);
    ~ Array();
public:
    int mCapacity;
    int mSize;
    T* pAddr;
};

template<class T>
Array<T>::Array(int capacity)
{
    this->mCapacity = capacity;
    this->mSize = 0;
    //申请内存
    this->pAddr = new T[this->mCapacity];
}

template<class T>
T& Array<T>::operator[](int index)
{
    return this->pAddr[index];
}

template<class T>
void Array<T>::PushBack(T& data)
{
    //判断容器是否已经满了否
    if (this->mSize >= this->mCapacity)
    {
        return;
    }

    this->pAddr[this->mSize] = data;
    this->mSize++;
}

//两个&&表示对右值进行取引
template<class T>
void Array<T>::PushBack(T&& data)
{
    if(this->mSize >= this->mCapacity)
        return;
    this->pAddr[this->mSize] = data;
    this-mSize++;
}

template<class T>
Array<T>::Array(const Array<T>& arr)
{
    this->mSize = arr.mSize;
    this->mCapacity = arr.mCapacity;

    //
    this->pAddr = new T[this->mCapacity];
    for (int i = 0; i < this->mSize; i++)
    {
        this->pAddr[i] = arr.pAddr[i];
    }
}

template<class T>
Array<T> Array<T>::operator=(const Array<T>& arr)
{
    if (this->pAddr != NULL)
    {
        delete[] this->pAddr;
    }

    this->mSize = arr.mSize;
    this->capacity = arr.mCapacity;

    this->pAddr = new T[this->capacity];
    for (int i = 0; i < this->mSize; i++)
        this->pAddr[i] = arr.pAddr[i];

    return *this;
}

template<class T>
Array<T>::~Array()
{
    if (this->pAddr != NULL)
        delete[] this->pAddr;
}

void test()
{
    int a = 10, b = 20, c = 30;
    Array<int> myarry(20);
    myarry.PushBack(a);
    myarry.PushBack(b);
    myarry.PushBack(c);

    myarry.PushBack(100);
    myarry.PushBack(200);

    for (int i = 0; i < myarry.mSize; i++)
    {
        cout << myarry[i] << endl;
    }
}

int main(int argc, char** argv)
{
    test();
    
    return 0;
}
