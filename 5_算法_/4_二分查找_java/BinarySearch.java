/*************************************************************************
	> File Name: BinarySearch.java
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年11月13日 星期二 20时14分44秒
 ************************************************************************/
import java.util.Arrays;

public class BinarySearch{

    public static int rank(int key, int[] a)
    {
        int lo = 0;
        int hi = a.length - 1;
        while(lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (key < a[mid]) hi = mid - 1;
            else if ( key > a[mid]) lo = mid + 1;
            else return mid;
        }

        return -1;
    }

    public static void main(String[] args)
    {
        int[] whitelist = {20, 22, 4, 6, 8, 4, 55, 7, 34, 33, 8, 90};
        Arrays.sort(whitelist);

        for (int i : whitelist)
            System.out.print(i + ", ");
        System.out.println("");

        int key = 33;
        int idex = rank(key, whitelist);
            System.out.println(idex);
    }
}

