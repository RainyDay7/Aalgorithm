
//计数排序
//O(n)
//局限：只能对整数进行排序


import java.util.Arrays;

public class CountSort {
    public static void main(String[] args) {
        int arr[] = {8, 9, 1, 7, 2, 3, 5, 4, 6, 0};
        countort(arr);
        System.out.println("计数排序后："+ Arrays.toString(arr));
    }

    private static void countort(int[] arr) {
        int n = arr.length;
        int max =arr[0], min=arr[0];
        for(int i=1; i<n; i++){//找出最大和最小的数
            if(arr[i]>max) max = arr[i];
            else if(arr[i]<min) min = arr[i];
        }

        int b_len = max-min+2;
        int[] b = new int [b_len];
        for(int i=0; i<n; i++){
            b[arr[i]-min+1] ++;
        }
        for(int i=0; i<b_len-1; i++){
            b[i+1] += b[i];
        }
        int[] c = new int[n];
        for(int i=0; i<n; i++){
            c[b[arr[i]-min]++] =arr[i];
        }
        for (int i=0;i<n;i++){
            arr[i] = c[i];
        }
    }
}
