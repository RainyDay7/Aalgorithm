import java.util.Arrays;
//不稳定
//构造初始堆。将给定无序序列构造成一个大顶堆（一般升序采用大顶堆，降序采用小顶堆)。
//.此时我们从最后一个非叶子结点开始（叶结点自然不用调整，第一个非叶子结点 从左至右，从下至上进行调整。
//将堆顶元素与末尾元素进行交换，使末尾元素最大。
// 然后继续调整堆，再将堆顶元素与末尾元素交换，得到第二大元素。
// 如此反复进行交换、重建、交换。




public class HeapSort {
    public static void main(String[] args) {
        int arr[] = {8, 9, 1, 7, 2, 3, 5, 4, 6, 0};
        heapSort(arr);
        System.out.println("堆排序后："+ Arrays.toString(arr));
    }
    public static void heapSort(int []arr){
        //构建大顶堆
        for(int i = arr.length/2-1; i>=0; i--){
            adjustHeap(arr,i,arr.length);
        }
        for(int j=arr.length-1; j>0; j--){
            swap(arr, 0, j);
            adjustHeap(arr,0,j);
        }
    }

    private static void adjustHeap(int[] arr, int cur, int length) {
        int temp = arr[cur];
        for(int k=cur*2+1; k<length; k=k*2+1){
            if(k+1<length && arr[k]<arr[k+1]){//如果左子结点小于右子结点，k指向右子结点
                k++;
            }
            if(arr[k]>temp){
                arr[cur] = arr[k];
                cur=k;
            }
            else break;
        }
        arr[cur] = temp;//将temp值放到最终的位置
    }

    public static void swap(int []arr,int a ,int b){
        int temp=arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
}
