import java.util.Scanner;

//最小公倍数
//lcm = ab/gcd(a,b)
//由于a*b有可能溢出，更恰当的写法是 a/d*b，由于d是最大公约数，所以一定能被整除
// Least Common Multiple
//求一组数字的最小公倍数
public class LCM {
    public static int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b, a%b);
    }
    public  static int lcm(int a, int b){
        return a/gcd(a,b)*b;
    }
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); sc.nextLine();
        for(int i=0; i<n; i++){
            String[] arr = sc.nextLine().split("\\s+"); //字符串以空格分割
            int a = Integer.parseInt(arr[0]);
            for(int j=1; j<arr.length; j++){
                a = lcm(a,Integer.parseInt(arr[j]));
            }
            System.out.println(a);
        }
    }
}
