import java.util.Arrays;

//先选定一个基准数，然后从右到左找比这个基准数小的数,从左往右找比这个基准数大的数
//交换这两个数的位置，然后继续找。一遍排序后，基准数的左边都是比他小的数，右边都是比他大的数。然后分为2部分，递归。
public class QuickSort {
    public static void main(String[] args) {
        int arr[] = {8, 9, 1, 7, 2, 3, 5, 4, 6, 0};
        quickSort(arr,0,arr.length-1); //递归版本
        System.out.println("快速排序后："+Arrays.toString(arr));
    }

    /**
     * 快速排序
     * @param arr	排序的数组
     * @param left	数组的前针
     * @param right 数组后针
     */
    private static void quickSort(int[] arr, int left, int right) {
        //如果left==right 数组只有一个元素，直接返回
        if(left>=right){
            return ;
        }
        //设置最左边的元素为基准值
        int key = arr[left];
        int i = left;
        int j = right;
        while(i<j){
            while(arr[j]>=key && i<j) j--;
            // 如果队尾元素小于tmp了,需要将其赋值给low
            arr[i] = arr[j];
            while(arr[i]<=key && i<j) i++;
            arr[j] = arr[i];
        }
        arr[i] = key;
        quickSort(arr,left,i-1);
        quickSort(arr,i+1,right);
    }
}
