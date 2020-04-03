//分数的加减乘除
public class FractionCompute {
     public Fraction add(Fraction a, Fraction b){
         Fraction res = new Fraction();
         res.setUp(a.getUp()*b.getDown()+a.getDown()*b.getUp());
         res.setDown(a.getDown()*b.getDown());
         res.reduction();
         return res;
     }
    public Fraction minu(Fraction a, Fraction b){
        Fraction res = new Fraction();
        res.setUp(a.getUp()*b.getDown()-a.getDown()*b.getUp());
        res.setDown(a.getDown()*b.getDown());
        res.reduction();
        return res;
    }
    public Fraction multi(Fraction a, Fraction b){
        Fraction res = new Fraction();
        res.setUp(a.getUp()*b.getUp());
        res.setDown(a.getDown()*b.getDown());
        res.reduction();
        return res;
    }
    public Fraction divide(Fraction a, Fraction b){
        Fraction res = new Fraction();
        res.setUp(a.getUp()*b.getDown());
        res.setDown(a.getDown()*b.getUp());
        res.reduction();
        return res;
    }
}

class Fraction{
    private int up;
    private int down;

    public Fraction() {
    }
    public Fraction(int up, int down) {
        this.up = up;
        this.down = down;
    }
    public int getUp() {
        return up;
    }
    public void setUp(int up) {
        this.up = up;
    }
    public int getDown() {
        return down;
    }
    public void setDown(int down) {
        this.down = down;
    }
    @Override
    public String toString() {
        //输出前需要进行化简
        //分母为1，输出整数，省略分母
        //分子的绝对值>分母down，假分数应该按带分数的形式输出，整数部分为up/down,分子abs(up)/down
        reduction();
        if(down == 1) return ""+up;
        if(Math.abs(up)>down){
            return ""+up/down+Math.abs(up)%down+"/"+down;
        }
        return ""+up+"/"+down;

    }
    public static int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b, a%b);
    }
    public void reduction () {
        if (down < 0) {//分母为负数，令分子和分母都变为负数
            up = -up;
            down = -down;
        }
        if(up == 0)//分子=0，分母为1
            down = 1;
        else {
            int d = gcd(up, down);
            up /= d;
            down /= d;
        }
    }
}


