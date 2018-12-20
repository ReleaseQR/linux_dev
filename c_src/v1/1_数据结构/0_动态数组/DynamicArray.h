/*************************************************************************
	> File Name: DynamicArray.h
	> Author: 张登翔
	> Mail:1097684676@qq.com 
	> Created Time: 2018年07月08日 星期日 21时21分39秒
 ************************************************************************/

#ifndef _DYNAMICARRAY_H
#define _DYNAMICARRAY_H

//动态增长内存,将内存放在堆上
typedef struct DYNAMICARRY {
    int* pAddr;    //存放数据地址
    int size;      //当前有多少个元素
    int capacity;  //容量，当前的最大容量是多少个元素
}DynamicArray;

//初始化
DynamicArray* DynamicArray_Init();

//插入
void PushBack_Array(DynamicArray* arr, int value);

//删除 根据位置删除
void RemoveByPos_Array(DynamicArray* arr, int pos);

//删除 根据值删除
void RemoveByValue_Array(DynamicArray* arr, int value);

//查找
int Find_Array(DynamicArray *arr, int val);

//打印
void Print_Array(DynamicArray *arr);

//释放动态数组的内存
void FreeSpace_Array(DynamicArray* arr);

//清空数组
void Clear_Array(DynamicArray* arr);

//获取动态数组容量
int Capacity_Array(DynamicArray* arr);

//获取动态数组当前元素个数
int Size_Array(DynamicArray* arr);

//获取某个位置元素
int At_Array(DynamicArray* arr, int pos);
#endif

