/*************************************************************************
	> File Name: test_0.java
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月22日 星期一 09时17分04秒
 ************************************************************************/
import java.io.*;

//判断一个数是否是素数
public static boolean isPrime(int N)
{
    if (N < 2)
        return false;
    for (int i = 2; i*i <= N; i++)
        if (N % i == 0)
            return false;
    return true;
}


public class test_0
{
    public static void main(String[] args)
    {
        System.out.println("hell java");
    }
}
