//求两个有序数组的第K小

public class KthSmallOfTwoOderedArrays {

    // 测试
    public static void main(String[] args) {
        int[] arr1 = {1, 2, 3};
        int[] arr2 = {0,4, 5, 6, 7, 8};
        System.out.println(findKth(arr1, arr2, 2));
    }
    // 由于中位数会受⻓度是奇偶数的影响，所以我们可以把问题转化为求
    // (（n+m+1)/2+(n+m+2)/2)/2。


    public static int findKth(int[] arr1,int []arr2, int k){
        int n = arr1.length;
        int m = arr2.length;
        if(arr1==null || arr1.length<1){
            return arr2[k-1];
        }
        if(arr2==null || arr2.length<1){
            return arr1[k-1];
        }
        return find(arr1, 0, arr1.length-1,arr2,0,arr2.length-1,k);
    }

    private static int find(int[] arr1, int l1, int r1, int[] arr2, int l2, int r2, int k) {
        if(l1>r1) return arr2[l2+k-1];
        if(l2>r2) return arr1[l1+k-1];
        if(k==0) return Math.min(arr1[l1], arr2[l2]);

        int mid1 = l1+(r1-l1)/2;
        int mid2 = l2+(r2-l2)/2;
        int halfLen = mid1-l1+mid2-l2+2;//从A和B的开始位置到两个数组中间位置的元素个数
        if(arr1[mid1]<arr2[mid2]) {
            if (halfLen > k) {
                // 此时在合并的数组中A[aBeg...aMid]和元素一定在B[bMid]的左侧，
                // 即此时第k大的元素一定比B[bMid]这个元素小（严格来说不大于）
                // 故以后没有必要搜索 B[bMid...bEnd]这些元素
                return find(arr1, l1, r1, arr2, l2, mid2-1, k);
            } else {
                // 此时在合并的数组中A[aBeg...aMid]元素一定在B[bMid]的左侧
                // 所以前K个元素中一定包含A[aBeg...aMid]（可以使用反证法来证明这点）
                // 但是无法判断A[amid+1...aEnd]与B[bBeg...bEnd]之间的关系，帮需要对他们进xing判断
                return find(arr1, mid1 + 1, r1, arr2, l2, r2, k - (mid1 - l1 + 1));
            }
        }
        else	{
            if (halfLen > k)
            {
                return find(arr1, l1, mid1 - 1, arr2, l2, r2, k);		}
                else		{
                    return find(arr1, l1, l2, arr2, mid2 + 1, r2, k - (mid2 - l2 + 1));
                }
        }

    }
}
