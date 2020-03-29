//O(logn)
public class FastPowerMultiplication {

    public static int pow(int x, int n){
        //求x^n
        int res = 1;
        while(n>0){
            if(n%2==1){
                res*=x;
            }
            n/=2;
            x*=x;
        }
        return res;
    }
}
