/*************************************************************************
	> File Name: DynamicArray.c
	> Author: 张登翔
	> Mail:1097684676@qq.com 
	> Created Time: 2018年07月08日 星期日 21时40分16秒
 ************************************************************************/
#include "DynamicArray.h"
#include <stdlib.h>
#include <stdio.h>
//初始化
DynamicArray* DynamicArray_Init()
{
    DynamicArray* myArray = (DynamicArray*)malloc(sizeof(DynamicArray));
    myArray->size = 0;
    myArray->capacity = 20;
    myArray->pAddr = malloc(sizeof(int) * myArray->capacity);

    return myArray;
}

//插入
void PushBack_Array(DynamicArray* arr, int value)
{

}

//删除 根据位置删除
void RemoveByPos_Array(DynamicArray* arr, int pos)
{

}

//删除 根据值删除
void RemoveByValue_Array(DynamicArray* arr, int value)
{
    
}

//查找
int Find_Array(DynamicArray *arr, int val)
{
    return 0;
}

//打印
void Print_Array(DynamicArray *arr)
{
    
}

//释放动态数组的内存
void FreeSpace_Array(DynamicArray* arr)
{

}
//清空数组
void Clear_Array(DynamicArray* arr)
{
    
}

//获取动态数组容量
int Capacity_Array(DynamicArray* arr)
{
    return 0;
}

//获取动态数组当前元素个数
int Size_Array(DynamicArray* arr)
{
    return 0;
}

//获取某个位置元素
int At_Array(DynamicArray* arr, int pos)
{
    return 0;
}
