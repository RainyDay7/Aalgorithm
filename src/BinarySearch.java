//1）给的数据是有序的。
// （2）给的数据⽀支持随机访问
public class BinarySearch {

    public static int binarySearch(int tarhet, int[] arr){
        int left =0;
        int right = arr.length-1;
        while(left<=right){
            int mid = left + (right - left) / 2;//相比较于(left+right)/2, 不会产生溢出，因为left+right可能会产生溢出
            if(arr[mid]>tarhet) right = mid-1;
            else if(arr[mid]<tarhet) left=mid+1;
            else return arr[mid];
        }
        return -1;
    }
}
