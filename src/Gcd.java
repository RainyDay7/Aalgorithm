
//最大公约数 辗转相除法
//gcd(a,b) = gcd(b, a%b)
//递归边界 gcd(a,0) = a;

//注意 a>b
public class Gcd {
    public static int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b, a%b);
    }
}
