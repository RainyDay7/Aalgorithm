///希尔排序的思想是采用插入排序的方法，先让数组中任意间隔为 h 的元素有序，
// 刚开始 h 的大小可以是 h = n / 2,接着让 h = n / 4，让 h 一直缩小，
// 当 h = 1 时，也就是此时数组中任意间隔为1的元素有序，此时的数组就是有序的了。
public class ShellSort {
    public static void main(String[] args) {
        int arr[] = {8, 9, 1, 7, 2, 3, 5, 4, 6, 0};
        ShellSort(arr);
        for (int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
        }
    }


    public static void ShellSort(int[] arr) {
        if (arr == null || arr.length < 2) return;
        int n = arr.length;
        for (int gap = n / 2; gap > 0; gap /= 2) {/*步长逐渐减小*/
            for (int i = gap; i < arr.length; i++) { /*在同一步长内*/
                //同一步长内排序方式是插入排序
                int temp = arr[i], j; //待排元素
                // j-gap代表有序数组中最大数的下标，j-pag表示有序数组的前一个元素
                for(j=i; j>=gap && temp<arr[j-gap]; j-=gap)
                    arr[j] = arr[j-gap]; //原有序数组最大的后移一位
                arr[j] = temp; //找到了合适的位置插入

            }
        }
    }
}
