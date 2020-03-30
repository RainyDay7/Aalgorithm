//查找第一个不小于目标值的
//例如对于数组 arr = {1, 2, 5, 6, 9}，目标数 target = 6，那么我们要返回下标 i = 4 。
public class BinarySearchFirstNotSmaller {

    public int binarySearch(int []arr, int target){
        int left = 0;
        int right = arr.length-1;
        while (left <= right){
            int mid = left+(right-left)/2;
            if(arr[mid]<target){
                mid = right+1;
            }
            else {
                right = mid;
            }
        }
        return  right;
    }
}
