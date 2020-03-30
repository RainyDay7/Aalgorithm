
//查找第一个大于目标值的数
public class BinarySearchFirstBigger {

    public int binarySearch(int[]arr, int target){
        int left = 0;
        int right = arr.length-1;
        while (left <= right){
            int mid = left+(right-left)/2;
            if(arr[mid]<=target){
                mid = right+1;
            }
            else {
                right = mid;
            }
        }
        return  right;
    }

}
