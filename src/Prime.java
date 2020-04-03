//判断是否为素数
//O(sqrt(n))
//素数表 O(nloglogn)
public class Prime {
    int maxn = 101;//表长
    int[]prime = new int[maxn];//prime数组存放素数
    boolean [] p = new boolean [maxn];//如果i为素数，p[i]为false,否则为true
    int pnum = 0;//pnum 为素数个数
    public static boolean isPrime(int n){
        if(n<=1) return false;
        int sqr = (int)Math.sqrt(1.0*n);
        for(int i=2; i<=sqr; i++){
            if(n%i == 0) return false;
        }
        return true;
    }

    public  void findPrime(){
        for(int i=2; i<maxn; i++){
            if(p[i] == false){//如果i是素数
                prime[pnum++] = i;
                for(int j=i+i; j<maxn; j+=i){//筛去i的所有倍数，i的所有倍数都不是素数
                    p[j] = true;
                }
            }
        }
    }
}
