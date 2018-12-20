/*************************************************************************
	> File Name: SqList.c
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年12月19日 星期三 17时15分37秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef int data_t;
#define MAX 100


typedef struct {
    data_t data[MAX];
    int length;
}SqList;

SqList* CreateEmptySqList()
{
    SqList* p;
    p = (SqList*)malloc(sizeof(SqList));
    if (p == NULL)
    {
        printf("malloc failed \n");
        return NULL;
    }
    //设置为空表
    p->length = 0;
    return p;
}

//返回１成功，0:失败
int GetElem(SqList* list, int i, data_t* data)
{
    if (i > list->length || i < 0)
    {
        printf("error \n");
        return 0;
    }

    *data = list->data[i];
    return 1;
}


int InsertElem(SqList* list, int idex, data_t data)
{
    if (MAX == list->length)
    {
        printf("List is full \n");
        return 0;
    }else if (idex < 0 || idex > list->length)
    {
        printf("Position error \n");
        return 0;
    }

    for (int k = list->length-1; k >= idex; k--)
        list->data[k+1] = list->data[k];
    list->data[idex] = data;
    list->length += 1;

    return 1;
}

int DeletElem(SqList* list, int idex)
{
    if (list->length == 0)
    {
        printf("List is Empty\n");
        return 0;
    }else if (idex >= list->length || idex < 0)
    {
        printf("POsition error \n");
        return 0;
    }

    for (int k = idex; k < list->length - 1; k++)
        list->data[k] = list->data[k+1];
    list->length--;

    return 1;
}

int main(int argc, char** argv)
{
    data_t num;
    SqList* List = CreateEmptySqList();
    for (int i=0; i <  20; i++)
    {
        InsertElem(List, i, i);
    }

    for (int i = 0; i < List->length; i++)
        printf("list->data[%d] = %d \n", i, List->data[i]);

    GetElem(List, atoi(argv[1]), &num);
    printf("get idex%d =  %d \n", atoi(argv[1]), num);

    InsertElem(List, 10, 100);

    for (int i = 0; i < List->length; i++)
        printf("list->data[%d] = %d \n", i, List->data[i]);

    DeletElem(List, 13);

    for (int i = 0; i < List->length; i++)
        printf("list->data[%d] = %d \n", i, List->data[i]);
    return 0;
}
