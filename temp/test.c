/*************************************************************************
	> File Name: test.c
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年11月28日 星期三 20时43分22秒
 ************************************************************************/
#include<stdio.h>
int main()
{
        int a[100];
        int b[100];
        int i,m;
        int k=0;
        int flag=0;
        int n;
        printf("请输入洞的个数n：");
        scanf("%d",&n);
        printf("请输入要经过洞的个数m：");
        scanf("%d",&m);
        for(i=0;i<=n;i++)
        {
            a[i] = 0;
            b[i] = 1;
        }
        for(i=0;;i=(i+m)%n)
    {
                if(a[(i+m)%n]==0)
                a[(i+m)%n]=1;
                else
                if(a[(i+m)%n]==1)
                break;
            
    }
        for(i=0;i<=n;i++)
    {
                if(a[i]==0)
                k++;
                else
                if(a[i]==1)
                flag++;
            
    }
        if(k>0)
    {
                printf("\n兔子有存活机会，位置为：\n");
                for(i=0;i<n;i++)
                if(a[i]==0)
                printf("%d",i);
                printf("\n");
            
    }
        if(flag==n)
            printf("兔子死定了\n");

    return 0;
}

