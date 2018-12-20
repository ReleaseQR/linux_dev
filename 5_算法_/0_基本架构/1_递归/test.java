/*************************************************************************
	> File Name: test.java
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月22日 星期一 14时01分03秒
 ************************************************************************/
import java.io.*;


public class test
{
    public static void main(String[] args)
    {

        System.out.println(exR1(6));
    }
    
    public static String exR1(int n)
    {
        if (n <= 0) 
            return "-";
        return exR1(n-3) + n + exR1(n-2) + n;
    }
}
