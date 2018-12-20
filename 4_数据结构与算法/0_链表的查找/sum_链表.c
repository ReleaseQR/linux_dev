/*************************************************************************
	> File Name: sum_结构体话.c
	> Author: 张登翔
	> Mail:1097684676@qq.com 
	> Created Time: 2018年07月10日 星期二 20时45分33秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>


typedef struct SUM_LIST{
    int num;
    int sum;
    struct SUM_LIST* next;
}Sum_List;


Sum_List* Rearch(Sum_List* head, int data)
{
    Sum_List *temp = head;
    while(temp)
    {
        if (temp->num == data)
        {
            break;
        }
        temp = temp->next;
    }
    return temp;
}

int main(int argc, char **argv)
{
    int i = 0;
    int data = 0;
    int sum = 0;
    Sum_List* head = NULL;
    Sum_List* node = NULL;
    Sum_List* temp = NULL;
    while(1)
    {
        sum = 0;
        printf("input data num : ");
        scanf("%d", &data);
        temp = Rearch(head, data);
        if (temp)
        {
            printf("Reaech sum = %d \n", temp->sum);
        }
        else
        {
            for (i = 0; i <= data; i++)
                sum += i;
            printf("calc sum = %d \n", sum);
            //save sum
            node = malloc(sizeof(Sum_List));
            node->num = data;
            node->sum = sum;
            node->next = head;
            head = node;
        }
    }
    
    return 0;
}
