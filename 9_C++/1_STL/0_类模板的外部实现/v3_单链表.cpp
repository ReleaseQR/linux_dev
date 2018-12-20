/*************************************************************************
	> File Name: v3_单链表.cpp
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年11月20日 星期二 19时22分06秒
 ************************************************************************/

#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void InitList(Node* list, int val)
{
    list->val = val;
    list->next = NULL;
}

//链表元素的添加
int InsertListVal(Node* list, Node* node)
{
    if (node == NULL)
    {
        return -1;
    }
    list->next = node;
    return 0;
}

//链表元素的删除
int DeleteListVal(Node* list, int val)
{
    Node* temp = list;
    if (list == NULL)
    {
        return -1;
    }else

    //遍历链表
    /*
    int idex = 0;;
    for (Node* temp = list ; temp->data != val; temp = temp->next)
    {
        idex++;
    }*/

    while(temp->data != val || temp->next != NULL)
    {
        temp = temp->next;
    }

    //没有对应的元素
    if (temp->next == NULL)
    {
        return -1;
    }
    //找到了需要删除的元素


}

int main(int argc, char** argv)
{
    Node head;
    
    //初始化链表
    InitList(&head, 200);


    return 0;
}
