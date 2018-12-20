/*************************************************************************
	> File Name: src.c
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年11月23日 星期五 21时30分04秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
    int data[] = {3, 7, 4, 2, 5, 9, 0, 12, 56, 33, 77};
    int len = sizeof(data)/ sizeof(int);

    int key;
    int i;
    for (int j = 1; j <= len; j++)
    {
        key = data[j];//获取当前牌，待插入队列的牌
        //讲data[j]插入到已经拍好的序列中
        i = j - 1;//data[1.....j-1]表示已经拍好序的左手的牌
        while(i >= 0 && data[i] > key)
        {
            data[i + 1] = data[i];//一旦发现有需要进行插入的元素，则将大的元素往后摞一个位置
            i = i - 1;
        }
        data[i+1] = key;
    }

    for (int i = 0; i < len; i++)
    {
        printf("%d, ", data[i]);
    }
    printf("\n");
    return 0;
}
